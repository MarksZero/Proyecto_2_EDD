#include "lista.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

const char nombre_archivo[30] = "ListaUsuarios.txt";  //variable global que define el nombre de la lista de usuarios creados
int rut;
using namespace std;

bool vacia(Lista lista) {
    return fin(lista) == primero(lista);
}

int primero(Lista lista) {
    return 1;
}

int fin(Lista lista) {
    int c = 1;
    nodo *aux = lista.primero;
    while (aux != nullptr) {
        aux = aux->next;
        c++;
    }
    return c;
}

int siguiente(int p, Lista lista) {
    return p + 1;
}

void ingresar(tipoDato x, int p, Lista &lista) {
    nodo *nuevo = new nodo(x);
    nodo *aux = lista.primero;
    if (primero(lista) == p) {
        nuevo->next = lista.primero;
        lista.primero = nuevo;
    } else {
        for (int i = 0; i < p - 2; i++)
            aux = aux->next;
        nuevo->next = aux->next;
        aux->next = nuevo;
    }
}

void imprime_lista(Lista lista) {
    for (int i = primero(lista); i < fin(lista); i = siguiente(i, lista)) {
        tipoDato x = posicion(i, lista);
        cout <<"["<< i << "]"<< "-> "<< x << "\n";
    }
    printf("\n");
}

void anula(Lista &lista) {
    while (!vacia(lista))
        suprime(primero(lista), lista);
}

int encontrar(tipoDato x, Lista lista) {
    for (int i = primero(lista); i < fin(lista); i = siguiente(i, lista)) {
        tipoDato dato = posicion(i, lista);

        if (x == dato) {
            return true;
        }
    }
    return fin(lista);
}

tipoDato posicion(int p, Lista lista) {
    nodo *aux = lista.primero;
    for (int i = 1; i < p; i++)
        aux = aux->next;
    return aux->dato;
}

void suprime(int p, Lista &lista) {
    nodo *aux = lista.primero;
    if (primero(lista) == p)
        lista.primero = aux->next;
    else {
        nodo *aux2 = lista.primero;
        for (int i = 0; i < p - 2; i++)
            aux2 = aux2->next;
        aux = aux2->next;
        aux2->next = aux->next;
    }
    aux->next = nullptr;
    delete aux;
}

void saludo() { //funcion simplemente creada para enviar instrucciones
    cout << "**Bienvenido**" << "\n" << "Que accion desea realizar?" << "\n";
    cout << "[1] Crear usuario" << "\n" << "[2] Guardar datos de experimento" << "\n" << "[?] opciones de administrador\n";

}

void rellenar(const char *nombre) {
    Experimento experimento{};
    FILE *arch2 = fopen(nombre,"a+");  //creacion de archivo en modo en que  permite leer y agregar información en un archivo que existe. Si no existe se crea.
    datosExperimento(&experimento);
    fprintf(arch2, "%s %d \n %s %d \n",             //Imprimimos en el .txt los datos solicitados
            "Tiempo(dias): ", *&experimento.Tiempo,
            "Altura Actual(cm): ", *&experimento.Altura);
    fprintf(arch2, "%s %d \n %s %d \n",
            "Crecimiento(cm): ", *&experimento.Crecimiento,
            "Cantidad de especimenes muertas: ", *&experimento.Cantidad_de_celulas_muertas);
    fprintf(arch2, "%s %d \n ",
            "Cantidad de especimenes contaminadas: ", *&experimento.Cantidad_de_contaminadas);
    fprintf(arch2, "%s %d \n",
            "Cantidad de especimenes vivas: ", *&experimento.Cantidad_de_celulas_vivas);
    fprintf(arch2, "%s %lu \n",
            "Concetracion en soluciones: ", *&experimento.Concentración_en_solucione);
    fprintf(arch2, "%s \n", "-----------------");

    fclose(arch2);      //cerramos el archivo
}

void datosExperimento(Experimento *b) {      //funcion para solicitar datos de experimento creados en un struct
    cout << "ingrese los datos del experimento \n";
    cout << "Tiempo(dias):  ";
    cin >> b->Tiempo;                //llenado de dato sin la necesidad de especificar formato
    cout << "Altura Actual(cm):  ";
    cin >> b->Altura;
    cout << "Crecimiento(cm):  ";
    cin >> b->Crecimiento;
    cout << "cantidad de:\n";
    cout << "especimenes muertas:  ";
    cin >> b->Cantidad_de_celulas_muertas;
    cout << "especimenes contaminadas:  ";
    cin >> b->Cantidad_de_contaminadas;
    cout << "especimenes vivas:  ";
    cin >> b->Cantidad_de_celulas_vivas;
    cout << "Concetracion en sol:  ";
    cin >> b->Concentración_en_solucione;
}

int creacion_usuarios() {          //funcion para solicitar datos de usuario creados en un struct
    cout << "ingrese su rut, sin puntos ni guion \n";
    printf("Rut: ");          //llenado de dato previamente creado, con formato solicitado
    cin >> rut;
    printf("--------------------------------\n");
    FILE *arch = fopen("ListaUsuarios.txt", "a+");  //creacion del archivo .txt
    fprintf(arch, " %lu \n", rut);   //llenado de datos de "usuario"
    fclose(arch);  //cerrar archivo
    return 0;
}

void transpasar(Lista &lista) {
    int cont = 1;
    string filename(nombre_archivo);
    int number;
    ifstream input_file(filename);

    while (input_file >> number) {
        ingresar(number, cont, lista);
        cont++;
    }
    input_file.close();

}