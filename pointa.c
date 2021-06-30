/* pointa.f -- translated by f2c (version 20200916).
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

static integer c__0 = 0;

extern int v2st_ (integer *, real *, real *, integer *, integer *);
extern int tkpnt_ (integer *, integer *);
extern int lvlcht_ (void), pntmod_ (void);

/* ----------SUBROUTINE--POINTA------------------------TEKTRONIX, INC.----00005120 */
/*                                                                       00005130 */
/* Subroutine */ int
pointa_ (real * x, real * y)
{
  static integer ix, iy;

  lvlcht_ ();
/* * CONVERT TO SCREEN CO-ORDINATES                                      00005230 */
  v2st_ (&c__0, x, y, &ix, &iy);
/* * SKIP IF LINE COMPLETELY OUTSIDE WINDOW                              00005250 */
  if (tktrnx_1.kgnflg == 1)
    {
      goto L10;
    }
  if (tktrnx_1.kkmode != 2)
    {
      pntmod_ ();
    }
  tkpnt_ (&ix, &iy);
L10:
  return 0;
}				/* pointa_ */
