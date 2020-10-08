// $Id: constants.cc,v 1.1 2009/01/25 11:58:23 jsr Exp $
// constants.cc
// Defines a set of useful physical constants and coversions. SI-based. 

#include "constants.hh"

namespace C
{
  const double pi                  =  3.141592653589793238462643;

  const double gamma               =  0.577215664901532860606512;

  // Physical constants and conversion factors
  // CODATA recomendations, 2006

  // Fundamental physical constants (SI units):

  const double c                   = 2.99792458e+08;
  const double Gravity             = 6.67428e-11;
  const double Planck              = 6.62606896e-34;
  const double GasConst            = 8.314472;
  const double Avogadro            = 6.02214179e+23;
  const double qe                  = 1.602176487e-19;
  const double mp                  = 1.672621637e-27;
  const double mp_me               = 1836.15267247;

  // Derived physical constants (SI units):

  const double mu0                 = 4.0e-7 * pi;
  const double epsilon0            = 1.0 / ( mu0 * c * c );
  const double Planck_2pi          = Planck / ( 2 * pi );
  const double u                   = 1.0e-3 / Avogadro;
  const double amu                 = 1.0e-3 / Avogadro;
  const double Boltzmann           = GasConst / Avogadro;
  const double Faraday             = Avogadro * qe;
  const double me                  = mp / mp_me;
  const double re                  = 2.8179e-15;
  const double a0                  = 5.2918e-11;

  // Physical quantities (SI units):

  const double R0                  = 6.9599e+08;

  //----------------------------------------------------------------------------
  // Numerical conversion factors
  //----------------------------------------------------------------------------

  // Metric prefixes (unity):

  const double yotta               = 1.0e+24;
  const double zetta               = 1.0e+21;
  const double exa                 = 1.0e+18;
  const double peta                = 1.0e+15;
  const double tera                = 1.0e+12;
  const double giga                = 1.0e+09;
  const double mega                = 1.0e+06;
  const double kilo                = 1.0e+03;
  const double hecto               = 1.0e+02;
  const double deka                = 1.0e+01;
  const double deci                = 1.0e-01;
  const double centi               = 1.0e-02;
  const double milli               = 1.0e-03;
  const double micro               = 1.0e-06;
  const double nano                = 1.0e-09;
  const double pico                = 1.0e-12;
  const double femto               = 1.0e-15;
  const double atto                = 1.0e-18;
  const double zepto               = 1.0e-21;
  const double yocto               = 1.0e-24;

  // Angular measure:

  const double radian              = 1.0;
  const double circle              = (2.0 * pi) * radian;
  const double degree              = (1.0 / 360.0) * circle;
  const double arcmin              = (1.0 /  60.0) * degree;
  const double arcsec              = (1.0 /  60.0) * arcmin;
  const double grad                = (1.0 / 400.0) * circle;

  // Solid angular measure:

  const double steradian           = 1.0;
  const double square_degree       =     degree * degree;
  const double square_arcmin       =     arcmin * arcmin;
  const double square_arcsec       =     arcsec * arcsec;

  //----------------------------------------------------------------------------
  // Physical conversion factors
  //----------------------------------------------------------------------------

  // Time interval [T]:

  const double second              = 1.0;
  const double minute              = 60.0 * second;
  const double hour                = 60.0 * minute;
  const double day                 = 24.0 * hour;
  const double Hertz               = 1.0;

  // Length [L]:

  const double metre               =  1.0;
  const double meter               =                metre;
  const double Fermi               =      1.0e-15 * metre;
  const double Angstrom            =      1.0e-10 * metre;
  const double inch                =      2.54e-2 * metre;
  const double thou                =       1.0e-3 * inch;
  const double hand                =          4.0 * inch;
  const double span                =          9.0 * inch;
  const double foot                =         12.0 * inch;
  const double yard                =          3.0 * foot;
  const double fathom              =          6.0 * foot;
  const double rod                 =         16.5 * foot;
  const double perch               =                rod;
  const double rope                =         20.0 * foot;
  const double chain               =         22.0 * yard;
  const double furlong             =        220.0 * yard;
  const double mile                =       5280.0 * foot;
  const double nautical_mile       =       6080.0 * foot;
  const double point               = (1.0 / 72.0) * inch;
  const double pica                =         12.0 * point;
  const double astronomical_unit   = 1.4959787066e+11 * metre;
  const double light_second        =             c * metre;
  const double light_year          =   9.46073047e+15 * metre;
  const double parsec              =       3.26156378 * light_year;

