#this is a generic makefile to compile only one cpp file(for now i am creating one cpp for each practice example. make file will be changed if build requires multiple files)
#to compile a file use this command
#make -f makefile.mak FILE=<filename>

CC=g++
CPPFLAGS=-g
FILE=none
OBJDIR=./obj

vpath %.cpp ./src

all: out

out: $(OBJDIR)/$(FILE).o 
	$(CC) -o $@ $^ 

$(OBJDIR)/$(FILE).o: $(FILE).cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f out $(OBJDIR)/$(FILE).o

