/* incplt.f -- translated by f2c (version 20200916).
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
extern int ipmod_ (void);
extern int toutpt_ (integer *);

/* ----------SUBROUTINE--INCPLT-----------TEKTRONIX, INC.----00002720 */
int
incplt_ (integer * ionoff, integer * idir, integer * no)
{
  /* Initialized data */

  static integer ipltbl[8] = { 4, 5, 1, 9, 8, 10, 2, 6 };
  static integer kbmup[10] = { 0, 1, 1, 1, 0, -1, -1, -1, 0, 1 };

  /* System generated locals */
  integer i__1;

  /* Local variables */
  static integer i__, ipen;
  static integer ipltch, ndxplt, kbmupx, kbmupy;

  if (tktrnx_1.kkmode != 3)
    {
      ipmod_ ();
    }
  ipen = *ionoff * 48 + 32;
/* * THIS SECTION TO ACCOMMODATE PLOTTERS REQUIRING A SEPARATE PEN   00002890 */
/* * CHARACTER -- IT MAY BE OMITTED IF NOT NEEDED *******************00002900 */
  toutpt_ (&ipen);
  ipen = 64;
/* ******************************************************************00002930 */
  tktrnx_1.kmovef = (i__1 = *ionoff - 1, abs (i__1));
  ndxplt = *idir % 8 + 1;
  ipltch = ipltbl[ndxplt - 1] + ipen;
  kbmupx = kbmup[ndxplt - 1];
  kbmupy = kbmup[ndxplt + 1];
  i__1 = *no;
  for (i__ = 1; i__ <= i__1; ++i__)
    {
      toutpt_ (&ipltch);
      tktrnx_1.kbeamx += kbmupx;
/* L10: */
      tktrnx_1.kbeamy += kbmupy;
    }
  return 0;
}				/* incplt_ */
