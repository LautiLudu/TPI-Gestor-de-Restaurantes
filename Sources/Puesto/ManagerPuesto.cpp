#include <iostream>
#include "ManagerPuesto.h"
#include "ArchivoPuesto.h"
#include "ArchivoEmpleado.h"
#include "Utilidades.h"
using namespace std;

void mostrarPuesto(Puesto p){
    cout << p.getIdPuesto() << " | " << p.getNombre() << " | " << p.getDescripcion() << endl;
}

void cargarPuesto(){
    ArchivoPuesto a; ///archivo
    Puesto p; ///registro (de puesto)

    p.setIdPuesto(a.generarId());
    p.setNombre(pedirTexto("Nombre: ", 20));
    p.setDescripcion(pedirTexto("Descripcion: ", 50));

    if(a.grabarRegistro(p) == true){
        cout << "Puesto guardado con ID " << p.getIdPuesto() << endl;
    }
    else{
        cout << "Error: no se pudo guardar" << endl;
    }
    system("pause");
    system("cls");
}

void listarPuesto(){
    ArchivoPuesto a;
    int mostrados = 0;

    int cantidad = a.contarRegistros();
    for(int i = 0; i < cantidad; i++){
        Puesto p = a.leerRegistro(i);

        if(p.getEstado() == true){
            mostrarPuesto(p);
            mostrados++;
        }
    }
    if(mostrados == 0){
        cout << "No hay puestos activos." << endl;
    }
    system("pause");
    system("cls");
}

///devuelve true si hay algun empleado activo con ese puesto
bool puestoEnUso(int idPuesto){
    ArchivoEmpleado ae;

    int cantidad = ae.contarRegistros();
    for(int i = 0; i < cantidad; i++){
        Empleado e = ae.leerRegistro(i);
        if(e.getEstado() == true && e.getIdPuesto() == idPuesto){
            return true;
        }
    }
    return false;
}

void bajaPuesto(){
    ArchivoPuesto a;

    int id = pedirEntero("ID del puesto para ser dado de baja (0 para cancelar): ", 0, 10000);
    if(id == 0){
        cout << "Operacion cancelada." << endl;

        system("pause");
        system("cls");
        return;
    }

    int pos = a.buscarRegistroId(id);

    if(pos == -1){
        cout << "No existe ese puesto." << endl;

        system("pause");
        system("cls");
        return;
    }
    Puesto p = a.leerRegistro(pos);

    if(p.getEstado() == false){
        cout << "Ese puesto ya fue dado de baja." << endl;

        system("pause");
        system("cls");
        return;
    }

    ///no se puede dar de baja un puesto que todavia usan empleados activos
    if(puestoEnUso(id) == true){
        cout << "No se puede dar de baja: hay empleados activos con este puesto" << endl;

        system("pause");
        system("cls");
        return;
    }

    mostrarPuesto(p);
    if(pedirSiNo("Confirma la baja?") == true){
        p.setEstado(false);

        if(a.modificarRegistro(p, pos)){
            cout << "Baja realizada." << endl;
        } else{
            cout << "Error: no se pudo dar de baja en el archivo" << endl;
        }
    }
    system("pause");
    system("cls");
}

void reactivarPuesto(){
    ArchivoPuesto a;

    int id = pedirEntero("ID del puesto para ser reactivado (0 para cancelar): ", 0, 10000);
    if(id == 0){
        cout << "Operacion cancelada." << endl;

        system("pause");
        system("cls");
        return;
    }
    int pos = a.buscarRegistroId(id);

    if(pos == -1){
        cout << "No existe ese puesto." << endl;

        system("pause");
        system("cls");
        return;
    }

    Puesto p = a.leerRegistro(pos);
    if(p.getEstado() == true){
        cout << "Ese puesto ya estaba activo." << endl;

        system("pause");
        system("cls");
        return;
    }

    p.setEstado(true);
    if(a.modificarRegistro(p, pos)){
        cout << "Puesto reactivado." << endl;
    } else{
        cout << "Error: no se pudo reactivar en el archivo." << endl;
    }
    system("pause");
    system("cls");
}
