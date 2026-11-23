#include "Fecha.h"

Fecha::Fecha(){
    _Dia = 1;
    _Mes = 2;
    _Anio = 2000;
}

Fecha::Fecha(int Dia, int Mes, int Anio){
    _Dia = Dia;
    _Mes = Mes;
    _Anio = Anio;
}

///setters
void Fecha::setDia(int Dia){
    if(Dia >= 1 && Dia <= 31)
    _Dia = Dia;
}

void Fecha::setMes(int Mes){
    if(Mes >= 1 && Mes <= 12)
    _Mes = Mes;
}

void Fecha::setAnio(int Anio){
    if(Anio >= 1980 && Anio <= 2026)
    _Anio = Anio;
}

///getters
int Fecha::getDia() const{
    return _Dia;
}

int Fecha::getMes() const{
    return _Mes;
}

int Fecha::getAnio() const{
    return _Anio;
}
