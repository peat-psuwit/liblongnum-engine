PROG_C = fac-longnum fib longnum_engine-diff longnum_engine-divide  longnum_engine-multiply longnum_engine-sum
PROG_C++ = longnum_engine-multinum-sum

.PHONY : all clean
all : $(PROG_C) $(PROG_C++)

$(PROG_C) : ../library/liblongnum_engine.so
	cc -L../library/ -I../library/ -o $@ $@.c -llongnum_engine

$(PROG_C++) : ../library/liblongnum_engine.so
	c++ -L../library/ -I../library/ -o $@ $@.cpp -llongnum_engine

clean :
	-rm $(PROG_C) $(PROG_C++)