#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Usuario {
    char nombre[30];
    long rut;
};

void ingresarUsuario(Usuario *a);
void saludo();


int main() {
    saludo();
    int opcion;
    cin>>opcion;

    int numero_de_usuarios=0;
    Usuario c[numero_de_usuarios];

    //----------------------------------------------------

if(opcion==1) {
    //CREACION DE USUARIOS
    cout<<numero_de_usuarios <<"\n";
    numero_de_usuarios++;
    for (int i = 0; i < numero_de_usuarios; i++) {
        ingresarUsuario(&c[i]);
        printf("%s\n", c[i].nombre);


    }
}
    //----------------------------------------------------
else if(opcion==2){
    cout<<numero_de_usuarios <<"\n";
    printf("%s\n", c->nombre[1]);
    printf("%lu\n", c->rut);
}
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