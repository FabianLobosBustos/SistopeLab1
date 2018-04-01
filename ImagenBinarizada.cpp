#include "ImagenBinarizada.h"



ImagenBinarizada::ImagenBinarizada()
{

}

ImagenBinarizada::ImagenBinarizada(int x, int y)
{
	this->matrizBinarizada = (int**) malloc(x * sizeof(int*));
	int i;
    for(i = 0; i<y; i++) {
        this->matrizBinarizada[i] = (int*) malloc(y*  sizeof(int));
    }

    this->x=x;
    this->y=y;
}

ImagenBinarizada::~ImagenBinarizada()
{
    //dtor
}