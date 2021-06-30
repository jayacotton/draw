/* baksp.f -- translated by f2c (version 20200916).
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

extern int alfmod_ (void), toutpt_ (integer *);
/* Table of constant values */

static integer c__8 = 8;

/* ----------SUBROUTINE--BAKSP-------------TEKTRONIX, INC.----00019370 */
int
baksp_ (void)
{

  if (tktrnx_1.kkmode != 0)
    {
      alfmod_ ();
    }
/* * OUTPUT (BS)                                               00019480 */
  toutpt_ (&c__8);
  tktrnx_1.kbeamx -= (tktrnx_1.khorsz + tktrnx_1.kfactr / 2) /
    tktrnx_1.kfactr;
  if (tktrnx_1.kbeamx >= 0)
    {
      goto L10;
    }
  tktrnx_1.kbeamx += 4095 / tktrnx_1.kfactr;
L10:
  return 0;
}				/* baksp_ */
