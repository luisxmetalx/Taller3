#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cifraso.h>
#include <codificacion.h>

#define TAMANO 1024

//using namespace std;

//funciones
void cifradoCiclico(char frase[], int llave);
void codigoMorse (char mensaje[]);

int main (int argc, char *argv[]){
    int llave,tam,i;
    char *mensaje;
    size_t bufsize = TAMANO;
    size_t characters;
    //Inicializacion del puntero..dandole memoria dinamica
    mensaje = (char *)malloc(bufsize * sizeof(char));
    if( mensaje == NULL)
    {
        perror("Unable to allocate mensaje");
        exit(1);
    }
    printf("\n********************************\n");
    printf("********Cifrado Ciclico*********\n");
    printf("********************************\n");
    printf("\n");

    //prueba si hay algun argumento enviado por consola
    if ( argc == 1 ) {
        printf( "No Hay argumentos desde consola.\n\n" );
        printf("ingrese el mensaje a Cifrar: ");
        //captura lo que se escribe un una linea...sirve para capturar los espacios entre palabras.
        characters = getline(&mensaje,&bufsize,stdin);
        printf("ingrese el numero de llave: ");
        scanf("%d",&llave);
        //funcion a utilizar
        cifradoCiclico(mensaje,llave);
    } else {
        printf( "Hay argumentos desde consola\n\n" );
        //funcion a utilizar
        //le mandamos el parametro argv[argc-1] para capturar lo  le enviamos por consola
        //parametro argc son en numero de parametros que se han enviado, en un principio sera 1(nombre del ejecutable)
        cifradoCiclico(argv[argc-1],atoi(argv[argc-2]));
        printf("\n");
        
    }
    return 0;
}