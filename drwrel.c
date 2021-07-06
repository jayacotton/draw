#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

extern int drwabs_(integer *, integer *);
int drwrel_(integer * ix, integer * iy)
{
    static integer jx, jy;

    jx = tktrnx_1.kbeamx + *ix;
    jy = tktrnx_1.kbeamy + *iy;
    drwabs_(&jx, &jy);
    return 0;
}				/* drwrel_ */
int drwrel(int x, int y)
{
int ix,iy;
	ix = x;
	iy = y;
	return(drwrel_(&ix, &iy));
}
