LFLAGS = -lGL -lGLU -lglut -lm

a.out: balls.o Point.o Camera.o
	g++ balls.o Point.o Camera.o $(LFLAGS)

balls.o: balls.cpp
	g++ -c balls.cpp $(LFLAGS)

Camera.o: Camera.cpp
	g++ -c Camera.cpp $(LFLAGS)

Point.o: Point.cpp
	g++ -c Point.cpp

Ball.o: Ball.cpp
	g++ -c Ball.cpp

clean:
	rm a.out *.o

# a.out: driver.o Ball.o Point.o Checkerboard.o Camera.o
# 	g++ driver.o Ball.o Point.o Checkerboard.o Camera.o $(LFLAGS)
#
# driver.o: driver.cpp
# 	g++ -c driver.cpp $(LFLAGS)
#
# Ball.o: Ball.cpp
# 	g++ -c Ball.cpp $(LFLAGS)
#
# Point.o: Point.cpp
# 	g++ -c Point.cpp
#
# Checkerboard.o: Checkerboard.cpp
# 	g++ -c Checkerboard.cpp $(LFLAGS)
#
# Camera.o: Camera.cpp
# 	g++ -c Camera.cpp $(LFLAGS)
#
# clean:
# 	rm a.out *.o