#include "f2c.h"
#define tktrnx_1 tktrnx_

extern int v2st_(integer *, real *, real *, integer *, integer *);
extern int vecmod_(void);
extern int cwsend_(void);
extern int lvlcht_(void);
extern int xycnvt_(integer *, integer *);
static integer c__1 = 1;

int drawa_(real *x, real *y)
{
    static integer ix, iy;

/* * SET TERMINAL TO DRAW SOLID LINES IF NEEDED    */
/* * THIS SECTION IS NEEDED FOR 4014 ENHANCED ******/
    if (tktrnx_1.kline == 0) {
	goto L5;
    }
    tktrnx_1.kline = 0;
    cwsend_();
  L5:
/* *************************************************/
    lvlcht_();
/* * CONVERT TO SCREEN CO-ORDINATES                */
    v2st_(&c__1, x, y, &ix, &iy);
/* * SKIP IF LINE COMPLETELY OUTSIDE WINDOW        */
    if (tktrnx_1.kgnflg == 1) {
	goto L10;
    }
    if (tktrnx_1.kkmode != 1) {
	vecmod_();
    }
    if (tktrnx_1.kmovef == 1) {
	xycnvt_(&tktrnx_1.kbeamx, &tktrnx_1.kbeamy);
    }
    xycnvt_(&ix, &iy);
  L10:
    return 0;
}				/* drawa_ */

int drawa(real x, real y)
{
real ix,iy;
	ix = x;
	iy = y;
	return(drawa_(&ix,&iy));
}
