###############################################################
# Program:
#     Powder Packing
# Author(s):
#     Kevin Foniciello
# Summary:
#     This simulator will only display all the elements to it.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Powder Packing simulator
###############################################################
a.out: driver.o simulator.o uiInteract.o uiDraw.o point.o Camera.o Checkerboard.o Sphere.o
	g++ driver.o simulator.o uiInteract.o uiDraw.o point.o Camera.o Checkerboard.o Sphere.o $(LFLAGS)
# 	tar -j -cf powderPacking.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw spheres on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    simulator.o  Handles the simulator interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

simulator.o: simulator.h simulator.cpp uiDraw.h uiInteract.h point.h
	g++ -c simulator.cpp

driver.o: driver.cpp simulator.h uiInteract.h
	g++ -c driver.cpp

Camera.o: Camera.cpp Camera.h
	g++ -c Camera.cpp

Checkerboard.o: Checkerboard.cpp Checkerboard.h
	g++ -c Checkerboard.cpp

Sphere.o: Sphere.cpp Sphere.h
	g++ -c Sphere.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
