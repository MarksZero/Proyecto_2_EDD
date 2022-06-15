#ifndef LISTA_STRUCT_H
#define LISTA_STRUCT_H

#define tipoDato int
/* Estructuras*/
struct nodo{
    tipoDato dato;
    struct nodo* next;
    nodo(){
        next=NULL;
    }
    nodo(tipoDato x){
        nodo();
        dato=x;
    }
};

struct Lista{
    struct nodo* primero;
    Lista(){
        primero=NULL;
    }
};

struct Experimento {    //datos a solicitar para poder llenar la hoja del experimento
    int Tiempo;
    int Crecimiento;
    int Altura;
    int Cantidad_de_celulas_muertas;
    int Cantidad_de_contaminadas;
    int Cantidad_de_celulas_vivas;
    long Concentración_en_solucione;
};

#endif