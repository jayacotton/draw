#include "f2c.h"

/* Common Block Declarations */


#define tktrnx_1 tktrnx_
extern int movabs_(integer *, integer *);

int movrel_(integer * ix, integer * iy)
{
    static integer jx, jy;

    jx = tktrnx_1.kbeamx + *ix;
    jy = tktrnx_1.kbeamy + *iy;
    movabs_(&jx, &jy);
    return 0;
}				/* movrel_ */

int movrel(int ix, int iy)
{
int x,y;
	x = ix;
	y = iy;
	return(movrel_(&x,&y));
}
