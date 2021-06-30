/* recovr.f -- translated by f2c (version 20200916).
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
extern int cwsend_ (void);
extern int movabs_ (integer *, integer *);
extern int pntmod_ (void);

/* ----------SUBROUTINE--RECOVR--------TEKTRONIX, INC.----00019820 */
int
recovr_ (void)
{
  static integer iy, mode, iflag;

/*  SAVE THE GRAPHIC LEVEL FLAG */
  iflag = tktrnx_1.kgrafl;
/* * REMOVE MOVE FLAG                                 00019920 */
  tktrnx_1.kmovef = 0;
/* * SAVE THE MODE                                    00019940 */
  mode = tktrnx_1.kkmode + 1;
/* * SAVE THE Y-COORDINATE                            00019960 */
  iy = tktrnx_1.kbeamy;
/* * CLEAR ALL OTHER MODES                            00019980 */
  alfmod_ ();
/* * MOVE TO SCREEN LOCATION                          00020000 */
  movabs_ (&tktrnx_1.kbeamx, &iy);
/* * SET THE HARDWARE DASH AND Z-AXIS WHEN NEEDED */
  if (tktrnx_1.kterm >= 2)
    {
      cwsend_ ();
    }
/* * PLACE IN THE PROPER MODE                            00020020 */
  if (mode < 1)
    {
      mode = 1;
    }
  if (mode > 5)
    {
      mode = 5;
    }
  switch (mode)
    {
    case 1:
      goto L100;
    case 2:
      goto L200;
    case 3:
      goto L120;
    case 4:
      goto L100;
    case 5:
      goto L200;
    }
L100:
  alfmod_ ();
  goto L200;
L120:
  pntmod_ ();
/* * RESTORE THE GRAPHIC LEVEL FLAG */
L200:
  tktrnx_1.kgrafl = iflag;
  return 0;
}				/* recovr_ */
