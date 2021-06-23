#ifndef __FUNCIONES
#define __FUNCIONES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define LIMITE 1000

void ingresarnumeros(char numero1[LIMITE], char numero2[LIMITE]);
void cerrar_socket(int socket_cerrar);
int *sumando(int sum[LIMITE],char num1[LIMITE], char num2[LIMITE]);
char *obtenernumeros(int cadena[LIMITE], char cadenastring[LIMITE], int tamanio);



//-----------FUNCIONES-----------

void ingresarnumeros(char numero1[LIMITE], char numero2[LIMITE]){
	printf("INGRESA UN NUMERO: ");
	scanf("%s", numero1);
	
	printf("INGRESA UN NUMERO: ");
	scanf("%s", numero2);
	//return numero1;
}

void cerrar_socket(int socket_cerrar){
	close(socket_cerrar);
	printf("\n----->CONEXION FINALIZADA<-----\n");
}

char *obtenernumeros(int cadena[LIMITE], char cadenastring[LIMITE], int tamanio){
	int i=0, j=0;
	if ((cadena[i]) >= 10){
		int carcadena = cadena[i];
		cadenastring[0] = (carcadena%10) + '0';
		cadenastring[1] = (carcadena%10) + '0';
		tamanio++;
		i = i + 2;
		j++;
	}
	while(i != tamanio){
		cadenastring[i] = cadena[j] + '0';
		i++;
		j++;
	}
	return cadenastring;
}

int *sumando(int sum[LIMITE],char num1[LIMITE], char num2[LIMITE])
{
    
    int opnum1[LIMITE], opnum2[LIMITE], conta,contb,contc, cnum1,cnum2,carry;

    cnum1=strlen(num1);
    cnum2=strlen(num2);
    carry = ( cnum1 > cnum2)? cnum1:cnum2 ;

    for (conta=0; conta<cnum1; conta++){
        opnum1[conta]=num1[conta]-'0';
    }

	for (contb=0; contb<cnum2; contb++){
	    opnum2[contb]=num2[contb]-'0';
	}

    for(conta=cnum1-1,contb=cnum2-1,contc=carry-1; conta>=0 && contb>=0; conta--,contb--,contc--){
        sum[contc] = opnum1[conta] + opnum2[contb];
    }

    for(;conta>=0; conta--,contc--){
        sum[contc] = opnum1[conta];
    }

    for(;contb>=0; contb--,contc--){
        sum[contc] = opnum2 [contb];
    }

    for(contc=carry-1; contc>0; contc--){
        if(sum[contc] >9){
           sum[contc] = sum[contc]%10;
           sum[contc-1] += 1;
        }
    }

    //printf("\nEL RESULTADO ES: ");
    for( contc=0; contc<carry; contc++){
        //printf("%d",sum[contc]);
    }
    return sum;
}

#endif

