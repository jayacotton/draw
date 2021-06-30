CFLAGS = --list --c-code-in-asm  -Wall
MYLIB = /home/jay/projects/graphics/plot10/c
F2CLIB = /home/jay/projects/ftoc/lib/
all:	tri

tri:
	zcc +rc2014 -subtype=hbios -SO3 --max-allocs-per-node400000 $(CFLAGS) -DSTATIC -DTYPE2 -DTEK4010 -create-app -otri tri.c -m -lm @plot10.lst

clean:
	$(RM) *.err *.lis *.def *.sym *.exe *.COM tri 
