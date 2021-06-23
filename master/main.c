#include "scheduler.h"


void *reproducir_musica(void *args);
void hilo1();
void *abrir_youtube(void *args);
void hilo2();
void *escribir_texto_word(void *args);
void hilo3();
void *descargar_archivo(void *args);
void hilo4();
void *subiendo_archivo(void *args);
void hilo5();
void *compilando_programa(void *args);
void hilo6();
void *ejecutando_programa(void *args);
void hilo7();
void *usando_terminal(void *args);
void hilo8();

int main(int argc, char const *argv[]){

	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", hilo1, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", hilo2, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", hilo3, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", hilo4, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", hilo5, ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", hilo6, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", hilo7, ACTIVO);	//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", hilo8, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", hilo8, NO_ACTIVO);	//<--

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}



void *reproducir_musica(void *args){
	char *reproducir="Reproduciendo Música\n";
	printf("%s", reproducir);
	sleep(1);
	return reproducir_musica;
}

void hilo1(){
	pthread_t hilo1;
	pthread_create(&hilo1,NULL,reproducir_musica,NULL);
	pthread_join(hilo1, NULL);
}

void *abrir_youtube(void *args){
	char *reproducir="Usando Youtube\n";
	printf("%s", reproducir);sleep(1);
	return abrir_youtube;
}

void hilo2(){
	pthread_t hilo2;
	pthread_create(&hilo2,NULL,abrir_youtube,NULL);
	pthread_join(hilo2, NULL);
}

void *escribir_texto_word(void *args){
	char *reproducir="Escribiendo Texto en Word\n";
	printf("%s", reproducir);sleep(1);
	return escribir_texto_word;
}

void hilo3(){
	pthread_t hilo3;
	pthread_create(&hilo3,NULL,escribir_texto_word,NULL);
	pthread_join(hilo3, NULL);
}

void *descargar_archivo(void *args){
	char *reproducir="Descargando Archivo\n";
	printf("%s", reproducir);sleep(1);
	return descargar_archivo;
}

void hilo4(){
	pthread_t hilo4;
	pthread_create(&hilo4,NULL,descargar_archivo,NULL);
	pthread_join(hilo4, NULL);
}

void *subiendo_archivo(void *args){
	char *reproducir="Subiendo Archivo\n";
	printf("%s", reproducir);sleep(1);
	return subiendo_archivo;
}

void hilo5(){
	pthread_t hilo5;
	pthread_create(&hilo5,NULL,subiendo_archivo,NULL);
	pthread_join(hilo5, NULL);
}

void *compilando_programa(void *args){
	char *reproducir="Compilando programa\n";
	printf("%s", reproducir);sleep(1);
	return subiendo_archivo;
}

void hilo6(){
	pthread_t hilo6;
	pthread_create(&hilo6,NULL,compilando_programa,NULL);
	pthread_join(hilo6, NULL);
}

void *ejecutando_programa(void *args){
	char *reproducir="Ejecutando programa\n";
	printf("%s", reproducir);sleep(1);
	return ejecutando_programa;
}

void hilo7(){
	pthread_t hilo7;
	pthread_create(&hilo7,NULL,ejecutando_programa,NULL);
	pthread_join(hilo7, NULL);
}

void *usando_terminal(void *args){
	char *reproducir="Usando la terminal\n";
	printf("%s", reproducir);sleep(1);
	return usando_terminal;
}

void hilo8(){
	pthread_t hilo8;
	pthread_create(&hilo8,NULL,usando_terminal,NULL);
	pthread_join(hilo8, NULL);
}
