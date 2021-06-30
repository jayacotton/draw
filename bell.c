/* bell.f -- translated by f2c (version 20200916).
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

/* Table of constant values */

extern int toutpt_ (integer *);
static integer c__7 = 7;

/* ----------SUBROUTINE--BELL--------------TEKTRONIX, INC.----00003440 */
int
bell_ (void)
{

/* *  OUTPUT (BEL)                                            00003540 */
  toutpt_ (&c__7);
/* * BELL NULLIFIES MOVE AT TERMINAL                          00003560 */
  tktrnx_1.kmovef = 0;
  return 0;
}				/* bell_ */
