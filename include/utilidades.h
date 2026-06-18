#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>
#include "equipo.h"

void mostrarMenu();
int leerOpcion();
std::string leerTextoNoVacio(std::string mensaje);
int leerEnteroPositivo(std::string mensaje);
float leerDecimalPositivo(std::string mensaje);
bool esFechaValida(const std::string &fecha);
void copiarTexto(char destino[], int tamanio, const std::string &origen);
std::string texto(const char campo[]);
int claveFecha(const char fecha[]);
void pausar();
void mostrarEquipo(const Equipo &e);

#endif
