#ifndef ARCHIVOMESA_H_INCLUDED
#define ARCHIVOMESA_H_INCLUDED
#pragma once
#include <string>
#include "Mesa.h"

class ArchivoMesa{
public:
    ArchivoMesa(std::string nombre = "Mesa.DAT");

    Mesa leerRegistro(int pos);
    bool grabarRegistro(Mesa reg);
    bool modificarRegistro(Mesa reg, int pos);
    int contarRegistros();
    int buscarRegistroId(int id);
    int generarId();

private:
    std::string _nombre;
};

#endif // ARCHIVOMESA_H_INCLUDED
