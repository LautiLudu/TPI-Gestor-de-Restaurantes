#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED
#pragma once
#include <string>
#include "Fecha.h"

int pedirEntero(std::string mensaje, int minimo, int maximo);
float pedirFloat(std::string mensaje, float minimo, float maximo);
std::string pedirTexto(std::string mensaje, int tamanio);
bool pedirSiNo(std::string mensaje);
Fecha pedirFecha(std::string mensaje, int anioMinimo = 1980, int anioMaximo = 2026);

#endif // UTILIDADES_H_INCLUDED
