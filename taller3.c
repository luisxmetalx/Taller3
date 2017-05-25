#include <stdio.h>
#include <stdlib.h>

#define TAMANO 1024

//using namespace std;

//funciones
void cifradoCiclico(char frase[], int llave);
void codigoMorse (char mensaje[]);

int main (int argc, char *argv[]){
    int llave,tam,i;
    printf("\n********************************\n");
    printf("********Cifrado Ciclico*********\n");
    printf("********************************\n");
    printf("\n");
    //prueba si hay algun argumento enviado por consola
    /*if ( argc == 1 ) {
        printf( "No arguments were passed.\n" );
    } else {
        printf( "Hay argumentos desde consola" );
        for(i=0; i<argc;i++){
            printf("\n %s \n",argv[i]);
        }
    }*/

    //funcion a utilizar
    //le mandamos el parametro argv[argc-1] para capturar lo  le enviamos por consola
    //parametro argc son en numero de parametros que se han enviado, en un principio sera 1(nombre del ejecutable)
    
    cifradoCiclico(argv[argc-1],atoi(argv[argc-2]));
    return 0;
}

//Implementacion de las funciones
//esta funcion me da la frase cifrada a la llave que le demos.
void cifradoCiclico(char frase[], int llave){
    int i=0,tam;
    char tmp[TAMANO];
    for (i=0; i<TAMANO; i++){
        if(frase[i]!='\0'){
            if(llave>0){
                if(frase[i]>='a' && frase[i]<='u'){
                    tmp[i]=frase[i]+llave;
                }else if(frase[i]>='A' && frase[i]<='U'){
                    tmp[i]=frase[i]+llave;
                }else if(frase[i]>='v' && frase[i]<='z'){
                    tmp[i]=(frase[i]-26)+llave;
                }else if(frase[i]>='V' && frase[i]<='Z'){
                    tmp[i]=(frase[i]-26)+llave;
                }else if(frase[i]==32){
                    tmp[i]=32;
                }
            }else if(llave <0){
                if(frase[i]>='f' && frase[i]<='z'){
                    tmp[i]=frase[i]+llave;
                }else if(frase[i]>='F' && frase[i]<='Z'){
                    tmp[i]=frase[i]+llave;
                }else if(frase[i]>='a' && frase[i]<='e'){
                    tmp[i]=(frase[i]+llave)+26;
                }else if(frase[i]>='A' && frase[i]<='E'){
                    tmp[i]=(frase[i]+llave)+26;
                }else if(frase[i]==32){
                    tmp[i]=32;
                }
            }
        }else{
            tmp[i]='\0';
            break;
        }
    }
    printf("Cifrado llave %d: %s\n\n",llave,tmp);
}

//funcion para transformar una frase a codigo morse
void codigoMorse (char mensaje[]){

    char morse[TAMANO];
    int i;

    for (i=0; i<TAMANO; i++){
        if(mensaje[i]!='\0'){
            switch(mensaje[i]){
                case 'A':
                    morse[i]=".-";
                default:
                    break;
            }
        }else{
            break;
        }
    }
}