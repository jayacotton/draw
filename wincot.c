#include "f2c.h"

/* Common Block Declarations */


#define tktrnx_1 tktrnx_

extern float log(doublereal);
extern float cos(doublereal);
extern float sin(doublereal);
/* ----------SUBROUTINE--WINCOT------------TEKTRONIX, INC.----00009450 */
int wincot_(real * x, real * y, integer * ix, integer * iy)
{
    /* Initialized data */

    static real de2rad = .01745f;

    /* Builtin functions */

    /* Local variables */
    static real a, r__, dx, dy;
    static integer key, keyl;

/* * CHECK FOR PERMITTED VALUE OF CONVERSION KEY      */
/* * DEFAULT IS LINEAR,ERROR IS NONE                  */
    dx = *x - tktrnx_1.tminvx;
    dy = *y - tktrnx_1.tminvy;
    key = tktrnx_1.keycon;
    if (tktrnx_1.keycon < 1) {
	key = 5;
    }
    if (tktrnx_1.keycon > 4) {
	key = 4;
    }
/* * BRANCH TO PROPER SECTION                         */
/* * LINEAR LOG POLAR USER ERROR                      */
    switch (key) {
    case 1:
	goto L500;
    case 2:
	goto L300;
    case 3:
	goto L600;
    case 4:
	goto L700;
    case 5:
	goto L100;
    }
/*       ERROR                                        */
  L100:
    *ix = *x;
    *iy = *y;
    goto L800;
/* * LOG TRANSFORM                                    */
  L300:
    keyl = tktrnx_1.trpar1 + .001f;
    if (keyl == 2) {
	goto L400;
    }
/* * SETUP X LOG TRANSFORM                            */
    dx = log(*x) - tktrnx_1.trpar2;
  L400:
    if (keyl == 1) {
	goto L500;
    }
/* * SETUP Y LOG TRANSFORM                            */
    dy = log(*y) - tktrnx_1.trpar3;
/* * CONVERT LINIER                  */
  L500:
    *ix = (integer) (dx * tktrnx_1.trfacx + .5f) + tktrnx_1.kminsx;
    *iy = (integer) (dy * tktrnx_1.trfacy + .5f) + tktrnx_1.kminsy;
/* * GO TO EXIT                                     */
    goto L800;
/* * POLAR TRANSFORMATION                           */
  L600:
    a = (*y - tktrnx_1.trpar6) * tktrnx_1.trfacy;
    r__ = (*x - tktrnx_1.trpar5) * tktrnx_1.trfacx;
    *ix = r__ * cos(a * de2rad) + tktrnx_1.trpar3;
    *iy = r__ * sin(a * de2rad) + tktrnx_1.trpar4;
/* * GO TO EXIT                                     */
    goto L800;
/* * USER TRANSFORMATION IN USE                     */
  L700:
/*      CALL USECOT(X,Y,IX,IY)                      */
/* * EXIT POINT                                     */
  L800:
    return 0;
}				/* wincot_ */
