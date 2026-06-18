#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include "equipo.h"
#include "metricas.h"

ResultadoBusqueda busquedaSecuencialSerie(const std::vector<Equipo> &equipos, const char serieBuscada[]);
ResultadoBusqueda busquedaBinariaIterativaSerie(const std::vector<Equipo> &equipos, const char serieBuscada[]);
ResultadoBusqueda busquedaBinariaRecursivaSerie(const std::vector<Equipo> &equipos, int izquierda, int derecha, const char serieBuscada[], int llamadasPrevias);

#endif
