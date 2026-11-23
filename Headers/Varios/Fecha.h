#pragma once

class Fecha{
public :
    Fecha();
    Fecha(int Dia , int Mes , int Anio);

    ///setters
    void setDia(int Dia);
    void setMes(int Mes);
    void setAnio(int Anio);

    ///getter
    int getDia() const;
    int getMes() const;
    int getAnio() const;

private :
    int _Dia;
    int _Mes;
    int _Anio;
};
