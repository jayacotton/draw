/* rel2ab.f -- translated by f2c (version 20200916).
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
extern int lvlcht_(void);

/* ----------SUBROUTINE--REL2AB----------KTRONIX, INC.----00005680 */
int rel2ab_(real * xin, real * yin, real * xout, real * yout)
{

    lvlcht_();
    *xout = (*xin * tktrnx_1.trcosf - *yin * tktrnx_1.trsinf) *
	tktrnx_1.trscal + tktrnx_1.timagx;
    *yout = (*xin * tktrnx_1.trsinf + *yin * tktrnx_1.trcosf) *
	tktrnx_1.trscal + tktrnx_1.timagy;
    return 0;
}				/* rel2ab_ */
