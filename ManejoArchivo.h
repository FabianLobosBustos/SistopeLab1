#ifndef ManejoArchivo_H
#define ManejoArchivo_H
#include <iostream>
#include <fstream>
#include <vector>
#include "DatosBmp.h"
#include "ImagenBmp.h"
#include "ImagenBinarizada.h"
#include "ImagenGrises.h"


using namespace std;

class ManejoArchivo
{
    public:
        ManejoArchivo();
        virtual ~ManejoArchivo();
        DatosBmp leerDatosBmp();
        ImagenBmp leerImagenBmp(DatosBmp datosBmp);

        ImagenGrises transformarGrises(ImagenBmp imagenBmp);

        ImagenBinarizada transformarBinarizada(ImagenGrises imagenGrises, int umbral);

    protected:

    private:
};

#endif 