#include "ManejoArchivo.h"



ManejoArchivo::ManejoArchivo()
{

}

ManejoArchivo::~ManejoArchivo()
{
    //dtor
}

//Leer datos Bmp lee la cabecera de un archivo BMP
 //por el momento pide el nombre por pantalla
DatosBmp ManejoArchivo::leerDatosBmp(){

	cout<<"Ingrese nombre del archivo (con extension .bmp)"<<endl;
	string nombre;
	cin>>nombre;

	DatosBmp datosBmp;
	FILE *f;
	
    const char *nombre_char = nombre.c_str();
    datosBmp.nombreArchivo = nombre;

    uint16_t type;        /* 2 bytes identificativos */

  	f=fopen (nombre_char, "r");
  	if (!f){
  		cout<<"No se ha podido abrir el archivo"<<endl;
    	return datosBmp;        /* Si no podemos leer, no hay imagen*/
  	}
  	/* Leemos los dos primeros bytes */

  	fread(&type, sizeof(uint16_t), 1, f);
  	if (type !=0x4D42)        /* Comprobamos el formato */
    {
      cout<<"El archivo no es BMP"<<endl;
      fclose(f);
      return datosBmp;
    }


  	//Leemos el tamaño
  	fread(&(datosBmp.size), sizeof(uint32_t), 1, f);
  	
  	//Leemos ambos reservados
  	fread(&(datosBmp.resv1), sizeof(uint16_t), 1, f);
  	fread(&(datosBmp.resv2), sizeof(uint16_t), 1, f);

  	//Leemos el offset
  	fread(&(datosBmp.offset), sizeof(uint32_t), 1, f);

  	//Leemos el headersize
  	fread(&(datosBmp.headersize), sizeof(uint32_t), 1, f);

  	//Leemos el ancho y alto
  	fread(&(datosBmp.ancho), sizeof(uint32_t), 1, f);
  	fread(&(datosBmp.alto), sizeof(uint32_t), 1, f);

  	//Leemos el planes
  	fread(&(datosBmp.planes), sizeof(uint16_t), 1, f);
 
 	//Leemos el bpp
 	fread(&(datosBmp.bpp), sizeof(uint16_t), 1, f);

 	//Leemos la compresion
 	fread(&(datosBmp.compress), sizeof(uint32_t), 1, f);

 	//Leemos el tamaño de imagen
 	fread(&(datosBmp.imgsize), sizeof(uint32_t), 1, f);


  	/* Cerramos */
  	fclose(f);

  /* Devolvemos la imagen */
 	return datosBmp;
}

//LeerImagenBmp nos permite que pasandole los datos podamos
// extraer el array de bytes de la imagen BMP, en sintesis, extraemos
// la imagen BMP a traves de los datos de la cabecera de la misma.
  
  //OJO!!! ACA SE VUELVE A ABRIR EL FLUJO DE INFORMACION,
 // SE REALIZA A TRAVES DEL NOMBRE.
ImagenBmp ManejoArchivo::leerImagenBmp(DatosBmp datosBmp){
	FILE *j;
	ImagenBmp imagenBmp;


	const char *nombre_char = datosBmp.nombreArchivo.c_str();
	
	j=fopen(nombre_char, "r");
	if (!j){
  		cout<<"No se ha podido abrir el archivo"<<endl;
    	return imagenBmp;        /* Si no podemos leer, no hay imagen*/
  	}
	
    imagenBmp.pixelesImagenBmp = (unsigned char*)malloc(datosBmp.imgsize);
    
    /* Nos situamos en el sitio donde empiezan los datos de imagen,
    nos lo indica el offset de la cabecera de fichero*/
    fseek(j, datosBmp.offset, SEEK_SET);
  
    /* Leemos los datos de imagen, tantos bytes como imgsize */
    fread(imagenBmp.pixelesImagenBmp, datosBmp.imgsize,1, j);

    /* Cerramos */
    fclose(j);
    imagenBmp.x=datosBmp.ancho;
    imagenBmp.y=datosBmp.alto;

  /* Devolvemos la imagen */
  	return imagenBmp;
}



//TranformarGrises recibe una imagen BMP, y retorna su equivalente en grises
 //Basicamente esta funcion aplica la funcion de luminisencia, y a partir de una imagen
 // bmp retorna una imagen en escala de grises
ImagenGrises ManejoArchivo::transformarGrises(ImagenBmp imagenBmp){
  ImagenGrises imagenGrises(imagenBmp.x ,imagenBmp.y);
  int y,x;
    /* Dibujamos la imagen */
  for (y= imagenBmp.y; y>0; y = y-1)
    {
      for (x=0; x<imagenBmp.x; x = x +1)
    {
      /*
      b=(img[3*(x+y*info->width)]>umbral);
      g=(img[3*(x+y*info->width)+1]>umbral);
      r=(img[3*(x+y*info->width)+2]>umbral);
      */

      float red = (imagenBmp.pixelesImagenBmp[3*(x+y*imagenBmp.x)+2])*0.3;
      float green = (imagenBmp.pixelesImagenBmp[3*(x+y*imagenBmp.x)+1])*0.59;
      float blue = (imagenBmp.pixelesImagenBmp[3*(x+y*imagenBmp.x)] )*0.11;

      float Y = red + green + blue;

      imagenGrises.matrizGrises[x][imagenBmp.y - y]= Y; 


    }
      
  }

  cout<<"creo que termino..."<<endl;
  return imagenGrises;

}


//A partir de la imagen en escala de grises y el umbral, creo una imagen binarizada.
ImagenBinarizada ManejoArchivo::transformarBinarizada(ImagenGrises imagenGrises, int umbral){
  ImagenBinarizada imagenBinarizada(imagenGrises.x,imagenGrises.y);

  for (int i = 0; i < imagenBinarizada.x; ++i)
  {
    for (int j = 0; j < imagenBinarizada.y; ++j)
    {
      if (imagenGrises.matrizGrises[i][j]>umbral)
      {
        imagenBinarizada.matrizBinarizada[i][j]=1;
      }
      else{
        imagenBinarizada.matrizBinarizada[i][j]=0;
      }
      cout<<imagenBinarizada.matrizBinarizada[i][j];
    }
    cout<<endl;
  }

  return imagenBinarizada;
}