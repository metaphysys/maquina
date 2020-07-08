#include <stdio.h>

int main(void) {

	/* Declaramos la variable fichero como puntero a FILE. */
	FILE *fichero;

	/* Abrimos "fichero1.txt" en modo texto y
	 * guardamos su direccion en el puntero. */
	fichero = fopen("example.txt", "rt");

	if(fichero == NULL) {
		/* Imprimimos un mensaje para indicar que no existe. */
		printf("El fichero no se ha podido abrir, no existe.");
	} else {
		/* Imprimimos mesaje de exito y la direccion para este ejemplo. */
		printf("El fichero existe y esta en la direccion: %p\n",fichero);

		/* Cerramos "fichero1.txt". */
		fclose(fichero);
	}
}