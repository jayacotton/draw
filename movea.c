#include "f2c.h"


#define tktrnx_1 tktrnx_

/* Table of constant values */

static integer c__0 = 0;
extern int v2st_ (integer *, real *, real *, integer *, integer *);
extern int vecmod_ (void);
extern int lvlcht_ (void);
extern int xycnvt_ (integer *, integer *);

int
movea_ (real x, real y)
{
  static integer ix, iy;

  lvlcht_ ();
/* * CONVERT TO SCREEN CO-ORDINATES                              00005950 */
  v2st_ (&c__0, &x, &y, &ix, &iy);
/* * SKIP IF LINE COMPLETELY OUTSIDE WINDOW                      00005970 */
  if (tktrnx_1.kgnflg == 1)
    {
      goto L10;
    }
  vecmod_ ();
  xycnvt_ (&ix, &iy);
L10:
  return 0;
}				/* movea_ */
