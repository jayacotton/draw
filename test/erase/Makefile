CFLAGS = --list --c-code-in-asm  -Wall 
MYLIB = /home/jay/projects/graphics/plot10/c
F2CLIB = /home/jay/projects/ftoc/lib/
all:	erase

erase:	main.c
	zcc +rc2014 -subtype=hbios -create-app $(CFLAGS) -oerase main.c -lmath32 $(MYLIB)/initt.o $(MYLIB)/finitt.o $(MYLIB)/alfmod.o $(MYLIB)/reset.o $(MYLIB)/newpag.o $(MYLIB)/movabs.o $(MYLIB)/tsend.o $(MYLIB)/toutpt.o $(MYLIB)/cwsend.o $(MYLIB)/charsiz.o $(MYLIB)/toutst.o $(MYLIB)/iowait.o $(MYLIB)/vecmod.o $(MYLIB)/xycnvt.o $(MYLIB)/buffpk.o $(MYLIB)/pltchr.o $(F2CLIB)/s_stop.o
