#include "Facturacion.h"
#include "Fecha.h"

Facturacion::Facturacion(){
    _IdFactura = 0;
    _IdRestaurante = 0;
    _MetodoPago = 0;
    _Propina = 0;
    _Estado = true;
}

Facturacion::Facturacion(int IdFactura, int IdRestaurante, Fecha FechaFacturacion, int MetodoPago, float Propina){
    setIdFactura(IdFactura);
    setIdRestaurante(IdRestaurante);
    setFechaFacturacion(FechaFacturacion);
    setMetodoPago(MetodoPago);
    setPropina(Propina);
    _Estado = true;
}

///getters
int Facturacion::getIdFactura() const{
    return _IdFactura;
}

int Facturacion::getIdRestaurante() const{
    return _IdRestaurante;
}

Fecha Facturacion::getFechaFacturacion() const{
    return _FechaFacturacion;
}

int Facturacion::getMetodoPago() const{
    return _MetodoPago;
}

float Facturacion::getPropina() const{
    return _Propina;
}

bool Facturacion::getEstado() const{
    return _Estado;
}

///setters
void Facturacion::setIdFactura(int IdFactura){
    _IdFactura = IdFactura;
}

void Facturacion::setIdRestaurante(int IdRestaurante){
    _IdRestaurante = IdRestaurante;
}

void Facturacion::setFechaFacturacion(Fecha FechaFacturacion){
    ///falta validacion
    _FechaFacturacion = FechaFacturacion;
}

void Facturacion::setMetodoPago(int MetodoPago){
    if(MetodoPago == 1 || MetodoPago == 2 || MetodoPago == 3)
    _MetodoPago = MetodoPago;
}

void Facturacion::setPropina(float Propina){
    if(Propina >= 0){
        _Propina = Propina;
    }
}

void Facturacion::setEstado(bool Estado){
    _Estado = Estado;
}
