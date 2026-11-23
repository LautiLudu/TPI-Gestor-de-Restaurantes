#ifndef MENURESTAURANTE_H_INCLUDED
#define MENURESTAURANTE_H_INCLUDED
#include "Restaurante.h"

void mostrarRestaurante(Restaurante r);
void cargarRestaurante();
void listarRestaurante();
void bajaRestaurante();
void reactivarRestaurante();

///listados
void listarRestauranteNombre();
void listarRestauranteEstado();

///consultas
void consultarRestauranteId(int id);
void consultarRestauranteNombre(std::string nombre);

///informes
int infCapacidadPorRestaurante();
int infFacturacionPorRestaurante();

#endif // MENURESTAURANTE_H_INCLUDED
