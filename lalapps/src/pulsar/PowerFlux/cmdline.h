/* cmdline.h */

/* File autogenerated by gengetopt version 2.11  */

#ifndef CMDLINE_H
#define CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
#define CMDLINE_PARSER_PACKAGE PACKAGE
#endif

#ifndef CMDLINE_PARSER_VERSION
#define CMDLINE_PARSER_VERSION VERSION
#endif

struct gengetopt_args_info
{
  char * config_arg;	/* configuration file (in gengetopt format) to pass parameters.  */
  char * sky_grid_arg;	/* sky grid type (arcsin, plain_rectangular, sin_theta) (default='sin_theta').  */
  int fine_factor_arg;	/* make fine grid this times finer (default='7').  */
  char * input_arg;	/* path to input files (power or SFT).  */
  char * input_format_arg;	/* format of input files (GEO, SFT, Power) (default='GEO').  */
  char * output_arg;	/* output directory.  */
  char * detresponse_path_arg;	/* path to detresponse program from lalapps.  */
  char * pnmtopng_arg;	/* ppmtopng command (with path if necessary) for outputting images (default='pnmtopng').  */
  char * earth_ephemeris_arg;	/* Earth ephemeris file.  */
  char * sun_ephemeris_arg;	/* Sun ephemeris file.  */
  int first_bin_arg;	/* first frequency bin in the band to be analyzed.  */
  int nbins_arg;	/* number of frequency bins to analyze (default='501').  */
  int side_cut_arg;	/* number of bins to cut from each side due to corruption from doppler shifts.  */
  char * detector_arg;	/* detector location (i.e. LHO or LLO), passed to detresponse.  */
  double spindown_arg;	/* compensate for pulsar spindown during run (fdot) (default='0').  */
  double orientation_arg;	/* orientation of the source (default='0').  */
  int no_demodulation_arg;	/* do not perform demodulation stage, analyze background only (default='0').  */
  int no_decomposition_arg;	/* do not perform noise decomposition stage, output simple statistics only (default='0').  */
  int no_am_response_arg;	/* force AM_response() function to return 1.0 irrespective of the arguments (default='0').  */
  int three_bins_arg;	/* average 3 neighbouring bins to broaden Doppler curves (default='0').  */
  int do_cutoff_arg;	/* neglect contribution from SFT with high effective noise level (default='1').  */
  int filter_lines_arg;	/* perform detection of lines in background noise and veto corresponding frequency bins (default='1').  */
  int dec_bands_arg;	/* split sky in this many bands in declination for logging maximum upper limits (default='9').  */
  double resolution_ratio_arg;	/* ratio that determines the coarsness of the grid (default='1.0').  */
  double small_weight_ratio_arg;	/* ratio that determines which weight is too small to include in max statistics (default='0.2').  */
  double fake_ra_arg;	/* RA of fake signal to inject (default='3.14').  */
  double fake_dec_arg;	/* DEC of fake signal to inject (default='0.0').  */
  double fake_orientation_arg;	/* orientation of fake signal to inject (default='0.0').  */
  double fake_spindown_arg;	/* spindown of fake signal to inject (default='0.0').  */
  double fake_strain_arg;	/* amplitude of fake signal to inject (default='1e-23').  */
  double fake_freq_arg;	/* frequency of fake signal to inject.  */
  int npolarizations_arg;	/* number of linear polarizations to profile, distributed uniformly between plus and cross (default='3').  */
  char * write_dat_arg;	/* regular expression describing which *.dat files to write (default='.*').  */
  char * write_png_arg;	/* regular expression describing which *.png files to write (default='.*').  */

  int help_given ;	/* Whether help was given.  */
  int version_given ;	/* Whether version was given.  */
  int config_given ;	/* Whether config was given.  */
  int sky_grid_given ;	/* Whether sky-grid was given.  */
  int fine_factor_given ;	/* Whether fine-factor was given.  */
  int input_given ;	/* Whether input was given.  */
  int input_format_given ;	/* Whether input-format was given.  */
  int output_given ;	/* Whether output was given.  */
  int detresponse_path_given ;	/* Whether detresponse-path was given.  */
  int pnmtopng_given ;	/* Whether pnmtopng was given.  */
  int earth_ephemeris_given ;	/* Whether earth-ephemeris was given.  */
  int sun_ephemeris_given ;	/* Whether sun-ephemeris was given.  */
  int first_bin_given ;	/* Whether first-bin was given.  */
  int nbins_given ;	/* Whether nbins was given.  */
  int side_cut_given ;	/* Whether side-cut was given.  */
  int detector_given ;	/* Whether detector was given.  */
  int spindown_given ;	/* Whether spindown was given.  */
  int orientation_given ;	/* Whether orientation was given.  */
  int no_demodulation_given ;	/* Whether no-demodulation was given.  */
  int no_decomposition_given ;	/* Whether no-decomposition was given.  */
  int no_am_response_given ;	/* Whether no-am-response was given.  */
  int three_bins_given ;	/* Whether three-bins was given.  */
  int do_cutoff_given ;	/* Whether do-cutoff was given.  */
  int filter_lines_given ;	/* Whether filter-lines was given.  */
  int dec_bands_given ;	/* Whether dec-bands was given.  */
  int resolution_ratio_given ;	/* Whether resolution-ratio was given.  */
  int small_weight_ratio_given ;	/* Whether small-weight-ratio was given.  */
  int fake_ra_given ;	/* Whether fake-ra was given.  */
  int fake_dec_given ;	/* Whether fake-dec was given.  */
  int fake_orientation_given ;	/* Whether fake-orientation was given.  */
  int fake_spindown_given ;	/* Whether fake-spindown was given.  */
  int fake_strain_given ;	/* Whether fake-strain was given.  */
  int fake_freq_given ;	/* Whether fake-freq was given.  */
  int npolarizations_given ;	/* Whether npolarizations was given.  */
  int write_dat_given ;	/* Whether write-dat was given.  */
  int write_png_given ;	/* Whether write-png was given.  */

} ;

int cmdline_parser (int argc, char * const *argv, struct gengetopt_args_info *args_info);

void cmdline_parser_print_help(void);
void cmdline_parser_print_version(void);

int cmdline_parser_configfile (char * const filename, struct gengetopt_args_info *args_info, int override);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
