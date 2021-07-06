#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

integer kin_(real * ri)
{
    /* System generated locals */
    integer ret_val;

    ret_val = *ri * 546.f / (real) tktrnx_1.kfactr;
/* * USE APPROPRIATE FACTOR FOR LARGE SCREEN TERMINALS     */
    if (tktrnx_1.kterm > 1) {
	ret_val = *ri * 285.7f / (real) tktrnx_1.kfactr;
    }
    return ret_val;
}				/* kin_ */

int kin (real r)
{
real ri;
	ri = r;
	return(kin_(&ri));
}	
