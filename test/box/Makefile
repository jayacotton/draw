CFLAGS = +cpm -SO3 --list --c-code-in-asm  -Wall
DEFF = -DSTATIC -DTYPE2 -DTEK4010 -DDEBUG
all:	box

box:
	zcc $(CFLAGS) $(DEFF) -create-app -m -obox box.c -lmath48 -L../../ -L../../lib -llibplot.lib -llibmath.lib

clean:
	$(RM) *.err *.lis *.def *.sym *.exe *.COM box *.map 

install:
	sudo cp BOX.COM /var/www/html/.
