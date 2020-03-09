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