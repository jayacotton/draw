/* scursr.f -- translated by f2c (version 20200916).
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

static integer c__2 = 2;
static integer c__5 = 5;
extern int recovr_ (void);
extern int tinstr_ (integer *, integer *);
extern int toutst_ (integer *, integer *);

/* ----------SUBROUTINE--SCURSR-----TEKTRONIX, INC.----00014950 */
int
scursr_ (integer * ichar, integer * ix, integer * iy)
{
  /* Initialized data */

  static integer icode[2] = { 27, 26 };

  static integer in[5];

/* * SET THE GRAPHIC INPUT FLAG */
  tktrnx_1.kmoflg[0] = 1;
/* * OUTPUT (ESC) (SUB) TO TURN ON CURSOR                 00015070 */
  toutst_ (&c__2, icode);
/* * CURSER SHOULD ALWAYS INPUT A NEW BUFFER               00015090 */
  tktrnx_1.kinlft = 0;
  tinstr_ (&c__5, in);
/* * REMOVE THE GRAPHIC INPUT FLAG */
  tktrnx_1.kmoflg[0] = 0;
/* * RESTORE THE TERMINAL STATUS                           00015120 */
  recovr_ ();
  *ichar = in[0];
/* * DECODE SCREEN CO-ORDINATES                            00015150 */
  *ix = (in[1] % 32 << 5) + in[2] % 32;
  *iy = (in[3] % 32 << 5) + in[4] % 32;
/* * APPLY SCREEN SCALE FACTOR                              00015180 */
  *ix = (*ix << 2) / tktrnx_1.kfactr;
  *iy = (*iy << 2) / tktrnx_1.kfactr;
  return 0;
}				/* scursr_ */
