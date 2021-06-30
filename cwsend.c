#include "f2c.h"

/* Common Block Declarations */


#define tktrnx_1 tktrnx_

/* Table of constant values */

static integer c__2 = 2;
extern int toutst_ (integer *, integer *);

int
cwsend_ (void)
{
  /* Initialized data */

  static integer icode[2] = { 27 };

  icode[1] = 96 + (tktrnx_1.kzaxis << 3) + tktrnx_1.kline;
  toutst_ (&c__2, icode);
  return 0;
}				/* cwsend_ */
