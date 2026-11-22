#include "Restaurante.h"
#include <cstring>

Restaurante::Restaurante(){
    _IdRestaurante = 0;
    _Nombre[0] = '\0';
    _Direccion[0] = '\0';
    _Telefono[0] = '\0';
    _Mail[0] = '\0';
    _Estado = true;
}

Restaurante::Restaurante(int IdRestaurante, std::string Nombre, std::string Direccion, std::string Telefono, std::string Mail){
    setIdRestaurante(IdRestaurante);
    setNombre(Nombre);
    setDireccion(Direccion);
    setTelefono(Telefono);
    setMail(Mail);
    _Estado = true;
}

///getters
int Restaurante::getIdRestaurante() const{
    return _IdRestaurante;
}

std::string Restaurante::getNombre() const{
    return _Nombre;
}

std::string Restaurante::getDireccion() const{
    return _Direccion;
}

std::string Restaurante::getTelefono() const{
    return _Telefono;
}

std::string Restaurante::getMail() const{
    return _Mail;
}

bool Restaurante::getEstado() const{
    return _Estado;
}

///setters
void Restaurante::setIdRestaurante(int IdRestaurante){
    _IdRestaurante = IdRestaurante;
}

void Restaurante::setNombre(std::string Nombre){
    if(Nombre.size() <= 20)
    strcpy(_Nombre, Nombre.c_str());
}

void Restaurante::setDireccion(std::string Direccion){
    if(Direccion.size() <= 30)
    strcpy(_Direccion, Direccion.c_str());
}

void Restaurante::setTelefono(std::string Telefono){
    if(Telefono.size() <= 15)
    strcpy(_Telefono, Telefono.c_str());
}

void Restaurante::setMail(std::string Mail){
    if(Mail.size() <= 50)
    strcpy(_Mail, Mail.c_str());
}

void Restaurante::setEstado(bool Estado){
    _Estado = Estado;
}
