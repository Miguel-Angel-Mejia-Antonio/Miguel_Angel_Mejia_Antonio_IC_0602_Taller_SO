#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int proceso[0][3], num_procesos, quantum, scheduler[1000],tiempoespera[100];
int tiempo = 0;

typedef struct puntero
{
	int p;
	struct puntero *sig;

}principal;
principal *quan = NULL;


void PedirDatosProcesos()
{
	int i;
	printf("\nNumero de Procesos: ");
	scanf("%i", &num_procesos);
	printf("\nQuantum (Tiempo de ejecucion para cada proceso): ");
	scanf("%i", &quantum);
	
	for(i=0; i<num_procesos; i++ )
	{
		char nombre[num_procesos][15];
		printf("\nNombre del proceso %i: ",i);
		scanf("%s",&nombre[i]);
		printf("\nRafaga de Tiempo Total del Proceso %i: ", i);
		scanf("%d", &proceso[i][1]);
		proceso[i][2]=proceso[i][1];
	}
}

int ejecucion()
{
	int i, a=0;
	for(i=0; i<num_procesos; i++)
	{
		if(proceso[i][2]>0)
		{
			a= 1;
		}
	}
	return a;
}
void agregarQuan(int i)
{
	principal *pun1, *pun2;
	pun1 = (principal *)malloc(sizeof(principal));
	pun1->sig = NULL;
	pun1->p = i;
	if(quan == NULL)
	{
		
		quan = pun1;
	}
	else
	{
		for(pun2 = quan ; pun2->sig!=NULL; pun2=pun2->sig);
		pun2 ->sig = pun1;
	}
}
void llegadaprocesoquan()
{
	int i;
	for(i=0; i<num_procesos; i++)
	{
		if(proceso[i][0] == tiempo)
		{
			agregarQuan(i);
		}
	}
}
int siguienteproceso()
{
	principal *pun1;
	int a;
	if(quan == NULL)
	{
		return -1;
	}
	else
	{
		a=quan->p;
		pun1=quan;
		quan=quan->sig;
		free(pun1);
		return a;
	}
}
void schedule()
{
	int sigpro, a, i;
	a=0;
	llegadaprocesoquan();
	while(ejecucion())
	{
		sigpro= siguienteproceso();
		if(sigpro==-1)
		{
			scheduler[tiempo] = -1;
			tiempo++;
			llegadaprocesoquan();
		}
		else
		{
			a=quantum;
			if(proceso[sigpro][2]<a)
			{
				a= proceso[sigpro][2];
			}
			for(i=a; i>0; i--)
			{
				scheduler[tiempo]=sigpro;
				tiempo++;
				proceso[sigpro][2]--;
				llegadaprocesoquan();
			}
			if(proceso[sigpro][2]>0)
			{
				agregarQuan(sigpro);
			}
		}
		int x;	
	}
}
void imprimirdatos()
{
	int i;
	printf("\n\nEjecucion de Procesos: \n");
	for(i=0; i<tiempo; i++)
	{
		printf("[%d-%d] -->Proceso: %d\n",i,i+1 ,scheduler[i]);
	}
	printf("\n\nTiempo de Espera por cada Proceso: \n");
	for(i=0; i<num_procesos; i++)
	{
		printf("\n-->Proceso %d: %d", i, tiempoespera[i]);
	}
	
	float tiempromespera = 0.0;
	for(i=0; i<num_procesos; i++)
	{
		tiempromespera = tiempromespera+tiempoespera[i];
	}
	tiempromespera = tiempromespera/num_procesos;
	printf("\n\nTiempo Promedio de Espera: %0.2f", tiempromespera);
	
}
void TiempoEspera()
{
	int i, tiempo1, i2;
	for(i=0; i<num_procesos; i++)
	{
		
		for(i2=tiempo-1; scheduler[i2]!= i; i2--);
		tiempo1 = i2+1;
		tiempoespera[i] = tiempo1 - proceso[i][0] - proceso[i][1];
	}
}

int main()
{
	PedirDatosProcesos();
	schedule();
	TiempoEspera();
	imprimirdatos();
}
