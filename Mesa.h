#pragma once
#include "Fecha.h"
#include <string>

class Mesa {
public :
    Mesa();
    Mesa(int IdMesa, int IdRestaurante, std::string Descripcion, int CantidadDeSillas, int Ubicacion, bool Ocupado);

    ///getters
    int getIdMesa() const;
    int getIdRestaurante() const;
    std::string getDescripcion() const;
    int getCantidadDeSillas() const;
    int getUbicacion() const;
    bool getOcupado() const;
    bool getEstado() const;

    ///setters
    void setIdMesa(int IdMesa);
    void setIdRestaurante(int IdRestaurante);
    void setDescripcion(std::string Descripcion);
    void setCantidadDeSillas(int CantidadDeSillas);
    void setUbicacion(int Ubicacion);
    void setOcupado(bool Ocupado);
    void setEstado(bool Estado);

private :
    int _IdMesa;
    int _IdRestaurante;
    char _Descripcion[50];
    int _CantidadDeSillas;
    int _Ubicacion; /// 1 interior , 2 terraza
    bool _Ocupado;
    bool _Estado;
};
