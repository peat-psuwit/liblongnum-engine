DIRS = library #demo-program
.PHONY : library demo-program all clean

library :
	cd library && $(MAKE)

demo-program :
	cd demo-program && $(MAKE)

all : $(DIRS)

clean : 
	for dir in $(DIRS); do cd $$dir && $(MAKE) clean || exit $$?; done
