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

 // funcion de codificacion por contraseña
void cifradoContrasena (char mensaje[],char llave[])
{
    //declaracion de variables internas
    int i,j,k;
    char tmp[26];
    char salida[strlen(mensaje)];
    char abc[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    //la contraseña debe ser menor que el numero de caracteres del alfabeto
    if(strlen(llave)<26)
    {
        //se llena un arreglo temporal con la contraseña y desplazando el resto del alfabeto
        for(i=0;i<26;i++)
        {
            if(i<strlen(llave))
            {
                tmp[i]=llave[i];
            }
            else
            {
                tmp[i]=abc[i-strlen(llave)];
            }
        }
        // se cifra el mensaje con el arreglo temporal
        for(j=0;j<(strlen(mensaje)-1);j++)
        {
            if(mensaje[j]==' ')
            {
                salida[j]=mensaje[j];
            }
            else
            {
                for(k=0;k<26;k++)
                {
                    if(mensaje[j]==abc[k])
                    {
                        salida[j]=tmp[k];
                    }
                }
            }
        }
        //imprimimos la salida
        printf("%s\n",salida);
    }
    else
    {
        printf("Ingrese una clave que no exceda los 26 caracteres\n");
        printf("%s\n",salida);
    }
}