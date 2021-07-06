/* dasha.f -- translated by f2c (version 20200916).
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

extern int v2st_(integer *, real *, real *, integer *, integer *);
extern int dshmod_(integer *), tkdash_(integer *, integer *);
extern int lvlcht_(void);

static integer c__1 = 1;

/* ----------SUBROUTINE--DASHA-------------TEKTRONIX, INC.----00004530 */
int dasha_(real * x, real * y, integer * l)
{
    static integer ix, iy;

    lvlcht_();
/* * CONVERT TO SCREEN CO-ORDINATES                           00004640 */
    v2st_(&c__1, x, y, &ix, &iy);
/* * SKIP IF LINE COMPLETELY OUTSIDE WINDOW                   00004660 */
    if (tktrnx_1.kgnflg == 1) {
	goto L10;
    }
    dshmod_(l);
    tkdash_(&ix, &iy);
  L10:
    return 0;
}				/* dasha_ */
