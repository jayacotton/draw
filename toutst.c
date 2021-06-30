/* toutst.f -- translated by f2c (version 20200916).
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
extern int buffpk_ (integer *, integer *);

/* ----------SUBROUTINE--TOUTST--------TEKTRONIX, IN--- --00023500 */
int
toutst_ (integer * len, integer * iade)
{
  /* Initialized data */

  static integer isync = 22;
  static integer maxlen = 72;

  /* System generated locals */
  integer i__1, i__2;

  /* Local variables */
  static integer i__, k, iuse[72], itemp, itest;
  static integer lenout;

  /* Parameter adjustments */
  --iade;

  /* Function Body */
  lenout = 0;
  if (*len <= 0)
    {
      goto L40;
    }
  itest = tktrnx_1.kpad2 - 1;
  i__1 = *len;
  for (i__ = 1; i__ <= i__1; ++i__)
    {
      itemp = iade[i__];
/* * TEST TO SEE IF PADDING WITH (SYN) TO SOLVE SPEED IS NEEDED    00023670 */
/* * REMOVE THIS SECTION IF NOT NEEDED ****************************00023680 */
#if 0
      if (itest <= 0)
	{
	  goto L20;
	}
      if (itemp > 31)
	{
	  goto L20;
	}
      if (itemp < 27)
	{
	  goto L20;
	}
      i__2 = itest;
      for (k = 1; k <= i__2; ++k)
	{
	  if (lenout >= maxlen)
	    {
	      goto L40;
	    }
	  ++lenout;
/* L10: */
	  iuse[lenout - 1] = isync;
	}
#endif
    L20:
/* ******************************************************************00023770 */
/* * INSERT CODE EXPANSION CHARACTERS HERE, WHEN NEEDED              00023780 */
      if (lenout >= maxlen)
	{
	  goto L40;
	}
      ++lenout;
/* L30: */
      iuse[lenout - 1] = itemp;
    }
L40:
  buffpk_ (&lenout, iuse);
  return 0;
}				/* toutst_ */
