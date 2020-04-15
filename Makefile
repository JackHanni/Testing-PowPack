###############################################################
## Program:
##     Powder Packing
## Author(s):
##     Kevin Foniciello
## Summary:
##     This simulator will only display all the elements to it.
###############################################################


LFLAGS = -lglut -lGLU -lGL
OBJDIR = ./.makefileObjects

###############################################################
## Build the main Powder Packing simulator
###############################################################
a.out: directories ${OBJDIR}/driver.o ${OBJDIR}/Simulator.o \
                   ${OBJDIR}/Interface.o ${OBJDIR}/uiDraw.o ${OBJDIR}/Point.o \
                   ${OBJDIR}/Camera.o ${OBJDIR}/Checkerboard.o ${OBJDIR}/Sphere.o
	g++ ${OBJDIR}/*.o $(LFLAGS)

###############################################################
## Individual files
##    uiDraw.o       Draw spheres on the screen and do all OpenGL graphics
##    Interface.o    Handles input events
##    Point.o        The position on the screen
##    Simulator.o    Handles the simulator interaction
##    driver.o       Main file that drives the whole programme
##    Camera.o       Handles the camera movement
##    Checkerboard.o Handles the ground / world
##    Sphere.o       Everything about the spheres that are packed
###############################################################
${OBJDIR}/uiDraw.o: src/uiDraw.C include/uiDraw.h
	g++ -c src/uiDraw.C -o $@

${OBJDIR}/Interface.o: src/Interface.C include/Interface.h
	g++ -c src/Interface.C -o $@

${OBJDIR}/Point.o: src/Point.C include/Point.h
	g++ -c src/Point.C -o $@

${OBJDIR}/Simulator.o: include/Simulator.h src/Simulator.C include/uiDraw.h \
                       include/Interface.h include/Point.h
	g++ -c src/Simulator.C -o $@

${OBJDIR}/driver.o: src/driver.C include/Simulator.h include/Interface.h
	g++ -c src/driver.C -o $@

${OBJDIR}/Camera.o: src/Camera.C include/Camera.h
	g++ -c src/Camera.C -o $@

${OBJDIR}/Checkerboard.o: src/Checkerboard.C include/Checkerboard.h
	g++ -c src/Checkerboard.C -o $@

${OBJDIR}/Sphere.o: src/Sphere.C include/Sphere.h
	g++ -c src/Sphere.C -o $@

###############################################################
## General rules
###############################################################
clean:
	@rm ${OBJDIR}/*
	@rm a.out *.o

# Make OBJDIR if needs be
directories:
	@mkdir -p ${OBJDIR}
