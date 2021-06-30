/* aoutst.f -- translated by f2c (version 20200916).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"
extern int anstr_ (integer *, integer *);
extern int kam2as_ (integer *, integer *, integer *);

/* ----------SUBROUTINE--AOUTST-------TEKTRONIX, INC.----00018330 */
int
aoutst_ (integer * nchar, integer * iam)
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
  kam2as_ (&len, &iam[1], iade);
  anstr_ (&len, iade);
  anstr_ (&len, iade);
  return 0;
}				/* aoutst_ */
