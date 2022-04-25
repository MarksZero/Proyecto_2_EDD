#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <fstream>



char palabra[20];
bool existir = false;
char nombre_arch[30];
struct Usuario {
    char nombre[50];
    long rut;
};
struct Experimento {
    int Tiempo;
    int Crecimiento;
    int Altura;
    int Cantidad_de_celulas_muertas;
    int Cantidad_de_contaminadas;
    int Cantidad_de_celulas_vivas;
    long Concentración_en_solucione;
};
char nombre_archivo[30] = "ListaUsuarios.txt";

void ingresarUsuario(Usuario *a);
void datosExperimento(Experimento *b);

void saludo();

void lectura();

void rellenar();

void lineas();


using namespace std;

int main() {

    saludo();
    int opcion;
    cin >> opcion;

    int numero_de_usuarios = 0;
    Usuario u[numero_de_usuarios];
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
        lectura();

    }
        //-----------------------------------------------------
    else if (opcion == 3) {
        cout << "Ingresa tu nombre por favor: ";
        cin >> palabra;
        lineas();
        if (existir == true) {
            cout << "ingresa el nombre del archivo y termionelo en .txt \n";
            cin >> nombre_arch;
            rellenar();

        } else {
            cout << "Lo sentimos, el usuario no fue encontrado";
        }
        return 0;

    }
}


void ingresarUsuario(Usuario *a) {
    cout << "ingrese su nombre y rut, sin puntos ni guion \n";
    printf("Nombre: ");
    scanf("%s", a->nombre);
    printf("Rut: ");
    scanf("%lu", &(a->rut));
    printf("--------------------------------\n");
}

void datosExperimento(Experimento *b) {
    cout << "ingrese los datos del experimento \n";
    cout << "Tiempo(dias):  ";
    cin >> b->Tiempo;
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

void lectura() {
    char nombre_archivo[20] = "ListaUsuarios.txt";
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

void rellenar() {
    Experimento experimento;
    //char nombre_arch[30] = "archivo";
    //cin >> nombre_arch[30];
    FILE *arch2 = fopen(nombre_arch, "a+");
    datosExperimento(&experimento);
    fprintf(arch2, "%s %d \n %s %d \n",
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

    fclose(arch2);
}

void lineas() {

    char nombre[30] = "ListaUsuarios.txt";

    if (palabra != NULL) {
        ifstream fichero("ListaUsuarios.txt");
        char cadena[500];
        int nlinea = 0;
        if (fichero) {
            while (fichero) {
                fichero.getline(cadena, 500);
                nlinea++;
                if (fichero)
                    if (strstr(cadena, palabra))
                        existir = true;
            }
        }
    }
}
