FLAGS=-Wall -g -std=c++11

all: DatosBmp.o ImagenBinarizada.o ImagenBmp.o ManejoArchivo.o ImagenGrises.o main.cpp
	g++ $(FLAGS) main.cpp DatosBmp.o ImagenBinarizada.o ImagenBmp.o ManejoArchivo.o ImagenGrises.o -o programaBMP

DatosBmp.o: DatosBmp.cpp DatosBmp.h
	g++ $(FLAGS) -c DatosBmp.cpp -o DatosBmp.o

ImagenBinarizada.o: ImagenBinarizada.cpp ImagenBinarizada.h
	g++ $(FLAGS) -c ImagenBinarizada.cpp -o ImagenBinarizada.o

ImagenBmp.o: ImagenBmp.cpp ImagenBmp.h
	g++ $(FLAGS) -c ImagenBmp.cpp -o ImagenBmp.o

ManejoArchivo.o: ManejoArchivo.cpp ManejoArchivo.h
	g++ $(FLAGS) -c ManejoArchivo.cpp -o ManejoArchivo.o

ImagenGrises.o: ImagenGrises.cpp ImagenGrises.h
	g++ $(FLAGS) -c ImagenGrises.cpp -o ImagenGrises.o
