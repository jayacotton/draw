#ifdef TEK4010
#include <math.h>
#include <stdio.h>
#include "gems.h"
#include "/home/jay/projects/graphics/plot10/c/f2c.h"
#include "/home/jay/projects/graphics/plot10/c/plot.h"
#endif

#define TRACEL(msg) printf("%s %d %s\n",__FILE__,__LINE__,msg);

void main()
{
	initt_(30);
	vwindo_(0.0,8.0,0.0,6.0);
	movea_(1.0,1.0);
	drawa_(1.0,4.0);
	drawa_(4.0,4.0);
	drawa_(4.0,1.0);
	drawa_(1.0,1.0);
	movea_(1.0,1.0);
	drawa_(1.0,4.0);
	drawa_(4.0,4.0);
	drawa_(4.0,1.0);
	drawa_(1.0,1.0);
	pointa_(2.5,2.5);
	finitt_(0,767);
}
int count ;
int adeout_(int len, int *buf)
{
printf("count %d\n",len);
        count = len;
        if(count == 0) 
		return 0;
        while(count--){
                putchar(*buf++);
        }
        return 0;
}

