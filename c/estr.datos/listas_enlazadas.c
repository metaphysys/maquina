#include <stdio.h>
#include <string.h>
#include "listas_enlazadas.h"

int main()
{
    lista *l;
    l = malloc(sizeof(l));

    libro* lb;
    lb = malloc(sizeof(lb));
    lb->id = 1;
    strcpy(lb->autor, "Richard Stallman"); 
    strcpy(lb->titulo, "Libro 1"); 

    libro* lb2;
    lb2 = malloc(sizeof(lb2));
    lb2->id = 2;
    strcpy(lb2->autor, "Richard Stallman"); 
    strcpy(lb2->titulo, "Libro 1"); 

    libro* lb3;
    lb3 = malloc(sizeof(lb3));
    lb3->id = 3;
    strcpy(lb3->autor, "Richard Stallman"); 
    strcpy(lb3->titulo, "Libro 1"); 

    insertarCabezaLista(l, lb);
    insertarCabezaLista(l, lb2);
    insertarCabezaLista(l, lb3);

    libro* lbb = getLibro(0, l);
    printf("Nombre del libro %d: %s", lbb->id, lbb->autor);

    printf("%d", sizeLista(l));

    return 0;
}