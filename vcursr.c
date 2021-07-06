/* vcursr.f -- translated by f2c (version 20200916).
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
extern int revcot_(integer *, integer *, real *, real *);
extern int scursr_(integer *, integer *, integer *);

/* ----------SUBROUTINE--VCURSR-----------TEKTRONIX, INC.----00006040 */
int vcursr_(integer * ichar, real * x, real * y)
{
    static integer ixa, iya;

    scursr_(ichar, &ixa, &iya);
    revcot_(&ixa, &iya, x, y);
    return 0;
}				/* vcursr_ */
