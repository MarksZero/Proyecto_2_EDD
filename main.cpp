/* Universidad de La Frontera
* Departamento de Ingeniería Eléctrica
*
* IIE-344 ESTRUCTURA DE DATOS Y ALGORITMOS
*
* Tarea 2
*
* Autores: Pablo Martinez. (p.martinez10@ufromail.cl)
*          Pablo Rivera. (p.rivera07@ufromail.cl)
*
* Fecha: 15/06/2022
*
* Descripción general del programa:
* el programa tiene la finalidad de la creación de archivos txt los cuales contienen información
* de experimentos realizados por estudiantes de biotecnología.
* Para poder hacer uso de este programa se requiere de la previa creación de un usuario, el cual
* será almacenado en un archivo txt llamado listaUsuarios, el cual será "escaneado" y traspasado
* a un TDA de Lista para hacer uso más rápido de este.
* Una vez comprobada la existencia del usuario, se procederá a llenar los campos de información
* solicitados, para luego guardarlos en un archivo que tenga el nombre que el usuario estime conveniente.
* Este archivo puede ser editado múltiples veces para así funcionar a manera de bitácora de experimentos.
*/
#include <iostream>
#include "lista.h"

int verificador;
int opcion;
char nombre_arch[30]; //nombre del archivo a ser creado
//-------------------------------------------------------------------------------
Lista lista;
using namespace std;
//-------------------------------------------------------------------------------


int main() {
//-----------------------------------------------------------
    anula(lista); //funcion que se encarga de eliminar los elementos de la lista
    saludo(); //llamado a la funcion saludo que solo imprime_lista un mensaje
    transpasar(lista);
//-----------------------------------------------------------
    cin >> opcion;
 //--------------//CREACION-DE-USUARIOS---------------------
    if (opcion == 1) {
        creacion_usuarios();
    }
//-------CORROBORAR-USUARIO-Y-GUARDAR-DATOS-----------------
    else if (opcion == 2) {
        cout << "Ingresa tu rut por favor: ";   //solicitud de datos para corroborar la existencia del usuario
        cin >> verificador;
        if (encontrar(verificador, lista) == true) {
            cout<< "ingresa el nombre del archivo y termionelo en .txt \n";    //solicitud de nombre para el archivo a crear
            cin >> nombre_arch;
            rellenar(nombre_arch);     //llamado a la funcion que se encarga de rellenar los datos de experimento
        } else {
            cout << "Lo sentimos, el usuario no fue encontrado";
        }
    }
//--------REVISION-DE-USUARIOS-------------------------------
    else if (opcion == 123) {   //colocamos un numero que solo el creador sabra para evitar que los usuarios vean a los usuarios ya creados
        imprime_lista(lista);  //llamado a la funcion para poder ver los usuarios previamente creados
    }
}
