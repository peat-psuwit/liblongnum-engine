LIBS = liblongnum_engine.so
OBJS = longnum_engine.o
.PHONY : all clean

release debug : $(LIBS)

debug : CPPFLAGS := $(CPPFLAGS) -g
debug : LDFLAGS := $(LDFLAGS) -g

liblongnum_engine.so : $(OBJS)
	$(CC) $(LDFLAGS) -shared -o $@ $(OBJS)

$(OBJS) : CPPFLAGS := $(CPPFLAGS) -fPIC -Wall
$(OBJS) : longnum_engine.h

clean :
	-rm $(LIBS) $(OBJS)
