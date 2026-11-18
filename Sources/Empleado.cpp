#include "Empleado.h"
#include <cstring>

Empleado::Empleado(){
    _IdEmpleado = 0;
    _IdRestaurante = 0;
    _IdPuesto = 0;
    _Nombre[0] = '\0';
    _Apellido[0] = '\0';
    _DNI = 0;
    _Mail[0] = '\0';
    _Telefono[0] = '\0';
    _Turno = 0;
    _Estado = true;
}

Empleado::Empleado(int IdEmpleado,int IdRestaurante,int IdPuesto,std::string Nombre,std::string Apellido,int DNI,std::string Mail,std::string Telefono,Fecha FechaNacimiento,int Turno){
    setIdEmpleado(IdEmpleado);
    setIdRestaurante(IdRestaurante);
    setIdPuesto(IdPuesto);
    setNombre(Nombre);
    setApellido(Apellido);
    setDNI(DNI);
    setMail(Mail);
    setTelefono(Telefono);
    setFechaNacimiento(FechaNacimiento);
    setTurno(Turno);
    _Estado = true;
}
///getters
int Empleado::getIdEmpleado() const{
    return _IdEmpleado;
}

int Empleado::getIdRestaurante() const{
    return _IdRestaurante;
}

int Empleado::getIdPuesto() const{
    return _IdPuesto;
}

std::string Empleado::getNombre() const{
    return _Nombre;
}

std::string Empleado::getApellido() const{
    return _Apellido;
}

int Empleado::getDNI() const{
    return _DNI;
}

std::string Empleado::getMail() const{
    return _Mail;
}

std::string Empleado::getTelefono() const{
    return _Telefono;
}

Fecha Empleado::getFechaNacimiento() const{
    return _FechaNacimiento;
}

int Empleado::getTurno() const{
    return _Turno;
}

bool Empleado::getEstado() const{
    return _Estado;
}

///setters
void Empleado::setIdEmpleado(int IdEmpleado){
    if(IdEmpleado > 0)
    _IdEmpleado = IdEmpleado;
}

void Empleado::setIdRestaurante(int IdRestaurante){
    if(IdRestaurante > 0 )
    _IdRestaurante = IdRestaurante;
}

void Empleado::setIdPuesto(int IdPuesto){
    _IdPuesto = IdPuesto;
}

void Empleado::setNombre(std::string Nombre){
    if(Nombre.size() <= 20)
    strcpy(_Nombre, Nombre.c_str());
}

void Empleado::setApellido(std::string Apellido){
    if(Apellido.size() <= 20)
    strcpy(_Apellido, Apellido.c_str());
}

void Empleado::setDNI(int DNI){
    if(DNI > 0)
    _DNI = DNI;
}

void Empleado::setMail(std::string Mail){
    if(Mail.size() <= 50)
    strcpy(_Mail, Mail.c_str());
}

void Empleado::setTelefono(std::string Telefono){
    if(Telefono.size() <= 15)
    strcpy(_Telefono, Telefono.c_str());
}

void Empleado::setFechaNacimiento(Fecha FechaNacimiento){
    ///validar
    _FechaNacimiento = FechaNacimiento;
}

void Empleado::setTurno(int Turno){
    if(Turno == 1 || Turno == 2 || Turno == 3)
    _Turno = Turno;
}

void Empleado::setEstado(bool Estado){
    _Estado = Estado;
}
