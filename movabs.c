#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_

extern int vecmod_ (void);
extern int xycnvt_ (integer *, integer *);

int
movabs_ (integer ix, integer iy)
{
  vecmod_ ();
  xycnvt_ (&ix, &iy);
  tktrnx_1.kgrafl = 0;
  return 0;
}				/* movabs_ */
