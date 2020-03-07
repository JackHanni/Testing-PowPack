###############################################################
# Program:
#     Project 07, Powder Packing
# Author(s):
#     Kevin Foniciello
# Summary:
#     This simulation will only display all the elements to it.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Powder Packing simulator
###############################################################
a.out: driver.o ground.o simulation.o uiInteract.o uiDraw.o point.o lander.o velocity.o Camera.o Checkerboard.o Sphere.o
	g++ driver.o ground.o simulation.o uiInteract.o uiDraw.o point.o lander.o velocity.o Camera.o Checkerboard.o Sphere.o $(LFLAGS)
# 	tar -j -cf powderPacking.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw spheres on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    simulation.o  Handles the simulator interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

simulation.o: simulation.h simulation.cpp uiDraw.h uiInteract.h point.h ground.h
	g++ -c simulation.cpp

driver.o: driver.cpp simulation.h uiInteract.h
	g++ -c driver.cpp

lander.o: lander.cpp lander.h
	g++ -c lander.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

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
	rm a.out *.o *.tar
