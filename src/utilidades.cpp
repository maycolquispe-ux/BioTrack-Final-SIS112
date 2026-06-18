#include <iostream>
#include <string>
#include <limits>
#include <cstring>
#include "utilidades.h"

using namespace std;

/*
Nombre: mostrarMenu
Proposito: Muestra las opciones principales del sistema BioTrack.
Parametros: Ninguno.
Retorno: void.
*/
void mostrarMenu() {
    cout << "\n========================================\n";
    cout << "     BIOTRACK FINAL - EQUIPOS BIOMEDICOS\n";
    cout << "========================================\n";
    cout << "1. Registrar equipo\n";
    cout << "2. Listar equipos\n";
    cout << "3. Modificar equipo\n";
    cout << "4. Eliminar equipo\n";
    cout << "5. Ordenar por numero de serie (Bubble)\n";
    cout << "6. Buscar equipo por numero de serie\n";
    cout << "7. Comparar ordenacion Bubble vs Merge\n";
    cout << "8. Intercalar archivos de prueba\n";
    cout << "9. Generar reporte PDF\n";
    cout << "0. Salir\n";
    cout << "========================================\n";
}

/*
Nombre: leerOpcion
Proposito: Lee una opcion numerica desde consola validando errores de entrada.
Parametros: Ninguno.
Retorno: int con la opcion ingresada.
*/
int leerOpcion() {
    int opcion;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada invalida. Ingrese un numero: ";
        cin >> opcion;
    }

    cin.ignore(1000, '\n');
    return opcion;
}

/*
Nombre: leerTextoNoVacio
Proposito: Solicita un texto y evita que se ingresen campos vacios.
Parametros: mensaje por valor.
Retorno: string con el texto ingresado.
*/
string leerTextoNoVacio(string mensaje) {
    string textoLeido;
    do {
        cout << mensaje;
        getline(cin, textoLeido);
        if (textoLeido == "") {
            cout << "El campo no puede estar vacio.\n";
        }
    } while (textoLeido == "");
    return textoLeido;
}

/*
Nombre: leerEnteroPositivo
Proposito: Lee un entero positivo validando cin.fail y valores menores o iguales a cero.
Parametros: mensaje por valor.
Retorno: int positivo.
*/
int leerEnteroPositivo(string mensaje) {
    int valor;
    cout << mensaje;
    cin >> valor;

    while (cin.fail() || valor <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada invalida. Ingrese un entero positivo: ";
        cin >> valor;
    }

    cin.ignore(1000, '\n');
    return valor;
}

/*
Nombre: leerDecimalPositivo
Proposito: Lee un numero decimal positivo validando cin.fail y valores negativos.
Parametros: mensaje por valor.
Retorno: float positivo o cero.
*/
float leerDecimalPositivo(string mensaje) {
    float valor;
    cout << mensaje;
    cin >> valor;

    while (cin.fail() || valor < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada invalida. Ingrese un numero positivo: ";
        cin >> valor;
    }

    cin.ignore(1000, '\n');
    return valor;
}

/*
Nombre: esFechaValida
Proposito: Verifica si una fecha tiene el formato DD/MM/AAAA.
Parametros: fecha por referencia constante.
Retorno: true si el formato es valido, false en caso contrario.
*/
bool esFechaValida(const string &fecha) {
    if (fecha.size() != 10) return false;
    if (fecha[2] != '/' || fecha[5] != '/') return false;

    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5) {
            if (fecha[i] < '0' || fecha[i] > '9') return false;
        }
    }
    return true;
}

/*
Nombre: copiarTexto
Proposito: Copia un string hacia un arreglo char de tamanio fijo, necesario para archivos binarios con structs.
Parametros: destino por referencia implicita, tamanio por valor, origen por referencia constante.
Retorno: void.
*/
void copiarTexto(char destino[], int tamanio, const string &origen) {
    strncpy(destino, origen.c_str(), tamanio - 1);
    destino[tamanio - 1] = '\0';
}

/*
Nombre: texto
Proposito: Convierte un arreglo char en string para facilitar comparaciones o salidas.
Parametros: campo char.
Retorno: string equivalente.
*/
string texto(const char campo[]) {
    return string(campo);
}

/*
Nombre: claveFecha
Proposito: Convierte fecha DD/MM/AAAA en entero AAAAMMDD para ordenar correctamente.
Parametros: fecha en arreglo char.
Retorno: int con formato AAAAMMDD.
*/
int claveFecha(const char fecha[]) {
    string f(fecha);
    if (f.size() != 10) return 0;
    string clave = f.substr(6, 4) + f.substr(3, 2) + f.substr(0, 2);
    return atoi(clave.c_str());
}

/*
Nombre: pausar
Proposito: Pausa la ejecucion hasta que el usuario presione Enter.
Parametros: Ninguno.
Retorno: void.
*/
void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.get();
}

/*
Nombre: mostrarEquipo
Proposito: Muestra en consola todos los datos de un equipo.
Parametros: Equipo por referencia constante.
Retorno: void.
*/
void mostrarEquipo(const Equipo &e) {
    cout << "ID: " << e.id << endl;
    cout << "Numero de serie: " << e.numeroSerie << endl;
    cout << "Nombre: " << e.nombre << endl;
    cout << "Area: " << e.area << endl;
    cout << "Marca: " << e.marca << endl;
    cout << "Estado: " << e.estado << endl;
    cout << "Fecha mantenimiento: " << e.fechaMantenimiento << endl;
    cout << "Costo mantenimiento: " << e.costoMantenimiento << " Bs" << endl;
}
