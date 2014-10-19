
OUTFILE=raytracer
CFLAGS=-Wall -g 
LFLAGS=-g -rdynamic
LIBS=-lSDL -lm

OBJECTS= \
	main.o \
	application.o \
	window.o \
	vector3.o \
	camera.o \
	film.o \
	ray.o \
	sphere.o \
	plane.o \
	scene.o \
	scene-object.o \
	material.o


all: $(OBJECTS)
	g++ -g $(OBJECTS) $(LFLAGS) -o $(OUTFILE) $(LIBS)

.cc.o:
	g++ $< -c $(CFLAGS) -o $@

tags: FORCE
	ctags *.cc *.hh

clean:
	rm -rf $(OBJECTS) $(OUTFILE)

FORCE:

