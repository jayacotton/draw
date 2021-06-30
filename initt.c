#include "f2c.h"

/* Common Block Declarations */


#define tktrnx_1 tktrnx_

extern int reset_ (void);
extern int newpag_ (void);
int
initt_ (integer ibaud)
{

  tktrnx_1.kkmode = 1;
  tktrnx_1.kbaudr = ibaud;
  tktrnx_1.kpad2 = tktrnx_1.kbaudr / 220 + 1;
  tktrnx_1.kmoflg[0] = 0;
  tktrnx_1.kterm = 1;
  tktrnx_1.kfactr = 4;
/* * SET THE OUTPUT BUFFER FORMAT        */
  tktrnx_1.kunit = 1;
  tktrnx_1.kinlft = 0;
  tktrnx_1.kotlft = 1;
  reset_ ();
  newpag_ ();
  return 0;
}				/* initt_ */
