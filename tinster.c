/* tinster.f -- translated by f2c (version 20200916).
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

extern int adein_(integer *, integer *);
extern int tsend_(void);

/* ----------SUBROUTINE--TINSTR----------------TEKTRONIX, INC.----00015510 */
int tinstr_(integer * nchar, integer * iade)
{
    /* Initialized data */

    static integer isent = 0;
    static integer igot = 0;
    static integer ipad = 32;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, len, itmp;
    static integer inbuff[72];

    /* Parameter adjustments */
    --iade;

    /* Function Body */
    if (tktrnx_1.kinlft > 0) {
	goto L10;
    }
/* * REQUEST A NEW INPUT BUFFER                                          00015640 */
/* * PUT OUT THE OUTPUT BUFFER                                           00015650 */
    tsend_();
    adein_(&igot, inbuff);
    isent = 0;
    tktrnx_1.kinlft = igot;
  L10:
    len = *nchar;
    if (len <= 0) {
	goto L50;
    }
    i__1 = len;
    for (i__ = 1; i__ <= i__1; ++i__) {
	++isent;
	itmp = i__;
	if (isent > igot) {
	    goto L30;
	}
/* L20: */
	iade[i__] = inbuff[isent - 1];
    }
    tktrnx_1.kinlft = igot - isent;
    goto L50;
/* * PAD WITH BLANKS WHEN NEEDED                                         00015780 */
  L30:
    i__1 = len;
    for (i__ = itmp; i__ <= i__1; ++i__) {
/* L40: */
	iade[i__] = ipad;
    }
    tktrnx_1.kinlft = 0;
  L50:
    return 0;
}				/* tinstr_ */
