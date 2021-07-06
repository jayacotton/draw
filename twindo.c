#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_
extern int rescal_(void);

int twindo_(integer * minx, integer * maxx, integer * miny, integer * maxy)
{

/* * DEFINE TERMINAL WINDOW IN TERMINAL COMMON AREA         */
    tktrnx_1.kminsx = *minx;
    tktrnx_1.kmaxsx = *maxx;
    tktrnx_1.kminsy = *miny;
    tktrnx_1.kmaxsy = *maxy;
    rescal_();
    return 0;
}				/* twindo_ */

int twindo(int minx, int maxx, int miny, int maxy)
{
int ix,iy,xm,ym;

	ix = minx;
	iy = miny;
	xm = maxx;
	ym = maxy;
	return(twindo_(&ix,&xm,&iy,&ym));
	
}
