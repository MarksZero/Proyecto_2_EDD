#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

struct Usuario {
    char nombre[30];
    long rut;
};

void ingresarUsuario(Usuario *a);
void saludo();
int main() {
    saludo();
                                                            //SOLICITUD DE USUARIOS A CREAR COMO ESTRUCTURA
    int numero_de_usuarios=2;                               //DEJAR SIN VALOR AL TERMINAR
    printf("Ingrese la cantidad de personas:\n");
   // scanf("%d", &numero_de_usuarios);
    Usuario c[numero_de_usuarios];

    //----------------------------------------------------

if() {
    //CREACION DE USUARIOS
    for (int i = 1; i < numero_de_usuarios + 1; i++) {

        ingresarUsuario(&c[i]);
        printf("%s\n", c[i].nombre);
    }
}
    //----------------------------------------------------

    return 0;
}

void ingresarUsuario(Usuario *a) {
    printf("Nombre:\n");
    scanf("%s", a->nombre);
    printf("Rut");
    scanf("%lu", &(a->rut));
    printf("--------------------------------\n");
}
void saludo(){
    cout<<"**Bienvenido**" << "\n" << "Que accion desea realizar?" << "\n";
    cout<<"[1] Crear usuario" << "\n" << "[2] Ingresar a un usuario existente" <<"\n";

}