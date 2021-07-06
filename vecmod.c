#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

/* Table of constant values */

extern int toutpt_(integer *);
static integer c__31 = 31;
static integer c__29 = 29;

int vecmod_(void)
{
    static integer ii;
    if (tktrnx_1.kkmode == 1) {
	goto L10;
    }
/* * OUTPUT (US) TO ENTER A/N MODE AND RESET FOR VECTOR MODE             00021010 */
    toutpt_(&c__31);
    for (ii = 1; ii <= 5; ++ii) {
/* L112: */
	tktrnx_1.kpchar[ii - 1] = -1;
    }
    tktrnx_1.kkmode = 1;
/* * OUTPUT (GS) TO ENTER VECTOR MODE                                    00021060 */
  L10:
    toutpt_(&c__29);
    tktrnx_1.kmovef = 1;
    return 0;
}				/* vecmod_ */
