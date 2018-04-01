#include <iostream>
#include "DatosBmp.h"
#include "ImagenBmp.h"
#include "ImagenBinarizada.h"
#include "ManejoArchivo.h"
#include "ImagenGrises.h"
using namespace std;

int main()
{
	DatosBmp datosBmp;

	ManejoArchivo manejoArchivo;

	//En primera instancia leemos los datos de la cabecera del archivo BMP
	   //por mientras pedimos el nombre por pantalla
	datosBmp = manejoArchivo.leerDatosBmp();

	//Luego leemos la imagen BMP
	ImagenBmp imagenBmp = manejoArchivo.leerImagenBmp(datosBmp);
	
	//Finalmente tomamos la imagen BMP y la tranformamos a grises
	ImagenGrises imagenGris = manejoArchivo.transformarGrises(imagenBmp);

	//Luego tomamos la imagen y la binarizamos
	ImagenBinarizada imagenBinarizada = manejoArchivo.transformarBinarizada(imagenGris,90);
	
    return 0;
}