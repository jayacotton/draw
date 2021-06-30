/* drwrel.f -- translated by f2c (version 20200916).
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

extern int drwabs_ (integer *, integer *);
/* ----------SUBROUTINE--DRWREL-----------TEKTRONIX, INC.----00011330 */
int
drwrel_ (integer * ix, integer * iy)
{
  static integer jx, jy;

  jx = tktrnx_1.kbeamx + *ix;
  jy = tktrnx_1.kbeamy + *iy;
  drwabs_ (&jx, &jy);
  return 0;
}				/* drwrel_ */
