#ifndef METRICAS_H
#define METRICAS_H

struct ResultadoBusqueda {
    int indice;
    int comparaciones;
    int llamadas;
};

struct MetricasOrdenacion {
    int comparaciones;
    int intercambios;
};

#endif
