#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include "archivos.h"
#include "utilidades.h"

using namespace std;

static Equipo crearEquipoBase(int id, const string &serie, const string &nombre, const string &area,
                              const string &marca, const string &estado, const string &fecha, float costo) {
    Equipo e;
    e.id = id;
    copiarTexto(e.numeroSerie, 30, serie);
    copiarTexto(e.nombre, 60, nombre);
    copiarTexto(e.area, 40, area);
    copiarTexto(e.marca, 40, marca);
    copiarTexto(e.estado, 30, estado);
    copiarTexto(e.fechaMantenimiento, 11, fecha);
    e.costoMantenimiento = costo;
    return e;
}

/*
Nombre: existeArchivoConDatos
Proposito: Verifica si un archivo binario existe y contiene al menos un registro.
Parametros: nombreArchivo por referencia constante.
Retorno: true si existe y tiene datos, false en caso contrario.
*/
bool existeArchivoConDatos(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str(), ios::binary | ios::ate);
    if (!archivo) return false;
    return archivo.tellg() >= (streampos)sizeof(Equipo);
}

/*
Nombre: cargarEquiposBinario
Proposito: Lee registros Equipo desde un archivo binario y los carga en un vector.
Parametros: nombreArchivo por referencia constante, equipos por referencia.
Retorno: void.
*/
void cargarEquiposBinario(const string &nombreArchivo, vector<Equipo> &equipos) {
    equipos.clear();
    ifstream archivo(nombreArchivo.c_str(), ios::binary);

    if (!archivo) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    Equipo temp;
    while (archivo.read((char*)&temp, sizeof(Equipo))) {
        equipos.push_back(temp);
    }

    archivo.close();
}

/*
Nombre: guardarEquiposBinario
Proposito: Guarda todos los registros del vector en un archivo binario.
Parametros: nombreArchivo por referencia constante, equipos por referencia constante.
Retorno: void.
*/
void guardarEquiposBinario(const string &nombreArchivo, const vector<Equipo> &equipos) {
    ofstream archivo(nombreArchivo.c_str(), ios::binary | ios::trunc);

    if (!archivo) {
        cout << "Error al crear o abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    for (int i = 0; i < (int)equipos.size(); i++) {
        archivo.write((char*)&equipos[i], sizeof(Equipo));
    }

    archivo.close();
}

/*
Nombre: asegurarDatosIniciales
Proposito: Carga automaticamente 10 registros de prueba si el archivo principal esta vacio.
Parametros: nombreArchivo por referencia constante.
Retorno: void.
*/
void asegurarDatosIniciales(const string &nombreArchivo) {
    if (existeArchivoConDatos(nombreArchivo)) return;

    vector<Equipo> iniciales;
    iniciales.push_back(crearEquipoBase(1, "EQ-1001", "Monitor Multiparametro", "UCI", "Philips", "Operativo", "15/05/2026", 850));
    iniciales.push_back(crearEquipoBase(2, "EQ-1002", "Bomba de Infusion", "Emergencias", "Baxter", "Mantenimiento", "02/06/2026", 420));
    iniciales.push_back(crearEquipoBase(3, "EQ-1003", "Electrocardiografo", "Cardiologia", "GE", "Operativo", "20/04/2026", 300));
    iniciales.push_back(crearEquipoBase(4, "EQ-1004", "Desfibrilador", "Emergencias", "Zoll", "Operativo", "10/05/2026", 650));
    iniciales.push_back(crearEquipoBase(5, "EQ-1005", "Ventilador Mecanico", "UCI", "Drager", "Revision", "01/06/2026", 1200));
    iniciales.push_back(crearEquipoBase(6, "EQ-1006", "Incubadora Neonatal", "Neonatologia", "Atom", "Operativo", "18/05/2026", 900));
    iniciales.push_back(crearEquipoBase(7, "EQ-1007", "Autoclave", "Esterilizacion", "Tuttnauer", "Operativo", "25/04/2026", 500));
    iniciales.push_back(crearEquipoBase(8, "EQ-1008", "Ecografo", "Imagenologia", "Samsung", "Mantenimiento", "05/06/2026", 1100));
    iniciales.push_back(crearEquipoBase(9, "EQ-1009", "Aspirador Quirurgico", "Quirofano", "Medela", "Operativo", "30/05/2026", 250));
    iniciales.push_back(crearEquipoBase(10, "EQ-1010", "Lampara Cialitica", "Quirofano", "Mindray", "Operativo", "12/05/2026", 700));

    guardarEquiposBinario(nombreArchivo, iniciales);
    cout << "Se cargaron automaticamente 10 registros iniciales en " << nombreArchivo << ".\n";
}

