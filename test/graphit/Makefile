CFLAGS = --list --c-code-in-asm  -Wall
MYLIB = /home/jay/projects/graphics/plot10/c
F2CLIB = /home/jay/projects/ftoc/lib/
all:	graphit

graphit:
	zcc +rc2014 -subtype=hbios -SO3 --max-allocs-per-node400000 $(CFLAGS) -DSTATIC -DTYPE2 -DTEK4010 -create-app -ographit graphit.c -m -lm $(MYLIB)/initt.o $(MYLIB)/finitt.o $(MYLIB)/alfmod.o $(MYLIB)/reset.o $(MYLIB)/newpag.o $(MYLIB)/movabs.o $(MYLIB)/tsend.o $(MYLIB)/toutpt.o $(MYLIB)/cwsend.o $(MYLIB)/charsiz.o $(MYLIB)/toutst.o $(MYLIB)/iowait.o $(MYLIB)/vecmod.o $(MYLIB)/xycnvt.o $(MYLIB)/buffpk.o $(MYLIB)/pltchr.o $(F2CLIB)/s_stop.o $(MYLIB)/drwabs.o $(MYLIB)/erase.o $(MYLIB)/recovr.o $(MYLIB)/pntmod.o $(MYLIB)/vwindo.o $(MYLIB)/movea.o $(MYLIB)/drawa.o $(MYLIB)/pointa.o $(MYLIB)/rescal.o $(MYLIB)/lvlcht.o $(MYLIB)/v2st.o $(MYLIB)/tkpnt.o $(MYLIB)/pscal.o $(MYLIB)/revcot.o $(MYLIB)/clipt.o $(MYLIB)/wincot.o $(MYLIB)/pclipt.o $(MYLIB)/parclt.o $(F2CLIB)/pow_dd.o $(F2CLIB)/r_sign.o $(F2CLIB)/r_mod.o $(MYLIB)/twindo.o $(MYLIB)/dwindo.o

clean:
	$(RM) *.err *.lis *.def *.lst *.sym *.exe *.COM cube 
