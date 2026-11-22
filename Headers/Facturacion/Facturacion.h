#pragma once
#include "Fecha.h"

class Facturacion{
public :
    Facturacion();
    Facturacion(int IdFactura, int IdRestaurante, Fecha FechaFacturacion, int MetodoPago, float Propina);

    ///getters
    int getIdFactura() const;
    int getIdRestaurante() const;
    Fecha getFechaFacturacion() const;
    int getMetodoPago() const;
    float getPropina() const;
    bool getEstado() const;

    ///setters
    void setIdFactura(int IdFactura);
    void setIdRestaurante(int IdRestaurante);
    void setFechaFacturacion(Fecha FechaFacturacion);
    void setMetodoPago(int MetodoPago);
    void setPropina(float Propina);
    void setEstado(bool Estado);

private :
    int _IdFactura;
    int _IdRestaurante;
    Fecha _FechaFacturacion;
    int _MetodoPago;///1 efectivo, 2 debito , 3 credito , 4 transferencia
    float _Propina;
    bool _Estado;
};
