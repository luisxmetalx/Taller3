#include <stdio.h>
#include <stdlib.h>

#define TAMANO 1024

//using namespace std;

//funciones
void cifradoCiclico(char frase[], int llave);

int main (){
    char *mensaje;
    int llave,tam;
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
    printf("ingrese el mensaje a Cifrar: ");
    //captura lo que se escribe un una linea...sirve para capturar los espacios entre palabras.
    characters = getline(&mensaje,&bufsize,stdin);
    printf("ingrese el numero de llave: ");
    scanf("%d",&llave);
    //funcion a utilizar
    cifradoCiclico(mensaje,llave);
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