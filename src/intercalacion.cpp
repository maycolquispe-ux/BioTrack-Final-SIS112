#include <iostream>
#include <vector>
#include "intercalacion.h"
#include "ordenacion.h"
#include "archivos.h"
#include "utilidades.h"

using namespace std;

/*
Nombre: intercalarEquiposPorFecha
Proposito: Combina dos vectores ordenados por fecha manteniendo el orden final.
Parametros: equipos1 y equipos2 por referencia constante, metricas por referencia.
Retorno: vector<Equipo> con datos intercalados.
*/
vector<Equipo> intercalarEquiposPorFecha(const vector<Equipo> &equipos1, const vector<Equipo> &equipos2, MetricasOrdenacion &metricas) {
    vector<Equipo> resultado;
    metricas.comparaciones = 0;
    metricas.intercambios = 0;

    int i = 0;
    int j = 0;

    while (i < (int)equipos1.size() && j < (int)equipos2.size()) {
        metricas.comparaciones++;
        if (claveFecha(equipos1[i].fechaMantenimiento) <= claveFecha(equipos2[j].fechaMantenimiento)) {
            resultado.push_back(equipos1[i]);
            i++;
        } else {
            resultado.push_back(equipos2[j]);
            j++;
        }
        metricas.intercambios++;
    }

    while (i < (int)equipos1.size()) {
        resultado.push_back(equipos1[i]);
        i++;
        metricas.intercambios++;
    }

    while (j < (int)equipos2.size()) {
        resultado.push_back(equipos2[j]);
        j++;
        metricas.intercambios++;
    }

    return resultado;
}

/*
Nombre: ejecutarIntercalacionArchivos
Proposito: Genera/carga dos archivos binarios de prueba, los ordena e intercala en resultado.dat.
Parametros: Ninguno.
Retorno: void.
*/
void ejecutarIntercalacionArchivos() {
    const string archivo1 = "data/equipos1.dat";
    const string archivo2 = "data/equipos2.dat";
    const string archivoResultado = "data/resultado.dat";

    generarArchivosIntercalacionPrueba(archivo1, archivo2);

    vector<Equipo> equipos1, equipos2, resultado;
    cargarEquiposBinario(archivo1, equipos1);
    cargarEquiposBinario(archivo2, equipos2);

    MetricasOrdenacion m1, m2, mi;
    ordenarPorFechaMerge(equipos1, m1);
    ordenarPorFechaMerge(equipos2, m2);

    resultado = intercalarEquiposPorFecha(equipos1, equipos2, mi);
    guardarEquiposBinario(archivoResultado, resultado);

    cout << "\nIntercalacion realizada correctamente.\n";
    cout << "Archivo generado: " << archivoResultado << endl;
    cout << "Comparaciones de intercalacion: " << mi.comparaciones << endl;
    cout << "Movimientos al resultado: " << mi.intercambios << endl;

    cout << "\n===== CONTENIDO INTERCALADO =====\n";
    for (int i = 0; i < (int)resultado.size(); i++) {
        cout << "\nEquipo " << i + 1 << "\n";
        mostrarEquipo(resultado[i]);
    }
}
