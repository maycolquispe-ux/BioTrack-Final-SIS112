#ifndef CRUD_H
#define CRUD_H

#include <vector>
#include "equipo.h"

int buscarIndicePorID(const std::vector<Equipo> &equipos, int idBuscado);
int buscarIndicePorSerie(const std::vector<Equipo> &equipos, const char serieBuscada[]);
void crearEquipo(std::vector<Equipo> &equipos);
void listarEquipos(const std::vector<Equipo> &equipos);
void modificarEquipo(std::vector<Equipo> &equipos);
void eliminarEquipo(std::vector<Equipo> &equipos);

#endif
