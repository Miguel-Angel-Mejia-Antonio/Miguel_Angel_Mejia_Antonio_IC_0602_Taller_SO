all:
	gcc -g -c -Wall main.c -o main.o
	gcc -g -c -Wall scheduler.c -o scheduler.o
	gcc -g -Wall main.o scheduler.o -o application -l pthread

clean:
	rm *.o
	rm application
