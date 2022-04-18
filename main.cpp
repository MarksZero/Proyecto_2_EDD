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
    FILE * arch;
    arch = fopen ("Listas.txt", "a+");

    saludo();
    int opcion;
    cin>>opcion;

    int numero_de_usuarios=0;
    Usuario u[numero_de_usuarios];

    //----------------------------------------------------

    if(opcion==1) {
        //CREACION DE USUARIOS
        cout<<numero_de_usuarios <<"\n";    // solicitar numero de cuentas que deseas crear

        numero_de_usuarios++;
        for (int i = 0; i < numero_de_usuarios; i++) {
            ingresarUsuario(&u[i]);
            long alfa=u[i].rut;
            cout<<alfa;
            fprintf(arch, "%s %lu",u[i].nombre, &alfa);
            fclose(arch);
            arch =fopen("Listas.txt", "a+");
           fscanf(arch, "%s %lu", u[i].nombre, &alfa);


        }
    }
        //----------------------------------------------------
    else if(opcion==2){
        /* cout<<numero_de_usuarios <<"\n";
         printf("%s\n", u->nombre[1]);
         printf("%lu\n", u->rut);
         */
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
void saludo(){
    cout<<"**Bienvenido**" << "\n" << "Que accion desea realizar?" << "\n";
    cout<<"[1] Crear usuario" << "\n" << "[2] Ingresar a un usuario existente" <<"\n";

}