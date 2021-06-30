#include "f2c.h"

extern int kas2am_ (integer *, integer *, integer *);
extern int tinstr_ (integer *, integer *);
int
ainst_ (integer * nchar, integer * iam)
{
  /* Initialized data */

  static integer maxlen = 72;

  static integer len, iade[72];

  /* Parameter adjustments */
  --iam;

  /* Function Body */
  len = *nchar;
  if (len > maxlen)
    {
      len = maxlen;
    }
  tinstr_ (&len, iade);
  kas2am_ (&len, iade, &iam[1]);
  return 0;
}				/* ainst_ */
