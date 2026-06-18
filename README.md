# BioTrack Final - Sistema de Trazabilidad de Equipos Biomédicos

## Datos generales

**Materia:** Programación I - SIS-112  
**Proyecto:** Examen Final Integrador  
**Estudiante:** Maycol Eugenio Quispe Mamani  
**Carrera:** Ingeniería Biomédica  

## Descripción del dominio

BioTrack es un sistema de consola desarrollado en C++ para gestionar información básica de equipos biomédicos. El sistema permite registrar, listar, modificar, eliminar, buscar, ordenar e intercalar registros de equipos médicos.

## Struct principal

```cpp
struct Equipo {
    int id;
    char numeroSerie[30];
    char nombre[60];
    char area[40];
    char marca[40];
    char estado[30];
    char fechaMantenimiento[11];
    float costoMantenimiento;
};
```

Se utilizan arreglos `char` en lugar de `string` para permitir almacenamiento directo en archivos binarios usando `read()` y `write()`.

## Estructura del proyecto

```text
BioTrack_Final/
├── include/   archivos .h
├── src/       archivos .cpp
├── data/      archivos binarios .dat y reporte PDF
└── main.cpp
```

## Funcionalidades

- CRUD completo con archivos binarios.
- Carga automática inicial de 10 registros si el archivo está vacío.
- Búsqueda secuencial por número de serie.
- Búsqueda binaria iterativa por número de serie.
- Búsqueda binaria recursiva por número de serie.
- Bubble Sort optimizado.
- Merge/Intercalación con métricas.
- Comparación de eficiencia entre Bubble Sort y Merge.
- Intercalación de archivos binarios de prueba.
- Generación de reporte PDF básico.
- Validaciones de texto, enteros, decimales y fecha.

## Compilación

Desde la raíz del proyecto:

```bash
g++ -std=c++11 main.cpp src/*.cpp -Iinclude -o BioTrackFinal
```

En Windows con MinGW:

```bash
g++ -std=c++11 main.cpp src/*.cpp -Iinclude -o BioTrackFinal.exe
```

## Ejecución

```bash
./BioTrackFinal
```

En Windows:

```bash
BioTrackFinal.exe
```

## Guía rápida de uso

1. Registrar equipo.
2. Listar equipos.
3. Modificar equipo.
4. Eliminar equipo.
5. Ordenar por número de serie.
6. Buscar por número de serie.
7. Comparar Bubble Sort vs Merge.
8. Intercalar archivos de prueba.
9. Generar reporte PDF.
0. Salir.

## Archivos generados

- `data/equipos.dat`: archivo principal binario.
- `data/equipos1.dat`: archivo auxiliar para intercalación.
- `data/equipos2.dat`: archivo auxiliar para intercalación.
- `data/resultado.dat`: resultado de la intercalación.
- `data/reporte_biotrack.pdf`: reporte exportable.
