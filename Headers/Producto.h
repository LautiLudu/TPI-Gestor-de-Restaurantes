#pragma once
#include <string>

class Producto {
public :
    Producto();
    Producto(int IdProducto, int IdRestaurante, int Stock, std::string Nombre, float Precio, int IdCategoria, std::string Descripcion, std::string Restriccion);

    ///getters
    int getIdProducto() const;
    int getIdRestaurante() const;
    int getStock() const;
    std::string getNombre() const;
    float getPrecio() const;
    int getIdCategoria() const;
    std::string getDescripcion() const;
    std::string getRestriccion() const;
    bool getEstado()const;

    ///setters
    void setIdProducto(int IdProducto);
    void setIdRestaurante(int IdRestaurante);
    void setStock(int stock);
    void setNombre(std::string Nombre);
    void setPrecio(float Precio);
    void setIdCategoria(int IdCategoria);
    void setDescripcion(std::string Descripcion);
    void setRestriccion(std::string Restriccion);
    void setEstado(bool Estado);

private :
    int _IdProducto;
    int _IdRestaurante;
    int _Stock;
    char _Nombre[50];
    float _Precio;
    int _IdCategoria;
    char _Descripcion[100];
    char _Restriccion[30];
    bool _Estado;
};
