/** @file output.h Documented includes for output module */

#ifndef __OUTPUT__
#define __OUTPUT__

#include "lensing.h"

/**
 * Structure containing various informations on the output format, 
 * all of them initialized by user in input module.
 *
 */

struct output {

   /** @name - root for all file names */

  //@{

  FileName root;

  //@}

  /** @name - number and value(s) of redshift at which P(k,z) and T_i(k,z) should be written */

  //@{

  double z_pk_num;
  double * z_pk;

  //@}

  /** @name - technical parameters */

  //@{
  
  short output_verbose; /**< flag regulating the amount of information sent to standard output (none if set to zero) */

  ErrorMsg error_message; /**< zone for writing error messages */

  //@}
};

/*************************************************************************************************************/

/*
 * Boilerplate for C++ 
 */
#ifdef __cplusplus
extern "C" {
#endif

  int output_init(
		  struct background * pba,
		  struct perturbs * ppt,
		  struct spectra * psp,
		  struct output * pop
		  );

  int output_cl(
		struct perturbs * ppt,
		struct spectra * psp,
		struct output * pop
		);

  int output_pk(
		struct background * pba,
		struct perturbs * ppt,
		struct spectra * psp,
		struct output * pop
		);

  int output_pk(
		struct background * pba,
		struct perturbs * ppt,
		struct spectra * psp,
		struct output * pop
		);

  int output_tk(
		struct background * pba,
		struct perturbs * ppt,
		struct spectra * psp,
		struct output * pop
		);


  int output_open_cl_file(
			  struct spectra * psp,
			  struct output * pop,
			  FILE * * clfile,
			  FileName filename,
			  char * first_line,
			  int lmax
			  );

  int output_one_line_of_cl(
			    FILE * clfile,
			    double l,
			    double * cl,
			    int ct_size
			    );

  int output_open_pk_file(
			  struct spectra * psp,
			  struct output * pop,
			  FILE * * pkfile,
			  FileName filename,
			  char * first_line,
			  double z
			  );

  int output_one_line_of_pk(
			    FILE * tkfile,
			    double one_k,
			    double one_pk
			    );

  int output_open_tk_file(
			  struct background * pba,
			  struct spectra * psp,
			  struct output * pop,
			  FILE * * tkfile,
			  FileName filename,
			  char * first_line,
			  double z
			  );

  int output_one_line_of_tk(
			    FILE * tkfile,
			    double one_k,
			    double * tk,
			    int tr_size
			    );

#ifdef __cplusplus
}
#endif

#endif
