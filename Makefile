DIRS = library demo-program
.PHONY : $(DIRS) all clean

$(DIRS) :
	cd $@ && $(MAKE)

demo-program : library

all : $(DIRS)

clean : 
	for dir in $(DIRS); do cd $$dir && $(MAKE) clean && cd .. || exit $$?; done
