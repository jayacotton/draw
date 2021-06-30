#include "f2c.h"

/* Common Block Declarations */

#define tktrnx_1 tktrnx_
extern int parclt_ (real *, real *, real *, real *, real *, real *);

int
clipt_ (real * bufin, real * outbf)
{
  static real a, b, q, r__, dendx, gendx, gendy, dendy, dstax, dstay, gstax,
    gstay;

  /* Parameter adjustments */
  --outbf;
  --bufin;
  /* Function Body */
  gstax = bufin[1];
  gstay = bufin[2];
  gendx = bufin[3];
  gendy = bufin[4];
  if (gstax >= tktrnx_1.tminvx)
    {
      goto L10;
    }
  if (gendx >= tktrnx_1.tminvx)
    {
      goto L20;
    }
  goto L110;
L10:
  if (gstax <= tktrnx_1.tmaxvx)
    {
      goto L20;
    }
  if (gendx <= tktrnx_1.tmaxvx)
    {
      goto L20;
    }
  goto L110;
L20:
  if (gstay >= tktrnx_1.tminvy)
    {
      goto L21;
    }
  if (gendy >= tktrnx_1.tminvy)
    {
      goto L30;
    }
  goto L110;
L21:
  if (gstay <= tktrnx_1.tmaxvy)
    {
      goto L30;
    }
  if (gendy <= tktrnx_1.tmaxvy)
    {
      goto L30;
    }
  goto L110;
L30:
  if (gstax != gendx)
    {
      goto L31;
    }
  dstax = gstax;
  dendx = gstax;
  parclt_ (&gstay, &gendy, &tktrnx_1.tminvy, &tktrnx_1.tmaxvy, &dstay,
	   &dendy);
  goto L120;
L31:
  if (gstay != gendy)
    {
      goto L40;
    }
  dstay = gstay;
  dendy = gstay;
  parclt_ (&gstax, &gendx, &tktrnx_1.tminvx, &tktrnx_1.tmaxvx, &dstax,
	   &dendx);
  goto L120;
L40:
  a = gendx - gstax;
  b = gendy - gstay;
  if (gstax < tktrnx_1.tminvx)
    {
      goto L41;
    }
  if (gstax <= tktrnx_1.tmaxvx)
    {
      goto L43;
    }
  q = tktrnx_1.tmaxvx;
  goto L42;
L43:
  if (gstay > tktrnx_1.tmaxvy)
    {
      goto L140;
    }
  if (gstay < tktrnx_1.tminvy)
    {
      goto L44;
    }
  dstax = gstax;
  dstay = gstay;
  goto L150;
L41:
  q = tktrnx_1.tminvx;
L42:
  dstay = gstay + (q - gstax) * b / a;
  if (dstay > tktrnx_1.tmaxvy)
    {
      goto L140;
    }
  if (dstay < tktrnx_1.tminvy)
    {
      goto L44;
    }
  dstax = q;
  goto L150;
L44:
  r__ = tktrnx_1.tminvy;
  goto L45;
L140:
  r__ = tktrnx_1.tmaxvy;
L45:
  dstax = gstax + (r__ - gstay) * a / b;
  if (dstax > tktrnx_1.tmaxvx)
    {
      goto L110;
    }
  if (dstax < tktrnx_1.tminvx)
    {
      goto L110;
    }
  dstay = r__;
L150:
  if (gendx < tktrnx_1.tminvx)
    {
      goto L50;
    }
  if (gendx > tktrnx_1.tmaxvx)
    {
      goto L51;
    }
  if (gendy > tktrnx_1.tmaxvy)
    {
      goto L160;
    }
  if (gendy < tktrnx_1.tminvy)
    {
      goto L52;
    }
  dendx = gendx;
  dendy = gendy;
  goto L120;
L51:
  q = tktrnx_1.tmaxvx;
  goto L53;
L50:
  q = tktrnx_1.tminvx;
L53:
  dendy = gstay + (q - gstax) * b / a;
  if (dendy > tktrnx_1.tmaxvy)
    {
      goto L160;
    }
  if (dendy < tktrnx_1.tminvy)
    {
      goto L52;
    }
  dendx = q;
  goto L120;
L52:
  r__ = tktrnx_1.tminvy;
  goto L60;
L160:
  r__ = tktrnx_1.tmaxvy;
L60:
  dendx = gstax + (r__ - gstay) * a / b;
  dendy = r__;
L120:
  outbf[1] = dstax;
  outbf[2] = dstay;
  outbf[3] = dendx;
  outbf[4] = dendy;
  tktrnx_1.kgnflg = 0;
  goto L70;
/* * SET FLAG IF LINE OUTSIDE WINDOW               00007500 */
L110:
  tktrnx_1.kgnflg = 1;
L70:
  return 0;
}				/* clipt_ */
