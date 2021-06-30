/* rrotat.f -- translated by f2c (version 20200916).
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
extern float sin (doublereal);
extern float cos (doublereal);

/* ----------SUBROUTINE--RROTAT--------EKTRONIX, INC.----00003060 */
int
rrotat_ (real * deg)
{
  /* Builtin functions */

  tktrnx_1.trsinf = sin (*deg / 57.29578f);
  tktrnx_1.trcosf = cos (*deg / 57.29578f);
  return 0;
}				/* rrotat_ */
