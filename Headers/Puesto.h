#pragma once
#include <string>

class Puesto {
public :
    Puesto();
    Puesto(int IdPuesto,std::string Nombre,std::string Descripcion);

    ///getters
    int getIdPuesto() const;
    std::string getNombre() const;
    std::string getDescripcion() const;
    bool getEstado() const;

    ///setters
    void setIdPuesto(int IdPuesto);
    void setNombre(std::string Nombre);
    void setDescripcion(std::string Descripcion);
    void setEstado(bool Estado);

private :
    int _IdPuesto;
    char _Nombre[20];
    char _Descripcion[50];
    bool _Estado;
};
