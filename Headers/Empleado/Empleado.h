#pragma once
#include "Fecha.h"
#include <string>

class Empleado{
public :
    Empleado();
    Empleado(int IdEmpleado,int IdRestaurante,int IdPuesto,std::string Nombre,std::string Apellido,int DNI,std::string Mail,std::string Telefono,Fecha FechaNacimiento,int Turno);

    ///getters
    int getIdEmpleado() const;
    int getIdRestaurante() const;
    int getIdPuesto() const;
    std::string getNombre() const;
    std::string getApellido() const;
    int getDNI() const;
    std::string getMail() const;
    std::string getTelefono() const;
    Fecha getFechaNacimiento() const;
    int getTurno() const;
    bool getEstado() const;

    ///setters
    void setIdEmpleado(int IdEmpleado);
    void setIdRestaurante(int IdRestaurante);
    void setIdPuesto(int IdPuesto);
    void setNombre(std::string Nombre);
    void setApellido(std::string Apellido);
    void setDNI(int DNI);
    void setMail(std::string Mail);
    void setTelefono(std::string Telefono);
    void setFechaNacimiento(Fecha FechaNacimiento);
    void setTurno(int Turno);
    void setEstado(bool Estado);

private :
    int _IdEmpleado;
    int _IdRestaurante;
    int _IdPuesto;
    char _Nombre[20];
    char _Apellido[20];
    int _DNI;
    char _Mail[50];
    char _Telefono[15];
    Fecha _FechaNacimiento;
    int _Turno;
    bool _Estado;
};
