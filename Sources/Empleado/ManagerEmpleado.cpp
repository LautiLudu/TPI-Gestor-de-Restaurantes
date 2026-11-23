#include <iostream>
#include "ManagerEmpleado.h"
#include "ArchivoEmpleado.h"
#include "Validaciones.h"
#include "Utilidades.h"
using namespace std;

///convierte el numero de turno en texto
string textoTurno(int turno){
    if(turno == 1) return "Manana";
    if(turno == 2) return "Tarde";
    return "Noche";
}

void mostrarEmpleado(Empleado e){
    Fecha f = e.getFechaNacimiento();

    cout << e.getIdEmpleado() << " | " << e.getApellido() << ", " << e.getNombre()
         << " | DNI " << e.getDNI()
         << " | Restaurante " << e.getIdRestaurante()
         << " | Puesto " << e.getIdPuesto()
         << " | " << textoTurno(e.getTurno())
         << " | Nac: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio()
         << " | " << e.getMail() << " | " << e.getTelefono() << endl;
}

///devuelve true si ya hay un empleado activo con ese dni
bool dniRepetido(int dni){
    ArchivoEmpleado a;

    int cantidad = a.contarRegistros();
    for(int i = 0; i < cantidad; i++){
        Empleado e = a.leerRegistro(i);
        if(e.getEstado() == true && e.getDNI() == dni){
            return true;
        }
    }
    return false;
}

///pide un dni y lo repite hasta que no este repetido
int pedirDNI(){
    while(true){
        int dni = pedirEntero("DNI (sin puntos): ", 1000000, 99999999);
        if(dniRepetido(dni) == false){
            return dni;
        }
        cout << "Ya existe un empleado activo con ese DNI." << endl;
    }
}

void cargarEmpleado(){
    ArchivoEmpleado a; ///archivo
    Empleado e; ///registro (de empleado)

    e.setIdEmpleado(a.generarId());
    e.setIdRestaurante(pedirEntero("Id del puesto en que trabaja: ", 1, 100000));
    e.setIdPuesto(pedirEntero("Id del restaurante en que trabaja: ", 1, 100000));
    e.setNombre(pedirTexto("Nombre: ", 20));
    e.setApellido(pedirTexto("Apellido: ", 20));
    e.setDNI(pedirDNI());
    e.setMail(pedirTexto("Mail: ", 50));
    e.setTelefono(pedirTexto("Telefono: ", 15));
    e.setFechaNacimiento(pedirFecha("Fecha de nacimiento:", 1940, 2010));
    e.setTurno(pedirEntero("Turno (1: manana, 2: tarde, 3: noche): ", 1, 3));

    if(a.grabarRegistro(e) == true){
        cout << "Empleado guardado con ID " << e.getIdEmpleado() << endl;
        cout << "----------------------------" << endl;
    }
    else{
        cout << "Error: no se pudo guardar" << endl;
    }
    system("pause");
    system("cls");
}

void listarEmpleado(){
    ArchivoEmpleado a;
    int mostrados = 0;

    int cantidad = a.contarRegistros();
    for(int i = 0; i < cantidad; i++){
        Empleado e = a.leerRegistro(i);

        if(e.getEstado() == true){
            mostrarEmpleado(e);
            mostrados++;
        }
    }

    if(mostrados == 0){
        cout << "No hay empleados activos." << endl;
    }
    system("pause");
    system("cls");
}

void bajaEmpleado(){
    ArchivoEmpleado a;

    int id = pedirEntero("ID del empleado para ser dado de baja (0 para cancelar): ", 0, 10000);
    if(id == 0){
        cout << "Operacion cancelada." << endl;

        system("pause");
        system("cls");
        return;
    }

    int pos = a.buscarRegistroId(id);

    if(pos == -1){
        cout << "No existe ese empleado." << endl;
        system("pause");
        system("cls");
        return;
    }
    Empleado e = a.leerRegistro(pos);

    if(e.getEstado() == false){
        cout << "Ese empleado ya fue dado de baja." << endl;
        system("pause");
        system("cls");
        return;
    }

    mostrarEmpleado(e);
    if(pedirSiNo("Confirma la baja?") == true){
        e.setEstado(false);

        if(a.modificarRegistro(e, pos)){
            cout << "Baja realizada." << endl;
        } else{
            cout << "Error: no se pudo dar de baja en el archivo." << endl;
        }
    }
    system("pause");
    system("cls");
}

void reactivarEmpleado(){
    ArchivoEmpleado a;

    int id = pedirEntero("ID del empleado para ser reactivado (0 para cancelar): ", 0, 10000);
    if(id == 0){
        cout << "Operacion cancelada." << endl;

        system("pause");
        system("cls");
        return;
    }

    int pos = a.buscarRegistroId(id);

    if(pos == -1){
        cout << "No existe ese empleado." << endl;
        system("pause");
        system("cls");
        return;
    }

    Empleado e = a.leerRegistro(pos);
    if(e.getEstado() == true){
        cout << "Ese empleado ya estaba activo." << endl;
        system("pause");
        system("cls");
        return;
    }

    ///si otro empleado activo ya usa ese DNI, no se puede reactivar
    if(dniRepetido(e.getDNI()) == true){
        cout << "No se puede reactivar: hay otro empleado activo con el mismo DNI." << endl;
        system("pause");
        system("cls");
        return;
    }

    e.setEstado(true);
    if(a.modificarRegistro(e, pos)){
        cout << "Empleado reactivado." << endl;
    } else{
        cout << "Error: no se pudo reactivar en el archivo." << endl;
    }
    system("pause");
    system("cls");
}
