#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_
extern int dshabs_(integer *, integer *, integer *);

int dshrel_(integer * ix, integer * iy, integer * l)
{
    static integer jx, jy;

    jx = *ix + tktrnx_1.kbeamx;
    jy = *iy + tktrnx_1.kbeamy;
    dshabs_(&jx, &jy, l);
    return 0;
}				/* dshrel_ */

int dshrel(int ix, int iy, int l)
{
int x,y,z;
	x = ix;
	y = iy;
	z = l;
	return(dshrel_(&x, &y, &l));
}
