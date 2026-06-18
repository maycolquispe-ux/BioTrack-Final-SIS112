#include <cstring>
#include <vector>
#include "busqueda.h"

using namespace std;

/*
Nombre: busquedaSecuencialSerie
Proposito: Busca un equipo recorriendo secuencialmente el vector por numero de serie.
Parametros: equipos por referencia constante, serieBuscada por arreglo char.
Retorno: ResultadoBusqueda con indice y comparaciones.
*/
ResultadoBusqueda busquedaSecuencialSerie(const vector<Equipo> &equipos, const char serieBuscada[]) {
    ResultadoBusqueda r;
    r.indice = -1;
    r.comparaciones = 0;
    r.llamadas = 0;

    for (int i = 0; i < (int)equipos.size(); i++) {
        r.comparaciones++;
        if (strcmp(equipos[i].numeroSerie, serieBuscada) == 0) {
            r.indice = i;
            return r;
        }
    }
    return r;
}

/*
Nombre: busquedaBinariaIterativaSerie
Proposito: Busca un equipo por numero de serie mediante busqueda binaria iterativa.
Parametros: equipos ordenados por referencia constante, serieBuscada por arreglo char.
Retorno: ResultadoBusqueda con indice, comparaciones e iteraciones.
*/
ResultadoBusqueda busquedaBinariaIterativaSerie(const vector<Equipo> &equipos, const char serieBuscada[]) {
    ResultadoBusqueda r;
    r.indice = -1;
    r.comparaciones = 0;
    r.llamadas = 0;

    int izquierda = 0;
    int derecha = (int)equipos.size() - 1;

    while (izquierda <= derecha) {
        r.llamadas++;
        int medio = izquierda + (derecha - izquierda) / 2;
        r.comparaciones++;
        int cmp = strcmp(equipos[medio].numeroSerie, serieBuscada);

        if (cmp == 0) {
            r.indice = medio;
            return r;
        }
        if (cmp > 0) derecha = medio - 1;
        else izquierda = medio + 1;
    }
    return r;
}

/*
Nombre: busquedaBinariaRecursivaSerie
Proposito: Busca un equipo por numero de serie mediante busqueda binaria recursiva.
Parametros: equipos ordenados, limites izquierda/derecha, serieBuscada y llamadasPrevias.
Retorno: ResultadoBusqueda con indice, comparaciones y llamadas recursivas.
*/
ResultadoBusqueda busquedaBinariaRecursivaSerie(const vector<Equipo> &equipos, int izquierda, int derecha, const char serieBuscada[], int llamadasPrevias) {
    ResultadoBusqueda r;
    r.indice = -1;
    r.comparaciones = 0;
    r.llamadas = llamadasPrevias + 1;

    if (derecha < izquierda) return r;

    int medio = izquierda + (derecha - izquierda) / 2;
    r.comparaciones = 1;
    int cmp = strcmp(equipos[medio].numeroSerie, serieBuscada);

    if (cmp == 0) {
        r.indice = medio;
        return r;
    }

    ResultadoBusqueda sub;
    if (cmp > 0) sub = busquedaBinariaRecursivaSerie(equipos, izquierda, medio - 1, serieBuscada, r.llamadas);
    else sub = busquedaBinariaRecursivaSerie(equipos, medio + 1, derecha, serieBuscada, r.llamadas);

    sub.comparaciones += r.comparaciones;
    return sub;
}
