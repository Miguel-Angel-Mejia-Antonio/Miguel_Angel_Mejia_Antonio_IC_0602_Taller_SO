#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cont_palabras{
    char palabras[500];
}palabra[1000];

int main(int argc, char *argv[]){

	FILE*archivo = fopen(argv[1],"r");

    int i,j;
    int contador = 0;
    char aux[100];

    if(archivo == NULL)
    {
        printf("No se ha podido abrir el archivo.\n");
        exit(1);
    }else{
        printf("--------------------------------------------------------\n");
        printf("--ARCHIVO ---->%s<---- ABIERTO CORRECTAMENTE--\n",argv[1]);
        printf("--------------------------------------------------------\n\n");
    }

    for(i=0; !feof(archivo); i++)
    {
        fgets(palabra[i].palabras,100,archivo);
        contador++;
        printf("--PALABRAS:----->%s\n",palabra[i].palabras);
    }

    printf("--------------------------------------------------------\n");
    printf("---------ORDENANDO PALABRAS----------\n");
    printf("--------------------------------------------------------\n\n");
    for(i=0; i<contador; i++)
    {
        for(j=0; j<contador; j++)
        {
            if(strcmp(palabra[j].palabras,palabra[j+1].palabras)>0)
            {
                strcpy(aux,palabra[j].palabras);
                strcpy(palabra[j].palabras,palabra[j+1].palabras);
                strcpy(palabra[j+1].palabras,aux);        
            }
        }
    }
    
    printf("--------------------------------------------------------\n");
    printf("--CERRANDO EL ARCHIVO: -->%s<----\n",argv[1]);
    printf("--------------------------------------------------------\n\n");
    fclose(archivo);

    fopen(argv[2],"w");

    printf("--------------------------------------------------------\n");
    printf("--PALABRAS ORDENADAS CORRECTAMENTE en -->%s<----\n",argv[2]);
    printf("--------------------------------------------------------\n");

    for(i=0;i<=contador;i++)
    {
        fprintf(archivo,"%s",palabra[i].palabras);
    }
    fclose(archivo);
}


