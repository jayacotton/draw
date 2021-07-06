#include "f2c.h"

/* Common Block Declarations */


#define tktrnx_1 tktrnx_

extern int alfmod_(void), newlin_(void);
extern int toutpt_(integer *);

int ancho_(integer * ichar)
{
    if (tktrnx_1.kkmode == 0) {
	goto L10;
    }
    alfmod_();
  L10:
    toutpt_(ichar);
/* * ROUND NON-INTEGER CHARACTER WIDTH IN 1023 CO-ORDINATES         00018120 */
    tktrnx_1.kbeamx += (tktrnx_1.khorsz + tktrnx_1.kfactr / 2) /
	tktrnx_1.kfactr;
    if (tktrnx_1.kbeamx < tktrnx_1.krmrgn) {
	goto L20;
    }
    newlin_();
  L20:
    return 0;
}				/* ancho_ */
