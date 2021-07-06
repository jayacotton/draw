CFLAGS = +cpm -SO3 --list --c-code-in-asm  -Wall
DEFF = -DSTATIC -DTYPE2 -DTEK4010 -DDEBUG
all:	graphit

graphit:
	zcc $(CFLAGS) $(DEFF) -create-app -ographit graphit.c -m @plot.lst -lmath48

clean:
	$(RM) *.err *.lis *.def *.sym *.exe *.COM graphit *.map 

install:
	sudo cp GRAPHIT.COM /var/www/html/.
