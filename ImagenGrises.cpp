#include "ImagenGrises.h"



ImagenGrises::ImagenGrises()
{

}

ImagenGrises::ImagenGrises(int x, int y)
{
	this->matrizGrises = (float**) malloc(x * sizeof(float*));
	int i;
    for(i = 0; i<y; i++) {
        this->matrizGrises[i] = (float*) malloc(y*  sizeof(float));
    }

    this->x=x;
    this->y=y;
}

ImagenGrises::~ImagenGrises()
{
    //dtor
}

