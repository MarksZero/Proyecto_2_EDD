#include "lista.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

int rut;
using namespace std;


/*
* Nombre de la función: vacia.
* Tipo de función: booleana.
* Parámetros: “lista” de tipo Lista.
* Dato de retorno: Retorna verdadero si la Lista lista está vacía y falso en caso contrario
* Descripción de la función: La función vacia(Lista lista) cerciora el esta de la lista,
*                            si el primero y el ultimo son iguales significa que esta vacia.
*/
bool vacia(Lista lista) {
    return fin(lista) == primero(lista);
}
/*
* Nombre de la función: primero.
* Tipo de función: int.
* Parámetros:“lista” de tipo Lista.
* Dato de retorno: la primera posicion de la Lista lista;
* Descripción de la función: se encarga de retornar la posicion del primer elemento
 *                           contenido en la Lista
*/
int primero(Lista lista) {
    return 1;
}
/*
* Nombre de la función: fin.
* Tipo de función: int.
* Parámetros: “lista” de tipo Lista..
* Dato de retorno: “c” de tipo int.
* Descripción de la función: devulve la ultima posicion que CONTENGA un dato dentro
*                           de la Lista lista
*/
int fin(Lista lista) {
    int c = 1;
    nodo *aux = lista.primero;
    while (aux != nullptr) {
        aux = aux->next;
        c++;
    }
    return c;
}
/*
* Nombre de la función: siguiente.
* Tipo de función: int.
* Parámetros: “lista” de tipo Lista.
 *            “p” de tipo int.
* Dato de retorno: “p+1” de tipo int;
* Descripción de la función: devulve la posicion posicion siguiente a la ingresada dentro
*                           de la Lista lista.
*/
int siguiente(int p, Lista lista) {
    return p + 1;
}
/*
* Nombre de la función: ingresar.
* Tipo de función: void, vacia.
* Parámetros: “x” de tipo int.
 *            “p” de tipo int.
 *            “lista” de tipo Lista pasado por referencio.
* Dato de retorno: sin retorno.
* Descripción de la función: mediante el uso de de auxiliares que guardan punteros, ingresan
 *                          datos en la posicion indicada en la Lista lista
*/
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
/*
* Nombre de la función: imprime_lista.
* Tipo de función: void, vacia.
* Parámetros: “lista” de tipo Lista.
* Dato de retorno: sin retorno.
* Descripción de la función: mediante el uso del ciclo for, recorre la Lista lista
*                            imprimiendo por pantalla el dato y la posicion en la que se encuentra
*/
void imprime_lista(Lista lista) {
    for (int i = primero(lista); i < fin(lista); i = siguiente(i, lista)) {
        tipoDato x = posicion(i, lista);
        cout <<"["<< i << "]"<< "-> "<< x << "\n";
    }
    printf("\n");
}
/*
* Nombre de la función:anula.
* Tipo de función: void, vacia.
* Parámetros: “lista” de tipo Lista pasado por referencio.
* Dato de retorno: sin retorno.
* Descripción de la función: haciendo uso de la funcion "suprime" se encarga de borrar
*                            cada dato hasta que no quede ninguno
*/
void anula(Lista &lista) {
    while (!vacia(lista))
        suprime(primero(lista), lista);
}
/*
* Nombre de la función:anula.
* Tipo de función: int.
* Parámetros: “x” de tipo int.
*            “lista” de tipo Lista .
* Dato de retorno: booleano, ultima posicion de la Lista lista siendo este un NULL.
* Descripción de la función: recorre la lista desde el primer dato hasta el final comparando los datos
 *                          de la Lista lista con el dato ingresado, en caso de encontrarlo devuelve un true,
 *                          en caso contrario devuelve el final de la lista
*/
int encontrar(tipoDato x, Lista lista) {
    for (int i = primero(lista); i < fin(lista); i = siguiente(i, lista)) {
        tipoDato dato = posicion(i, lista);

        if (x == dato) {
            return true;
        }
    }
    return fin(lista);
}
/*
* Nombre de la función:posicion.
* Tipo de función: tipoDato int.
* Parámetros: “p” de tipo int.
*            “lista” de tipo Lista .
* Dato de retorno: nodo de la posicion del dato.
* Descripción de la función: recorre la lista desde el 1 hasta la posicion idicada,
*                            cambiando la direccion de aux
*/
tipoDato posicion(int p, Lista lista) {
    nodo *aux = lista.primero;
    for (int i = 1; i < p; i++)
        aux = aux->next;
    return aux->dato;
}
/*
* Nombre de la función: suprime.
* Tipo de función: void, vacia.
* Parámetros: “p” de tipo int.
*            “lista” de tipo Lista pasado por referencio.
* Dato de retorno: sin retorno.
* Descripción de la función: se encarga de eliminar un dato en la posicion indicada
*                            guardando la direccion de medio del siguiente dato para evitar
*                            perder los datos siguientes.
*/
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
/*
* Nombre de la función: saludo.
* Tipo de función: void, vacia.
* Parámetros: sin parametros.
* Dato de retorno: sin retorno.
* Descripción de la función: envia por pantalla un mensaje con las instrucciones.
*/
void saludo() { //funcion simplemente creada para enviar instrucciones
    cout << "**Bienvenido**" << "\n" << "Que accion desea realizar?" << "\n";
    cout << "[1] Crear usuario" << "\n" << "[2] Guardar datos de experimento" << "\n" << "[?] opciones de administrador\n";

}
/*
* Nombre de la función: rellenar.
* Tipo de función: void, vacia.
* Parámetros: puntero de "nombre" de tipo char.
* Dato de retorno: sin retorno.
* Descripción de la función: crea o edita un archivo cuyo nombre se solicita, luego comienza a rellenar el
*                            archivo con datos previamente solicitados, luego de terminar de usar el archivo
*                            este se cierra.
*/
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
/*
* Nombre de la función: datosExperimento.
* Tipo de función: void, vacia.
* Parámetros: puntero de experimento "b" de tipo struct.
* Dato de retorno: sin retorno.
* Descripción de la función: solicita y guarda los datos de la estructura "Experimeto"
*/
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
/*
* Nombre de la función: datosExperimento.
* Tipo de función: void.
* Parámetros: no solicita parametros.
* Dato de retorno: sin retorno.
* Descripción de la función: solicita el rut del usuario para luego guardarlos en un txt
*                            que contiene a todos los usuarios
*/
void creacion_usuarios() {          //funcion para solicitar datos de usuario creados en un struct
    cout << "ingrese su rut, sin puntos ni guion \n";
    printf("Rut: ");          //llenado de dato previamente creado, con formato solicitado
    cin >> rut;
    printf("--------------------------------\n");
    FILE *arch = fopen("ListaUsuarios.txt", "a+");  //creacion del archivo .txt
    fprintf(arch, " %lu \n", rut);   //llenado de datos de "usuario"
    fclose(arch);  //cerrar archivo
}
/*
* Nombre de la función: transpasar.
* Tipo de función: void, vacia.
* Parámetros: “lista” de tipo Lista pasado por referencio.
* Dato de retorno: sin retorno.
* Descripción de la función: se encarga de extraer el contenido de la lista de usuarios
 *                           como bit para luego transformarlos a enteros, y de esa manera
 *                           poder añadirlos a la Lista lista para su uso mas rapido.
*/
void transpasar(Lista &lista) {
    int cont = 1;
    string filename("ListaUsuarios.txt");
    int number;
    ifstream input_file(filename);

    while (input_file >> number) {
        ingresar(number, cont, lista);
        cont++;
    }
    input_file.close();

}