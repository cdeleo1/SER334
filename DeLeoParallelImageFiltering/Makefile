CC=gcc -O3 -Wall
CLIBS= -pthread
	
all: DeLeoBoxBlur
	
time.o: time.c timer.h
	$(CC) -c time.c
	
BMP.o: BMP.c BMP.h
	$(CC) -c BMP.c

%: %.c time.o BMP.o
	$(CC) -o $@ $@.c time.o BMP.o
	
%pt: %pt.c time.o BMP.o
	$(CC) $(CLIBS) -o $@ $@.c time.o BMP.o
	
clean:
	rm -f *.o

distclean: clean
	rm -f *~