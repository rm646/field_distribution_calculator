#include <vector>
#include <iostream>
#include "constants.cc"
#include "vec3.hh"
#include "fpointdef.h" //a brief structure which holds a a position vector and a vector associated with that point
#include "ver2loop.h" //specify functions which describe the current dist. (ver2 uses a more appropriate parametrisation)

using std::vector;
using cav::Vec3;
using std::cout;
using std::abs;

double pi = C::pi;

//Fix the number of points in each dimension (for b measurement)
const int xnum = 300;
const int ynum = 300;
const int znum = 1;

//Describe lattice of points to measure b at
double fx(int ix, int iy, int iz);
double fy(int ix, int iy, int iz);
double fz(int ix, int iy, int iz);

//Set a threshold for components of the B field which if exceeded will become the component which exceeded it (see calculate_bfield)
//double threshold = 2.5;

void distribute_b_points(field_point field[xnum][ynum][znum], double (*fx)(int, int, int),  double (*fy)(int, int, int),  double (*fz)(int, int, int));

void calculate_bfield(field_point field[xnum][ynum][znum], field_point current[xcnm][ycnm][zcnm]);

void print_bfield(field_point field[xnum][ynum][znum]);

void output_heatmap_data(field_point field[xnum][ynum][znum], int iz);

void output_vector_field_in_plane(field_point field[xnum][ynum][znum], int iz);

void cakeulate_deviation(field_point field[xnum][ynum][znum], double (*theory_single)(double), int iy, int iz);

void calculate_dev_plane(field_point field[xnum][ynum][znum]);

double theory_single(double x);

int main() {

  static field_point field[xnum][ynum][znum];
  static field_point current1[xcnm][ycnm][zcnm];
  static field_point current2[xcnm][ycnm][zcnm];
  distribute_b_points(field, fx, fy, fz);
  double x1 =0.5;
  setup_current_loop(current1, x1, cx, cy, cz,1.0);  //fill the array describing the current using the info in the header file
  double x2 =-0.5;
  setup_current_loop(current2, x2, cx, cy, cz,-1.0);
  calculate_bfield(field, current1);
  //cakeulate_deviation(field, theory_single, 0, 0);
  calculate_bfield(field, current2);
  output_vector_field_in_plane(field,0);
  //output_heatmap_data(field, 0);  //output x,y,|B| to console
  //print_current(current1); //output r,dl to console
  //calculate_dev_plane(field);
  return 0;

}


double fx(int ix,int iy,int iz) {
  //runs from -xrange/2 to xrange/2
  double xrange = 16.0;
  double x = ((double)ix)*(xrange/(double)xnum) - xrange/2.0;
  return x;
}

double fy(int ix,int iy,int iz) {
  //runs from -yrange/2 to yrange/2
  double yrange = 16.0;
  return ((double)iy)*(yrange/(double)ynum) - yrange/2;
}

double fz(int ix,int iy,int iz) {
  //double zrange = 4.0;
  //return ((double)iz)*(zrange/znum) - zrange/2;
  return 0.0;
}

void distribute_b_points(field_point field[xnum][ynum][znum], double (*fx)(int, int, int),  double (*fy)(int, int, int),  double (*fz)(int, int, int))  {
    //This function generates a set of field points by using the functions fx,fy,fz

    //Placing points

    for (int iz=0; iz< znum; iz++) {
      for (int iy=0; iy< ynum; iy++) {
	for (int ix=0; ix< xnum; ix++) {
	  Vec3 place(fx(ix,iy,iz), fy(ix,iy,iz), fz(ix,iy,iz));
	  field[ix][iy][iz].r = place;
	  for (int i=0; i<3; i++){
	    field[ix][iy][iz].fvec[i] =0;
	  }
	  //Am I wasting memory by not killing off place?
	}
      }
    }
    return;
}