  // Area [L*L]:

  const double square_metre        = metre * metre;
  const double square_meter        =            square_metre;
  const double are                 =    100.0 * square_metre;
  const double barn                =  1.0e-28 * square_metre;
  const double square_inch         =  inch * inch;
  const double square_foot         =  foot * foot;
  const double square_yard         =  yard * yard;
  const double square_mile         =  mile * mile;
  const double square_perch        = perch * perch;
  const double rood                =     40.0 * square_perch;
  const double acre                =      4.0 * rood;
  const double square              =    100.0 * square_foot;

  // Volume [L*L*L]:

  const double cubic_metre         =     metre * square_metre;
  const double cubic_meter         =                cubic_metre;
  const double stere               =                cubic_metre;
  const double litre               =       1.0e-3 * cubic_metre;
  const double liter               =                litre;
  const double cubic_inch          =      inch * square_inch;
  const double cubic_foot          =      foot * square_foot;
  const double cubic_yard          =      yard * square_yard;
  const double cubic_mile          =      mile * square_mile;
  const double gallon              =     277.4193 * cubic_inch;
  const double quart               =  (1.0 / 4.0) * gallon;
  const double pint                =  (1.0 / 2.0) * quart;
  const double gill                =  (1.0 / 4.0) * pint;
  const double fluid_ounce         =  (1.0 / 5.0) * gill;
  const double drachm              =  (1.0 / 8.0) * fluid_ounce;
  const double scruple             =  (1.0 / 3.0) * drachm;
  const double minim               = (1.0 / 20.0) * scruple;
  const double USgallon            =        231.0 * cubic_inch;
  const double USquart             =  (1.0 / 4.0) * USgallon;
  const double USpint              =  (1.0 / 2.0) * USquart;
  const double USgill              =  (1.0 / 4.0) * USpint;
  const double USfluid_ounce       =  (1.0 / 4.0) * USgill;
  const double USdram              =  (1.0 / 8.0) * USfluid_ounce;
  const double USminim             = (1.0 / 60.0) * USdram;

  // Speed [L/T]:

  const double knot                = nautical_mile / hour;

  // Acceleration (speed / time) [L/(T*T)]:

  const double g                   = 9.80665 * metre / second / second;

  // Mass [M]:

  const double kilogram            = 1.0;
  const double gram                = 0.001 * kilogram;
  const double tonne               =       1000.0 * kilogram;
  const double carat               =  (1.0 / 5.0) * gram;
  const double pound               =   0.45359237 * kilogram;
  const double ounce               = (1.0 / 16.0) * pound;
  const double stone               =         14.0 * pound;
  const double quarter             =          2.0 * stone;
  const double hundredweight       =          4.0 * quarter;
  const double ton                 =         20.0 * hundredweight;
  const double cental              =        100.0 * pound;
  const double shortquarter        =         25.0 * pound;
  const double shortcwt            =          4.0 * shortquarter;
  const double shortton            =         20.0 * shortcwt;

  // Force (mass * acceleration) [M*L/(T*T)]:

  const double Newton              = kilogram * metre / second / second;
  const double dyne                = 1.0e-5 * Newton;

  // Pressure (force / area) [M/(L*T*T)]:

  const double Pascal              =  Newton / square_metre;
  const double atmosphere          =       1.01325e+5 * Pascal;
  const double bar                 =           1.0e+5 * Pascal;
  const double torr                =    (1.0 / 760.0) * atmosphere;
  const double mmHg                = (13.5951 * g) * Pascal;

  // Energy (force * length) [M*L*L/(T*T)]:

  const double Joule               =  Newton * metre;
  const double kWh                 =     3.6e+6 * Joule;
  const double erg                 =     1.0e-7 * Joule;
  const double calorie             =      4.184 * Joule;
  const double calorie_IT          =     4.1868 * Joule;
  const double Btu                 = 1.05435e+3 * Joule;
  const double eV                  =      qe * Joule;

