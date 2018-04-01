#ifndef ImagenBinarizada_H
#define ImagenBinarizada_H
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class ImagenBinarizada
{
    public:
        ImagenBinarizada();
        ImagenBinarizada(int x,int y);
        virtual ~ImagenBinarizada();
        int** matrizBinarizada;
        int x;
        int y;

    protected:

    private:
};

#endif 