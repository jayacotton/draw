/* tkdash.f -- translated by f2c (version 20200916).
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
extern int cwsend_ (void);
extern int xycnvt_ (integer *, integer *);
extern int toutpt_ (integer *);
extern float sqrt (doublereal);

/* ----------SUBROUTINE--TKDASH-------------TEKTRONIX, INC.----00013340 */
int
tkdash_ (integer * ix, integer * iy)
{
  /* Initialized data */

  static integer isimhd[4] = { 12, 31212, 32, 52 };
  static integer idtype = -1;
  static real u[9] =
    { 5.f, -5.f, 10.f, -10.f, 25.f, -25.f, 50.f, -50.f, 0.f };
  static integer lastx = -1;
  static integer lasty = -1;

  /* System generated locals */
  integer i__1, i__2;
  real r__1;

  /* Builtin functions */

  /* Local variables */
  static real f;
  static integer i__, k;
  static real x, y, d1, dx;
  static integer no;
  static real dy;
  static integer num;
  static real diag, dcur;
  static integer isub;
  static real dist, work[10], dtabl[10];
  static integer ichar;
  static real seglen;

  if (tktrnx_1.kdasht < 0)
    {
      goto L320;
    }
/* * SET TERMINAL FOR HARDWARE DASHED LINES                              00013510 */
/* * THIS SECTION IS FOR 4014 ENHANCED **********************************00013520 */
  if (tktrnx_1.kdasht > 4)
    {
      goto L101;
    }
  if (tktrnx_1.kterm >= 3)
    {
      goto L103;
    }
  if (tktrnx_1.kdasht == 0)
    {
      goto L330;
    }
/* * HARDWARE DASH SIMULATION FOR TYPE 1 + 2 TERMINALS                   00013560 */
  tktrnx_1.kdasht = isimhd[tktrnx_1.kdasht - 1];
L101:
  if (tktrnx_1.kline == 0)
    {
      goto L104;
    }
  tktrnx_1.kline = 0;
  cwsend_ ();
  goto L104;
/* * SET AND TRANSMIT HARDWARE DASH CODE                                 00013620 */
L103:
  if (tktrnx_1.kline == tktrnx_1.kdasht)
    {
      goto L330;
    }
  tktrnx_1.kline = tktrnx_1.kdasht;
  cwsend_ ();
  goto L330;
L104:
/* **********************************************************************00013680 */
  if (tktrnx_1.kdasht == 0)
    {
      goto L330;
    }
  if (tktrnx_1.kdasht == idtype)
    {
      goto L170;
    }
/* * BUILD NEW DASH TABLE                                                00013710 */
  ichar = tktrnx_1.kdasht;
  for (no = 1; no <= 10; ++no)
    {
    L120:
      if (ichar != 0)
	{
	  goto L130;
	}
      else
	{
	  goto L150;
	}
    L130:
      i__ = ichar - ichar / 10 * 10;
      ichar /= 10;
      if (i__ != 0)
	{
	  goto L140;
	}
      else
	{
	  goto L120;
	}
    L140:
      work[no - 1] = u[i__ - 1];
    }
  no = 11;
L150:
  --no;
/* * INVERT TABLE AND STORE IN DTABLE                                    00013810 */
  i__1 = no;
  for (i__ = 1; i__ <= i__1; ++i__)
    {
      isub = no + 1 - i__;
/* L160: */
      dtabl[i__ - 1] = work[isub - 1];
    }
/* * MODIFIY TABLE TO COMPENSATE FOR FLARE                               00013850 */
  d1 = dtabl[0];
  num = no - 1;
  i__1 = num;
  for (k = 1; k <= i__1; ++k)
    {
      dcur = dtabl[k - 1];
      if (dcur * dtabl[k] > 0.f || dcur * d1 < 0.f)
	{
	  goto L165;
	}
      dtabl[k - 1] += -1.f;
      dtabl[k] += -1.f;
    L165:
      ;
    }
  idtype = tktrnx_1.kdasht;
  i__ = 0;
  seglen = 0.f;
/* * BRANCH FOR ALTERNATING AND SOLID                                    00013970 */
L170:
  if ((i__1 = no - 1) < 0)
    {
      goto L320;
    }
  else if (i__1 == 0)
    {
      goto L330;
    }
  else
    {
      goto L180;
    }
L180:
  if (lastx - tktrnx_1.kbeamx != 0)
    {
      goto L200;
    }
  else
    {
      goto L190;
    }
L190:
  if (lasty - tktrnx_1.kbeamy != 0)
    {
      goto L200;
    }
  else
    {
      goto L210;
    }
/* * SET START OF SEQUENCE IF NOT INTERRUPTED BY A MOVE                  00014010 */
L200:
  seglen = 0.f;
  i__ = 0;
/* * COMPUTE NEXT SEGMENT LENGTH                                         00014040 */
L210:
  x = (real) tktrnx_1.kbeamx;
  y = (real) tktrnx_1.kbeamy;
  dx = (real) (*ix - tktrnx_1.kbeamx);
  dy = (real) (*iy - tktrnx_1.kbeamy);
  diag = sqrt (dx * dx + dy * dy);
  dist = diag;
  if (seglen - 1.5f <= 0.f)
    {
      goto L220;
    }
  else
    {
      goto L230;
    }
L220:
  i__ = i__ % no + 1;
  seglen = (r__1 = dtabl[i__ - 1], dabs (r__1));
L230:
  if (seglen - dist >= 0.f)
    {
      goto L270;
    }
  else
    {
      goto L240;
    }
L240:
  f = seglen / diag;
  x += dx * f;
  y += dy * f;
  if (dtabl[i__ - 1] <= 0.f)
    {
      goto L250;
    }
  else
    {
      goto L260;
    }
/* * OUTPUT A GS FOR A DARK VECTOR                                       00014190 */
L250:
  toutpt_ (&c__29);
  tktrnx_1.kmovef = 1;
L260:
  i__1 = (integer) x;
  i__2 = (integer) y;
  xycnvt_ (&i__1, &i__2);
/* * CALCULATE REMAINING DISTANCE TO POINT                               00014230 */
  dist -= seglen;
  seglen = 0.f;
  goto L220;
L270:
  if (dtabl[i__ - 1] <= 0.f)
    {
      goto L280;
    }
  else
    {
      goto L290;
    }
L280:
  toutpt_ (&c__29);
  tktrnx_1.kmovef = 1;
/* * THAT WAS A GS FOR AN INVISIBLE LINE                                 00014300 */
L290:
  xycnvt_ (ix, iy);
  lastx = *ix;
  lasty = *iy;
/* * CALCULATE SEGMENT FRAGMENT UNUSED                                   00014340 */
  seglen -= dist;
  goto L340;
L320:
  toutpt_ (&c__29);
  tktrnx_1.kmovef = 1;
L330:
  xycnvt_ (ix, iy);
  no = 1 - no;
  idtype = tktrnx_1.kdasht;
L340:
  return 0;
}				/* tkdash_ */
