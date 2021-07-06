#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_
extern int pltchr_(integer *, integer *, integer *);
extern int toutst_(integer *, integer *);

int xycnvt_(integer * ix, integer * iy)
{
    /* Initialized data */

    static integer idrew = 0;
    static integer isyn = 22;

    static integer len, iplt[5], iopt[5];
/* * RECEIVE THE PLOT CHARACTERS                      */
    pltchr_(ix, iy, iplt);
/* * OPTIMIZE THE OUTPUT                              */
    len = 0;
/* * CHECK IF HIGH Y IS NEEDED                        */
    if (tktrnx_1.kpchar[0] == iplt[0]) {
	goto L10;
    }
/* * INCLUDE HIGH Y IF NEEDED                         */
    len = 1;
    tktrnx_1.kpchar[0] = iplt[0];
    iopt[0] = iplt[0];
/* * CHECK IF LSBYX IS NEEDED                         */
  L10:
    if (tktrnx_1.kterm <= 2) {
	goto L20;
    }
    if (tktrnx_1.kpchar[1] == iplt[1]) {
	goto L20;
    }
/* * INCLUDE LSBYX IF NEEDED                          */
    ++len;
    tktrnx_1.kpchar[1] = iplt[1];
    iopt[len - 1] = iplt[1];
    goto L30;
/* * CHECK IF LOW Y IS NEEDED                         */
  L20:
    if (tktrnx_1.kpchar[2] != iplt[2]) {
	goto L30;
    }
    if (tktrnx_1.kpchar[3] == iplt[3]) {
	goto L40;
    }
/* * INCLUDE LOW Y IF NEEDED                          */
  L30:
    ++len;
    tktrnx_1.kpchar[2] = iplt[2];
    iopt[len - 1] = iplt[2];
/* * CHECK IF HIGH X IS NEEDED                        */
    if (tktrnx_1.kpchar[3] == iplt[3]) {
	goto L50;
    }
/* * INCLUDE HIGH X IF NEEDED                         */
    ++len;
    tktrnx_1.kpchar[3] = iplt[3];
    iopt[len - 1] = iplt[3];
/* * CHECK IF LOW X IS NEEDED                         */
  L40:
    if (tktrnx_1.kpchar[4] != iplt[4]) {
	goto L50;
    }
/* * CHECK IF ALL THE CHARACTERS ARE THE SAME         */
    if (len != 0) {
	goto L50;
    }
/* * CHECK IF (GS) FOR DARK VECTOR ALREADY SENT       */
    if (tktrnx_1.kmovef == 1) {
	goto L50;
    }
/* * CHECK IF VECTOR IS ALREADY DRAWN TO SPOT         */
    if (idrew == 1) {
	goto L80;
    }
/* * INCLUDE THE LOW X                                */
  L50:
    ++len;
    tktrnx_1.kpchar[4] = iplt[4];
    iopt[len - 1] = iplt[4];
/* * CHECK FOR POSSIBLE SPEED PROBLEM                 */
  L60:
    goto L70;			/* hack */
    if (len >= tktrnx_1.kpad2) {
	goto L70;
    }
    ++len;
    iopt[len - 1] = isyn;
    goto L60;
/* * SEND THE ARRAY TO THE OUTPUT BUFFER              */
  L70:
    toutst_(&len, iopt);
/* * SET THE COMMON AND HISTORY VARIABLES             */
/* * SET THE DREW HERE FLAG                           */
    idrew = 1;
/* * REMOVE  THE DREW HERE FLAG IF DIDNT DRAW         */
    if (tktrnx_1.kmovef == 1) {
	idrew = 0;
    }
/* * REMOVE THE MOVE FLAG                             */
    tktrnx_1.kmovef = 0;
  L80:
    tktrnx_1.kbeamx = *ix;
    tktrnx_1.kbeamy = *iy;
    return 0;
}				/* xycnvt_ */
