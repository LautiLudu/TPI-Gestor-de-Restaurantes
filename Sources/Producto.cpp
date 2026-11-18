#include "Producto.h"
#include <cstring>

Producto::Producto(){
    _IdProducto = 0;
    _IdRestaurante = 0;
    _Stock = 0;
    _Nombre[0] = '\0';
    _Precio = 0;
    _IdCategoria = 0;
    _Descripcion[0] = '\0';
    _Restriccion[0] = '\0';
    _Estado = true;
}

Producto::Producto(int IdProducto, int IdRestaurante, int Stock, std::string Nombre, float Precio, int IdCategoria, std::string Descripcion, std::string Restriccion){
    setIdProducto(IdProducto);
    setIdRestaurante(IdRestaurante);
    setStock(Stock);
    setNombre(Nombre);
    setPrecio(Precio);
    setIdCategoria(IdCategoria);
    setDescripcion(Descripcion);
    setRestriccion(Restriccion);
    _Estado = true;
}

///getters
int Producto::getIdProducto() const{
    return _IdProducto;
}

int Producto::getIdRestaurante() const{
    return _IdRestaurante;
}

int Producto::getStock() const{
    return _Stock;
}

std::string Producto::getNombre() const{
    return _Nombre;
}

float Producto::getPrecio() const{
    return _Precio;
}

int Producto::getIdCategoria() const{
    return _IdCategoria;
}

std::string Producto::getDescripcion() const{
    return _Descripcion;
}

std::string Producto::getRestriccion() const{
    return _Restriccion;
}
bool Producto::getEstado() const{
    return _Estado;
}

///setters
void Producto::setIdProducto(int IdProducto){
    _IdProducto = IdProducto;
}

void Producto::setIdRestaurante(int IdRestaurante){
    _IdRestaurante = IdRestaurante;
}

void Producto::setStock(int Stock){
    _Stock = Stock;
}

void Producto::setNombre(std::string Nombre){
    if(Nombre.size() <= 50)
    strcpy(_Nombre, Nombre.c_str());
}

void Producto::setPrecio(float Precio){
    if(Precio > 0){
        _Precio = Precio;
    }
}
void Producto::setIdCategoria(int IdCategoria){
    _IdCategoria = IdCategoria;
}

void Producto::setDescripcion(std::string Descripcion){
    if(Descripcion.size() <= 100)
    strcpy(_Descripcion, Descripcion.c_str());
}

void Producto::setRestriccion(std::string Restriccion){
    if(Restriccion.size() <= 30)
    strcpy(_Restriccion, Restriccion.c_str());
}
void Producto::setEstado(bool Estado){
    _Estado = Estado;
}
