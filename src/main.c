#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cifraso.h"

#define TAMANO 1024

int main (int argc, char *argv[]){
    int llave,opciones;
    char mensaje[100],txtLlave[100];
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
        printf( "1. Cifrado ciclico.\n" );
        printf( "2. Cifrado por contraseña.\n" );
        printf( "3. Cifrado por llave.\n\n" );
        printf( "Ingrese su opcion: " );
        scanf("%d",&opciones);

        switch(opciones){
            case 1:
                printf("ingrese el mensaje a Cifrar: ");
                //captura lo que se escribe un una linea...sirve para capturar los espacios entre palabras.
                scanf("%s",mensaje);
               // characters = getline(&mensaje,&bufsize,stdin);
                printf("ingrese el numero de llave: ");
                scanf("%d",&llave);
                //funcion a utilizar
                cifradoCiclico(mensaje,llave);
                break;
            case 2:
                printf("ingrese el mensaje a Cifrar: ");
                scanf("%s",mensaje);
                printf("ingrese la contraseña: ");
                scanf("%s",txtLlave);
                cifradoContrasena(mensaje,txtLlave);
                break;
            case 3:
                printf("ingrese el mensaje a Cifrar: ");
                scanf("%s",mensaje);
                printf("ingrese la llave: ");
                scanf("%s",txtLlave);
                cifradoAutollave(mensaje,txtLlave);
                break;
            default:
                break;
        }
    } else {
        printf( "Hay argumentos desde consola\n\n" );
        //funcion a utilizar
        //le mandamos el parametro argv[argc-1] para capturar lo  le enviamos por consola
        //parametro argc son en numero de parametros que se han enviado, en un principio sera 1(nombre del ejecutable)
        if(strcmp(argv[argc-1],"-c")==0){
            cifradoCiclico(argv[argc-2],atoi(argv[argc-3]));
        }else if(strcmp(argv[argc-1],"-a")==0){
            cifradoAutollave(argv[argc-2],argv[argc-3]);
        }else if(strcmp(argv[argc-1],"-p")==0){
            cifradoContrasena(argv[argc-2],argv[argc-3]);
        }
        
    }
    return 0;
}