#ifndef ARCHIVORESTAURANTE_H_INCLUDED
#define ARCHIVORESTAURANTE_H_INCLUDED
#pragma once
#include <string>
#include "Restaurante.h"

class ArchivoRestaurante{
public:
    ArchivoRestaurante(std::string nombre = "Restaurante.DAT");

    Restaurante leerRegistro(int pos);
    bool grabarRegistro(Restaurante reg);
    bool modificarRegistro(Restaurante reg, int pos);
    int contarRegistros();
    int buscarRegistro(int id);
    int generarId();

private:
    std::string _nombre;
};

#endif // ARCHIVORESTAURANTE_H_INCLUDED
