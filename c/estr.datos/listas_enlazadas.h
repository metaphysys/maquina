#include <string.h>

#ifndef LISTAS_ENLAZADAS_H
#define LISTAS_ENLAZADAS_H

// Estructura para almacenar datos de libro
typedef struct libro {
  int id;
  char titulo[50];
  char autor[50];
} libro;

// Nodo; contiene un libro y un puntero al 
// siguiente libro
typedef struct nodo { 
  struct libro libro;
  struct nodo* siguiente;
} nodo;

// Almacena el puntero a la cabeza de la lista
typedef struct lista {
  nodo* cabeza;
  int longitud;
} lista;

// Creación de nuevo nodo a partir de un libro 
// pasado por parámetros
nodo* crearNodo(libro* l) {
  nodo* n = (nodo *) malloc(sizeof(nodo)); // Instancia de nuevo nodo
  // Copiamos los datos del libro parametrizado en el libro del nodo
  n->libro.id = l->id; 
  strncpy(n->libro.autor, l->autor, 50);
  strncpy(n->libro.titulo, l->titulo, 50);
  // No sabemos a quién va a apuntar el siguiente, así que ponemos el 
  // puntero siguiente a null.
  n->siguiente = NULL;
  return n;
}

// Función para eliminar un nodo, si no, se quedará en memoria pululando
void destruirNodo(nodo* n) {
  free(n);
}

// Insertar a la cabeza de una lista
void insertarCabezaLista(lista* l, libro* lb) {
  nodo* n = crearNodo(lb); // Creamos un nodo a partir de los datos del libro parametrizado
  n->siguiente = l->cabeza; // Ponemos como cola del nodo que acabamos de crear el primer nodo de la lista
  l->cabeza = n; // Movemos el puntero para que apunte al nuevo sitio
  l->longitud++;
}

void insertarFinalLista(lista* l, libro* lb) {
  nodo* n = crearNodo(lb);
  if (l->cabeza == NULL) {
    l->cabeza = n;
  } else {
    nodo* p = l->cabeza; // Creamos un nodo que nos hará de puntero, 
    // que será inicialmente la cabeza de la lista, e irá avanzando de una 
    // posición a otra hasta llegar al final de la lista.
    while (p->siguiente) {
      p = p->siguiente;
    } // Una vez salido del bucle sabemos que el puntero p apunta al último elemento
    p->siguiente = n ;
  }
  l->longitud++;
}

void insertarDespuesX(int x, lista* l, libro* lb) {
  nodo* n = crearNodo(lb);
  if (l->cabeza == NULL) {
    l->cabeza = n;
  } else {
    nodo* p = l->cabeza; 
    int posicion = 0;
    while (posicion < x && p->siguiente) {
      p = p->siguiente;
      posicion++;
    } 
    n->siguiente = p->siguiente;
    p->siguiente = n;
  }
  l->longitud++;
}

libro* getLibro(int x, lista* l)  {
  if (l->cabeza == NULL) {
    return NULL;
  } else {
    nodo* p = l->cabeza; 
    int posicion = 0;
    while (posicion < x && p->siguiente) {
      p = p->siguiente;
      posicion++;
    } 
    if (posicion != x) {
      return NULL;
    } else {
      return &p->libro;
    }
  }
}

int sizeLista(lista* l) {
  return l->longitud;
}

int listaVacia(lista* l) {
  // if (l->cabeza == NULL) {
  //   return 1;
  // } else {
  //   return 0;
  // }
  return l->cabeza == NULL;
}

void eliminarPrincipio(lista* l) {
  if (l->cabeza == NULL) {
    nodo* ne = l->cabeza;
    l->cabeza = l->cabeza->siguiente;
    destruirNodo(ne);
    l->longitud--;
  }
}

void eliminarFinal(lista* l) {
  if (l->cabeza != NULL) {
    if (l->cabeza->siguiente) {
      nodo* p = l->cabeza;
      while (p->siguiente->siguiente == NULL) {
        p = p->siguiente;
      }
      nodo* ne = p->siguiente;
      p->siguiente = NULL;
      destruirNodo(ne);
      l->longitud--;
    } else {
      nodo* ne = l->cabeza;
      l->cabeza = NULL;
      destruirNodo(ne);
      l->longitud--;
    }
  }
}

void eliminarX(int x, lista* l) {
  if (l->cabeza) {
    if (x == 0) {
      nodo* ne = l->cabeza;
      l->cabeza = l->cabeza->siguiente;
      destruirNodo(ne);
      l->longitud--;
    } else if (x < l->longitud) {
      nodo* p = l->cabeza;
      int posicion = 0;
      while (posicion < (x-1)) {
        p = p->siguiente;
        posicion++;
      }
      nodo* ne = p->siguiente;
      p->siguiente = ne->siguiente;
      destruirNodo(ne);
      l->longitud--;
    }
  }
}

#endif