/* svstat.f -- translated by f2c (version 20200916).
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

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

/* ----------SUBROUTINE--SVSTAT---------TEKTRONIX, INC.----00015870 */
int svstat_(real * rarray)
{
    /* Local variables */
    static integer i__;
#define ib ((integer *)&tktrnx_1 + 19)
#define rb ((real *)&tktrnx_1)

/* * COPY TERMINAL STATUS AREA INTO GIVEN SAVE ARRAY          015990 */
    /* Parameter adjustments */
    --rarray;

    /* Function Body */
    for (i__ = 1; i__ <= 19; ++i__) {
/* L100: */
	rarray[i__] = rb[i__ - 1];
    }
    for (i__ = 1; i__ <= 41; ++i__) {
/* L101: */
	rarray[i__ + 19] = (real) ib[i__ - 1];
    }
    return 0;
}				/* svstat_ */

#undef rb
#undef ib
