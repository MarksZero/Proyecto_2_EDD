/* Universidad de La Frontera
* Departamento de Ingeniería Eléctrica
*
* IIE-344 ESTRUCTURA DE DATOS Y ALGORITMOS
*
* Tarea 2
*
* Autores: Pablo Martinez p.martinez10@ufromail.cl
*          Pablo rivera p.rivera07@ufromail.cl
*
* Fecha: 15/06/2022
*
* Descripción general del programa
*/
#include <iostream>
#include "lista.h"

const char nombre_archivo[30] = "ListaUsuarios.txt";  //variable global que define el nombre de la lista de usuarios creados
int verificador;
char nombre_arch[30]; //nombre del archivo a ser creado
//-------------------------------------------------------------------------------
Lista lista;
using namespace std;
//-------------------------------------------------------------------------------


int main() {
//-----------------------------------------------------------
    anula(lista); //funcion que se encarga de eliminar los elementos de la lista
    saludo(); //llamado a la funcion saludo que solo imprime un mensaje
    transpasar(lista);
//-----------------------------------------------------------
    int opcion;
    cin >> opcion;
 //--------------//CREACION-DE-USUARIOS---------------------
    if (opcion == 1) {
        creacion_usuarios();
    }
//-------CORROBORAR-USUARIO-Y-GUARDAR-DATOS-----------------
    else if (opcion == 2) {
        cout << "Ingresa tu rut por favor: ";   //solicitud de datos para corroborar la existencia del usuario
        cin >> verificador;
        if (localiza(verificador, lista) == true) {
            cout<< "ingresa el nombre del archivo y termionelo en .txt \n";    //solicitud de nombre para el archivo a crear
            cin >> nombre_arch;
            rellenar();     //llamado a la funcion que se encarga de rellenar los datos de experimento
        } else {
            cout << "Lo sentimos, el usuario no fue encontrado";
        }
    }
//--------REVISION-DE-USUARIOS-------------------------------
    else if (opcion == 123) {   //colocamos un numero que solo el creador sabra para evitar que los usuarios vean a los usuarios ya creados
        transpasar(lista);
        imprime(lista);  //llamado a la funcion para poder ver los usuarios previamente creados
    }
}
