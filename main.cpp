#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <fstream>

using namespace std;

struct Usuario {
    char nombre[50];
    long rut;
};
struct Experimento{
    int Tiempo;
    long Crecimiento;
    long Altura;
    int Cantidad_de_celulas_muertas;
    int Cantidad_de_contaminadas;
    int Cantidad_de_celulas_vivas;
    long Concentración_en_solucione;
};

void ingresarUsuario(Usuario *a);
void datosExperimento(Experimento *b);
void saludo();

void lectura();

char nombre_archivo[30] = "ListaUsuarios.txt";


int main() {

    saludo();
    int opcion;
    cin >> opcion;

    int numero_de_usuarios = 0;
    Usuario u[numero_de_usuarios];
    Experimento experimento;

    //----------------------------------------------------

    if (opcion == 1) {
        //CREACION DE USUARIOS
        FILE *arch = fopen("ListaUsuarios.txt", "a+");
        cout << numero_de_usuarios << "\n";    // solicitar numero de cuentas que deseas crear
        numero_de_usuarios++;
        for (int i = 0; i < numero_de_usuarios; i++) {
            ingresarUsuario(&u[i]);
            fprintf(arch, " %s %lu \n", u[i].nombre, *&u[i].rut);
            fclose(arch);
        }
    }
        //----------------------------------------------------
    else if (opcion == 2) {
        cout << numero_de_usuarios << "\n";
        //  cout << u->nombre;
        lectura();

    }
        //-----------------------------------------------------
    else if (opcion == 3) {

        cout<<"Por favor ingrese el nombre con el que quiere trabajar, y terminelo en .txt\n";
        cin>> nombre_archivo[30];
        FILE *arch2 = fopen(nombre_archivo, "a+");
        datosExperimento(&experimento);
        fprintf(arch2, " %d %d %lu %lu %d %d %d \n", *&experimento.Tiempo, *&experimento.Crecimiento, *&experimento.Altura,
                *&experimento.Cantidad_de_celulas_muertas, *&experimento.Cantidad_de_contaminadas ,
                *&experimento.Cantidad_de_celulas_vivas, *&experimento.Concentración_en_solucione);


        fclose(arch2);
    }
//    fclose(arch);
    return 0;
}

void ingresarUsuario(Usuario *a) {
    cout << "ingrese su nombre y rut, sin puntos ni guion \n";
    printf("Nombre: ");
    scanf("%s", a->nombre);
    printf("Rut: ");
    scanf("%lu", &(a->rut));
    printf("--------------------------------\n");
}
void datosExperimento(Experimento *b){
    cout<<"ingrese los datos del experimento \n";
    cout<<"Tiempo: ";
    scanf("%d", b->Tiempo);
    cout<<"Crecimiento";
    scanf("%lu", &(b->Crecimiento));
    cout<<"Altura";
    scanf("%lu", &(b->Altura));
    cout<<"Cantidad de celulas muertas";
    scanf("%d", &(b->Cantidad_de_celulas_muertas));
    cout<<"Cantidad de contaminadas";
    scanf("%d", &(b->Cantidad_de_contaminadas));
    cout<<"Cantidad de celulas vivas";
    scanf("%d", &(b->Cantidad_de_celulas_vivas));
    cout<<"Concetracion en soluciones";
    scanf("%d", &(b->Concentración_en_solucione));
}

void lectura() {
    //char nombre_archivo[20] = "ListaUsuarios.txt";
    ifstream archivo;
    string texto;
    archivo.open(nombre_archivo, ios::in);//abrimos un archivo en modo lectura
    if (archivo.fail()) {
        cout << "\n no se pudo abrir el archivo \n";
    }
    while (!archivo.eof()) {//mientras no sea el final del archivo
        getline(archivo, texto);
        cout << texto << endl;
    }
    archivo.close();
}

void saludo() {
    cout << "**Bienvenido**" << "\n" << "Que accion desea realizar?" << "\n";
    cout << "[1] Crear usuario" << "\n" << "[2] Ver usurarios creados" << "\n" << "[3] Guardar notas\n";

}