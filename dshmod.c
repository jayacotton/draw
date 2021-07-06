/* dshmod.f -- translated by f2c (version 20200916).
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

/* Table of constant values */

static integer c__31 = 31;
static integer c__29 = 29;
extern int xycnvt_(integer *, integer *);
extern int toutpt_(integer *);

/* ----------SUBROUTINE--DSHMOD--------------TEKTRONIX, INC.----00013100 */
int dshmod_(integer * l)
{
    static integer i__;

    if (tktrnx_1.kkmode == 4) {
	goto L10;
    }
    tktrnx_1.kkmode = 4;
/* * OUTPUT (US) TO CANCEL PREVIOUS MODE                     00013220 */
    toutpt_(&c__31);
/* * CANCEL OPTIMIZATION AND INSERT MOVE TO CURRENT LOCATION  00013240 */
    toutpt_(&c__29);
    tktrnx_1.kmovef = 1;
    for (i__ = 1; i__ <= 5; ++i__) {
/* L5: */
	tktrnx_1.kpchar[i__ - 1] = -1;
    }
    xycnvt_(&tktrnx_1.kbeamx, &tktrnx_1.kbeamy);
  L10:
    tktrnx_1.kdasht = *l;
    return 0;
}				/* dshmod_ */
