/* seetrm.f -- translated by f2c (version 20200916).
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

/* Common Block Declarations */


#define tktrnx_1 tktrnx_

/* ----------SUBROUTINE--SEETRM----------TEKTRONIX, INC.----00000400 */
int
seetrm_(integer * ibaudr, integer * iterm, integer * icsize,
	integer * maxscr)
{
    *ibaudr = tktrnx_1.kbaudr;
    *iterm = tktrnx_1.kterm;
    *icsize = tktrnx_1.ksizef;
    *maxscr = 4095 / tktrnx_1.kfactr;
    return 0;
}				/* seetrm_ */
