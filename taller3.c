#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

//Implementacion de las funciones
//esta funcion me da la frase cifrada a la llave que le demos.
void cifradoCiclico(char frase[], int llave){
    int i=0,tam;
    char tmp[TAMANO], tmp1[TAMANO];
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
    printf("\nCifrado llave %d: %s\n",llave,tmp);
    printf("\n");
    strcpy(tmp1,tmp);
    printf("clave morse es: ");
    codigoMorse(tmp1);
}

//funcion para transformar una frase a codigo morse
void codigoMorse (char mensaje[]){

    int i,j;
    //almacene el abcdario en un arreglo para ser comparado despues
    char abc[37]={'A','A','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0',' '};
    //almacene las letras y numeros en morse para comparar despues
    char morse[37][6] = {{".-"},{"-..."},{"-.-."},{"-.."},{"."},{"..-."},{"--."},{"...."},{".."},{".---"}
    ,{"-.-"},{".-.."},{"--"},{"-."},{"---"},{".--."},{"--.-"},{".-."},{"..."},{"-"},{"..-"},{"...-"},{".--"}
    ,{"-..-"},{"-.--"},{"--.."},{".----"},{"..---"},{"...--"},{"....-"},{"....."},{"-...."},{"--..."},{"---.."}
    ,{"----."},{"-----"},{"//"}}; 

    for(i=0;i<mensaje[i]; i++){
        for(j=0; j<37; j++){
            //si concuerda la letra con la letra del abcdario pues procede a sacar el indice para 
            //poder utilizar ese indice en la obtencion de la clave morse para cada letra
            if(mensaje[i]==abc[j]){
                printf("%s ",morse[j]);
            }
        }
    }
    printf("\n");
}