/* restat.f -- translated by f2c (version 20200916).
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
extern int cwsend_ (void);
extern int chrsiz_ (integer *);
extern int recovr_ (void);

/* ----------SUBROUTINE--RESTAT-----------TEKTRONIX, INC.----00016070 */
int
restat_ (real * rarray)
{
  /* Local variables */
  static integer i__;
#define ib ((integer *)&tktrnx_1 + 19)
#define rb ((real *)&tktrnx_1)

/* * COPY GIVEN STATUS INTO TCS COMMON                        00016190 */
  /* Parameter adjustments */
  --rarray;

  /* Function Body */
  for (i__ = 1; i__ <= 19; ++i__)
    {
/* L100: */
      rb[i__ - 1] = rarray[i__];
    }
  for (i__ = 1; i__ <= 41; ++i__)
    {
/* L101: */
      ib[i__ - 1] = rarray[i__ + 19];
    }
/* * RESTORE CHARACTER SIZE                                  00016240 */
  if (tktrnx_1.kterm > 1)
    {
      chrsiz_ (&tktrnx_1.ksizef);
    }
/* * RESTORE ZAXIS AND DASH LINE                             00016260 */
  if (tktrnx_1.kterm > 2)
    {
      cwsend_ ();
    }
/* * CALL TO RECOVER POSITION AND MODE                        00016280 */
  recovr_ ();
  return 0;
}				/* restat_ */

#undef rb
#undef ib
