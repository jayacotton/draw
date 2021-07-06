
#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;
static integer c__10 = 10;

extern int iowait_(integer *);
extern int recovr_(void);
extern int toutst_(integer *, integer *);
int erase_(void)
{
    /* Initialized data */

    static integer icode[2] = { 27, 12 };

    toutst_(&c__2, icode);
    iowait_(&c__10);
    recovr_();
    return 0;
}				/* erase_ */
int erase()
{
	return(erase_());
}
