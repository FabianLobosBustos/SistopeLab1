#ifndef DatosBmp_H
#define DatosBmp_H
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class DatosBmp
{
    public:
        DatosBmp();
        virtual ~DatosBmp();
      string nombreArchivo;
    	uint32_t size;        /* Tamaño del archivo */
  		uint16_t resv1;       /* Reservado */
  		uint16_t resv2;       /* Reservado */
  	 	uint32_t offset;      /* Offset hasta hasta los datos de imagen */

  		uint32_t headersize;      /* Tamaño de la cabecera */
 		  uint32_t ancho;       /* Ancho */
  		uint32_t alto;      /* Alto */
  		uint16_t planes;          /* Planos de color (Siempre 1) */
  		uint16_t bpp;             /* bits por pixel */
  		uint32_t compress;        /* compresión */
  		uint32_t imgsize;     /* tamaño de los datos de imagen */
    protected:

    private:
};

#endif 