all : liblongnum_engine

liblongnum_engine : liblongnum_engine.so

liblongnum_engine.so : longnum_engine.o
	c++ -shared -o liblongnum_engine.so longnum_engine.o

longnum_engine.o : longnum_engine.h longnum_engine.cpp
	c++ -c -Wall -Werror -fpic longnum_engine.cpp
