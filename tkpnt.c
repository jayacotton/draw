/* tkpnt.f -- translated by f2c (version 20200916).
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

/* Table of constant values */

static integer c__29 = 29;
extern int xycnvt_ (integer *, integer *);
extern int toutpt_ (integer *);

/* ----------SUBROUTINE--TKPNT------------TEKTRONIX, INC.----00017640 */
int
tkpnt_ (integer * ix, integer * iy)
{

  if (tktrnx_1.kterm >= 3)
    {
      goto L10;
    }
/* * PUT OUT A GS FOR SIMULATED POINT PLOT MODE            00017750 */
  toutpt_ (&c__29);
  tktrnx_1.kmovef = 1;
/* * MOVE TO POINT                                         00017780 */
  xycnvt_ (ix, iy);
/* * DRAW  POINT                                             00017800 */
L10:
  xycnvt_ (ix, iy);
  return 0;
}				/* tkpnt_ */
