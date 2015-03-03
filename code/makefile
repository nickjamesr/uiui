bindir=bin
objdir=obj
srcdir=src
hdir=$(srcdir)/heads

cc=g++
cflags=-c -Wall
lflags=

objs=$(addprefix $(objdir)/,main.o circuit.o estimator.o sampler.o)

$(bindir)/go : $(objs)
	$(cc) -o $(bindir)/go $(objs)

$(objdir)/%.o : $(srcdir)/%.cc $(hdir)/%.h
	$(cc) $(cflags) -o $@ $<

$(objdir)/main.o : $(srcdir)/main.cc
	$(cc) $(cflags) -o $(objdir)/main.o $(srcdir)/main.cc

