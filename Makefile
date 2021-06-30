CC = zcc
SHELL = /bin/sh
CFLAGS = +cpm -Wall --list -DCPM  -DSkip_f2c_Undefs -x
CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)

libplot.a: $(OFILES)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

tab:	
	indent $(CFILES)

clean: 
	rm *.o *.lis
