#**************************************
# Makefile
#
# Makefile for lang compiler
#
# Author: Phil Howard 
# phil.howard@oit.edu
#
# Date: Jan. 12, 2016
#
TAR_FILE=lab3_jiawei_xu.tar
COPTS=-Wall -g -c -O0 -std=c++11
OBJS=main.o \
	 langlex.o \
	 cSymbolTable.o \
	 utils.o \
	 parse.o \

all: lang

clean:
	rm -f $(OBJS)
	rm -f *.o
	rm -f langlex.c
	rm -f lang
	rm -f out.xml
	rm -f out2.xml
	rm -f out

.c.o:
	g++ $(COPTS) $? -o $@

.cpp.o:
	g++ $(COPTS) $? -o $@

main.o: main.cpp langlex.c
	g++ $(COPTS) main.cpp -o main.o

langlex.c: lang.l
	flex -o langlex.c lang.l

langlex.o: langlex.c
	g++ $(COPTS) -Wno-sign-compare $? -o $@

lang: $(OBJS)
	g++ $(OBJS) -o lang

cSymbolTable.o: cSymbolTable.cpp
	g++ $(COPTS) -Wno-sign-compare $? -o $@

utils.o: utils.cpp
	g++ $(COPTS) -Wno-sign-compare $? -o $@

parse.o: parse.cpp
	g++ $(COPTS) -Wno-sign-compare $? -o $@

tar:
	rm -rf $(TAR_FILE)
	tar -cvf $(TAR_FILE) *.h *.cpp *.md *.l [Mm]akefile
