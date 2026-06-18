#include <iostream>
#include <vector>
#include <cstring>
#include "ordenacion.h"
#include "utilidades.h"

using namespace std;

/*
Nombre: estaOrdenadoPorSerie
Proposito: Verifica si el vector esta ordenado por numero de serie.
Parametros: vector equipos por referencia constante.
Retorno: true si esta ordenado, false en caso contrario.
*/
bool estaOrdenadoPorSerie(const vector<Equipo> &equipos) {
    for (int i = 0; i < (int)equipos.size() - 1; i++) {
        if (strcmp(equipos[i].numeroSerie, equipos[i + 1].numeroSerie) > 0) return false;
    }
    return true;
}

/*
Nombre: ordenarPorSerieBubble
Proposito: Ordena equipos por numero de serie usando Bubble Sort optimizado y metricas.
Parametros: equipos por referencia, metricas por referencia.
Retorno: void.
*/
void ordenarPorSerieBubble(vector<Equipo> &equipos, MetricasOrdenacion &metricas) {
    metricas.comparaciones = 0;
    metricas.intercambios = 0;
    bool huboIntercambio;

    for (int i = 0; i < (int)equipos.size() - 1; i++) {
        huboIntercambio = false;
        for (int j = 0; j < (int)equipos.size() - i - 1; j++) {
            metricas.comparaciones++;
            if (strcmp(equipos[j].numeroSerie, equipos[j + 1].numeroSerie) > 0) {
                Equipo aux = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = aux;
                metricas.intercambios++;
                huboIntercambio = true;
            }
        }
        if (!huboIntercambio) break;
    }
}

/*
Nombre: ordenarPorFechaBubble
Proposito: Ordena equipos por fecha de mantenimiento usando Bubble Sort optimizado y metricas.
Parametros: equipos por referencia, metricas por referencia.
Retorno: void.
*/
void ordenarPorFechaBubble(vector<Equipo> &equipos, MetricasOrdenacion &metricas) {
    metricas.comparaciones = 0;
    metricas.intercambios = 0;
    bool huboIntercambio;

    for (int i = 0; i < (int)equipos.size() - 1; i++) {
        huboIntercambio = false;
        for (int j = 0; j < (int)equipos.size() - i - 1; j++) {
            metricas.comparaciones++;
            if (claveFecha(equipos[j].fechaMantenimiento) > claveFecha(equipos[j + 1].fechaMantenimiento)) {
                Equipo aux = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = aux;
                metricas.intercambios++;
                huboIntercambio = true;
            }
        }
        if (!huboIntercambio) break;
    }
}

static void mergeFecha(vector<Equipo> &equipos, int izquierda, int medio, int derecha, MetricasOrdenacion &metricas) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;
    vector<Equipo> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = equipos[izquierda + i];
    for (int j = 0; j < n2; j++) R[j] = equipos[medio + 1 + j];

    int i = 0, j = 0, k = izquierda;
    while (i < n1 && j < n2) {
        metricas.comparaciones++;
        if (claveFecha(L[i].fechaMantenimiento) <= claveFecha(R[j].fechaMantenimiento)) {
            equipos[k++] = L[i++];
        } else {
            equipos[k++] = R[j++];
        }
        metricas.intercambios++;
    }

    while (i < n1) {
        equipos[k++] = L[i++];
        metricas.intercambios++;
    }
    while (j < n2) {
        equipos[k++] = R[j++];
        metricas.intercambios++;
    }
}

static void mergeSortFecha(vector<Equipo> &equipos, int izquierda, int derecha, MetricasOrdenacion &metricas) {
    if (izquierda >= derecha) return;
    int medio = izquierda + (derecha - izquierda) / 2;
    mergeSortFecha(equipos, izquierda, medio, metricas);
    mergeSortFecha(equipos, medio + 1, derecha, metricas);
    mergeFecha(equipos, izquierda, medio, derecha, metricas);
}

/*
Nombre: ordenarPorFechaMerge
Proposito: Ordena equipos por fecha de mantenimiento usando Merge Sort con metricas.
Parametros: equipos por referencia, metricas por referencia.
Retorno: void.
*/
void ordenarPorFechaMerge(vector<Equipo> &equipos, MetricasOrdenacion &metricas) {
    metricas.comparaciones = 0;
    metricas.intercambios = 0;
    if (!equipos.empty()) mergeSortFecha(equipos, 0, (int)equipos.size() - 1, metricas);
}

/*
Nombre: compararOrdenamientos
Proposito: Compara Bubble Sort optimizado y Merge Sort usando comparaciones e intercambios.
Parametros: equipos por referencia constante.
Retorno: void.
*/
void compararOrdenamientos(const vector<Equipo> &equipos) {
    vector<Equipo> copiaBubble = equipos;
    vector<Equipo> copiaMerge = equipos;
    MetricasOrdenacion mb, mm;

    ordenarPorFechaBubble(copiaBubble, mb);
    ordenarPorFechaMerge(copiaMerge, mm);

    cout << "\n===== REPORTE COMPARATIVO DE ORDENACION =====\n";
    cout << "Criterio: fecha de mantenimiento\n";
    cout << "\nBubble Sort optimizado:\n";
    cout << "Comparaciones: " << mb.comparaciones << endl;
    cout << "Intercambios: " << mb.intercambios << endl;

    cout << "\nMerge Sort / Intercalacion:\n";
    cout << "Comparaciones: " << mm.comparaciones << endl;
    cout << "Movimientos: " << mm.intercambios << endl;

    int totalBubble = mb.comparaciones + mb.intercambios;
    int totalMerge = mm.comparaciones + mm.intercambios;

    if (totalBubble < totalMerge) cout << "\nMetodo mas eficiente para estos datos: Bubble Sort\n";
    else if (totalMerge < totalBubble) cout << "\nMetodo mas eficiente para estos datos: Merge/Intercalacion\n";
    else cout << "\nAmbos metodos tuvieron metricas equivalentes en este conjunto.\n";
}
