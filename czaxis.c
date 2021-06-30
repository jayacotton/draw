/* czaxis.f -- translated by f2c (version 20200916).
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

extern int cwsend_ (void);
#define tktrnx_1 tktrnx_

/* ----------SUBROUTINE--CZAXIS---------------TEKTRONIX, INC.----00022960 */
int
czaxis_ (integer * icode)
{

/* * ICODE = 0 -- NORMAL Z AXIS           00023060 */
/* *       = 1 --DEFOCUSED Z AXIS         00023070 */
/* *       = 2 --WRITE-THRU ENABLE        00023080 */
/* *       = 3 --NON-STORE ENABLE         00023090 */
  if (tktrnx_1.kterm <= 1)
    {
      goto L10;
    }
  tktrnx_1.kzaxis = *icode;
  if (tktrnx_1.kzaxis < 0)
    {
      tktrnx_1.kzaxis = 0;
    }
  if (tktrnx_1.kzaxis > 2)
    {
      tktrnx_1.kzaxis = 2;
    }
  cwsend_ ();
L10:
  return 0;
}				/* czaxis_ */
