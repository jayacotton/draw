/* hdcopy.f -- translated by f2c (version 20200916).
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

/* Table of constant values */

static integer c__2 = 2;
static integer c__180 = 180;

extern int iowait_(integer *);
extern int toutst_(integer *, integer *);

/* ----------SUBROUTINE--HDCOPY--------------TEKTRONIX, INC.----00014450 */
int hdcopy_(void)
{
    /* Initialized data */

    static integer icode[2] = { 27, 23 };


/* *  OUTPUT (ESC) (ETB) TO START HARD COPY                      00014500 */
    toutst_(&c__2, icode);
    iowait_(&c__180);
    return 0;
}				/* hdcopy_ */
