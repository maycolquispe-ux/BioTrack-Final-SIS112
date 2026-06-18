#ifndef ORDENACION_H
#define ORDENACION_H

#include <vector>
#include "equipo.h"
#include "metricas.h"

bool estaOrdenadoPorSerie(const std::vector<Equipo> &equipos);
void ordenarPorSerieBubble(std::vector<Equipo> &equipos, MetricasOrdenacion &metricas);
void ordenarPorFechaBubble(std::vector<Equipo> &equipos, MetricasOrdenacion &metricas);
void ordenarPorFechaMerge(std::vector<Equipo> &equipos, MetricasOrdenacion &metricas);
void compararOrdenamientos(const std::vector<Equipo> &equipos);

#endif
