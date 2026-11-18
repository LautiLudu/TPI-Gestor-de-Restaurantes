#include "Puesto.h"
#include <cstring>

Puesto::Puesto(){
    _IdPuesto = 0;
    _Nombre[0] = '\0';
    _Descripcion[0] = '\0';
    _Estado = true;
}

Puesto::Puesto(int IdPuesto,std::string Nombre,std::string Descripcion){
    setIdPuesto(IdPuesto);
    setNombre(Nombre);
    setDescripcion(Descripcion);
    _Estado = true;
}

///getters
int Puesto::getIdPuesto() const{
    return _IdPuesto;
}

std::string Puesto::getNombre() const{
    return _Nombre;
}

std::string Puesto::getDescripcion() const{
    return _Descripcion;
}

bool Puesto::getEstado() const{
    return _Estado;
}

///setters
void Puesto::setIdPuesto(int IdPuesto){
    _IdPuesto = IdPuesto;
}

void Puesto::setNombre(std::string Nombre){
        if(Nombre.size() <= 20)
    strcpy(_Nombre, Nombre.c_str());
}

void Puesto::setDescripcion(std::string Descripcion){
    if(Descripcion.size() <= 50)
    strcpy(_Descripcion, Descripcion.c_str());
}

void Puesto::setEstado(bool Estado){
    _Estado = Estado;
}





