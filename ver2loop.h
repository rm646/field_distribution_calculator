#ifndef LOOP_H
#define LOOP_H

//Describes a loop, centered on x=0.5 and lying in the zy plane (z positive) 
double R = 1.0;


//Fix the number of points to be used in describing each current dist.
//MUST BE EVEN
const int xcnm = 1;
const int ycnm = 200; 
const int zcnm = 1;

using cav::Vec3;
using std::cout;

//Set of functions to describe a loop in the zy plane centered on x=0.5
double cx(int ix,int iy,int iz, double &dx, double x0) {
  dx = 0.0;
  return x0;
}

double cy(int ix,int iy,int iz, double &dy) {
  double theta = 2*C::pi*((double)iy)/((double)ycnm);
  double dtheta = 2*C::pi*(1.0/((double)ycnm));
  dy = -R*sin(theta)*dtheta;
  return R*cos(theta);
}

double cz(int ix,int iy,int iz, double &dz) {
  double theta = 2*C::pi*((double)iy)/((double)ycnm);
  double dtheta = 2*C::pi*(1.0/((double)ycnm));
  dz = R*cos(theta)*dtheta;
  return R*sin(theta);
}



void setup_current_loop(field_point field[xcnm][ycnm][zcnm], double x0, double (*cx)(int, int, int, double&, double),  double (*cy)(int, int, int, double&),
			double (*cz)(int, int, int, double&), double current) {
  //Placing points
  double dx=0;
  double dy=0;
  double dz=0;
    for (int iz=0; iz< zcnm; iz++) {
      for (int iy=0; iy< ycnm; iy++) {
	for (int ix=0; ix< xcnm; ix++) {
	  Vec3 place(cx(ix,iy,iz, dx, x0), cy(ix,iy,iz, dy), cz(ix,iy,iz, dz));
	  Vec3 dl(dx,dy,dz);
	  field[ix][iy][iz].r = place;
	  field[ix][iy][iz].fvec = current*dl; 
	}
      }
    }
}

void print_current(field_point field[xcnm][ycnm][zcnm]) {
   for (int iz=0; iz< xcnm; iz++) {
      for (int iy=0; iy< ycnm; iy++) {
	for (int ix=0; ix< zcnm; ix++) {
	  cout << field[ix][iy][iz].r[0] << " "<< field[ix][iy][iz].r[1]<< " " << field[ix][iy][iz].r[2] << 
	    " "<< field[ix][iy][iz].fvec[0]<< " "<< field[ix][iy][iz].fvec[1]<< " "<< field[ix][iy][iz].fvec[2]<< std::endl;
	}
      }
    }
}

#endif
