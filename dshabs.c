/* dshabs.f -- translated by f2c (version 20200916).
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
extern int dshmod_(integer *);
extern int tkdash_(integer *, integer *);

/* ----------SUBROUTINE--DSHABS-----------TEKTRONIX, INC.----00004890 */
int dshabs_(integer * ix, integer * iy, integer * l)
{

    dshmod_(l);
    tkdash_(ix, iy);
/* * SET THE GRAPHIC LEVEL FLAG TO SCREEN */
    tktrnx_1.kgrafl = 0;
    return 0;
}				/* dshabs_ */
