#include <stdio.h>
#include "codificacion.h"
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