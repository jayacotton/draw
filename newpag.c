#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

/* Table of constant values */

static integer c__2 = 2;
static integer c__10 = 10;
extern int alfmod_(void);
extern int iowait_(integer *);
extern int movabs_(integer *, integer *);
extern int toutst_(integer *, integer *);

int newpag_(void)
{
    /* Initialized data */

    static integer icode[2] = { 27, 12 };

    if (tktrnx_1.kkmode != 0) {
	alfmod_();
    }
/* * OUTPUT (ESC) (FF) FOR NEW PAGE                          00020250 */
    toutst_(&c__2, icode);
    iowait_(&c__10);
    if (tktrnx_1.klmrgn == 0) {
	goto L10;
    }
    movabs_(&tktrnx_1.klmrgn, &tktrnx_1.khomey);
    alfmod_();
    goto L20;
  L10:
    tktrnx_1.kbeamx = 0;
    tktrnx_1.kbeamy = tktrnx_1.khomey;
  L20:
    return 0;
}				/* newpag_ */
