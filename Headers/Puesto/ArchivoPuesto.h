#ifndef ARCHIVOPUESTO_H_INCLUDED
#define ARCHIVOPUESTO_H_INCLUDED
#pragma once
#include "Puesto.h"

class ArchivoPuesto{
public:
    ArchivoPuesto(std::string nombre = "Empleado.DAT");

    Puesto leer(int posicion);
    int agregarRegistro();
    int buscarPuesto(int idPuesto);
    int cantidadRegistros();
    int mostrarRegistros();
    int buscarRegistro();
    int bajaRegistro();
    int modificarRegistro();

private:
   std::string _nombre;
};



#endif // ARCHIVOPUESTO_H_INCLUDED
