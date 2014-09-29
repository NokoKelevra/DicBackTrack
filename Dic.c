#include <fcntl.h>
#include <stdio.h>
//#include "syscalls.h"//no existe??
#include <stdlib.h> /* Funciones write() y close() */

//#define PERMS 0666
//#define BUFSIZ 1024 bytes
//#define MaxArray 3

main(){

//	int open (char *nombre, int flags, int perms);
//	int write (int fd, char *buf, int n);

//	char buf(BUFSIZ); //Declarar 'BUFSIZ' como tamaño de bloque del buffer
//	int fd;
//	int end;
//	char *nombre = "dic.txt";
//	int perms = 0666;
//	int max = 2;
	
	int MaxBits = 3;
	int print[3] = {0};

	BackTrack(MaxBits-1,0,print,MaxBits);

/*	fd = open(nombre, O_WRONLY, PERMS);
//printf(BUFSIZ,"\i");
	if (fd < 0) {
		printf("No hay archivo en el que escribir.\n");
	}else{
		printf("Escribe texto:\n");
		while ((end = getchar()) != EOF) { //Poner 'while' fuera del 'if' al arreglar (fd < 0)
			putchar(tolower(end)); printf("\n");
			//write(fd, buf, BUFSIZ);
			return 0;
		}
	}*/

}

BackTrack (int pos, int element, int print[], int MaxBits){
	int MaxElements = 3;
	
	if ( (pos == MaxBits-1) && (element == MaxElements)){				// Ultima posicion & elementos acabados
		imprime(MaxBits,print);
		print[pos] = 0;
		//--pos;
		BackTrack(pos-1,print[pos],print,MaxBits);
	}else if ( (pos == MaxBits-1) && (element != MaxElements)) {		// Ultima posicion & elemento no acabado
		imprime(MaxBits,print);
		//element++;
		print[pos] = element + 1;
		BackTrack(pos,element + 1,print,MaxBits);			
	} else if ( (element == MaxElements) && (pos != MaxBits-1)) {		// Elemento maximo pero no la utima posicion
		if (pos == 0) {													// Primera posicion
			printf("EXIT\n");
		} else {
			print[pos] = 0;
			//--pos;
			BackTrack(pos-1,print[pos],print,MaxBits);
		}	
	} else if ((pos != MaxBits-1) && (element != MaxElements)) {		// Posicion noo final & elemento no ultimo
		print[pos] = element+1;
		//pos++;
		BackTrack(pos+1,print[pos],print,MaxBits);
	}else{
	
	printf("Fuera\n");
	}
}

imprime (int MaxBits, int print[]) {
char *letter[3] = {"a","b","c"};
int m = 0;
	while (m < MaxBits) {
		printf("%s",letter[print[m]]);	
		m++;
	}
	printf("\n");

}
