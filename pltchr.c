#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

int pltchr_(integer * ix, integer * iy, integer * ichar)
{
    static integer kx, ky;

/* * CALCULATE THE PLOT CHARACTERS TO ARRIVE AT IX,IY      */
/* * ORDER IS HIY, LSBYX, LOY, HIX, LOX                    */
    /* Parameter adjustments */
    --ichar;

    /* Function Body */
    kx = *ix * tktrnx_1.kfactr;
    ky = *iy * tktrnx_1.kfactr;
    ichar[1] = ky / 128 % 32 + 32;
    ichar[2] = (ky % 4 << 2) + kx % 4 + 96;
    ichar[3] = ky / 4 % 32 + 96;
    ichar[4] = kx / 128 % 32 + 32;
    ichar[5] = kx / 4 % 32 + 64;
    return 0;
}				/* pltchr_ */
