#include <math.h>
#include <stdio.h>
#include "/home/jay/projects/graphics/plot10/c/f2c.h"
#include "/home/jay/projects/graphics/plot10/c/plot.h"

float f_0 = 0.0;
float f_10 = 10.0;
float f_20 = 20.0;
float f_60 = 60.0;

int int_zero 		= 0;
int int_767 		= 767;
int int_30		= 30;
int i_0 = 0;
int i_10 = 10;
int i_200 = 200;
int i_300 = 300;
int i_450 = 450;
int i_550 = 550;
int i_700 = 700;
int i_900 = 900;

float x[10] = {1.,2.,3.,4.,5.,6.,7.,8.,9.,10};
float y[10] = {30.,26.,42.,38.,40.,50.,54.,48.,40.,52.};
void grafit()
{
int i;
	movea_(&x[0],&y[0]);
	for(i = 1;i<10;i++){
		drawa_(&x[i],&y[i]);	
	}
	movea_(&f_0,&f_20);
	drawa_(&f_10,&f_20);
	drawa_(&f_10,&f_60);
	drawa_(&f_0,&f_60);
	drawa_(&f_0,&f_20);
}
void main()
{
int i;
	initt_(&int_30);
	for(i=0;i<3;i++){
	dwindo_(&f_0,&f_10,&f_20,&f_60);
	twindo_(&i_0,&i_200,&i_550,&i_700);
	grafit();
	twindo_(&i_300,&i_900,&i_550,&i_700);
	grafit();
	twindo_(&i_0,&i_200,&i_0,&i_450);
	grafit();
	twindo_(&i_300,&i_900,&i_0,&i_450);
	grafit();
	}	
	finitt_(&int_zero,&int_767);
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

