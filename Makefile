all : liblongnum_engine

liblongnum_engine : liblongnum_engine.so

liblongnum_engine.so : longnum_engine.o
	cc -shared -o liblongnum_engine.so longnum_engine.o

longnum_engine.o : longnum_engine.cpp
	cc -c -Wall -Werror -fpic longnum_engine.cpp
