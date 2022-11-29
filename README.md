# draw
Drawlines on a 4010 emulator with your z80

The code will build and produce a library "libplot.lib" that can be used to construct drawing
programs on your CP/M machine.  You will need z88dk.

There is a lib directory, do a make -i and ignore the errors.  We only need a few of the
routines in this library, just to lazy to figure out what is needed.  use  z88dk-z80asm -xlibmath.lib *.o
to build a library.

I have built the test/box program with these libraries, and will push a new Makefile asap.

This code was converted from fortran to c.  Thus it is pass by address and not by reference.
I am it the process of 'c'iffing the code.  

DO NOT USE THIS YET.

WRT license.  I found the fortran source on bitsaver, there was no license there, email to
tektronix was not replied to.  I don't think they care about it anymore but, don't build a
project on this code base.
