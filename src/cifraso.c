#include <stdio.h>
#include <cifraso.h>
#include <codificacion.h>
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

