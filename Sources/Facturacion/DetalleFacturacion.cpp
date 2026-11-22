#include "DetalleFacturacion.h"

DetalleFacturacion::DetalleFacturacion(){
    _IdDetalleFactura = 0;
    _IdFactura = 0;
    _IdProducto = 0;
    _Cantidad = 0;
    _PrecioUnitario = 0;
    _Estado = true;
}

DetalleFacturacion::DetalleFacturacion(int IdDetalleFactura,int IdFactura,int IdProducto,int Cantidad,float PrecioUnitario){
    setIdDetalleFactura(IdDetalleFactura);
    setIdFactura(IdFactura);
    setIdProducto(IdProducto);
    setCantidad(Cantidad);
    setPrecioUnitario(PrecioUnitario);
    _Estado = true;
}

///getters
int DetalleFacturacion::getIdDetalleFactura() const{
    return _IdDetalleFactura;
}

int DetalleFacturacion::getIdFactura() const{
    return _IdFactura;
}

int DetalleFacturacion::getIdProducto() const{
    return _IdProducto;
}

int DetalleFacturacion::getCantidad() const{
    return _Cantidad;
}

float DetalleFacturacion::getPrecioUnitario() const{
    return _PrecioUnitario;
}

bool DetalleFacturacion::getEstado() const{
    return _Estado;
}

///setters
void DetalleFacturacion::setIdDetalleFactura(int IdDetalleFactura){
    _IdDetalleFactura = IdDetalleFactura;
}

void DetalleFacturacion::setIdFactura(int IdFactura){
    _IdFactura = IdFactura;
}

void DetalleFacturacion::setIdProducto(int IdProducto){
    _IdProducto = IdProducto;
}

void DetalleFacturacion::setCantidad(int Cantidad){
    if(Cantidad > 0)
    _Cantidad = Cantidad;
}

void DetalleFacturacion::setPrecioUnitario(float PrecioUnitario){
    if(PrecioUnitario > 0)
    _PrecioUnitario = PrecioUnitario;
}

void DetalleFacturacion::setEstado(bool Estado){
    _Estado = Estado;
}