  // Temperature difference (energy) [M*L*L/(T*T)]:

  const double Kelvin              = Boltzmann * Joule;
  const double Celsius             =                Kelvin;
  const double Centigrade          =                Celsius;
  const double Fahrenheit          =  (5.0 / 9.0) * Kelvin;
  const double Rankine             =                Fahrenheit;

  // Temperature at 0 on each temperature scale:

  const double Kelvin_0            =    0.0 * Kelvin;
  const double Celsius_0           = 273.15 * Kelvin;
  const double Centigrade_0        =          Celsius_0;
  const double Fahrenheit_0        = 459.67 * Fahrenheit;
  const double Rankine_0           =    0.0 * Fahrenheit;

  // Power (energy / time) [M*L*L/(T*T*T)]:

  const double Watt                = Joule / second;
  const double horsepower          = 745.7 * Watt;

  // Flux density (power / area / frequency) [M/(T*T)]:

  const double Jansky              = 1.0e-26 * Watt / square_metre / Hertz;
  const double fu                  = Jansky;

  // Electric charge [Q] (Coulomb):

  const double Coulomb             = 1.0;
  const double abCoulomb           =         10.0 * Coulomb;
  const double statCoulomb         = (0.1 / c) * Coulomb;

  // Electric current (electric charge / time) [Q/T]:

  const double Ampere              = Coulomb / second;
  const double abAmpere            =         10.0 * Ampere;
  const double statAmpere          = (0.1 / c) * Ampere;

  // Electric field strength (force / electric charge) [M*L/(T*T*Q)]:

  // Electric potential (energy / electric charge) [M*L*L/(T*T*Q)]:

  const double Volt                = Joule / Coulomb;
  const double abVolt              =          1.0e-8 * Volt;
  const double statVolt            = ( c * 1.0e-6) * Volt;

  // Electric resistance (electric potential / current) [M*L*L/(T*Q*Q)]]:

  const double Ohm                 = Volt / Ampere;
  const double abOhm               =          1.0e-9 * Ohm;
  const double statOhm             = (3.0e+3 * c) * Ohm;

  // Electric conductance (current / electric potential) [T*Q*Q/(M*L*L)]:

  const double Siemens             = Ampere / Volt;
  const double mho                 = Siemens;

  // Electric capacitance (charge / electric potential) [T*T*Q*Q/(M*L*L)]:

  const double Farad               = Coulomb / Volt;
  const double abFarad             =                1.0e+9 * Farad;
  const double statFarad           = 1.0 / (3.0e+3 * c) * Farad;

  // Electric inductance (electric potential * time / current) [M*L*L/(Q*Q)]:

  const double Henry               = Volt * second / Ampere;
  const double abHenry             =          1.0e-9 * Henry;
  const double statHenry           = (3.0e+3 * c) * Henry;

  // Magnetic induction (force / electric charge / velocity) [M/(T*Q)]:

  const double Tesla               = Newton / Coulomb / ( metre / second);
  const double Gauss               = 1.0e-4 * Tesla;

  // Magnetic flux (magnetic induction * area) [M*L*L/(T*Q)]:

  const double Weber               = Tesla / square_metre;
  const double Maxwell             = 1.0e-8 * Weber;
  const double line                =          Maxwell;

  // Magnetomotance = magnetomotive force (electric current) [Q/T]:

  const double Ampere_turn         = Ampere;
  const double abAmpere_turn       = 10.0 * Ampere_turn;
  const double Gilbert             = 10.0 / (4.0 * pi) * Ampere_turn;
  const double praGilbert          =        (4.0 * pi) * Ampere_turn;

  // Magnetic field intensity (electric current / length) [Q/(T*L)]:

  const double Oersted             = 1000.0 / (4.0 * pi) * Ampere / metre;
  const double praOersted          =          (4.0 * pi) * Ampere / metre;

  // Radioactivity (Bequerel):

  const double Bequerel            = 1.0;

  // Luminous intensity [Iv]:

  const double candela             = 1.0;

  // Amount of substance [N]:

  const double mole                = 1.0;
  const double molecule            = (1.0 / Avogadro) * mole;

}
