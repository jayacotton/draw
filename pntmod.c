/* pntmod.f -- translated by f2c (version 20200916).
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

extern int toutpt_ (integer *);
/* Table of constant values */

static integer c__31 = 31;
static integer c__28 = 28;

/* ----------SUBROUTINE--PNTMOD---------TEKTRONIX, INC.----00021270 */
int
pntmod_ (void)
{
  static integer ii;

/* * CANCEL PREVIOUS MODES - OUTPUT (US)                    00021370 */
  toutpt_ (&c__31);
  for (ii = 1; ii <= 5; ++ii)
    {
/* L111: */
      tktrnx_1.kpchar[ii - 1] = -1;
    }
  tktrnx_1.kkmode = 2;
/* * FOR HARDWARE POINT PLOT OUTPUT AN (FS)                 00021420 */
  if (tktrnx_1.kterm >= 3)
    {
      toutpt_ (&c__28);
    }
  return 0;
}				/* pntmod_ */
