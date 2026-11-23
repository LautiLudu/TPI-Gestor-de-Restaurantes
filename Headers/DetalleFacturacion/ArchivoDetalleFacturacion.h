#ifndef ARCHIVODETALLEFACTURACION_H_INCLUDED
#define ARCHIVODETALLEFACTURACION_H_INCLUDED
#pragma once
#include <string>
#include "DetalleFacturacion.h"

class ArchivoDetalleFacturacion{
public:
    ArchivoDetalleFacturacion(std::string nombre = "DetalleFacturacion.DAT");

    DetalleFacturacion leerRegistro(int pos);
    bool grabarRegistro(DetalleFacturacion reg);
    bool modificarRegistro(DetalleFacturacion reg, int pos);
    int contarRegistros();
    int buscarRegistroId(int id);
    int generarId();

private:
    std::string _nombre;
};

#endif // ARCHIVODETALLEFACTURACION_H_INCLUDED
