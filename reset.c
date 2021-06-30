#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

/* Table of constant values */

static integer c__1 = 1;
extern int alfmod_ (void);
extern int cwsend_ (void);
extern int movabs_ (integer *, integer *);
extern int chrsiz_ (integer *);

int
reset_ (void)
{
  tktrnx_1.keycon = 1;
  tktrnx_1.trfacx = 1.f;
  tktrnx_1.trfacy = 1.f;
  tktrnx_1.kbeamx = 0;
  tktrnx_1.khomey = 3068 / tktrnx_1.kfactr;
  tktrnx_1.kbeamy = tktrnx_1.khomey;
  tktrnx_1.kminsx = 0;
  tktrnx_1.kmaxsx = 4095 / tktrnx_1.kfactr;
  tktrnx_1.kminsy = 0;
  tktrnx_1.kmaxsy = 3120 / tktrnx_1.kfactr;
  tktrnx_1.khorsz = 56;
  tktrnx_1.kline = 0;
  tktrnx_1.kzaxis = 0;
  tktrnx_1.klmrgn = 0;
  tktrnx_1.krmrgn = 4088 / tktrnx_1.kfactr;
  tktrnx_1.ksizef = 1;
  tktrnx_1.ktblsz = 10;
  tktrnx_1.kversz = 88;
  tktrnx_1.tminvx = 0.f;
  tktrnx_1.tmaxvx = 4095.f / (real) tktrnx_1.kfactr;
  tktrnx_1.tminvy = 0.f;
  tktrnx_1.tmaxvy = 3120.f / (real) tktrnx_1.kfactr;
  tktrnx_1.trcosf = 1.f;
  tktrnx_1.trsinf = 0.f;
  tktrnx_1.trscal = 1.f;
/* * MOVE TO THE HOME POSITION                               00017530 */
  movabs_ (&tktrnx_1.klmrgn, &tktrnx_1.khomey);
/* * SET 4014 ENHANCED FOR SOLID LINES                       00017550 */
  if (tktrnx_1.kterm >= 3)
    {
      cwsend_ ();
    }
/* * PLACE 4014 IN LARGE CHARACTER SIZE                      00017570 */
  if (tktrnx_1.kterm >= 2)
    {
      chrsiz_ (&c__1);
    }
/* * PLACE THE TERMINAL IN A/N MODE                         00017590 */
  alfmod_ ();
  return 0;
}				/* reset_ */
