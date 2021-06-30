/* create a cube and rotate it. */

/*
This code was found in the book Graphics Gems.  PG 686
Brian Wyvill seems to be the original coder.

WARNING:  Do not optimize this code.  i.e. no -O3 else it
will not run.

2/15/19 jc

*/

#include <math.h>
#include <stdio.h>
#include "gems.h"
#include "/home/jay/projects/graphics/plot10/c/f2c.h"
#include "/home/jay/projects/graphics/plot10/c/plot.h"

#ifdef STATIC
#undef STATIC
#define STATIC static
#else
#define STATIC
#endif

#define SWAP(a,b)  {a^=b; b^=a; a^=b;}
#define absolute(i,j,k) ((i-j)*(k=((i-j)<0 ? -1 : 1)))

extern void plot (int, int, int);
extern void setpixel (int, int);
extern void DRAW (char);

struct IntPoint3Struct Cube[24] = {
  {0, 100, 100}, {100, 100, 100},
  {100, 0, 100}, {100, 100, 100},
  {0, 0, 100}, {0, 100, 100},
  {0, 0, 100}, {100, 0, 100},

  {0, 0, 100}, {0, 0, 0},
  {0, 100, 100}, {0, 100, 0},
  {100, 0, 100}, {100, 0, 0},
  {100, 100, 100}, {100, 100, 0},

  {0, 100, 0}, {100, 100, 0},
  {100, 0, 0}, {100, 100, 0},
  {0, 0, 0}, {0, 100, 0},
  {0, 0, 0}, {100, 0, 0},
};

#define NCUBE (sizeof (Cube)/sizeof (struct IntPoint3Struct))
void
unity (struct Matrix4Struct *mat)
{
  STATIC int i, j;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      mat->element[i][j] = 0.0;
  mat->element[0][0] = mat->element[1][1] = mat->element[2][2] =
    mat->element[3][3] = 1.0;
}

void
transform (struct Matrix4Struct *mat, struct IntPoint3Struct *Pin,
	   struct IntPoint3Struct *Pout)
{
  STATIC double_t w;
  Pout->x = (Pin->x * mat->element[0][0]) + (Pin->y * mat->element[1][0]) +
    (Pin->z * mat->element[2][0]) + mat->element[3][0];
  Pout->y = (Pin->x * mat->element[0][1]) + (Pin->y * mat->element[1][1]) +
    (Pin->z * mat->element[2][1]) + mat->element[3][1];
  Pout->z = (Pin->x * mat->element[0][2]) + (Pin->y * mat->element[3][2]) +
    (Pin->z * mat->element[2][2]) + mat->element[3][2];
  w = (Pin->x * mat->element[0][3]) + (Pin->y * mat->element[1][3]) +
    (Pin->z * mat->element[2][3]) + mat->element[3][3];
  if (w != 0.0)
    {
      Pout->x /= w;
      Pout->y /= w;
      Pout->z /= w;
    }
}

void
rotate (struct Matrix4Struct *mat, float angle, int axis)
{
  STATIC float rads;
  STATIC float c;

  rads = angle * 3.1415928 / 180.0;
  switch (axis)
    {
    case 1:			/* x axis */
      mat->element[1][1] = c = cosf (rads);
      mat->element[1][2] = sinf (rads);
      mat->element[2][1] = -sinf (rads);
      mat->element[2][2] = c;
      break;
    case 2:			/* y axis */
      mat->element[0][0] = c = cosf (rads);
      mat->element[0][2] = -sinf (rads);
      mat->element[2][0] = sinf (rads);
      mat->element[2][2] = c;
      break;
    case 3:			/* z axis */
      mat->element[0][0] = c = cosf (rads);
      mat->element[0][1] = sinf (rads);
      mat->element[1][0] = -sinf (rads);
      mat->element[1][1] = c;
      break;
    default:
      break;
    }
}

int x1, y1, x2, y2, z1, z2;
void
main ()
{
  STATIC int i, j;
  STATIC char d;
  STATIC float ang;
  STATIC struct IntPoint3Struct *CubePtr, P1, P2;
  STATIC struct Matrix4Struct matrix;
  initt_ (30);
  unity (&matrix);
  ang = 10.0;
  for (j = 0; j < 32; j++)
    {
      CubePtr = &Cube[0];
      erase_ ();
      for (i = 0; i < NCUBE; i += 2)
	{
	  transform (&matrix, CubePtr, &P1);
	  x1 = P1.x;
	  y1 = P1.y;
	  z1 = P1.z;
	  CubePtr++;
	  transform (&matrix, CubePtr, &P2);
	  x2 = P2.x;
	  y2 = P2.y;
	  z2 = P2.z;
	  CubePtr++;
	  x1 += 200;
	  y1 += 200;
	  x2 += 200;
	  y2 += 200;
	  movabs_ (x1, y1);
	  drwabs_ (x2, y2);
	}
      rotate (&matrix, ang, 1);
      rotate (&matrix, ang, 2);
      rotate (&matrix, ang, 3);
      ang += 10.0;
    }
  finitt_ (0, 0);
}

int count;
int
adeout_ (int len, int *buf)
{
  count = len;
  if (count == 0)
    return 0;
  while (count--)
    {
      putchar (*buf++);
    }
  return 0;
}
