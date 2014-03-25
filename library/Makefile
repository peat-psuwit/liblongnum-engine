LIBS = liblongnum_engine.so
OBJS = longnum_engine.o
.PHONY : all clean

all : $(LIBS)

liblongnum_engine.so : longnum_engine.o
	c++ -shared -o liblongnum_engine.so longnum_engine.o

longnum_engine.o : longnum_engine.h longnum_engine.cpp
	c++ -c -Wall -Werror -fpic longnum_engine.cpp

clean :
	-rm $(LIBS) $(OBJS)
