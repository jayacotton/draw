/* cartn.f -- translated by f2c (version 20200916).
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

static integer c__13 = 13;
extern int alfmod_(void);
extern int cwsend_(void);
extern int movabs_(integer *, integer *);
extern int toutpt_(integer *);

/* ----------SUBROUTINE--CARTN---------------TEKTRONIX, INC.----00018870 */
int cartn_(void)
{

    if (tktrnx_1.klmrgn == 0) {
	goto L10;
    }
/*IF (CR) CAN NOT BE SENT REMOVE ALL EXECUTEABLE CODE EXCEPT NEXT 2 00018980 */
/* * LINES AND RETURN                                               00018990 */
    movabs_(&tktrnx_1.klmrgn, &tktrnx_1.kbeamy);
    alfmod_();
    goto L30;
  L10:
    if (tktrnx_1.kkmode != 0) {
	alfmod_();
    }
/* * OUTPUT (CR)                                                00019040 */
    toutpt_(&c__13);
    tktrnx_1.kbeamx = 0;
/* * RESTORE ZAXIS STATE ON 4014                                 00019070 */
    if (tktrnx_1.kterm >= 2) {
	cwsend_();
    }
  L30:
    return 0;
}				/* cartn_ */
