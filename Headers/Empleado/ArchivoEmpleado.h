#ifndef ARCHIVOEMPLEADO_H_INCLUDED
#define ARCHIVOEMPLEADO_H_INCLUDED
#pragma once
#include "Empleado.h"
#include <string>

class ArchivoEmpleado{
public:
    ArchivoEmpleado(std::string nombre = "Empleado.DAT");

    Empleado leer(int posicion);
    int agregarRegistro();
    int buscarPorID(int idEmpleado);
    int mostrarRegistros();
    int modificarRegistro();
    int cantidadRegistros();
    int cantidadRegistrosActivos();
    int bajaRegistro();

    //listados
    void listarPorRestaurante();
    void listarPorPuesto();
    void listarOrdenadosPorApellido();
    void listarOrdenadosPorFechaNac();

    //consultar
    void consultarPorID();
    void consultarPorDNI();
    void consultarPorPuesto();
    void consultarPorTurno();
    void consultarPorRestaurante();

private:
    std::string _nombre;
};

//filtro por restaurante: pido idRestaurante y recorro los empleados activos mostrando los que tengan empleado.getidRestaurante() == idRestaurante

//filtro por puesto: pido idPuesto (puedo validarcon archivoPuesto) y muestro los empleados activos con empleado.getidpuesto() == idpuesto

//ordenar por apellido: copio los empleados activos a un vector y los oredno comparando apellido con strcmp(vec[i].getapellido(), vec[j+1].getapellido())>0
//despues recorro vector y llamo a mostrar

//ordenar por fecha de nac: copio los empleados activos a vec y compara año, mes, dia de getFechaNacimiento(), dedpues muestro vector y libero memoria con delete[] vector.

///consultado de emepleados

//por id: pido id, buscarPorID(), y si pos>=0, leo con leer(pos), despues Mostrar();
//por dni: pido dni, busco registroactivo con strcmp(empleado.getDNI(), dni) == 0 y muestra el empleado encontrado (o avisa si no existe)

#endif // ARCHIVOEMPLEADO_H_INCLUDED

