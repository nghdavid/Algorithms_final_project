main.out:shape.o main.o genetic.o
	g++ -std=c++11 -o main.out shape.o main.o genetic.o 
main.o:shape.h genetic.h main.cpp
	g++ -std=c++11 -c main.cpp
shape.o:shape.h shape.cpp
	g++ -std=c++11 -c shape.cpp
genetic.o:shape.h genetic.h genetic.cpp 
	g++ -std=c++11 -c genetic.cpp

clean:
	rm -rf *.o *.out
