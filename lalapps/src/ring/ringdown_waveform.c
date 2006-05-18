#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include <lal/LALStdlib.h>
#include <lal/LALConstants.h>
#include <lal/Units.h>
#include <lal/TimeSeries.h>
#include <lal/BlackHoleMode.h>
#define LAL_USE_COMPLEX_SHORT_MACROS
#include <lal/LALComplex.h>

#define a_invalid -100.0 /* invalid */
#define i_invalid -361.0 /* invalid */
#define l_invalid (INT_MIN + 1) /* invalid */
#define m_invalid (INT_MAX) /* invalid */
REAL8 a = a_invalid;
REAL8 M = 0.0;
REAL8 r = 0.0;
REAL8 e = 0.0;
REAL8 i = i_invalid;
REAL8 q = 0.0;
int l = l_invalid;
int m = m_invalid;

int usage( const char *program );
int parseargs( int argc, char **argv );

int main( int argc, char *argv[] )
{
  const UINT4 length = 16384;
  REAL8 deltaT = 1.0 / length;
  LIGOTimeGPS epoch = { 0, 0 };
  REAL4TimeSeries *plus;
  REAL4TimeSeries *cross;
  int npt;
  int n;

  lalDebugLevel = 7;
  XLALSetErrorHandler( XLALBacktraceErrorHandler );

  parseargs( argc, argv );

  plus = XLALCreateREAL4TimeSeries( "h_plus", &epoch, 0.0, deltaT, &lalStrainUnit, length );
  cross = XLALCreateREAL4TimeSeries( "h_cross", &epoch, 0.0, deltaT, &lalStrainUnit, length );

  fprintf( stdout, "# time (s)\th_plus      \th_cross\n" );
  npt = XLALBlackHoleRingdownWaveform( plus, cross, M, a, e, r, i, q, l, m );
  for ( n = 0; n < npt; ++n )
    fprintf( stdout, "%e\t%e\t%e\n", n * deltaT, plus->data->data[n], cross->data->data[n] );

  XLALDestroyREAL4TimeSeries( cross );
  XLALDestroyREAL4TimeSeries( plus );
  LALCheckMemoryLeaks();

  return 0;
}

int parseargs( int argc, char **argv )
{
  struct option long_options[] = 
  {
    { "help", no_argument, 0, 'h' },
    { "leaver", no_argument, 0, 'L' },
    { "mass", required_argument, 0, 'M' },
    { "spin", required_argument, 0, 'a' },
    { "inclination", required_argument, 0, 'i' },
    { "azimuth", required_argument, 0, 'q' },
    { "energy", required_argument, 0, 'e' },
    { "distance", required_argument, 0, 'r' },
    { "l", required_argument, 0, 'l' },
    { "m", required_argument, 0, 'm' },
    { 0, 0, 0, 0 }
  };
  char args[] = "hM:a:i:q:e:r:l:m:";
  while ( 1 )
  {
    int option_index = 0;
    int c;

    c = getopt_long_only( argc, argv, args, long_options, &option_index );
    if ( c == -1 ) /* end of options */
      break;

    switch ( c )
    {
      case 0: /* if option set a flag, nothing else to do */
        if ( long_options[option_index].flag )
          break;
        else
        {
          fprintf( stderr, "error parsing option %s with argument %s\n",
              long_options[option_index].name, optarg );
          exit( 1 );
        }
      case 'h': /* help */
        usage( argv[0] );
        exit( 0 );
      case 'M': /* mass */
        M = atof( optarg );
        break;
      case 'a': /* spin */
        a = atof( optarg );
        break;
      case 'i': /* inclination */
        i = LAL_PI_180 * atof( optarg );
        break;
      case 'q': /* azimuth */
        q = LAL_PI_180 * atof( optarg );
        break;
      case 'e': /* energy */
        e = atof( optarg );
        break;
      case 'r': /* distance */
        r = atof( optarg );
        break;
      case 'l':
        l = atoi( optarg );
        break;
      case 'm':
        m = atoi( optarg );
        break;
      case '?':
      default:
        fprintf( stderr, "unknown error while parsing options\n" );
        exit( 1 );
    }
  }

  if ( optind < argc )
  {
    fprintf( stderr, "extraneous command line arguments:\n" );
    while ( optind < argc )
      fprintf( stderr, "%s\n", argv[optind++] );
    exit( 1 );
  }

  if ( a == a_invalid || l == l_invalid || m == m_invalid
      || M <= 0.0 || e <= 0.0 || e >= 1.0 || r <= 0.0 || i == i_invalid )
  {
    fprintf( stderr, "must specify mass, spin, distance, frac. energy loss, l, m\n" );
    usage( argv[0] );
    exit( 1 );
  }

  return 0;
}

int usage( const char *program )
{
  fprintf( stderr, "usage: %s [options]\n", program );
  fprintf( stderr, "options:\n" );
  fprintf( stderr, "\t-h, --help     \tprint this message and exit\n" );
  fprintf( stderr, "\t-M Msolar      \t(required) set black hole mass (solar masses)\n" );
  fprintf( stderr, "\t-a a           \t(required) set value of a, -1<a<1\n" );
  fprintf( stderr, "\t-r distanceMpc \t(required) set distance (Mpc)\n" );
  fprintf( stderr, "\t-e fracEnergy  \t(required) set energy radiated (fraction of M)\n" );
  fprintf( stderr, "\t-i inclination \t(required) set inclination angle (degrees)\n" );
  fprintf( stderr, "\t-q azimuth     \t(default=0) set azimuth angle (degrees)\n" );
  fprintf( stderr, "\t-l l           \t(required) set value of l, l>=0\n" );
  fprintf( stderr, "\t-m m           \t(required) set value of m, abs(m)<=l\n" );
  return 0;
}
