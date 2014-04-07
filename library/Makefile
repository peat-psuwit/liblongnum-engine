LIBS = liblongnum_engine.so
OBJS = longnum_engine.o
.PHONY : all clean

all : $(LIBS)

liblongnum_engine.so : $(OBJS)
	$(CXX) $(LDFLAGS) -shared -o $@ $(OBJS)

$(OBJS) : CPPFLAGS = -fPIC -Wall

clean :
	-rm $(LIBS) $(OBJS)
