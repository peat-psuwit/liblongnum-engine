PROG_C = fac-longnum fib longnum_engine-diff longnum_engine-divide  longnum_engine-multiply longnum_engine-sum
PROG_C++ = longnum_engine-multinum-sum

.PHONY : all clean
release debug : $(PROG_C) $(PROG_C++)

debug : LDFLAGS := $(LDFLAGS) -g

$(PROG_C) $(PROG_C++) : CPPFLAGS = -L../library/ -I../library/
$(PROG_C) $(PROG_C++) : LDLIBS = -llongnum_engine

$(PROG_C) $(PROG_C++) : ../library/liblongnum_engine.so

clean :
	-rm $(PROG_C) $(PROG_C++)
