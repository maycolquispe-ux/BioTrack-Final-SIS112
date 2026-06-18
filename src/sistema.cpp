#include <iostream>
#include <vector>
#include <string>
#include "sistema.h"
#include "equipo.h"
#include "archivos.h"
#include "crud.h"
#include "ordenacion.h"
#include "busqueda.h"
#include "intercalacion.h"
#include "utilidades.h"

using namespace std;

static const string ARCHIVO_PRINCIPAL = "data/equipos.dat";

static void buscarEquipoPorSerie(vector<Equipo> &equipos) {
    if (equipos.empty()) {
        cout << "\nNo existen equipos registrados.\n";
        return;
    }

    string serie = leerTextoNoVacio("Ingrese numero de serie a buscar: ");
    char serieBuscada[30];
    copiarTexto(serieBuscada, 30, serie);

    cout << "\n1. Busqueda secuencial\n";
    cout << "2. Busqueda binaria iterativa\n";
    cout << "3. Busqueda binaria recursiva\n";
    int tipo = leerEnteroPositivo("Seleccione tipo de busqueda: ");

    ResultadoBusqueda resultado;

    if (tipo == 1) {
        resultado = busquedaSecuencialSerie(equipos, serieBuscada);
    } else if (tipo == 2) {
        MetricasOrdenacion m;
        if (!estaOrdenadoPorSerie(equipos)) {
            cout << "El vector no estaba ordenado por serie. Se ordenara antes de buscar.\n";
            ordenarPorSerieBubble(equipos, m);
            guardarEquiposBinario(ARCHIVO_PRINCIPAL, equipos);
        }
        resultado = busquedaBinariaIterativaSerie(equipos, serieBuscada);
    } else if (tipo == 3) {
        MetricasOrdenacion m;
        if (!estaOrdenadoPorSerie(equipos)) {
            cout << "El vector no estaba ordenado por serie. Se ordenara antes de buscar.\n";
            ordenarPorSerieBubble(equipos, m);
            guardarEquiposBinario(ARCHIVO_PRINCIPAL, equipos);
        }
        resultado = busquedaBinariaRecursivaSerie(equipos, 0, (int)equipos.size() - 1, serieBuscada, 0);
    } else {
        cout << "Opcion de busqueda invalida.\n";
        return;
    }

    if (resultado.indice != -1) {
        cout << "\nEquipo encontrado:\n";
        mostrarEquipo(equipos[resultado.indice]);
    } else {
        cout << "\nEquipo no encontrado.\n";
    }

    cout << "Comparaciones realizadas: " << resultado.comparaciones << endl;
    if (tipo == 2) cout << "Iteraciones utilizadas: " << resultado.llamadas << endl;
    if (tipo == 3) cout << "Llamadas recursivas utilizadas: " << resultado.llamadas << endl;
}

/*
Nombre: iniciarSistema
Proposito: Ejecuta el flujo principal del sistema BioTrack Final.
Parametros: Ninguno.
Retorno: void.
*/
void iniciarSistema() {
    asegurarDatosIniciales(ARCHIVO_PRINCIPAL);

    vector<Equipo> equipos;
    cargarEquiposBinario(ARCHIVO_PRINCIPAL, equipos);

    int opcion;

    do {
        mostrarMenu();
        opcion = leerOpcion();

        switch (opcion) {
        case 1:
            crearEquipo(equipos);
            guardarEquiposBinario(ARCHIVO_PRINCIPAL, equipos);
            break;

        case 2:
            listarEquipos(equipos);
            break;

        case 3:
            modificarEquipo(equipos);
            guardarEquiposBinario(ARCHIVO_PRINCIPAL, equipos);
            break;

        case 4:
            eliminarEquipo(equipos);
            guardarEquiposBinario(ARCHIVO_PRINCIPAL, equipos);
            break;

        case 5: {
            MetricasOrdenacion m;
            ordenarPorSerieBubble(equipos, m);
            guardarEquiposBinario(ARCHIVO_PRINCIPAL, equipos);
            cout << "\nEquipos ordenados correctamente por numero de serie.\n";
            cout << "Comparaciones: " << m.comparaciones << endl;
            cout << "Intercambios: " << m.intercambios << endl;
            break;
        }

        case 6:
            buscarEquipoPorSerie(equipos);
            break;

        case 7:
            compararOrdenamientos(equipos);
            break;

        case 8:
            ejecutarIntercalacionArchivos();
            break;

        case 9:
            generarReportePDF("data/reporte_biotrack.pdf", equipos);
            break;

        case 0:
            cout << "\nSaliendo de BioTrack Final...\n";
            break;

        default:
            cout << "\nOpcion invalida.\n";
        }

        if (opcion != 0) pausar();

    } while (opcion != 0);
}
