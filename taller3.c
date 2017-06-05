#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANO 1024

//using namespace std;

//funciones
void cifradoCiclico(char frase[], int llave);
void codigoMorse (char mensaje[]);
void cifradoAutollave(char mensaje[],char llave[]  );
void cifradoContrasena (char mensaje[],char llave[]);

int main (int argc, char *argv[]){
    int llave,tam,i,opciones;
    char mensaje[100],txtLlave[100];
    size_t bufsize = TAMANO;
    size_t characters;
    //Inicializacion del puntero..dandole memoria dinamica
    //mensaje = (char *)malloc(bufsize * sizeof(char));
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
        printf( "1. cifrado ciclico.\n" );
        printf( "2. cifrado por contraseña.\n" );
        printf( "3. cifrado por llave.\n\n" );
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
                printf("ingrese el numero de llave: ");
                scanf("%s",txtLlave);
                cifradoContrasena(mensaje,txtLlave);
                break;
            case 3:
                printf("ingrese el mensaje a Cifrar: ");
                scanf("%s",mensaje);
                printf("ingrese el numero de llave: ");
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
        /*printf("\n");
        cifradoAutollave(argv[argc-1],"MARAZUL");
        printf("\n");
        cifradoContrasena (argv[argc-1],"MARAZUL");*/
        
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
    char abc[37]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'
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
                        //printf("mensaje es: %c ",mensaje[k]);
                        //printf("clave es: %c\n",tmp[k]);
                        salida[j]=tmp[k];
                    }
                }
            }
        }
        //imprimimos la salida
        printf("El cifrado es: %s\n",salida);
        printf("clave morse es: ");
        codigoMorse(salida);
    }
    else
    {
        printf("Ingrese una clave que no exceda los 26 caracteres\n");
        printf("%s\n",salida);
    }
}
