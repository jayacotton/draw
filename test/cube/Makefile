CFLAGS = +rc2014 -subtype=hbios --max-allocs-per-node400000 -DSTATIC -DTYPE2 -DTEK4010 -create-app -Wall -DGCC
MYLIB = /home/jay/projects/graphics/plot10/c
F2CLIB = /home/jay/projects/ftoc/lib/
all: cube

cube:
	zcc $(CFLAGS) -ocube cube.c -m -lm $(MYLIB)/initt.o $(MYLIB)/finitt.o $(MYLIB)/alfmod.o $(MYLIB)/reset.o $(MYLIB)/newpag.o $(MYLIB)/movabs.o $(MYLIB)/tsend.o $(MYLIB)/toutpt.o $(MYLIB)/cwsend.o $(MYLIB)/charsiz.o $(MYLIB)/toutst.o $(MYLIB)/iowait.o $(MYLIB)/vecmod.o $(MYLIB)/xycnvt.o $(MYLIB)/buffpk.o $(MYLIB)/pltchr.o $(F2CLIB)/s_stop.o $(MYLIB)/drwabs.o $(MYLIB)/erase.o $(MYLIB)/recovr.o $(MYLIB)/pntmod.o

clean:
	$(RM) *.err *.lis *.def *.lst *.sym *.exe *.COM cube 
