#ifndef ImagenBmp_H
#define ImagenBmp_H
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class ImagenBmp
{
    public:
        ImagenBmp();
        virtual ~ImagenBmp();
        unsigned char* pixelesImagenBmp;
        int x;
        int y;


    protected:

    private:
};

#endif 