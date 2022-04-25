#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <fstream>



char palabra[20];   //variable global para luego buscar por nombre
bool existir = false; //boleano para corroborar que el usuario exista
char nombre_arch[30]; //nombre del archivo a ser creado
struct Usuario {   //datos a solicitar para la creacion de un usuario
    char nombre[50];
    long rut;
};

struct Experimento {    //datos a solicitar para poder llenar la hoja del experimento
    int Tiempo;
    int Crecimiento;
    int Altura;
    int Cantidad_de_celulas_muertas;
    int Cantidad_de_contaminadas;
    int Cantidad_de_celulas_vivas;
    long Concentración_en_solucione;
};
char nombre_archivo[30] = "ListaUsuarios.txt";  //variable global que define el nombre de la lista de usuarios creados
//-------------------------------------------------------------------------------
//lista de void's usados
//-------------------------------------------------------------------------------
void ingresarUsuario(Usuario *a);

void datosExperimento(Experimento *b);

void saludo();

void lectura();

void rellenar();

void revision_usuarios();

//-------------------------------------------------------------------------------

using namespace std;

int main() {

    saludo(); //llamado a la funcion saludo que solo imprime un mensaje
    int opcion;
    cin >> opcion;

    int numero_de_usuarios = 0;
    Usuario u[numero_de_usuarios];      //numero de usuarios creados
    //----------------------------------------------------

    if (opcion == 1) {
        //CREACION DE USUARIOS
        FILE *arch = fopen("ListaUsuarios.txt", "a+");  //creacion del archivo .txt
        numero_de_usuarios++;
        for (int i = 0; i < numero_de_usuarios; i++) {
            ingresarUsuario(&u[i]);
            fprintf(arch, " %s %lu \n", u[i].nombre, *&u[i].rut);   //llenado de datos de "usuario"
            fclose(arch);            //cerrar archivo
        }
    }
        //----------------------------------------------------
    else if (opcion == 2) {
        cout << "Ingresa tu rut por favor: ";   //solicitud de datos para corroborar la existencia del usuario
        cin >> palabra;
        revision_usuarios();      //funcion que corrobora la existencia de la palabra/numero dado
        if (existir == true) {      //verificacion de que el usuario exista
            cout << "ingresa el nombre del archivo y termionelo en .txt \n";    //solicitud de nombre para el archivo a crear
            cin >> nombre_arch;
            rellenar();     //llamado a la funcion que se encarga de rellenar los datos de experimento

        } else {
            cout << "Lo sentimos, el usuario no fue encontrado";
        }
        return 0;

    }
        //-----------------------------------------------------

    else if (opcion == 1501) {   //colocamos un numero que solo el creador sabra para evitar que los usuarios vean a los usuarios ya creados
        lectura();  //llamado a la funcion para poder ver los usuarios previamente creados

    }
}


void ingresarUsuario(Usuario *a) {          //funcion para solicitar datos de usuario creados en un struct
    cout << "ingrese su nombre y rut, sin puntos ni guion \n";
    printf("Nombre: ");
    scanf("%s", a->nombre);             //llenado de dato previamente creado, con formato solicitado
    printf("Rut: ");
    scanf("%lu", &(a->rut));
    printf("--------------------------------\n");
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

void saludo() { //funcion simplemente creada para enviar instrucciones
    cout << "**Bienvenido**" << "\n" << "Que accion desea realizar?" << "\n";
    cout << "[1] Crear usuario" << "\n"  << "[2] Guardar datos de experimento"<< "\n" << "[?] Ver usurarios creados\n";

}

void rellenar() {
    Experimento experimento;
    FILE *arch2 = fopen(nombre_arch, "a+");  //creacion de archivo en modo en que  permite leer y agregar información en un archivo que existe. Si no existe se crea.
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

void revision_usuarios() {     //funcion creada para corroborar la existencia de usuario

    if (palabra != NULL) {
        ifstream fichero("ListaUsuarios.txt");  //llamdo a la lista de usuarios para poder corroborar su existencia
        char cadena[500];
        int nlinea = 0;
        if (fichero) {
            while (fichero) {
                fichero.getline(cadena, 500);       //obtencion de lineas del archivo txt
                nlinea++;
                if (fichero)
                    if (strstr(cadena, palabra)) //comparacion de palabras
                        existir = true;     //cambio de estado del boleano al comprobar la existencia del usuario
            }
        }
    }
}
