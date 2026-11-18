#pragma once

class DetalleFacturacion{
public:
    DetalleFacturacion();
    DetalleFacturacion(int IdDetalleFactura,int IdFactura,int IdProducto,int Cantidad,float PrecioUnitario);

    ///getters
    int getIdDetalleFactura() const;
    int getIdFactura() const;
    int getIdProducto() const;
    int getCantidad() const;
    float getPrecioUnitario() const;
    bool getEstado() const;

    ///setters
    void setIdDetalleFactura(int IdDetalleFactura);
    void setIdFactura(int IdFactura);
    void setIdProducto(int IdProducto);
    void setCantidad(int Cantidad);
    void setPrecioUnitario(float PrecioUnitario);
    void setEstado(bool Estado);

private:
    int _IdDetalleFactura;
    int _IdFactura;
    int _IdProducto;
    int _Cantidad;
    float _PrecioUnitario;
    bool _Estado;
};
