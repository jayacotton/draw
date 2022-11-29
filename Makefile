CC = zcc
SHELL = /bin/sh
#CFLAGS = +cpm -Wall --list --c-code-in-asm -DCPM  -DSkip_f2c_Undefs -x
CFLAGS = +cpm -Wall -DCPM  -DSkip_f2c_Undefs -x
CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)

libplot.lib: $(OFILES)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

lib:	$(OFILES)
	z88dk-z80asm -x=libplot.lib *.o
	
tab:	
	indent $(CFILES)

clean: 
	rm *.o *.lis
