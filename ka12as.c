/* ka12as.f -- translated by f2c (version 20200916).
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

/* ----------SUBROUTINE KA12AS------------EGLIN AFB-----------00024920 */
int
ka12as_ (integer * nc, logical1 * ia1, logical1 * iade)
{
  /* Initialized data */

  static logical1 z__ = FALSE_;

  /* System generated locals */
  integer i__1;

  /* Local variables */
  static integer i__, ie;

  /* Parameter adjustments */
  --iade;
  --ia1;

  /* Function Body */
  ie = 2 * *nc - 1;
  i__1 = ie;
  for (i__ = 1; i__ <= i__1; i__ += 2)
    {
      iade[i__] = ia1[i__];
/* L1: */
      iade[i__ + 1] = z__;
    }
  return 0;
}				/* ka12as_ */
