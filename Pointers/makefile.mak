#this is a generic makefile to compile only one cpp file(for now i am creating one cpp for each practice example. make file will be changed if build requires multiple files)
#to compile a file use this command
#make -f makefile.mak file=<filename>

CC=g++
CPPFLAGS=-g
file=none
OBJDIR=./obj

vpath %.cpp ./src

all: out

out: $(OBJDIR)/$(file).o 
	$(CC) -o $@ $^ 

$(OBJDIR)/$(file).o: $(file).cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f out $(OBJDIR)/$(file).o

cleanall:
	rm -f out $(OBJDIR)/*.o

