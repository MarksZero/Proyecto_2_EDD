#include <cstdio>
#include "listaStruct.h"
#include <iostream>


/* Prototipos */
bool vacia(Lista lista);
int primero(Lista lista);
int fin(Lista lista);
int siguiente(int p, Lista lista);
void ingresar(tipoDato x, int p, Lista &lista);
tipoDato posicion(int p, Lista lista);
void imprime_lista(Lista lista);
int encontrar(tipoDato x, Lista lista);
void suprime(int p, Lista &lista);
void anula(Lista &lista);
void saludo();
int creacion_usuarios();
void datosExperimento(Experimento *b);
void rellenar(const char *nombre);
void transpasar(Lista &lista);

