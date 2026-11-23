#ifndef MANAGERMESA_H_INCLUDED
#define MANAGERMESA_H_INCLUDED
#include <string>
#include "Mesa.h"

std::string textoUbicacion(int ubicacion);
void mostrarMesa(Mesa m);
void cargarMesa();
void listarMesa();
void bajaMesa();
void reactivarMesa();

///listados
void listarMesaCantSillas();
void listarMesaFiltUbicacion();
void listarMesaFiltOcupado();

///consultas
void consultarMesaRestaurante(std::string Nombre);
void consultarMesaid(int id);
void consultarMesaUbicacion(int ubicacion);
void consultarMesaOcupado(bool ocupado);

///informes


#endif // MANAGERMESA_H_INCLUDED
