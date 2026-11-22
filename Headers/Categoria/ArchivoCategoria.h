#ifndef ARCHIVOCATEGORIA_H_INCLUDED
#define ARCHIVOCATEGORIA_H_INCLUDED
#pragma once
#include <string>
#include "Categoria.h"

class ArchivoCategoria{
public:
    ArchivoCategoria(std::string nombre = "Categoria.DAT");

    Categoria leerRegistro(int pos);
    bool grabarRegistro(Categoria reg);
    bool modificarRegistro(Categoria reg, int pos);
    int contarRegistros();
    int buscarRegistro(int id);
    int generarId();
    int bajaCategoria();

private:
    std::string _nombre;
};

#endif // ARCHIVOCATEGORIA_H_INCLUDED

