/* revcot.f -- translated by f2c (version 20200916).
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

static real c_b12 = 360.f;
extern float pow_dd (doublereal *, doublereal *);
extern float atan2 (doublereal, doublereal);
extern float sqrt (doublereal);
extern float r_mod (real *, real *);
extern int pclipt_ (real *, real *);

/* ----------SUBROUTINE--REVCOT------------TEKTRONIX, INC.----00010150 */
int
revcot_ (integer * ix, integer * iy, real * x, real * y)
{
  /* System generated locals */
  real r__1;
  doublereal d__1, d__2;

  /* Builtin functions */

  /* Local variables */
  static real e, dx, dy;
  static logical dec;
  static integer key;
  static real tr1a, tr2a;
  static integer keyl;

  e = 2.7182818284f;
  dx = (real) (*ix - tktrnx_1.kminsx) / tktrnx_1.trfacx;
  dy = (real) (*iy - tktrnx_1.kminsy) / tktrnx_1.trfacy;
  key = tktrnx_1.keycon;
  if (tktrnx_1.keycon < 1)
    {
      key = 5;
    }
  if (tktrnx_1.keycon > 4)
    {
      key = 4;
    }
/* *       LINEAR LOG POLAR USER ERROR           00010320 */
  switch (key)
    {
    case 1:
      goto L300;
    case 2:
      goto L400;
    case 3:
      goto L500;
    case 4:
      goto L600;
    case 5:
      goto L100;
    }
/* * ERROR                                        00010340 */
L100:
  *x = (real) (*ix);
  *y = (real) (*iy);
  goto L700;
/* * LINEAR                                         00010380 */
L300:
  *x = dx + tktrnx_1.tminvx;
  *y = dy + tktrnx_1.tminvy;
  goto L700;
/* * LOG SCALES                                       00010420 */
L400:
  keyl = tktrnx_1.trpar1;
  *x = dx + tktrnx_1.tminvx;
  *y = dy + tktrnx_1.tminvy;
  if (keyl != 2)
    {
      d__1 = (doublereal) e;
      d__2 = (doublereal) (dx + tktrnx_1.trpar2);
      *x = pow_dd (&d__1, &d__2);
    }
  if (keyl != 1)
    {
      d__1 = (doublereal) e;
      d__2 = (doublereal) (dy + tktrnx_1.trpar3);
      *y = pow_dd (&d__1, &d__2);
    }
  goto L700;
/* * POLAR                                         00010490 */

L500:
  dx = (real) (*ix) - tktrnx_1.trpar3;
  dy = (real) (*iy) - tktrnx_1.trpar4;
  *y = atan2 (dy, dx) * 57.2957795131f;
  *x = sqrt (dy * dy + dx * dx) / tktrnx_1.trfacx + tktrnx_1.trpar5;
/* * ADJUST ANGLE MOD 2 PI TO VALUE WITHIN WINDOW      00010540 */
  dec = FALSE_;
L510:
  if (*y > tktrnx_1.trpar1)
    {
      goto L530;
    }
/* * INCREMENT ANGLE                                  00010570 */
  *y += 360.f;
  goto L510;
L530:
  if (*y <= tktrnx_1.trpar2)
    {
      goto L550;
    }
/* * DECREMENT ANGLE                                     00010610 */
  *y += -360.f;
  dec = TRUE_;
  goto L530;
L550:
  if (dec && *y < tktrnx_1.trpar1)
    {
      *y += 360.f;
    }
  if (tktrnx_1.tminvx >= 0.f)
    {
      goto L560;
    }
  r__1 = tktrnx_1.trpar1 + 180.f;
  tr1a = r_mod (&r__1, &c_b12);
  r__1 = tktrnx_1.trpar2 + 180.f;
  tr2a = r_mod (&r__1, &c_b12);
  if (*y > dmax (tr1a, tr2a) || *y < dmin (tr1a, tr2a))
    {
      goto L560;
    }
  r__1 = *y + 180.f;
  *y = r_mod (&r__1, &c_b12);
  *x = -(*x);
L560:
  *y = *y / tktrnx_1.trfacy + tktrnx_1.trpar6;
  goto L700;
/* * USER CONVERSION                                        00010740 */
L600:
/*      CALL UREVCT(IX,IY,X,Y)                            00010760 */
/* * EXIT POINT                                             00010770 */
L700:
  pclipt_ (x, y);
  return 0;
}				/* revcot_ */
