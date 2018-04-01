#ifndef ImagenGrises_H
#define ImagenGrises_H
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class ImagenGrises
{
    public:
        ImagenGrises();
        ImagenGrises(int largo, int ancho);
        virtual ~ImagenGrises();

        float** matrizGrises;
        int x;
        int y;


    protected:

    private:
};

#endif 