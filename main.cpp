#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

struct Usuario {
    char nombre[50];
    long rut;
};

void ingresarUsuario(Usuario *a);

void saludo();


int main() {

    FILE *arch = fopen("Listas.txt", "a+");

    saludo();
    int opcion;
    cin >> opcion;

    int numero_de_usuarios = 0;
    Usuario u[numero_de_usuarios];

    //----------------------------------------------------

    if (opcion == 1) {
        //CREACION DE USUARIOS
        cout << numero_de_usuarios << "\n";    // solicitar numero de cuentas que deseas crear

        numero_de_usuarios++;
        for (int i = 0; i < numero_de_usuarios; i++) {

            ingresarUsuario(&u[i]);
            // long alfa = u[i].rut;

            fprintf(arch, "%s %lu ", u[i].nombre, *&u[i].rut);
            fclose(arch);
            //arch = fopen("Listas.txt", "a+
        }
    }
        //----------------------------------------------------
    else if (opcion == 2) {
        cout << numero_de_usuarios << "\n";
        cout<<u->nombre;

        for (int i = 0; i < numero_de_usuarios; i++) {
            FILE *arch = fopen("Listas.txt", "r");
            fscanf(arch, "%s %lu ", u[i].nombre, *&u[i].rut);
            printf("hola %s tu rut es %lu");

        }
    }
    fclose(arch);
    return 0;
}

void ingresarUsuario(Usuario *a) {
    printf("Nombre: ");
    scanf("%s", a->nombre);
    printf("Rut: ");
    scanf("%lu", &(a->rut));
    printf("--------------------------------\n");
}

void saludo() {
    cout << "**Bienvenido**" << "\n" << "Que accion desea realizar?" << "\n";
    cout << "[1] Crear usuario" << "\n" << "[2] Ingresar a un usuario existente" << "\n";

}