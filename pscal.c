/* pscal.f -- translated by f2c (version 20200916).
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

static real c_b4 = 1.f;

extern int wincot_ (real *, real *, integer *, integer *);

extern float r_sign (real *, real *);

/* ----------SUBROUTINE--PSCAL---------TEKTRONIX, INC.----00008730 */
int
pscal_ (void)
{
  /* System generated locals */
  integer i__1;
  real r__1, r__2;

  /* Builtin functions */

  /* Local variables */
  static real x, r1, r2;
  static integer ix1, iy1, ix2, iy2, ix3, iy3, ix4, iy4;
  static real aang;
  static logical aneg;
  static real quad, rmax, pidv2;
  static integer nquad;
  static real thmin, thmax;
  static integer ixmin, iymin, ixmax, iymax;
  static real factor, xrange, yrange;
  static real tsranx, tsrany;

  aneg = tktrnx_1.trpar1 > tktrnx_1.trpar2;
/* * FLAG THE OLD VIRTUAL COORDINATES AS INCORRECT */
  tktrnx_1.kgrafl = 0;
  pidv2 = 90.f;
/* * SET UP UNTRANSLATED TRIAL POLAR WINDOW                    00008860 */
  tktrnx_1.trpar3 = 0.f;
  tktrnx_1.trpar4 = 0.f;
  tktrnx_1.trfacy = 1.f;
  tktrnx_1.trpar6 = 0.f;
  r1 = tktrnx_1.tminvx;
  r2 = tktrnx_1.tmaxvx;
/* Computing MAX */
  r__1 = dabs (r1), r__2 = dabs (r2);
  rmax = dmax (r__1, r__2);
  tktrnx_1.trfacx = 1e3f / rmax;
  thmin = dmin (tktrnx_1.trpar1, tktrnx_1.trpar2);
  thmax = dmax (tktrnx_1.trpar2, tktrnx_1.trpar1);
/* * FIND EXTREMES OF THE TRIAL POLAR WINDOW                00008970 */
  wincot_ (&r1, &thmin, &ix1, &iy1);
  wincot_ (&r1, &thmax, &ix2, &iy2);
  wincot_ (&r2, &thmin, &ix3, &iy3);
  wincot_ (&r2, &thmax, &ix4, &iy4);
/* Computing MIN */
  i__1 = min (ix1, ix2), i__1 = min (i__1, ix3);
  ixmin = min (i__1, ix4);
/* Computing MAX */
  i__1 = max (ix1, ix2), i__1 = max (i__1, ix3);
  ixmax = max (i__1, ix4);
/* Computing MIN */
  i__1 = min (iy1, iy2), i__1 = min (i__1, iy3);
  iymin = min (i__1, iy4);
/* Computing MAX */
  i__1 = max (iy1, iy2), i__1 = max (i__1, iy3);
  iymax = max (i__1, iy4);
  x = thmin / pidv2;
  if (thmin > 0.f)
    {
      x += .999f;
    }
  quad = (real) ((integer) x) * pidv2;
  nquad = 0;
/* * CHECK EXTREMES OF TRIAL WINDOW AT 90 DEGREE INTERVALS      00009100 */
L200:
  if (quad >= thmax)
    {
      goto L300;
    }
  ++nquad;
  wincot_ (&r1, &quad, &ix1, &iy1);
  wincot_ (&r2, &quad, &ix2, &iy2);
/* Computing MIN */
  i__1 = min (ix1, ix2);
  ixmin = min (i__1, ixmin);
/* Computing MAX */
  i__1 = max (ix1, ix2);
  ixmax = max (i__1, ixmax);
/* Computing MIN */
  i__1 = min (iy1, iy2);
  iymin = min (i__1, iymin);
/* Computing MAX */
  i__1 = max (iy1, iy2);
  iymax = max (i__1, iymax);
  quad += pidv2;
  if (nquad < 4)
    {
      goto L200;
    }
/* * COMPUTE SCREEN AND VIRTUAL RANGES                         00009210 */
L300:
  tsranx = (real) (tktrnx_1.kmaxsx - tktrnx_1.kminsx);
  tsrany = (real) (tktrnx_1.kmaxsy - tktrnx_1.kminsy);
  xrange = (real) (ixmax - ixmin);
  yrange = (real) (iymax - iymin);
/* * COMPUTE RELATIVE RADIUS SCALE FACTOR                       00009260 */
/* Computing MIN */
  r__1 = dabs (tsranx) / xrange, r__2 = dabs (tsrany) / yrange;
  factor = dmin (r__1, r__2);
/* * COMPUTE SCREEN OFFSETS                                    00009280 */
  tktrnx_1.trpar3 = (real) tktrnx_1.kminsx - factor * (real) ixmin;
  tktrnx_1.trpar4 = (real) tktrnx_1.kminsy - factor * (real) iymin;
/* * COMPUTE FINAL RADIUS SCALE FACTOR                          00009310 */
  tktrnx_1.trfacx *= factor;
/* * COMPUTE ANGLE SCALE FACTOR                                 00009330 */
  tktrnx_1.trfacy = (tktrnx_1.trpar2 - tktrnx_1.trpar1) / (tktrnx_1.tmaxvy
							   - tktrnx_1.tminvy);
/* * APPLY CORRECT SIGN TO ANGLE SCALE FACTOR                  00009350 */
  r__1 = tsranx * tsrany;
  tktrnx_1.trfacy = r_sign (&c_b4, &r__1) * tktrnx_1.trfacy;
  aang = 0.f;
/* * APPLY CORRECTION FOR @REVERSED@ WINDOWS                     00009380 */
  if (aneg && tsrany < 0.f || tsranx < 0.f && !aneg)
    {
      aang = 180.f;
    }
/* * COMPUTE ANGLE OFFSET                                       00009400 */
  tktrnx_1.trpar6 = tktrnx_1.tminvy - (tktrnx_1.trpar1 + aang) /
    tktrnx_1.trfacy;
  return 0;
}				/* pscal_ */
