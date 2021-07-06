/* mover.f -- translated by f2c (version 20200916).
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

/* ----------SUBROUTINE--MOVER----EKTRONIX, INC.----00005600 */
extern int movea_(real *, real *);
extern int rel2ab_(real *, real *, real *, real *);
int mover_(real * x, real * y)
{
    static real rx, ry;

    rel2ab_(x, y, &rx, &ry);
    movea_(&rx, &ry);
    return 0;
}				/* mover_ */
