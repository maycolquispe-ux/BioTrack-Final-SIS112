#ifndef INTERCALACION_H
#define INTERCALACION_H

#include <vector>
#include "equipo.h"
#include "metricas.h"

std::vector<Equipo> intercalarEquiposPorFecha(const std::vector<Equipo> &equipos1, const std::vector<Equipo> &equipos2, MetricasOrdenacion &metricas);
void ejecutarIntercalacionArchivos();

#endif
