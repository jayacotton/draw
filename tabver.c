/* tabver.f -- translated by f2c (version 20200916).
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
extern int movabs_(integer *, integer *);
/* ----------SUBROUTINE--TABVER-----------TEKTRONIX, INC.----00012880 */
int tabver_(integer * itbtbl)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, k;

    /* Parameter adjustments */
    --itbtbl;

    /* Function Body */
    i__1 = tktrnx_1.ktblsz;
    for (k = 1; k <= i__1; ++k) {
	i__ = tktrnx_1.ktblsz - k + 1;
	if (itbtbl[i__] <= 0) {
	    goto L10;
	}
	if (itbtbl[i__] < tktrnx_1.kbeamy) {
	    goto L30;
	}
	if (itbtbl[i__] < tktrnx_1.kbeamy) {
	    goto L30;
	}
	if (itbtbl[i__] < tktrnx_1.kbeamy) {
	    goto L30;
	}
      L10:
	;
    }
    goto L20;
  L30:
    movabs_(&tktrnx_1.kbeamx, &itbtbl[i__]);
    alfmod_();
  L20:
    return 0;
}				/* tabver_ */
