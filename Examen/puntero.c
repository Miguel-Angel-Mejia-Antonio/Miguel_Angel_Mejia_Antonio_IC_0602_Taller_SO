#include <stdio.h>
#include <stdlib.h>

int main(){

//Pasos a seguir:

	
	//Paso 1
	char x;
	char *p;

	//Paso 2
	char y;
	char *puntero;

	//Paso 3
	x='x';

	//Paso 4
	p=&x;

	//Paso 5
	printf("Contenido del puntero [p]= %c \n", *p);

	//Paso 6
	p=p+1;

	//Paso 7
	printf("Contenido del puntero [p]= %c \n", *p);

	//Paso 8
	p=p+2;

	//Paso 9
	printf("Contenido del puntero [p]= %c \n", *p);

	//Paso 10
	y='y';

	//Paso 11
	puntero=&y;

	//Paso 12
	printf("Contenido del puntero [puntero]= %c \n", *puntero);



	return 0;

}
