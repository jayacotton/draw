#include "f2c.h"

/* Common Block Declarations */


#define tktrnx_1 tktrnx_

/* Table of constant values */

static integer c__22 = 22;
extern int toutpt_ (integer *);

int
iowait_ (integer * itime)
{
  /* System generated locals */
  integer i__1;

  /* Local variables */
  static integer j, kount;
  return 0;
/* * THIS ROUTINE IS USED TO GENERATE DELAYS FOR REMOTE TERMINALS  00020730 */
  if (tktrnx_1.kbaudr <= 0)
    {
      goto L20;
    }
  kount = *itime * tktrnx_1.kbaudr / 10;
  i__1 = kount;
  for (j = 1; j <= i__1; ++j)
    {
/* * OUTPUT (SYN) TO INSURE AGAINST LOSS OF OUTPUT WHILE            00020840 */
/* * TERMINAL IS BUSY. (SYN) DOES NOT AFFEINAL IS BUSY. L.           00020850 */
/* L10: */
      toutpt_ (&c__22);
    }
L20:
  return 0;
}				/* iowait_ */
