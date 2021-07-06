#include <math.h>
#include <stdio.h>
#include "../../f2c.h"
#include "../../plot.h"

float x[10] = { 1.,2.,3.,4.,5.,6.,7.,8.,9.,10. };
float y[10] = { 30.,26.,42.,38.,40.,50.,54.,48.,40.,52. };

void grafit()
{
    integer i;
    movea(x[0], y[0]);
    for (i = 0; i < 10; i++) {
	drawa(x[i], y[i]);
    }
    movea(0. , 20.);
    drawa(10., 20.);
    drawa(10., 60.);
    drawa(0. , 60.);
    drawa(0. , 20.);
}

void main()
{
    initt_(30);
	dwindo(.0, 10., 20., 60.);
	twindo(0, 200, 550, 700);
	grafit();
	twindo(300, 900, 550, 700);
	grafit();
	twindo(0, 200, 0, 450);
	grafit();
	twindo(300, 900, 0, 450);
	grafit();
    finitt_(0, 767);
}
