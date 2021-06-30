/* parclt.f -- translated by f2c (version 20200916).
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

/* ----------SUBROUTINE--PARCLT-----------TEKTRONIX, INC.----00007550 */
int
parclt_ (real * rl1, real * rl2, real * rm1, real * rm2, real * rn1,
	 real * rn2)
{
  if (*rl1 < *rm1)
    {
      goto L10;
    }
  if (*rl1 > *rm2)
    {
      goto L20;
    }
  *rn1 = *rl1;
  if (*rl2 - *rm1 >= 0.f)
    {
      goto L40;
    }
  else
    {
      goto L30;
    }
L10:
  *rn1 = *rm1;
L40:
  if (*rl2 <= *rm2)
    {
      goto L50;
    }
  *rn2 = *rm2;
  goto L60;
L50:
  *rn2 = *rl2;
  goto L60;
L20:
  *rn1 = *rm2;
  if (*rl2 >= *rm1)
    {
      goto L50;
    }
L30:
  *rn2 = *rm1;
L60:
  return 0;
}				/* parclt_ */
