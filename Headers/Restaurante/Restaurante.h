#pragma once
#include <string>

class Restaurante{
public :
    Restaurante();
    Restaurante(int IdRestaurante, std::string Nombre, std::string Direccion, std::string Telefono, std::string Mail);

    ///getters
    int getIdRestaurante() const;
    std::string getNombre() const;
    std::string getDireccion() const;
    std::string getTelefono() const;
    std::string getMail() const;
    bool getEstado() const;

    ///setters
    void setIdRestaurante(int IdRestaurante);
    void setNombre(std::string Nombre);
    void setDireccion(std::string Direccion);
    void setTelefono(std::string Telefono);
    void setMail(std::string Mail);
    void setEstado(bool Estado);

private :
    int _IdRestaurante;
    char _Nombre[20];
    char _Direccion[30];
    char _Telefono[15];
    char _Mail[50];
    bool _Estado;
};
