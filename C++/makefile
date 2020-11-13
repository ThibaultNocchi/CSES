BINDIR=bin
OUT_CPP=$(patsubst %, $(BINDIR)/%, $(patsubst %.cpp, %.out, $(wildcard *.cpp)))

.PHONY=clear

#Tell make to make one .out file for each .cpp file found in the current directory
all: $(OUT_CPP)

#Rule how to create arbitary .out files.
#First state what is needed for them e.g. additional headers, .cpp files in an include folder...
#Then the command to create the .out file, probably you want to add further options to the g++ call.
$(BINDIR)/%.out: %.cpp
	@mkdir -p $(BINDIR)
	g++ -g $< -o $@

clear:
	rm -r $(BINDIR)
