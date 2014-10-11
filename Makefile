
OUTFILE=raytracer
CFLAGS=-Wall -g 
LFLAGS=-g -rdynamic
LIBS=-lSDL

OBJECTS= \
	main.o \
	application.o \
	window.o \
	vector3.o \
	camera.o \
	film.o


all: $(OBJECTS)
	g++ -g $(OBJECTS) $(LFLAGS) -o $(OUTFILE) $(LIBS)

.cc.o:
	g++ $< -c $(CFLAGS) -o $@

tags: FORCE
	ctags *.cc *.hh

clean:
	rm -rf $(OBJECTS) $(OUTFILE)

FORCE:

