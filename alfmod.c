#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

/* Table of constant values */

static integer c__31 = 31;
extern int toutpt_(integer *);

int alfmod_(void)
{

/* * SET ALPHA MODE OUTPUT (US)                                00020470 */
    toutpt_(&c__31);
    tktrnx_1.kkmode = 0;
    if (tktrnx_1.kbeamy > tktrnx_1.khomey) {
	tktrnx_1.kbeamy = tktrnx_1.khomey;
    }
    return 0;
}				/* alfmod_ */
