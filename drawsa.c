/* drawsa.f -- translated by f2c (version 20200916).
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
extern float r_sign (real *, real *);
extern int drawa_ (real *, real *);
extern int lvlcht_ (void);

/* ----------SUBROUTINE--DRAWSA------------TEKTRONIX, INC.----00002290 */
int
drawsa_ (real * x, real * y)
{
  /* System generated locals */
  real r__1;

  /* Builtin functions */

  /* Local variables */
  static real dx, dy;
  static integer key;
  static real frac;
  static integer nseg;
  static real xold, yold, xout, yout;
  static real ystep;

  lvlcht_ ();
  xold = tktrnx_1.timagx;
  yold = tktrnx_1.timagy;
  key = tktrnx_1.keycon;
  if (tktrnx_1.keycon < 1)
    {
      key = 5;
    }
  if (tktrnx_1.keycon > 4)
    {
      key = 4;
    }
/* * LINEAR LOG POLAR USER ERROR                         00002450 */
  switch (key)
    {
    case 1:
      goto L100;
    case 2:
      goto L100;
    case 3:
      goto L200;
    case 4:
      goto L400;
    case 5:
      goto L100;
    }
/* * ERROR LINEAR LOG                                     00002470 */
L100:
  drawa_ (x, y);
  xold = *x;
  yold = *y;
  return 0;
/* * POLAR                                                 00002520 */
L200:
  dx = *x - xold;
  dy = *y - yold;
  r__1 = 5.f / tktrnx_1.trfacy;
  ystep = r_sign (&r__1, &dy);
  if ((r__1 = dy * .75f, dabs (r__1)) < dabs (ystep))
    {
      goto L100;
    }
  frac = dx / dy;
  nseg = dy / ystep + .9999f;
  yout = yold;
L300:
  if (nseg < 2)
    {
      goto L100;
    }
  yout += ystep;
  xout = xold + (yout - yold) * frac;
  drawa_ (&xout, &yout);
  --nseg;
  goto L300;
/* * USER SEGMENTATION                                   00002660 */
L400:
/*      CALL USDRAW(X,Y)                                  00002680 */
  goto L100;
}				/* drawsa_ */
