#include "f2c.h"
#define tktrnx_1 tktrnx_
extern int pscal_ (void);
extern float log (doublereal);
int
rescal_ (void)
{
  /* Builtin functions */

  /* Local variables */
  static integer key, keyl;

/* * FLAG OLD VIRTUAL COORDINATES AS INCORRECT */
  tktrnx_1.kgrafl = 0;
  tktrnx_1.kgnflg = 0;
  key = tktrnx_1.keycon;
  if (tktrnx_1.keycon < 1)
    {
      key = 5;
    }
  if (tktrnx_1.keycon > 4)
    {
      key = 4;
    }
/* * BRANCH TO PROPER SECTION AND RETURN  */
/* * LINEAR LOG POLAR USER ERROR          */
  switch (key)
    {
    case 1:
      goto L100;
    case 2:
      goto L200;
    case 3:
      goto L300;
    case 4:
      goto L400;
    case 5:
      goto L500;
    }
/* * BOTH AXES LINEAR                     */
L100:
  tktrnx_1.trpar1 = 0.f;
/* * SEMI LOG OR LOG LOG                  */
L200:
  keyl = tktrnx_1.trpar1 + 1.001f;
/* * X AXIS -- LINEAR OR LOG              */
  switch (keyl)
    {
    case 1:
      goto L210;
    case 2:
      goto L215;
    case 3:
      goto L210;
    case 4:
      goto L215;
    }
/* * LINEAR                               */
L210:
  tktrnx_1.trfacx =
    (real) (tktrnx_1.kmaxsx - tktrnx_1.kminsx) / (tktrnx_1.tmaxvx -
						  tktrnx_1.tminvx);
  goto L250;
/* * PREVENT INVALID TRANSFORMATION */
L215:
  if (tktrnx_1.tminvx > 0.f && tktrnx_1.tmaxvx > 0.f)
    {
      goto L220;
    }
  tktrnx_1.kgnflg = 1;
  tktrnx_1.trpar1 += -1.f;
  goto L210;
/* * SEMI LOG X AXIS                      */
L220:
  tktrnx_1.trpar2 = log (tktrnx_1.tminvx);
  tktrnx_1.trfacx =
    (real) (tktrnx_1.kmaxsx - tktrnx_1.kminsx) / (log (tktrnx_1.tmaxvx) -
						  tktrnx_1.trpar2);
/* * Y AXIS -- LINEAR OR LOG              */
L250:
  switch (keyl)
    {
    case 1:
      goto L260;
    case 2:
      goto L260;
    case 3:
      goto L270;
    case 4:
      goto L270;
    }
/* * LINEAR                                */
L260:
  tktrnx_1.trfacy =
    (real) (tktrnx_1.kmaxsy - tktrnx_1.kminsy) / (tktrnx_1.tmaxvy -
						  tktrnx_1.tminvy);
  goto L600;
/* *PREVENT INVALID TRANSFORMATION */
L270:
  if (tktrnx_1.tminvy > 0.f && tktrnx_1.tmaxvy > 0.f)
    {
      goto L280;
    }
  tktrnx_1.kgnflg = 1;
  tktrnx_1.trpar1 += -2.f;
  goto L260;
/* * SEMI LOG Y AXIS                       */
L280:
  tktrnx_1.trpar3 = log (tktrnx_1.tminvy);
  tktrnx_1.trfacy =
    (real) (tktrnx_1.kmaxsy - tktrnx_1.kminsy) / (log (tktrnx_1.tmaxvy) -
						  tktrnx_1.trpar3);
  goto L600;
/* * POLAR SCALING                         */
L300:
  pscal_ ();
  goto L600;
/* * USER FUNCTION                         */
L400:
/*      CALL URSCAL                        */
  goto L600;
/* * NO SCALE                              */
L500:
  tktrnx_1.trfacx = 1.f;
  tktrnx_1.trfacy = 1.f;
L600:
  return 0;
}				/* rescal_ */
