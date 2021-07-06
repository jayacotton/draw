/* lvlcht.f -- translated by f2c (version 20200916).
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
extern int revcot_(integer *, integer *, real *, real *);

/* ----------SUBROUTINE--LVLCHT--------------TEKTRONIX, INC.----00009970 */
int lvlcht_(void)
{

    if (tktrnx_1.kgrafl != 0) {
	goto L10;
    }
    revcot_(&tktrnx_1.kbeamx, &tktrnx_1.kbeamy, &tktrnx_1.trealx,
	    &tktrnx_1.trealy);
    tktrnx_1.timagx = tktrnx_1.trealx;
    tktrnx_1.timagy = tktrnx_1.trealy;
    tktrnx_1.kgrafl = 1;
  L10:
    return 0;
}				/* lvlcht_ */
