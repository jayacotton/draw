/* kin.f -- translated by f2c (version 20200916).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

/* ----------FUNCTION----KIN----------TEKTRONIX, INC.----00014560 */
integer
kin_ (real * ri)
{
  /* System generated locals */
  integer ret_val;

  ret_val = *ri * 546.f / (real) tktrnx_1.kfactr;
/* * USE APPROPRIATE FACTOR FOR LARGE SCREEN TERMINALS         00014670 */
  if (tktrnx_1.kterm > 1)
    {
      ret_val = *ri * 285.7f / (real) tktrnx_1.kfactr;
    }
  return ret_val;
}				/* kin_ */
