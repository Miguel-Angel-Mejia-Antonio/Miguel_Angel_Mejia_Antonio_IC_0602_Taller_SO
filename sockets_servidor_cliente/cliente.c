#include "funciones.h"


int main(int argc, char *argv[]){
	//Comprobamos los argumentos requeridos para iniciar la comunicacion entre el SERVIDOR-CLIENTE
	if (argc < 3){
		printf("FALTAN ARGUMENTOS: [%s] [ip] [puerto]\n", argv[0]);
		return 1;
	}
	
	char ip[(strlen(argv[1]))];
	strcpy(ip, argv[1]);
	
	int port = atoi(argv[2]);
	int socket_a_cliente;
	struct sockaddr_in cliente;

	//Creamos nuestro socket para el CLIENTE
	if((socket_a_cliente = socket(AF_INET, SOCK_STREAM, 0))==.1){
		printf("ERROR DE CREACION DEL SOCKET\n");
		exit(-1);
	}else{
		printf("SOCKET CREADO CORRECTAMENTE\n");
		printf("SOCKET INICIADO\n");
	}

	memset(&cliente, '\0', sizeof(cliente));
	cliente.sin_family = AF_INET;
	cliente.sin_port = port;
	cliente.sin_addr.s_addr = inet_addr(ip);

	//Establecemos una conexion con el SERVIDOR
	if (connect(socket_a_cliente, (struct sockaddr *)&cliente, sizeof(cliente)) == -1){
		printf("NO SE PUDO CONECTAR CON EL SERVIDOR\n"); 
		return -1;
	} else {
		printf("----->CLIENTE CONECTADO CON EL SERVIDOR<-----\n");
	}

	char numero1[LIMITE];
	char numero2[LIMITE];
	char resultado[LIMITE];
	
	// Pedimos los numeros para nuestra suma
	ingresarnumeros(numero1, numero2);

	//Enviamos los numeros al SERVIDOR
	printf("\n\n****************************************************");
	printf("\nENVIANDO DATOS AL SERVIDOR: \nENVIANDO EL NUMERO=[%s] AL SERVIDOR", numero1);
	send(socket_a_cliente, numero1, sizeof(numero1), 0);

	printf("\nENVIANDO EL NUMERO=[%s] AL SERVIDOR", numero2);
	send(socket_a_cliente, numero2, sizeof(numero2), 0);
	printf("\n****************************************************\n\n");

	printf("\n\n****************************************************");
	//Esperamos la respuesta del SERVIDOR
	printf("\nESPERANDO RESPUESTA.......");
	bzero(resultado, LIMITE);

	//Recivimos el resultado de la suma
	recv(socket_a_cliente, resultado, sizeof(resultado), 0);
	printf("\n----->RESPUESTA DEL SERVIDOR<-----");
	printf("\nEL RESULTADO DE LA SUMA ES:  %s", resultado);
	printf("\n****************************************************\n\n");
	
	//Finalizamos la comunicacion del cliente
	cerrar_socket(socket_a_cliente);
		
	return 0;
}
