#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
extern int toutst_(integer *, integer *);

int toutpt_(integer * kkout)
{
    static integer kout[1];
    kout[0] = *kkout;
    toutst_(&c__1, kout);
    return 0;
}				/* toutpt_ */
