#include <math.h>
#include <stdio.h>
#include "gems.h"
#include "/home/jay/projects/graphics/plot10/c/f2c.h"
#include "/home/jay/projects/graphics/plot10/c/plot.h"

void main()
{
	initt_ (30);
	movabs_(100,100);
	drwabs_(300,100);
	drwabs_(200,187);
	drwabs_(100,100);
	finitt_(0  ,768);
}
int count ;
int adeout_(int len, int *buf)
{
        count = len;
printf("count %d\n",count);
        if(count == 0) 
		return 0;
        while(count--){
                putchar(*buf++);
        }
        return 0;
}

