Ejemplo de ejecucion:

Paso 1: make
						Resultados:
									gcc -g -c -Wall servidor.c -o servidor.o
									gcc -g -Wall servidor.o -o servidor
									gcc -g -c -Wall cliente.c -o cliente.o
									gcc -g -Wall cliente.o -o cliente


Paso 2: ./servidor 8080


Paso 3: ./cliente 10.0.2.15 8080