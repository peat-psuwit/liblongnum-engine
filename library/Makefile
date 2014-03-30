LIBS = liblongnum_engine.so
OBJS = longnum_engine.o
.PHONY : all clean

all : $(LIBS)

liblongnum_engine.so : $(OBJS)
	c++ -shared -o liblongnum_engine.so $(OBJS)

$(OBJS) : longnum_engine.h $(@:.o=.cpp)
	c++ -c -fPIC -Wall $(@:.o=.cpp)

clean :
	-rm $(LIBS) $(OBJS)
