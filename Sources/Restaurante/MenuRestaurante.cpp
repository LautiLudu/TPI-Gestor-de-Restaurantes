#include <iostream>
#include <cstring>
#include "MenuRestaurante.h"
#include "ArchivoRestaurante.h"
#include "Utilidades.h"
using namespace std;

void mostrarRestaurante(Restaurante r){
     cout << r.getIdRestaurante() << " | " << r.getNombre() << " | " << r.getDireccion() << " | " << r.getTelefono() << " | " << r.getMail() << endl;
}

void cargarRestaurante(){
    ArchivoRestaurante a; ///archivo
    Restaurante r; ///registro (de restaurante)

    r.setIdRestaurante(a.generarId());
    r.setNombre(pedirTexto("Nombre: ", 20));
    r.setDireccion(pedirTexto("Direccion: ", 30));
    r.setTelefono(pedirTexto("Telefono: ", 15));
    r.setMail(pedirTexto("Mail: ", 50));

    if(a.grabarRegistro(r) == true){
        cout << "Restaurante guardado con ID " << r.getIdRestaurante() << endl;
        cout << "----------------------------" << endl;
        system("pause");
        system("cls");
    }
    else{
        cout << "Error: no se pudo guardar" << endl;
    }
}

void listarRestaurante(){
    ArchivoRestaurante a;

    int cantidad = a.contarRegistros();
    for(int i = 0; i < cantidad; i++){
        Restaurante r = a.leerRegistro(i);

        if(r.getEstado() == true){
            cout << r.getIdRestaurante() << " | " << r.getNombre() << " | " << r.getDireccion() << " | " << r.getTelefono() << " | " << r.getMail() << endl;
        }
    }
    system("pause");
    system("cls");
}

void bajaRestaurante(){
    ArchivoRestaurante a;

    int id = pedirEntero("ID del restaurante para ser dada de baja (0 para cancelar): ", 0, 10000);
    if(id == 0) return;

    int pos = a.buscarRegistro(id);

    if(pos == -1){
        cout << "No existe ese restaurante." << endl;
        system("pause");
        system("cls");
        return;
    }
    Restaurante r = a.leerRegistro(pos);

    if(r.getEstado() == false){
        cout << "Ese restaurante ya fue dada de baja." << endl;
        system("pause");
        system("cls");
        return;
    }

    mostrarRestaurante(r);
    if(pedirSiNo("Confirma la baja?") == true){
        r.setEstado(false);

        if(a.modificarRegistro(r, pos)){
            cout << "Baja realizada." << endl;
        } else{
            cout << "Error: no se pudo dar de baja el archivo." << endl;
        }
    }
    system("pause");
    system("cls");
}

void reactivarRestaurante(){
    ArchivoRestaurante a;

    int id = pedirEntero("ID del restaurante para ser reactivado (0 para cancelar): ", 0, 10000);
    if(id == 0) return;

    int pos = a.buscarRegistro(id);

    if(pos == -1){
        cout << "No existe ese restaurante." << endl;
        return;
    }

    Restaurante r = a.leerRegistro(pos);
    if(r.getEstado() == true){
        cout << "Ese restaurante ya estaba activo" << endl;
        return;
    }

    r.setEstado(true);
    if(a.modificarRegistro(r, pos)){
        cout << "Restaurante reactivado." << endl;
    } else{
        cout << "Error: no se pudo reactivar el archivo." << endl;
    }
    system("pause");
    system("cls");
}

