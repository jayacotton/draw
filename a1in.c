#include "f2c.h"

extern int kas2a1_ (integer *, integer *, integer *);
extern int tinstr_ (integer *, integer *);
int
a1in_ (integer * nchar, integer * ia1)
{
  /* Initialized data */

  static integer maxlen = 72;
  static integer len, iade[72];

  /* Parameter adjustments */
  --ia1;

  /* Function Body */
  len = *nchar;
  if (len > maxlen)
    {
      len = maxlen;
    }
  tinstr_ (&len, iade);
  kas2a1_ (&len, iade, &ia1[1]);
  return 0;
}				/* a1in_ */
