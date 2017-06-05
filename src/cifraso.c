#include <stdio.h>
#include "cifraso.h"
#include "codificacion.h"
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
        for(j=0;j<(strlen(mensaje));j++)
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

void cifradoAutollave (char msm[],char llave[]){
    int i,j,k,flag=0,tmpPos,tmp=0,flag1=0;
    char msmCifrado[TAMANO];
    char matriz[26][26]={{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z'},{'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A'},{'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B'},{'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C'},{'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D'},{'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E'},{'G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F'},{'H','I','J','K','L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G'},{'I','J','K','L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H'},{'J','K','L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I'},{'K','L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J'},{'L','M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K'},{'M','N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L'},{'N','O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M'},{'O','P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N'},{'P','Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'},{'Q','R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'},{'R','S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q'},{'S','T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R'},{'T','U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S'},{'U'
    ,'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'},
    {'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'},
    {'W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'},
    {'X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W'},
    {'Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W'},
    {'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','Y'}};

    char llavetmp[TAMANO];
    //generar la llave para cifrar
	for(i=0; i<100; i++){
        //printf("valor de i: %d\n",i);
        if(msm[i]!=' '){
            llavetmp[i]=llave[i];
            //printf("valor puesto:%c\n",llavetmp[i]);
            if(flag1==1){
               // printf("voy a poner la letra: %c\n",llave[tmp]);
                llavetmp[i]=llave[tmp];
                //printf("mensaje:%s\n",llavetmp);
                tmp+=1;
            }
        }else{
            llavetmp[i]=' ';
            tmp=i;
            flag1=1;
        }  

        if(llave[i]=='\0'){
            //printf("mensaje:%s\n",msm);
            //printf("mensaje:%s\n",llavetmp);
            tmpPos=0;
            for(j=i+1; j<100; j++){
                //printf("valor de j: %d\n",j);
                //printf("valor de tmpPos: %d\n",tmpPos);
                if(msm[tmpPos]!=' '){
                    llavetmp[j]=msm[tmpPos];
                    //printf("la letra guardada es: %c\n",msm[tmpPos]);
                    //printf("la nueva cadena es: %s\n",llavetmp);
                    tmpPos+=1;
                    flag=1;
                }else{
                    tmpPos+=1;
                    j-=1;
                    //printf("valor de j: %d \t",j);
                    //printf("espacio en blanco \n");
                }
            }
        }
        
        if(flag==1){
            flag=0;
            break;
        }
    }
    printf("\n\nla nueva llave es: %s\n\n",llavetmp);
    //cifrar el contenido con la llave generada
    for(i=0; i<TAMANO; i++){
        //pregunto si ya es fin de cadena
        if(msm[i]=='\0'){
            msmCifrado[i]='\0';
            break;
        }
        //recorre la matriz
        for(j=0; j<26; j++){
            if(msm[i]==' '){
                msmCifrado[i]=' ';
                break;
            }
            if(msm[i] == matriz[j][0]){
                //printf("%c",matriz[j][0]);
                for(k=0; k<26; k++){
                    if(llavetmp[i] == matriz[0][k]){
                        //printf("%c",matriz[0][k]);
                        msmCifrado[i]=matriz[j][k];
                        flag=1;
                        //acumK+=1;
                        //printf(" esta: %c\n",matriz[i][j]);
                        break;
                    }
                }
            }else if(flag==1){
                flag=0;
                break;
            }
        }
    }
    printf("cifrado es: %s\n",msmCifrado);
    printf("clave morse es: ");
    codigoMorse(msmCifrado);
}