#include "f2c.h"

/* Common Block Declarations */


#define tktrnx_1 tktrnx_
extern int rescal_(void);
int dwindo_(real * xmin, real * xmax, real * ymin, real * ymax)
{

/* * DEFINE DATA WINDOW IN TERMINAL COMMON AREA         00004280 */
    tktrnx_1.tminvx = *xmin;
    tktrnx_1.tmaxvx = *xmax;
    tktrnx_1.tminvy = *ymin;
    tktrnx_1.tmaxvy = *ymax;
    rescal_();
    return 0;
}				/* dwindo_ */

int dwindo(real xmin, real xmax, real ymin, real ymax)
{
real xm, xx, ym, yx;

	xm = xmin;
	xx = xmax;
	ym = ymin;
	yx = ymax;
	return(dwindo_(&xm, &xx, &ym, &yx));
}
