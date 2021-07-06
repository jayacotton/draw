
#include "f2c.h"

/* Common Block Declarations */


#define tktrnx_1 tktrnx_
extern int pscal_ (void);

int
poltrn_ (real * angmin, real * angmax, real * rsuprs)
{

  tktrnx_1.keycon = 3;
  tktrnx_1.trpar1 = *angmin;
  tktrnx_1.trpar2 = *angmax;
  tktrnx_1.trpar5 = *rsuprs;
  pscal_ ();
  return 0;
}				/* poltrn_ */

int
poltrn (real angmin, real angmax, real rsuprs)
{
  real a1, a2, a3;

  a1 = angmin;
  a2 = angmax;
  a3 = rsuprs;
  return (poltrn_ (&a1, &a2, &a3));
}
