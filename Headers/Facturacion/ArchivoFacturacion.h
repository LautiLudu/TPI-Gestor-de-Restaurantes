#ifndef ARCHIVOFACTURACION_H_INCLUDED
#define ARCHIVOFACTURACION_H_INCLUDED
#pragma once
#include <string>
#include "Facturacion.h"

class ArchivoFacturacion{
public:
    ArchivoFacturacion(std::string nombre = "Facturacion.DAT");

    Facturacion leerRegistro(int pos);
    bool grabarRegistro(Facturacion reg);
    bool modificarRegistro(Facturacion reg, int pos);
    int contarRegistros();
    int buscarRegistroId(int id);
    int generarId();

private:
    std::string _nombre;
};

#endif // ARCHIVOFACTURACION_H_INCLUDED