/*
Nombre: generarArchivosIntercalacionPrueba
Proposito: Genera dos archivos binarios de prueba para demostrar la intercalacion.
Parametros: archivo1 y archivo2 por referencia constante.
Retorno: void.
*/
void generarArchivosIntercalacionPrueba(const string &archivo1, const string &archivo2) {
    vector<Equipo> a;
    vector<Equipo> b;

    a.push_back(crearEquipoBase(11, "EQ-2001", "Monitor Signos Vitales", "UCI", "Nihon", "Operativo", "01/03/2026", 450));
    a.push_back(crearEquipoBase(12, "EQ-2003", "Centrifuga", "Laboratorio", "Eppendorf", "Operativo", "10/04/2026", 350));
    a.push_back(crearEquipoBase(13, "EQ-2005", "Rayos X Portatil", "Imagenologia", "Siemens", "Revision", "20/05/2026", 1400));

    b.push_back(crearEquipoBase(14, "EQ-2002", "Balanza Analitica", "Laboratorio", "Ohaus", "Operativo", "15/03/2026", 180));
    b.push_back(crearEquipoBase(15, "EQ-2004", "Equipo de Anestesia", "Quirofano", "Drager", "Operativo", "12/04/2026", 950));
    b.push_back(crearEquipoBase(16, "EQ-2006", "Pulsoximetro", "Emergencias", "Nonin", "Operativo", "25/05/2026", 120));

    guardarEquiposBinario(archivo1, a);
    guardarEquiposBinario(archivo2, b);
}

static string escaparPDF(const string &s) {
    string r;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == ')' || s[i] == '\\') r += '\\';
        r += s[i];
    }
    return r;
}

/*
Nombre: generarReportePDF
Proposito: Genera un reporte PDF simple con el listado de equipos cargados.
Parametros: nombreArchivo por referencia constante, equipos por referencia constante.
Retorno: void.
*/
void generarReportePDF(const string &nombreArchivo, const vector<Equipo> &equipos) {
    ofstream pdf(nombreArchivo.c_str(), ios::binary | ios::trunc);
    if (!pdf) {
        cout << "No se pudo generar el reporte PDF.\n";
        return;
    }

    string contenido = "BT /F1 10 Tf 40 800 Td (Reporte BioTrack - Equipos Biomedicos) Tj 0 -18 Td";
    int lineas = 0;
    for (int i = 0; i < (int)equipos.size() && lineas < 35; i++, lineas++) {
        string linea = "ID " + to_string(equipos[i].id) + " | Serie " + texto(equipos[i].numeroSerie) +
                       " | " + texto(equipos[i].nombre) + " | Fecha " + texto(equipos[i].fechaMantenimiento);
        contenido += " (" + escaparPDF(linea) + ") Tj 0 -14 Td";
    }
    contenido += " ET";

    vector<long> offsets;
    pdf << "%PDF-1.4\n";
    offsets.push_back((long)pdf.tellp());
    pdf << "1 0 obj << /Type /Catalog /Pages 2 0 R >> endobj\n";
    offsets.push_back((long)pdf.tellp());
    pdf << "2 0 obj << /Type /Pages /Kids [3 0 R] /Count 1 >> endobj\n";
    offsets.push_back((long)pdf.tellp());
    pdf << "3 0 obj << /Type /Page /Parent 2 0 R /MediaBox [0 0 612 842] /Resources << /Font << /F1 4 0 R >> >> /Contents 5 0 R >> endobj\n";
    offsets.push_back((long)pdf.tellp());
    pdf << "4 0 obj << /Type /Font /Subtype /Type1 /BaseFont /Helvetica >> endobj\n";
    offsets.push_back((long)pdf.tellp());
    pdf << "5 0 obj << /Length " << contenido.size() << " >> stream\n" << contenido << "\nendstream endobj\n";

    long xref = (long)pdf.tellp();
    pdf << "xref\n0 6\n0000000000 65535 f \n";
    for (int i = 0; i < (int)offsets.size(); i++) {
        char buffer[30];
        sprintf(buffer, "%010ld 00000 n ", offsets[i]);
        pdf << buffer << "\n";
    }
    pdf << "trailer << /Size 6 /Root 1 0 R >>\nstartxref\n" << xref << "\n%%EOF";
    pdf.close();

    cout << "Reporte PDF generado: " << nombreArchivo << endl;
}
