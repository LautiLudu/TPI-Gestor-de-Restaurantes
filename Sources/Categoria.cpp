#include "Categoria.h"
#include <cstring>

Categoria::Categoria(){
    _IdCategoria = 0;
    _Nombre[0] = '/0';
    _Descripcion[0] = '/0';
    _Estado = true;
}
Categoria::Categoria(int IdCategoria, std::string Nombre, std::string Descripcion){
    setIdCategoria(IdCategoria);
    setNombre(Nombre);
    setDescripcion(Descripcion);
    _Estado = true;
}

///getters
int Categoria::getIdCategoria() const {
    return _IdCategoria;
}

std::string Categoria::getNombre() const {
    return _Nombre;
}

std::string Categoria::getDescripcion() const {
    return _Descripcion;
}

bool Categoria::getEstado() const {
    return _Estado;
}

///setters
void Categoria::setIdCategoria(int IdCategoria) {
    if(IdCategoria > 0)
    _IdCategoria = IdCategoria;
}

void Categoria::setNombre(std::string Nombre) {
    if(Nombre.size() <= 20)
    strcpy(_Nombre, Nombre.c_str());
}

void Categoria::setDescripcion(std::string Descripcion) {
    if(Descripcion.size() <= 100)
    strcpy(_Descripcion, Descripcion.c_str());
}

void Categoria::setEstado(bool Estado) {
    _Estado = Estado;
}




