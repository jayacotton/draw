/* anstr.f -- translated by f2c (version 20200916).
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

extern int alfmod_(void);
extern int newlin_(void);
extern int toutst_(integer *, integer *);
/* ----------SUBROUTINE--ANSTR------------------TEKTRONIX, INC.----00018420 */
int anstr_(integer * nchar, integer * iade)
{
    static integer ipt, iend, isend;
    static integer maxlen;

    /* Parameter adjustments */
    --iade;

    /* Function Body */
    maxlen = 72;
    if (tktrnx_1.kunit == 1) {
	maxlen += -10;
    }
    if (tktrnx_1.kunit == 2 || tktrnx_1.kunit == 3) {
	maxlen += -2;
    }
    ipt = 1;
/* * PLACE THE TERMINAL IN A/N MODE, IF NEEDED                  00018550 */
    if (tktrnx_1.kkmode != 0) {
	alfmod_();
    }
/* * GET A NEWLINE WHEN THE BEAM POSITION IS OUTSIDE MARGINS    00018570 */
    if (tktrnx_1.kbeamx < tktrnx_1.klmrgn) {
	goto L10;
    }
  L5:
    if (tktrnx_1.kbeamx <= tktrnx_1.krmrgn) {
	goto L20;
    }
    if (tktrnx_1.kbeamx < 4092 / tktrnx_1.kfactr) {
	goto L10;
    }
    tktrnx_1.kbeamx = tktrnx_1.klmrgn;
    tktrnx_1.kbeamy -= (tktrnx_1.kversz + tktrnx_1.kfactr / 2) /
	tktrnx_1.kfactr;
    if (tktrnx_1.kbeamy < 0) {
	tktrnx_1.kbeamy = tktrnx_1.khomey;
    }
    goto L20;
  L10:
    newlin_();
/* * CALCULATE NUMBER OF CHARACTERS POSSIBLE TO PUT ON LINE       00018610 */
  L20:
    isend = ((tktrnx_1.krmrgn - tktrnx_1.kbeamx) * tktrnx_1.kfactr +
	     tktrnx_1.khorsz - 1) / tktrnx_1.khorsz;
/* * PUT OUT AT LEAST ONE CHARACTER                               00018630 */
    if (isend < 1) {
	isend = 1;
    }
/* * DON'T SEND ENOUGH CHARACTERS TO CAUSE BUFFER TRUNCATION       00018650 */
    if (isend > maxlen) {
	isend = maxlen;
    }
    iend = ipt + isend - 1;
/* * SEND ONLY NUMBER OF CHARACTERS RECEIVED                       00018680 */
    if (iend > *nchar) {
	isend = *nchar - ipt + 1;
    }
    toutst_(&isend, &iade[ipt]);
/* * UPDATE THE BEAM                                               00018710 */
    tktrnx_1.kbeamx += (isend * tktrnx_1.khorsz + tktrnx_1.kfactr / 2) /
	tktrnx_1.kfactr;
    if (tktrnx_1.kbeamx > 4092 / tktrnx_1.kfactr) {
	tktrnx_1.kbeamx = 4092 / tktrnx_1.kfactr;
    }
    ipt += isend;
/* * REPEAT ON NEWLINE UNTIL ALL CHARACTERS SENT                   00018740 */
    if (iend < *nchar) {
	goto L5;
    }
    return 0;
}				/* anstr_ */
