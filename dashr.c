/* dashr.f -- translated by f2c (version 20200916).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

extern int dasha_(real *, real *, integer *);
extern int rel2ab_(real *, real *, real *, real *);

/* ----------SUBROUTINE--DASHR-------------------TEKTRONIX, INC.----00004450 */
int dashr_(real * x, real * y, integer * l)
{
    static real xl, yl;

    rel2ab_(x, y, &xl, &yl);
    dasha_(&xl, &yl, l);
    return 0;
}				/* dashr_ */
