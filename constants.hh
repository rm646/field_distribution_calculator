// $Id: constants.hh,v 1.1 2009/01/25 11:57:46 jsr Exp $

#ifndef cavlib_constants_hh
#define cavlib_constants_hh

// constants.hh

// Defines useful physical and mathematical constants.  Values taken
// from CODATA 2006 recommendations.  

// John Richer, adapted from an old AIPS++ file.

// The values are defined as constant double precision values in a
// namespace called C. To use these values, include this header file,
// and reference the variables as e.g. C::Gravity or
// C::astronomical_unit

namespace C
{
extern const double pi;                  // pi
extern const double gamma;               // gamma

//#--------------------------------------------------------------------
//  Physical constants, and quantities
//#--------------------------------------------------------------------

// Fundamental physical constants (SI units):

extern const double c;                   // velocity of light
extern const double Gravity;             // Gravitational constant
extern const double Planck;              // Planck's constant
extern const double GasConst;            // gas constant
extern const double Avogadro;            // Avogardo's constant
extern const double qe;                  // electron charge
extern const double mp;                  // proton mass
extern const double mp_me;               // proton mass / electron mass

// Derived physical constants (SI units):

extern const double mu0;                 // magnetic permeability of vacuum
extern const double epsilon0;            // electric permittivity of vacuum
extern const double Planck_2pi;          // Planck's constant divided by 2*pi
extern const double u;                   // atomic mass unit
extern const double amu;                 // atomic mass unit
extern const double Boltzmann;           // Boltzmann's constant
extern const double Faraday;             // Faraday's constant
extern const double me;                  // electron mass
extern const double re;                  // classical electron radius
extern const double a0;                  // Bohr radius

// Physical quantities (SI units):

extern const double R0;                  // solar radius

//#--------------------------------------------------------------------
//  Physical units
//#--------------------------------------------------------------------

//#-----------------------------
//  Numerical conversion factors
//#-----------------------------

extern const double yotta;               // e+24 (Y)
extern const double zetta;               // e+21 (Z)
extern const double exa;                 // e+18 (E)
extern const double peta;                // e+15 (P)
extern const double tera;                // e+12 (T)
extern const double giga;                // e+09 (G)
extern const double mega;                // e+06 (M)
extern const double kilo;                // e+03 (k)
extern const double hecto;               // e+02 (h)
extern const double deka;                // e+01 (D)
extern const double deci;                // e-01 (d)
extern const double centi;               // e-02 (c)
extern const double milli;               // e-03 (m)
extern const double micro;               // e-06 (u)
extern const double nano;                // e-09 (n)
extern const double pico;                // e-12 (p)
extern const double femto;               // e-15 (f)
extern const double atto;                // e-18 (a)
extern const double zepto;               // e-21 (z)
extern const double yocto;               // e-24 (y)

// Angular measure:

extern const double radian;              // radian
extern const double circle;              // circle
extern const double circuit;             // circuit
extern const double cycle;               // cycle
extern const double rev;                 // revolution
extern const double revolution;          // revolution
extern const double rotation;            // rotation
extern const double degree;              // degree
extern const double arcmin;              // arcminute
extern const double arcsec;              // arcsecond
extern const double grad;                // grad

// Solid angular measure:

extern const double steradian;           // steradian
extern const double sphere;              // sphere
extern const double square_degree;       // square degree
extern const double square_arcmin;       // square arcminute
extern const double square_arcsec;       // square arcsecond

//#----------------------------
//  Physical conversion factors
//#----------------------------

// Time interval [T]:

extern const double second;              // second
extern const double minute;              // minute
extern const double hour;                // hour
extern const double day;                 // day
extern const double week;                // week
extern const double fortnight;           // fortnight

extern const double Hertz;               // Hertz

// Length [L]:

extern const double metre;               // metre
extern const double meter;               // metre (American spelling)
extern const double Fermi;               // Fermi
extern const double Angstrom;            // Angstrom
extern const double inch;                // inch
extern const double thou;                // thou (inch/1000)
extern const double hand;                // hand
extern const double span;                // span
extern const double foot;                // foot
extern const double yard;                // yard
extern const double fathom;              // fathom
extern const double rod;                 // rod
extern const double perch;               // perch
extern const double rope;                // rope
extern const double chain;               // chain
extern const double furlong;             // furlong
extern const double mile;                // English statute mile
extern const double nautical_mile;       // nautical mile
extern const double point;               // point
extern const double pica;                // pica
extern const double astronomical_unit;   // astronomical unit
extern const double light_second;        // light second
extern const double light_year;          // light year
extern const double parsec;              // parsec

// Area [L*L]:

extern const double square_metre;        // square metre
extern const double square_meter;        // square meter (American spelling)
extern const double are;                 // are
extern const double barn;                // barn
extern const double square_inch;         // square inch
extern const double square_foot;         // square foot
extern const double square_yard;         // square yard
extern const double square_mile;         // square mile
extern const double square_perch;        // square perch
extern const double rood;                // rood
extern const double acre;                // acre
extern const double square;              // square

// Volume [L*L*L]:

extern const double cubic_metre;         // cubic metre
extern const double cubic_meter;         // cubic meter (American spelling)
extern const double stere;               // stere
extern const double litre;               // litre
extern const double liter;               // liter (American spelling)
extern const double cubic_inch;          // cubic inch
extern const double cubic_foot;          // cubic foot
extern const double cubic_yard;          // cubic yard
extern const double cubic_mile;          // cubic mile
extern const double gallon;              // (Brit) gallon
extern const double quart;               // (Brit) quart
extern const double pint;                // (Brit) pint
extern const double gill;                // (Brit) gill
extern const double fluid_ounce;         // (Brit) fluid ounce
extern const double drachm;              // (Brit) drachm
extern const double scruple;             // (Brit) scruple
extern const double minim;               // (Brit) minim
extern const double USgallon;            // (US liq) gallon
extern const double USquart;             // (US liq) quart
extern const double USpint;              // (US liq) pint
extern const double USgill;              // (US liq) gill
extern const double USfluid_ounce;       // (US liq) fluid ounce
extern const double USdram;              // (US liq) dram
extern const double USminim;             // (US liq) minim

// Speed [L/T]:

extern const double knot;                // nautical miles per hour

// Acceleration (speed / time) [L/(T*T)]:

extern const double g;                   // gravitational acceleration

// Mass [M]:

extern const double kilogram;            // kilogram
extern const double gram;                // gram
extern const double tonne;               // metric ton
extern const double carat;               // metric carat
extern const double pound;               // pound (avoirdupois)
extern const double ounce;               // ounce (avoirdupois)
extern const double stone;               // stone
extern const double quarter;             // (long) quarter (Brit)
extern const double hundredweight;       // (long) hundredweight
extern const double ton;                 // (long) ton
extern const double cental;              // cental
extern const double shortquarter;        // short quarter (Brit)
extern const double shortcwt;            // short hundredweight
extern const double shortton;            // short ton

// Force (mass * acceleration) [M*L/(T*T)]:

extern const double Newton;              // Newton
extern const double dyne;                // dyne

// Pressure (force / area) [M/(L*T*T)]:

extern const double Pascal;              // Pascal
extern const double atmosphere;          // atmosphere
extern const double bar;                 // bar
extern const double torr;                // torr
extern const double mmHg;                // mm of Mercury

// Energy (force * length) [M*L*L/(T*T)]:

extern const double Joule;               // Joule
extern const double kWh;                 // kiloWatt*hour
extern const double erg;                 // erg
extern const double calorie;             // calorie (thermochemical)
extern const double calorie_IT;          // calorie (International Steam)
extern const double Btu;                 // British thermal unit
extern const double eV;                  // electron volt

// Temperature difference (energy) [M*L*L/(T*T)]:

extern const double Kelvin;              // Kelvin
extern const double Celsius;             // Celsius
extern const double Centigrade;          // Centigrade
extern const double Fahrenheit;          // Fahrenheit
extern const double Rankine;             // Rankine

// Temperature at 0 on each temperature scale:

extern const double Kelvin_0;
extern const double Celsius_0;
extern const double Centigrade_0;
extern const double Fahrenheit_0;
extern const double Rankine_0;

// Power (energy / time) [M*L*L/(T*T*T)]:

extern const double Watt;                // Watt
extern const double horsepower;          // horsepower

// Flux density (power / area / frequency) [M/(T*T)]:

extern const double Jansky;              // Jansky
extern const double fu;                  // flux units

// Electric charge [Q] (Coulomb):

extern const double Coulomb;             // Coulomb
extern const double abCoulomb;           // abCoulomb (emu)
extern const double statCoulomb;         // statCoulomb (esu)

// Electric current (charge / time) [Q/T]:

extern const double Ampere;              // Ampere
extern const double abAmpere;            // abAmpere (emu)
extern const double statAmpere;          // statAmpere (esu)

// Electric field strength (force / charge) [M*L/(T*T*Q)]:

// Electric potential (energy / charge) [M*L*L/(T*T*Q)]:

extern const double Volt;                // Volt
extern const double abVolt;              // abVolt (emu)
extern const double statVolt;            // statVolt (esu)

// Electric resistance (potential / current) [M*L*L/(T*Q*Q)]]:

extern const double Ohm;                 // Ohm
extern const double abOhm;               // abOhm (emu)
extern const double statOhm;             // starOhm (esu)

// Electric conductance (current / potential) [T*Q*Q/(M*L*L)]:

extern const double Siemens;             // Siemens
extern const double mho;                 // mho

// Electric capacitance (charge / potential) [T*T*Q*Q/(M*L*L)]:

extern const double Farad;               // Farad
extern const double abFarad;             // abFarad (emu)
extern const double statFarad;           // statFarad (esu)

// Electric inductance (potential * time / current) [M*L*L/(Q*Q)]:

extern const double Henry;               // Henry
extern const double abHenry;             // abHenry (emu)
extern const double statHenry;           // statHenry (esu)

// Magnetic induction (force / charge / velocity) [M/(T*Q)]:

extern const double Tesla;               // Tesla
extern const double Gauss;               // Gauss (emu)

// Magnetic flux (magnetic induction * area) [M*L*L/(T*Q)]:

extern const double Weber;               // Weber
extern const double Maxwell;             // Maxwell (emu)
extern const double line;                // line (emu)

// Magnetomotance = magnetomotive force (current) [Q/T]:

extern const double Ampere_turn;         // Ampere-turn
extern const double abAmpere_turn;       // abAmpere-turn
extern const double Gilbert;             // Gilbert (emu)
extern const double praGilbert;          // praGilbert (emu)

// Magnetic field intensity (current / length) [Q/(T*L)]:

extern const double Oersted;             // Oersted (emu)
extern const double praOersted;          // praOersted (emu)

// Radioactivity (Bequerel):

extern const double Bequerel;            // Bequerel

// Luminous intensity [Iv]:

extern const double candela;             // candela

// Amount of substance [N]:

extern const double mole;                // mole
extern const double molecule;            // number of molecules

}

#endif 

