CFLAGS = +cpm -SO3 --list --c-code-in-asm  -Wall
DEFF = -DSTATIC -DTYPE2 -DTEK4010 -DDEBUG
all:	tri

tri:
	zcc $(CFLAGS) $(DEFF) -create-app -otri tri.c -m @plot.lst -lmath48

clean:
	$(RM) *.err *.lis *.def *.sym *.exe *.COM tri *.map 

install:
	sudo cp TRI.COM /var/www/html/.
