#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_
extern int vecmod_ (void);
extern int cwsend_ (void);
extern int xycnvt_ (integer *, integer *);

int
drwabs_ (integer ix, integer iy)
{

/* * NON-4014/15 PRUNING BOUNDARY           */
/* * SET TERMINAL TO DRAW SOLID LINES       */
/* * THIS SECTION IS FOR 4014 ENHANCED **** */
  if (tktrnx_1.kline == 0)
    {
      goto L5;
    }
  tktrnx_1.kline = 0;
  cwsend_ ();
L5:
/* **************************************** */
  if (tktrnx_1.kkmode != 1)
    {
      vecmod_ ();
    }
  if (tktrnx_1.kmovef == 1)
    {
      xycnvt_ (&tktrnx_1.kbeamx, &tktrnx_1.kbeamy);
    }
  xycnvt_ (&ix, &iy);
  tktrnx_1.kgrafl = 0;
  return 0;
}				/* drwabs_ */
