#ifndef EQUIPO_H
#define EQUIPO_H

struct Equipo {
    int id;
    char numeroSerie[30];
    char nombre[60];
    char area[40];
    char marca[40];
    char estado[30];
    char fechaMantenimiento[11]; // DD/MM/AAAA
    float costoMantenimiento;
};

#endif
