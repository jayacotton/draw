#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_
extern int clipt_(real *, real *);
extern int vecmod_(void);
extern int wincot_(real *, real *, integer *, integer *);
extern int pclipt_(real *, real *);
extern int xycnvt_(integer *, integer *);

int v2st_(integer * i__, real * x, real * y, integer * ix, integer * iy)
{
    /* System generated locals */
    static real equiv_3[4], equiv_7[4];

    /* Local variables */
#define xe (equiv_3 + 2)
#define ye (equiv_3 + 3)
#define xs (equiv_3)
#define ys (equiv_3 + 1)
#define cxe (equiv_7 + 2)
#define cye (equiv_7 + 3)
#define cxs (equiv_7)
#define cys (equiv_7 + 1)
    static integer mode;
#define bufin (equiv_3)
#define bfout (equiv_7)

    *xe = *x;
    *ye = *y;
/* * POINT OR MOVE                          */
    if (*i__ == 0) {
	goto L10;
    }
/* * BRIGHT VECTOR                          */
    *xs = tktrnx_1.timagx;
    *ys = tktrnx_1.timagy;
/* * CLIP VECTOR                            */
    clipt_(bufin, bfout);
/* * ON SCREEN{                             */
    if (tktrnx_1.kgnflg == 1) {
	goto L110;
    }
/* * ARE WE AT START POINT?                 */
    if (*cxs == tktrnx_1.trealx && *cys == tktrnx_1.trealy) {
	goto L120;
    }
/* * MOVE BEAM TO START POINT               */
    mode = tktrnx_1.kkmode;
    vecmod_();
    wincot_(cxs, cys, ix, iy);
    xycnvt_(ix, iy);
    tktrnx_1.kkmode = mode;
    goto L120;
/* * POINT OR MOVE                          */
  L10:
    pclipt_(xe, ye);
/* * OFF SCREEN{                            */
    if (tktrnx_1.kgnflg == 1) {
	goto L110;
    }
    *cxe = *xe;
    *cye = *ye;
/* * CONVERT TO SCREEN COORDINATES          */
  L120:
    wincot_(cxe, cye, ix, iy);
/* * SAVE POSITION  ABS AND IMAGINARY       */
    tktrnx_1.trealx = *cxe;
    tktrnx_1.trealy = *cye;
  L110:
    tktrnx_1.timagx = *x;
    tktrnx_1.timagy = *y;
    return 0;
}				/* v2st_ */

#undef bfout
#undef bufin
#undef cys
#undef cxs
#undef cye
#undef cxe
#undef ys
#undef xs
#undef ye
#undef xe