void calculate_bfield(field_point field[xnum][ynum][znum], field_point current[xcnm][ycnm][zcnm]) {
  Vec3 R(0.5,0,0);
  for (int iz=0; iz< znum; iz++) {
    for (int iy=0; iy< ynum; iy++) {
      for (int ix=0; ix< xnum; ix++) {

	  for (int cx=0; cx< xcnm; cx++) {
	    for (int cy=0; cy< ycnm; cy++) {
	      for (int cz=0; cz< zcnm; cz++) {
		R = field[ix][iy][iz].r - current[cx][cy][cz].r;
		Vec3 db = ( (1/((double)4*pi)) * (current[cx][cy][cz].fvec * R) ) / (R.len()*R.len()*R.len());
		if(R.len() !=0){
		  field[ix][iy][iz].fvec = field[ix][iy][iz].fvec + db;
		}
	      }
	    }
	  }
	  //in here, we threshold the freshly calculated b field to avoid those pesky 'singularities' in the heatmap
	  /*if(fabs(field[ix][iy][iz].fvec[1]) > threshold)
	    {
	      field[ix][iy][iz].fvec[1] = threshold;
	      // field[ix][iy][iz].fvec[1] = threshold/sqrt(3);
	      //field[ix][iy][iz].fvec[2] = threshold/sqrt(3);
	      //field[ix][iy][iz].fvec[3] = threshold/sqrt(3);
	    }
	  if(fabs(field[ix][iy][iz].fvec[2]) > threshold)
	    {field[ix][iy][iz].fvec[2] = threshold;}
	  if(fabs(field[ix][iy][iz].fvec[3]) > threshold)
	    {field[ix][iy][iz].fvec[3] = threshold;}
	  */
	  //if(field[ix][iy][iz].fvec.len() > threshold)
	  //{
	  //  for (int i=0;i<3;i++) {field[ix][iy][iz].fvec[i]=threshold;}
	  //}
      }
    }
  }
}


void print_bfield(field_point field[xnum][ynum][znum]) {
   for (int iz=0; iz< znum; iz++) {
      for (int iy=0; iy< ynum; iy++) {
	for (int ix=0; ix< xnum; ix++) {
	  cout << field[ix][iy][iz].r[0] << " "<< field[ix][iy][iz].r[1]<< " " << field[ix][iy][iz].r[2] <<
	    " "<< field[ix][iy][iz].fvec[0]<< " "<< field[ix][iy][iz].fvec[1]<< " "<< field[ix][iy][iz].fvec[2]<< std::endl;
	}
      }
    }
}

void output_heatmap_data(field_point field[xnum][ynum][znum], int iz) {
  //Function outputs blocks of data suitable for gnuplot pm3d using a given index to supply the level of the xy plane
  for (int iy=0; iy< ynum; iy++) {
    for (int ix=0; ix< xnum; ix++) {
      cout << field[ix][iy][iz].r[0] << "   " << field[ix][iy][iz].r[1] << "   " <<field[ix][iy][iz].fvec.len() << std::endl;
    }
    cout<<std::endl;
  }
}

void output_vector_field_in_plane(field_point field[xnum][ynum][znum], int iz){
  //assumes index iz labels the desired slices
  //outputs x,y,bx,by with bx, by normalised for better-looking plots
  for (int iy=0; iy< ynum; iy++) {
    for (int ix=0; ix<xnum; ix++) {
      cout << field[ix][iy][iz].r[0] << "   " << field[ix][iy][iz].r[1] << "   " << field[ix][iy][iz].fvec[0]/field[ix][iy][iz].fvec.len() << "   " << field[ix][iy][iz].fvec[1]/field[ix][iy][iz].fvec.len() <<std::endl;}
  }

}

double theory_single(double x){
  double B = 1.0/(2.0*pow((1+(x-0.5)*(x-0.5)),(1.5)));
  return B;
}

void cakeulate_deviation(field_point field[xnum][ynum][znum], double (*theory_single)(double), int iy, int iz) {
  //calculates deviation of the b_field from theory for a single loop
  for(int ix=0; ix<xnum; ix++) {
    double x = field[ix][iy][iz].r[0];
    double approx = field[ix][iy][iz].fvec[0];
    double theory = theory_single(x);
    double deviation = theory - approx;
    cout<<x<<"   "<<approx<<"   "<<theory<<"    "<<deviation<<"\n";
  }
}

void calculate_dev_plane(field_point field[xnum][ynum][znum]){
  double centre_theory = pow((4.0/5.0),1.5);
  double x;
  double y;
  double b;
  double dev;
  int iz = 0;
  for(int iy=0; iy<ynum; iy++){
    for(int ix=0; ix<xnum; ix++){
      x = field[ix][iy][iz].r[0];
      y = field[ix][iy][iz].r[1];
      b = field[ix][iy][iz].fvec.len();
      dev = centre_theory - b;
      cout<<x<<"   "<<y<<"   "<<dev<<"\n";
    }
    cout<<std::endl;
  }

}
