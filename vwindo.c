#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_
extern int rescal_(void);

int vwindo_(real *xmin, real *xrange, real *ymin, real *yrange)
{

/* * DEFINE VIRTUAL WINDOW IN TERMINAL COMMON AREA          */
    tktrnx_1.tminvx = *xmin;
    tktrnx_1.tmaxvx = *xmin + *xrange;
    tktrnx_1.tminvy = *ymin;
    tktrnx_1.tmaxvy = *ymin + *yrange;
    rescal_();
    return 0;
}				/* vwindo_ */

int vwindo( real xmin, real xrange, real ymin , real yrange)
{
real x,y,xd,yd;

	x = xmin;
	y = ymin;
	xd = xrange;
	yd = yrange;
	return (vwindo_(&x,&xd,&y,&yd));
}
