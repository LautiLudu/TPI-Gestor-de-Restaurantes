#ifndef ARCHIVOPUESTO_H_INCLUDED
#define ARCHIVOPUESTO_H_INCLUDED
#pragma once
#include <string>
#include "Puesto.h"

class ArchivoPuesto{
public:
    ArchivoPuesto(std::string nombre = "Puesto.DAT");

    Puesto leerRegistro(int pos);
    bool grabarRegistro(Puesto reg);
    bool modificarRegistro(Puesto reg, int pos);
    int contarRegistros();
    int buscarRegistroId(int id);
    int generarId();

private:
    std::string _nombre;
};

#endif // ARCHIVOPUESTO_H_INCLUDED
