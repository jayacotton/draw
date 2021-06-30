/* rsttab.f -- translated by f2c (version 20200916).
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

/* ----------SUBROUTINE--RSTTAB-------TEKTRONIX, INC.----00012370 */
int
rsttab_ (integer * itab, integer * itbtbl)
{
  /* System generated locals */
  integer i__1;

  /* Local variables */
  static integer i__, j, k, ii;

  /* Parameter adjustments */
  --itbtbl;

  /* Function Body */
  if (*itab < 0)
    {
      goto L10;
    }
  else if (*itab == 0)
    {
      goto L20;
    }
  else
    {
      goto L30;
    }
L30:
  i__1 = tktrnx_1.ktblsz;
  for (i__ = 1; i__ <= i__1; ++i__)
    {
      if (*itab == itbtbl[i__])
	{
	  goto L50;
	}
/* L40: */
    }
  goto L10;
L50:
  j = tktrnx_1.ktblsz - 1;
  i__1 = j;
  for (k = i__; k <= i__1; ++k)
    {
/* L60: */
      itbtbl[k] = itbtbl[k + 1];
    }
  itbtbl[tktrnx_1.ktblsz] = 0;
  goto L10;
L20:
  i__1 = tktrnx_1.ktblsz;
  for (ii = 1; ii <= i__1; ++ii)
    {
/* L21: */
      itbtbl[ii] = 0;
    }
L10:
  return 0;
}				/* rsttab_ */
