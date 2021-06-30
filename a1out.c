#include "f2c.h"

extern int ka12as_ (integer *, integer *, integer *);
extern int anstr_ (integer *, integer *);

int
a1out_ (integer * nchar, integer * ia1)
{
  /* System generated locals */
  integer i__1;

  /* Local variables */
  static integer i__, iade[72];
  static integer isend, itemp;

  /* Parameter adjustments */
  --ia1;

  /* Function Body */
  itemp = *nchar;
  i__1 = *nchar;
  for (i__ = 1; i__ <= i__1; i__ += 72)
    {
      isend = 72;
      if (itemp < 72)
	{
	  isend = itemp;
	}
      ka12as_ (&isend, &ia1[i__], iade);
      anstr_ (&isend, iade);
/* L10: */
      itemp += -72;
    }
  return 0;
}				/* a1out_ */
