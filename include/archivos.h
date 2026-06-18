#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <vector>
#include <string>
#include "equipo.h"

bool existeArchivoConDatos(const std::string &nombreArchivo);
void cargarEquiposBinario(const std::string &nombreArchivo, std::vector<Equipo> &equipos);
void guardarEquiposBinario(const std::string &nombreArchivo, const std::vector<Equipo> &equipos);
void asegurarDatosIniciales(const std::string &nombreArchivo);
void generarArchivosIntercalacionPrueba(const std::string &archivo1, const std::string &archivo2);
void generarReportePDF(const std::string &nombreArchivo, const std::vector<Equipo> &equipos);

#endif
