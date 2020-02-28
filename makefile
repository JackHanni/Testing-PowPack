LFLAGS = -lGL -lGLU -lglut -lm

a.out: balls.o
	g++ balls.cpp $(LFLAGS)

balls.o: balls.cpp
	g++ -c balls.cpp

clean:
	rm a.out *.o