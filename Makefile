DIRS = library demo-program
.PHONY : $(DIRS) all clean

release :

release release-all : BUILD_MODE = release
debug debug-all : BUILD_MODE = debug

all : release-all

release debug : library
release-all debug-all : $(DIRS)

$(DIRS) :
	cd $@ && $(MAKE) $(BUILD_MODE)

demo-program : library

clean : 
	for dir in $(DIRS); do cd $$dir && $(MAKE) clean && cd .. || exit $$?; done
