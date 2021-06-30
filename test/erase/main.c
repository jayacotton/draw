#include <math.h>
#include <stdio.h>
#include "/home/jay/projects/graphics/plot10/c/f2c.h"
#include "/home/jay/projects/graphics/plot10/c/plot.h"

#include <stdio.h>

/* erase the tek 4010 screen and place it in alpha numeric mode */

extern FILE *ttyout;
int baud = 30;
int zero = 0;
void main ()
{
	initt_(&baud);
	finitt_(&zero,&zero);
}

int adeout_(int *len, int *buf)
{
int count ;
int ch;
	count = *len;
	if(count == 0) return 0;
	while(count--){
		ch = *buf++;
		putc(ch,ttyout);
	}
	return 0;
}
