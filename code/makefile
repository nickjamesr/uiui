bindir=bin
objdir=obj
srcdir=src
hdir=$(srcdir)/heads

cc=g++
cflags=-c -Wall
lflags=

objs=$(addprefix $(objdir)/,main.o circuit.o)

$(bindir)/go : $(objs)
	$(cc) -o $(bindir)/go $(objs)

$(objdir)/circuit.o : $(srcdir)/circuit.cc $(hdir)/circuit.h
	$(cc) $(cflags) -o $(objdir)/circuit.o $(srcdir)/circuit.cc

$(objdir)/main.o : $(srcdir)/main.cc
	$(cc) $(cflags) -o $(objdir)/main.o $(srcdir)/main.cc

