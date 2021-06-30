
#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

/* Table of constant values */

static integer c__2 = 2;

extern int toutst_ (integer *, integer *);

int
chrsiz_ (integer * k)
{
  /* Initialized data */

  static integer ichrtb[8] /* was [2][4] */  =
  { 56, 88, 51, 83, 34, 53, 31, 48 }
  ;
  static integer icode[2] = { 27 };

/* * CHECK TERMINAL TYPE                                00022840 */
  if (tktrnx_1.kterm <= 1)
    {
      goto L10;
    }
  if (*k < 1)
    {
      *k = 1;
    }
  if (*k > 4)
    {
      *k = 4;
    }
  tktrnx_1.ksizef = *k;
  tktrnx_1.khorsz = ichrtb[(*k << 1) - 2];
  tktrnx_1.kversz = ichrtb[(*k << 1) - 1];
  icode[1] = *k + 55;
  toutst_ (&c__2, icode);
L10:
  return 0;
}				/* chrsiz_ */
