#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

/* Table of constant values */

static integer c__0 = 0;

extern int v2st_(integer *, real *, real *, integer *, integer *);
extern int tkpnt_(integer *, integer *);
extern int lvlcht_(void), pntmod_(void);

int pointa_(real * x, real * y)
{
    static integer ix, iy;

    lvlcht_();
/* * CONVERT TO SCREEN CO-ORDINATES               */
    v2st_(&c__0, x, y, &ix, &iy);
/* * SKIP IF LINE COMPLETELY OUTSIDE WINDOW       */
    if (tktrnx_1.kgnflg == 1) {
	goto L10;
    }
    if (tktrnx_1.kkmode != 2) {
	pntmod_();
    }
    tkpnt_(&ix, &iy);
  L10:
    return 0;
}				/* pointa_ */

int pointa(real x, real y)
{
real ix,iy;

	ix = x;
	iy = y;
	return(pointa_(&ix, &iy));
}
