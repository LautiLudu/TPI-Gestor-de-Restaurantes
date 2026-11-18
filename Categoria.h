#pragma once
#include <string>

class Categoria {
public:
    Categoria();
    Categoria(int IdCategoria , std::string Nombre , std::string Descripcion );// no se le pone el estado por que eso no lo hace el usuario

    ///getters
    int getIdCategoria() const;
    std::string getNombre() const;
    std::string getDescripcion() const;
    bool getEstado() const;

    ///setters
    void setIdCategoria(int IdCategoria);
    void setNombre(std::string Nombre);
    void setDescripcion(std::string Descripcion);
    void setEstado(bool Estado);

private:
    int _IdCategoria;
    char _Nombre[20];
    char _Descripcion[50];
    bool _Estado;
};
