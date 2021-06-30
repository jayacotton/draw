/* tabhor.f -- translated by f2c (version 20200916).
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
extern int alfmod_ (void);
extern int newlin_ (void);
extern int movabs_ (integer *, integer *);

/* ----------SUBROUTINE--TABHOR----------TEKTRONIX, INC.----00012630 */
int
tabhor_ (integer * itbtbl)
{
  /* System generated locals */
  integer i__1;

  /* Local variables */
  static integer k, kflg;

  /* Parameter adjustments */
  --itbtbl;

  /* Function Body */
  kflg = 0;
  i__1 = tktrnx_1.ktblsz;
  for (k = 1; k <= i__1; ++k)
    {
      if (itbtbl[k] != 0)
	{
	  kflg = 1;
	}
      if (itbtbl[k] > tktrnx_1.kbeamx)
	{
	  goto L20;
	}
/* L10: */
    }
  if (kflg == 0)
    {
      goto L30;
    }
L15:
  newlin_ ();
  goto L30;
L20:
  if (itbtbl[k] >= tktrnx_1.krmrgn)
    {
      goto L15;
    }
  movabs_ (&itbtbl[k], &tktrnx_1.kbeamy);
  alfmod_ ();
L30:
  return 0;
}				/* tabhor_ */
