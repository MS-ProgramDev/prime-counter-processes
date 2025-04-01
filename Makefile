# Makefile for ex1_q1 winter 2025A

CFLAGS   = -Wall -std=c99
LDFLAGS  = -lm
CC       = gcc
ECHO     = @echo "-->going to build target $@ (dependent on $^)"

PROGS = count_primes ex1_q1

all: $(PROGS) test

my_libary_fun.o: my_libary_fun.c my_libary_fun.h
	$(ECHO)
	$(CC) $^ $(CFLAGS) -c

count_primes: count_primes.c my_libary_fun.h my_libary_fun.o
	$(ECHO)
	$(CC) $^ $(CFLAGS)  $(LDFLAGS) -o $@

ex1_q1: ex1_q1.c my_libary_fun.h my_libary_fun.o
	$(ECHO)
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@


clean:
	rm -vf *.o ${PROGS} *.log *.err *.out

test: $(PROGS)
	@echo test1\: running \"./count_primes 10 20 1\> test1.out 2\> test1.err\"
	-./count_primes 10 20 1> test1.out 2> test1.err
	cat test1.out
	@echo    
	-./ex1_q1 single 20 10 1> test2.out 2> test2.err
	@echo  
	cat test2.out
	-./ex1_q1 child 50 10 200 1> test3.out 2> test3.err
	cat test3.out

