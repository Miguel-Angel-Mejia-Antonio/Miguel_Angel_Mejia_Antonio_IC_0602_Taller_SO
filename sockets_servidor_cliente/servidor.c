#include "funciones.h"

int main(int argc, char *argv[]){
	//Comprobamos los argumentos requeridos para iniciar la comunicacion entre el SERVIDOR-CLIENTE
	if (argc < 2){
		printf("FALTA EL PUERTO: [%s] [puerto]\n", argv[0]);
		return 1;
	}

		int port = atoi(argv[1]);
		int socket_a_servidor, socket_b_cliente;
		struct sockaddr_in servidor, cliente;
		socklen_t tamanio;

		//Creamos nuestro socket para el SERVIDOR
		socket_a_servidor = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_a_servidor < 0) {
		perror("ERROR DE CREACION DE SOCKET");
		return 1;
	}else{
		printf("SOCKET CREADO CORRECTAMENTE\n");
		printf("SOCKET INICIADO\n");
	}

		memset(&servidor, '\0', sizeof(servidor));
		servidor.sin_family = AF_INET;
		servidor.sin_port = port;
		servidor.sin_addr.s_addr = INADDR_ANY;


	if (bind(socket_a_servidor, (struct sockaddr*)&servidor, sizeof(servidor)) == - 1){
		printf("\nERROR DE ENLAZE DE SOCKET\n");
		return -1;
	}

		listen(socket_a_servidor, 5);
		printf("SERVIDOR ESCUCHANDO....\n");
		tamanio=sizeof(cliente);
		socket_b_cliente = accept(socket_a_servidor,(struct sockaddr*)&cliente, &tamanio);
		printf("\n----------CLIENTE CONECTADO----------\n\n");
		printf("\nPREPARANDOSE PARA REALIZAR LA SUMA.....LISTO");
		printf("\n.....ESPERANDO DATOS DEL CLIENTE\n\n");


		char recibir[LIMITE];
		char numero1[LIMITE];
		char numero2[LIMITE];
		char almacenar[LIMITE];
		int resultado[LIMITE];
		int sinnumer1;
		int sinnumer2;
		int *punterosuma;
		char *puntalmac;

		punterosuma=resultado;
		puntalmac = almacenar;

		// Recibimos los primeros numeros ingresados desde el cliente y la almacenamos en una varible
		printf("\n\n****************************************************\n");
		bzero(recibir, LIMITE);
		recv(socket_b_cliente, recibir, sizeof(recibir), 0);
		printf("DATOS RECIVIDOS:\nEL CLIENTE HA INTRODUCIDO EL NUMERO: %s", recibir);
		strcpy(numero1, recibir);
		

		// Recibimos los segundos numeros ingresados desde el cliente y la almacenamos en una varible
		bzero(recibir, LIMITE);
		recv(socket_b_cliente, recibir, sizeof(recibir), 0);
		printf("\nEL CLIENTE HA INTRODUCIDO EL NUMERO: %s\n", recibir);
		strcpy(numero2, recibir);
		printf("\n****************************************************\n\n");

		//Convetimos los numeros a enteros sin signo.
		sinnumer1=(unsigned)strlen(numero1);	
		sinnumer2=(unsigned)strlen(numero2);

		printf("\n\n****************************************************");
			//Realizamos la suma y la almacenamos en la variable punterosuma
			printf("\nSUMANDO [%s]+[%s]", numero1, numero2);
			if (sinnumer1 < sinnumer2){
				punterosuma = sumando(resultado, numero1, numero2);
			}else{
				punterosuma = sumando(resultado, numero1, numero2);
			}

			//Usamos el resultado de la suma para obtener los datos de la suma del arrglo
			bzero(almacenar,LIMITE);
			if(sinnumer1 < sinnumer2){
				puntalmac = obtenernumeros(punterosuma,almacenar,sinnumer2);
			}else{
				puntalmac= obtenernumeros(punterosuma,almacenar,sinnumer1);
			}
		
		//Enviamos el resultado al cliente.
		printf("\nLA SUMA DE A Y B ES: %s", puntalmac);
		printf("\nENVIANDO RESULTADO DE LA SUMA AL CLIENTE.....");
		send(socket_b_cliente, almacenar, strlen(almacenar), 0);
		printf("\n****************************************************\n\n");

		//Cerramos la comunicacion entre SERVIDOR-CLIENTE
		close(socket_b_cliente);
		printf("----->CLIENTE DESCONECTADO<-----");	
		close(socket_a_servidor);
		printf("\n----->CONEXION DEL SERVIDOR TERMINADA<-----\n");
		return 0;	
}
