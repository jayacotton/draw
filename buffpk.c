#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

extern int adeout_ (integer *, integer *);
extern int pltchr_ (integer *, integer *, integer *);


int
buffpk_ (integer * nchar, integer * iout)
{
  /* Initialized data */

  static integer maxlen = 72;
  static integer lenout = 0;
  static integer nodata = 1;
  static integer itrail = 1;

  /* System generated locals */
  integer i__1;

  /* Local variables */
  static integer i__, len, key, idata[72];

  /* Parameter adjustments */
  --iout;

  /* Function Body */
  len = *nchar;
/* * DUMP THE BUFFER IF THE MODE IS UNBUFFERED */
  if (tktrnx_1.kunit == 4)
    {
      goto L45;
    }
/* * DUMP THE BUFFER WHEN REQUESTED BY LEN=0 */
  if (*nchar <= 0)
    {
      goto L10;
    }
/* * DON'T DUMP THE BUFFER IF NEW STRING WILL FIT */
  if (*nchar <= tktrnx_1.kotlft)
    {
      goto L70;
    }
/* * DETERMINE IF THERE IS DATA IN BUFFER */
L10:
  if (nodata == 1)
    {
      goto L50;
    }
  nodata = 1;
/* * DETERMINE THE FORMAT THE USER WANTS BUFFER DUMPED IN */
  switch (tktrnx_1.kunit)
    {
    case 1:
      goto L20;
    case 2:
      goto L30;
    case 3:
      goto L40;
    case 4:
      goto L45;
    }
/* * OUTPUT BUFFER FORMAT IS (GS),PLTCHRS,DATA,(US) */
L20:
  ++lenout;
/* * APPEND (US) TO END OF BUFFER */
  idata[lenout - 1] = 31;
  adeout_ (lenout, idata);
  pltchr_ (&tktrnx_1.kbeamx, &tktrnx_1.kbeamy, idata);
/* * RESTORE THE BEAM POSITION AT FIRST OF THE NEXT BUFFER */
  idata[1] = idata[0];
  idata[0] = 29;
/* * AND NOW THE MODE BEFORE THE OUTPUT WAS ASKED FOR */
  lenout = 6;
  key = tktrnx_1.kkmode + 1;
  if (key < 1)
    {
      key = 1;
    }
  if (key > 5)
    {
      key = 1;
    }
/* * MODE IS A/N,VEC,PNT,INC,DSH */
  switch (key)
    {
    case 1:
      goto L21;
    case 2:
      goto L22;
    case 3:
      goto L23;
    case 4:
      goto L24;
    case 5:
      goto L22;
    }
/* * ENTER A/N MODE */
L21:
  idata[lenout - 1] = 31;
  goto L50;
/* * ENTER VECTOR MODE */
L22:
  idata[lenout - 1] = 29;
  if (tktrnx_1.kmovef != 1)
    {
      --lenout;
    }
  goto L50;
/* * ENTER POINT MODE */
L23:
  if (tktrnx_1.kterm < 3)
    {
      goto L22;
    }
  idata[lenout - 1] = 28;
  ++lenout;
  goto L22;
/* * ENTER INCREMENTAL PLOT MODE */
L24:
  idata[lenout - 1] = 30;
/* * RAISE OR LOWER PEN AS NEEDED */
/* * THE FOLLOWING 3 LINES ARE NOT NEEDED ON SOME PLOTTERS ********* */
  ++lenout;
  idata[lenout - 1] = 80;
  if (tktrnx_1.kmovef == 1)
    {
      idata[lenout - 1] = 32;
    }
/* **************************************************************** */
  goto L50;
/* * OUTPUT BUFFER FORMAT IS (SYN),DATA,(ESC) */
L30:
  if (*nchar <= 0 && tktrnx_1.kmoflg[0] != 1)
    {
      goto L20;
    }
  ++lenout;
/* * APPEND (ESC) TO END OF BUFFER */
  idata[lenout - 1] = 27;
  adeout_ (lenout, idata);
  idata[0] = 22;
  lenout = 1;
  goto L50;
/* * OUTPUT BUFFER FORMAT IS DATA ONLY */
L40:
  adeout_ (lenout, idata);
  lenout = 0;
  goto L50;
/* * NON-BUFFERED OUTPUT FORMAT */
L45:
  if (lenout > 0)
    {
      adeout_ (lenout, idata);
    }
  if (len > 0)
    {
      adeout_ (len, &iout[1]);
    }
  lenout = 0;
  nodata = 1;
  goto L90;
L50:
  tktrnx_1.kotlft = maxlen - lenout - itrail;
  if (len <= 0)
    {
      goto L90;
    }
L70:
  nodata = 0;
  if (len > tktrnx_1.kotlft)
    {
      len = tktrnx_1.kotlft;
    }
  len = *nchar;
  if (len > tktrnx_1.kotlft)
    {
      len = tktrnx_1.kotlft;
    }
  i__1 = len;
  for (i__ = 1; i__ <= i__1; ++i__)
    {
      ++lenout;
/* L80: */
      idata[lenout - 1] = iout[i__];
    }
L90:
  tktrnx_1.kotlft = maxlen - lenout - itrail;
  return 0;
}				/* buffpk_ */
