/* linef.f -- translated by f2c (version 20200916).
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

extern int alfmod_(void);
extern int cwsend_(void);
extern int movabs_(integer *, integer *);
extern int toutpt_(integer *);

static integer c__10 = 10;

/* ----------SUBROUTINE--LINEF----------TEKTRONIX, INC.----00019120 */
int linef_(void)
{

/* * IF (LF) CAN NOT BE SENT REMOVE NEXT 2 EXECUTEABLE LINES AND   00019220 */
/* * CHANGE @GO TO@ FROM 200 TO 100                                00019230 */
    if (tktrnx_1.kkmode != 0) {
	alfmod_();
    }
/* * OUTPUT (LF)                                                   00019250 */
    toutpt_(&c__10);
    tktrnx_1.kbeamy -= (tktrnx_1.kversz + tktrnx_1.kfactr / 2) /
	tktrnx_1.kfactr;
    if (tktrnx_1.kbeamy >= 0) {
	goto L200;
    }
    tktrnx_1.kbeamy = tktrnx_1.khomey;
/* L100: */
    movabs_(&tktrnx_1.kbeamx, &tktrnx_1.kbeamy);
    alfmod_();
/* * RESTORE ZAXIS MODE IF APPROPRIATE                              00019320 */
  L200:
    if (tktrnx_1.kterm >= 2) {
	cwsend_();
    }
    return 0;
}				/* linef_ */
