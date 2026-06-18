#include <iostream>
#include <vector>
#include <cstring>
#include "crud.h"
#include "utilidades.h"

using namespace std;

/*
Nombre: buscarIndicePorID
Proposito: Busca la posicion de un equipo segun su ID.
Parametros: vector equipos por referencia constante, idBuscado por valor.
Retorno: indice encontrado o -1.
*/
int buscarIndicePorID(const vector<Equipo> &equipos, int idBuscado) {
    for (int i = 0; i < (int)equipos.size(); i++) {
        if (equipos[i].id == idBuscado) return i;
    }
    return -1;
}

/*
Nombre: buscarIndicePorSerie
Proposito: Busca la posicion de un equipo segun su numero de serie.
Parametros: vector equipos por referencia constante, serieBuscada por arreglo char.
Retorno: indice encontrado o -1.
*/
int buscarIndicePorSerie(const vector<Equipo> &equipos, const char serieBuscada[]) {
    for (int i = 0; i < (int)equipos.size(); i++) {
        if (strcmp(equipos[i].numeroSerie, serieBuscada) == 0) return i;
    }
    return -1;
}

/*
Nombre: crearEquipo
Proposito: Registra un nuevo equipo evitando IDs y numeros de serie duplicados.
Parametros: vector equipos por referencia.
Retorno: void.
*/
void crearEquipo(vector<Equipo> &equipos) {
    Equipo e;
    string entrada;

    cout << "\n===== REGISTRAR EQUIPO =====\n";
    e.id = leerEnteroPositivo("ID numerico del equipo: ");

    if (buscarIndicePorID(equipos, e.id) != -1) {
        cout << "Ya existe un equipo con ese ID.\n";
        return;
    }

    entrada = leerTextoNoVacio("Numero de serie: ");
    copiarTexto(e.numeroSerie, 30, entrada);

    if (buscarIndicePorSerie(equipos, e.numeroSerie) != -1) {
        cout << "Ya existe un equipo con ese numero de serie.\n";
        return;
    }

    copiarTexto(e.nombre, 60, leerTextoNoVacio("Nombre del equipo: "));
    copiarTexto(e.area, 40, leerTextoNoVacio("Area: "));
    copiarTexto(e.marca, 40, leerTextoNoVacio("Marca: "));
    copiarTexto(e.estado, 30, leerTextoNoVacio("Estado: "));

    do {
        entrada = leerTextoNoVacio("Fecha de mantenimiento (DD/MM/AAAA): ");
        if (!esFechaValida(entrada)) cout << "Formato invalido. Use DD/MM/AAAA.\n";
    } while (!esFechaValida(entrada));
    copiarTexto(e.fechaMantenimiento, 11, entrada);

    e.costoMantenimiento = leerDecimalPositivo("Costo de mantenimiento: ");
    equipos.push_back(e);

    cout << "Equipo registrado correctamente.\n";
}

/*
Nombre: listarEquipos
Proposito: Muestra todos los equipos almacenados en el vector.
Parametros: vector equipos por referencia constante.
Retorno: void.
*/
void listarEquipos(const vector<Equipo> &equipos) {
    if (equipos.empty()) {
        cout << "\nNo existen equipos registrados.\n";
        return;
    }

    cout << "\n===== LISTA DE EQUIPOS =====\n";
    for (int i = 0; i < (int)equipos.size(); i++) {
        cout << "\nEquipo " << i + 1 << "\n";
        cout << "-----------------------------\n";
        mostrarEquipo(equipos[i]);
    }
}

/*
Nombre: modificarEquipo
Proposito: Modifica los datos de un equipo existente buscado por ID.
Parametros: vector equipos por referencia.
Retorno: void.
*/
void modificarEquipo(vector<Equipo> &equipos) {
    if (equipos.empty()) {
        cout << "\nNo existen equipos registrados.\n";
        return;
    }

    cout << "\n===== MODIFICAR EQUIPO =====\n";
    int idBuscado = leerEnteroPositivo("Ingrese ID a modificar: ");
    int posicion = buscarIndicePorID(equipos, idBuscado);

    if (posicion == -1) {
        cout << "Equipo no encontrado.\n";
        return;
    }

    cout << "\nEquipo encontrado:\n";
    mostrarEquipo(equipos[posicion]);

    string entrada;
    cout << "\nIngrese los nuevos datos.\n";

    entrada = leerTextoNoVacio("Nuevo numero de serie: ");
    char nuevaSerie[30];
    copiarTexto(nuevaSerie, 30, entrada);
    int repetido = buscarIndicePorSerie(equipos, nuevaSerie);
    if (repetido != -1 && repetido != posicion) {
        cout << "Ya existe otro equipo con ese numero de serie.\n";
        return;
    }
    copiarTexto(equipos[posicion].numeroSerie, 30, entrada);

    copiarTexto(equipos[posicion].nombre, 60, leerTextoNoVacio("Nuevo nombre: "));
    copiarTexto(equipos[posicion].area, 40, leerTextoNoVacio("Nueva area: "));
    copiarTexto(equipos[posicion].marca, 40, leerTextoNoVacio("Nueva marca: "));
    copiarTexto(equipos[posicion].estado, 30, leerTextoNoVacio("Nuevo estado: "));

    do {
        entrada = leerTextoNoVacio("Nueva fecha mantenimiento (DD/MM/AAAA): ");
        if (!esFechaValida(entrada)) cout << "Formato invalido. Use DD/MM/AAAA.\n";
    } while (!esFechaValida(entrada));
    copiarTexto(equipos[posicion].fechaMantenimiento, 11, entrada);

    equipos[posicion].costoMantenimiento = leerDecimalPositivo("Nuevo costo mantenimiento: ");
    cout << "Equipo modificado correctamente.\n";
}

/*
Nombre: eliminarEquipo
Proposito: Elimina fisicamente un equipo del vector mediante desplazamiento y pop_back.
Parametros: vector equipos por referencia.
Retorno: void.
*/
void eliminarEquipo(vector<Equipo> &equipos) {
    if (equipos.empty()) {
        cout << "\nNo existen equipos registrados.\n";
        return;
    }

    cout << "\n===== ELIMINAR EQUIPO =====\n";
    int idBuscado = leerEnteroPositivo("Ingrese ID a eliminar: ");
    int posicion = buscarIndicePorID(equipos, idBuscado);

    if (posicion == -1) {
        cout << "Equipo no encontrado.\n";
        return;
    }

    for (int i = posicion; i < (int)equipos.size() - 1; i++) {
        equipos[i] = equipos[i + 1];
    }
    equipos.pop_back();

    cout << "Equipo eliminado correctamente.\n";
}
