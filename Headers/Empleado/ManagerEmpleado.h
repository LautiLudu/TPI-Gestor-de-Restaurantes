#ifndef MANAGEREMPLEADO_H_INCLUDED
#define MANAGEREMPLEADO_H_INCLUDED
#include <string>
#include "Empleado.h"

std::string textoTurno(int turno);
void mostrarEmpleado(Empleado e);
void cargarEmpleado();
void listarEmpleado();
void bajaEmpleado();
void reactivarEmpleado();

///listados
void listarEmpleadoRestaurante();
void listarEmpleadoPuesto();
void listarEmpleadoApellido();

///consultas
void consultarEmpleadoPorId(int id);
void consultarEmpleadoPorDNI(int DNI);
void consultarEmpleadoPorPuesto(int puesto);
void consultarEmpleadoPorRestaurante(std::string nombre);

///informes
int infCantidadEmpleadosPorRestaurante();
int infCantidadEmpleadosPorPuestoYTurno();

#endif // MANAGEREMPLEADO_H_INCLUDED
