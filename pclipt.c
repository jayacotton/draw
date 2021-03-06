/* pclipt.f -- translated by f2c (version 20200916).
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

/* ----------SUBROUTINE--PCLIPT-----------TEKTRONIX, INC.----00010820 */
int pclipt_(real * x, real * y)
{
    tktrnx_1.kgnflg = 0;
    if (*x < tktrnx_1.tminvx) {
	goto L10;
    }
    if (*x > tktrnx_1.tmaxvx) {
	goto L10;
    }
    if (*y < tktrnx_1.tminvy) {
	goto L10;
    }
    if (*y <= tktrnx_1.tmaxvy) {
	goto L20;
    }
  L10:
    tktrnx_1.kgnflg = 1;
  L20:
    return 0;
}				/* pclipt_ */
