##**************************************
## Makefile
##
## Build routine for lang compiler
##
## Author: Phil Howard 
## phil.howard@oit.edu
##
## Date: Jan. 18, 2015
##
TAR_FILE=lab4_jiawei_xu.tar
COPTS=-Wall -g -c  -O0 -std=c++11
OBJS=main.o \
	 langlex.o \
	 cSymbolTable.o \
	 langparse.o \
	 cVisitor.o

all: lang

clean:
	rm -f $(OBJS)
	rm -f langlex.c
	rm -f langparse.c
	rm -f langparse.h
	rm -f lang
	rm -f out.xml
	rm -f out2.xml
	rm -f $(TAR_FILE)
	
.cpp.o:
	g++ $(COPTS) $? -o $@

.c.o:
	g++ $(COPTS) $? -o $@

main.o: main.cpp langparse.c langlex.c 
	g++ $(COPTS) main.cpp -o $@

langlex.o: langlex.c
	g++ $(COPTS) -Wno-sign-compare $? -o $@

langlex.c: lang.l langparse.c
	flex -o langlex.c lang.l

langparse.c: lang.y
	bison --defines=langparse.h lang.y -o langparse.c

cSymbolTable.o: cSymbolTable.cpp
	g++ $(COPTS) -Wno-sign-compare $? -o $@

lang: $(OBJS)
	g++ $(OBJS) -o lang

tar:
	rm -rf $(TAR_FILE)
	tar -cf $(TAR_FILE) *.h *.cpp *.md *.l *.y [Mm]akefile test
	
trans: tar
	scp $(TAR_FILE) jiawei.xu@unix.cset.oit.edu:~/Classes/CST320

t:
	./lang test/test6.lang