/* kas2am.f -- translated by f2c (version 20200916).
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

/* ----------SUBROUTINE KAS2AM---------------- */

int kas2am_(integer * nc, integer * iade, logical1 * ia2)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;

    /* Parameter adjustments */
    --ia2;
    --iade;

    /* Function Body */
    i__1 = *nc;
    for (i__ = 1; i__ <= i__1; ++i__) {
/*       IA2(I)=IADE(I) */
/* L1: */
    }
    return 0;
}				/* kas2am_ */
