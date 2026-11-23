#ifndef ARCHIVOPRODUCTO_H_INCLUDED
#define ARCHIVOPRODUCTO_H_INCLUDED
#pragma once
#include <string>
#include "Producto.h"

class ArchivoProducto{
public:
    ArchivoProducto(std::string nombre = "Producto.DAT");

    Producto leerRegistro(int pos);
    bool grabarRegistro(Producto reg);
    bool modificarRegistro(Producto reg, int pos);
    int contarRegistros();
    int buscarRegistroId(int id);
    int generarId();

private:
    std::string _nombre;
};

#endif // ARCHIVOPRODUCTO_H_INCLUDED
