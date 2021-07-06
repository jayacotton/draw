
#include "f2c.h"

extern int tsend_(void);
extern int alfmod_(void);
extern int movabs_(integer *, integer *);
extern int s_stop(char *, ftnlen);

int finitt_(integer *ix, integer *iy)
{
    /* Builtin functions */

    movabs_(ix, iy);
    alfmod_();
    tsend_();
    s_stop("", (ftnlen) 0);
    return 0;
}				/* finitt_ */

int finitt(int x,int y)
{
int ix,iy;

	ix = x;
	iy = y;

	return(finitt_(&ix,&iy));
}
