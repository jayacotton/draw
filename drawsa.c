#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_
extern float r_sign(real *, real *);
extern int drawa_(real *, real *);
extern int lvlcht_(void);

int drawsa_(real * x, real * y)
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

    lvlcht_();
    xold = tktrnx_1.timagx;
    yold = tktrnx_1.timagy;
    key = tktrnx_1.keycon;
    if (tktrnx_1.keycon < 1) {
	key = 5;
    }
    if (tktrnx_1.keycon > 4) {
	key = 4;
    }
/* * LINEAR LOG POLAR USER ERROR      */
    switch (key) {
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
/* * ERROR LINEAR LOG                 */
  L100:
    drawa_(x, y);
    xold = *x;
    yold = *y;
    return 0;
/* * POLAR                            */
  L200:
    dx = *x - xold;
    dy = *y - yold;
    r__1 = 5.f / tktrnx_1.trfacy;
    ystep = r_sign(&r__1, &dy);
    if ((r__1 = dy * .75f, dabs(r__1)) < dabs(ystep)) {
	goto L100;
    }
    frac = dx / dy;
    nseg = dy / ystep + .9999f;
    yout = yold;
  L300:
    if (nseg < 2) {
	goto L100;
    }
    yout += ystep;
    xout = xold + (yout - yold) * frac;
    drawa_(&xout, &yout);
    --nseg;
    goto L300;
/* * USER SEGMENTATION                */
  L400:
/*      CALL USDRAW(X,Y)              */
    goto L100;
	return 0;
}				/* drawsa_ */

int drawsa(real  x, real  y)
{
real ix,iy;
	ix = x;
	iy = y;
	return (drawsa_(&ix,&iy));
}
