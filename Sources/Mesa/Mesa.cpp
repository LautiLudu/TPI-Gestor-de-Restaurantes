#include "Mesa.h"
#include <cstring>

Mesa::Mesa(){
    _IdMesa = 0;
    _IdRestaurante = 0;
    _Descripcion[0] = '\0';
    _CantidadDeSillas = 0;
    _Ubicacion = 0;
    _Ocupado = false;
    _Estado = true;
}

Mesa::Mesa(int IdMesa, int IdRestaurante, std::string Descripcion, int CantidadDeSillas, int Ubicacion, bool Ocupado){
    setIdMesa(IdMesa);
    setIdRestaurante(IdRestaurante);
    setDescripcion(Descripcion);
    setCantidadDeSillas(CantidadDeSillas);
    setUbicacion(Ubicacion);
    setOcupado(Ocupado);
    _Estado = true;
}

///getters
int Mesa::getIdMesa() const{
    return _IdMesa;
}

int Mesa::getIdRestaurante() const{
    return _IdRestaurante;
}

std::string Mesa::getDescripcion() const{
    return _Descripcion;
}

int Mesa::getCantidadDeSillas() const{
    return _CantidadDeSillas;
}

int Mesa::getUbicacion() const{
    return _Ubicacion;
}

bool Mesa::getOcupado() const{
    return _Ocupado;
}

bool Mesa::getEstado() const{
    return _Estado;
}

///setters
void Mesa::setIdMesa(int IdMesa){
    _IdMesa = IdMesa;
}

void Mesa::setIdRestaurante(int IdRestaurante){
    _IdRestaurante = IdRestaurante;
}

void Mesa::setDescripcion(std::string Descripcion){
    if(Descripcion.size() <= 50)
    strcpy(_Descripcion, Descripcion.c_str());
}

void Mesa::setCantidadDeSillas(int CantidadDeSillas){
    if(CantidadDeSillas > 0){
        _CantidadDeSillas = CantidadDeSillas;
    }
}

void Mesa::setUbicacion(int Ubicacion){
    if(Ubicacion == 1 || Ubicacion == 2){
        _Ubicacion = Ubicacion;
    }
}

void Mesa::setOcupado(bool Ocupado){
    if(Ocupado == 1 || Ocupado == 0)
    _Ocupado = Ocupado;
}

void Mesa::setEstado(bool Estado){
    if(Estado == 1 || Estado == 0)
    _Estado = Estado;
}
