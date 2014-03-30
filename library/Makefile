LIBS = liblongnum_engine.so
OBJS = longnum_engine.o
.PHONY : all clean

all : $(LIBS)

liblongnum_engine.so : $(OBJS)
	c++ -shared -o liblongnum_engine.so $(OBJS)

%.o : %.cpp longnum_engine.h
	c++ -c -fPIC -Wall $<

clean :
	-rm $(LIBS) $(OBJS)
