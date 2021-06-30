/* settab.f -- translated by f2c (version 20200916).
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

/* ----------SUBROUTINE--SETTAB---------TEKTRONIX, INC.----00012050 */
int
settab_ (integer * itab, integer * itbtbl)
{
  static integer i__, itemp, itempa;

  /* Parameter adjustments */
  --itbtbl;

  /* Function Body */
  tktrnx_1.kgnflg = 0;
  if (*itab <= 0)
    {
      goto L10;
    }
  i__ = 1;
L20:
  if (itbtbl[i__] == *itab)
    {
      goto L10;
    }
  if (*itab < itbtbl[i__])
    {
      goto L60;
    }
  if (itbtbl[i__] == 0)
    {
      goto L60;
    }
  ++i__;
  if (i__ <= tktrnx_1.ktblsz)
    {
      goto L20;
    }
L30:
  tktrnx_1.kgnflg = 1;
L10:
  return 0;
L60:
  itemp = itbtbl[i__];
  itbtbl[i__] = *itab;
L70:
  if (itemp == 0)
    {
      goto L10;
    }
  ++i__;
  if (i__ > tktrnx_1.ktblsz)
    {
      goto L30;
    }
  itempa = itbtbl[i__];
  itbtbl[i__] = itemp;
  itemp = itempa;
  goto L70;
}				/* settab_ */
