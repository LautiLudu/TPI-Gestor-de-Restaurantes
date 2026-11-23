#ifndef MANAGERPRODUCTO_H_INCLUDED
#define MANAGERPRODUCTO_H_INCLUDED
#include "Producto.h"

void mostrarProducto(Producto p);
void cargarProducto();
void listarProductoId();
void bajaProducto();
void reactivarProducto();

///listados
void listarProductoNombre();
void listarProductoPrecio();
void listarProductoCategoria();

///consultas
void consultarProductoId(int id);
void consultarProductoNombre(std::string nombre);
void consultarProductoCategoria(std::string categoria);
void consultarProductoPrecio(int precio);

///informes


#endif // MANAGERPRODUCTO_H_INCLUDED
