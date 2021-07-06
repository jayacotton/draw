#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

logical genflg_(integer * item)
{
    /* System generated locals */
    logical ret_val;

    ret_val = tktrnx_1.kgnflg == *item;
    return ret_val;
}				/* genflg_ */
