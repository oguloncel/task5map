LINK_TARGET = rtcut
VPATH = .

all : rtcut

rtcut : nominal.o mymap.o
	g++ -std=c++1y rtcut.cpp nominal.o mymap.o -o rtcut `root-config --cflags --glibs` -O2 -march=native

nominal.o : nominal.C
	g++ -std=c++1y -c nominal.C -o nominal.o `root-config --cflags --glibs`

mymap.o : mymap.cc
	g++ -std=c++1y -c mymap.cc -o mymap.o `root-config --cflags --glibs`

clean:
	rm rtcut nominal.o my map.o

