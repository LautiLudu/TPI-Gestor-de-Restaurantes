#include <iostream>
#include <cstring>
#include "ManagerCategoria.h"
#include "ArchivoCategoria.h"
#include "Utilidades.h"

using namespace std;

void mostrarCategoria(Categoria c){
    cout << c.getIdCategoria() << " | " << c.getNombre() << " | " << c.getDescripcion() << endl;
}

void cargarCategoria(){
    ArchivoCategoria a; ///archivo
    Categoria c; ///registro (de categoria)

    c.setIdCategoria(a.generarId());
    c.setNombre(pedirTexto("Nombre: ", 20));
    c.setDescripcion(pedirTexto("Descripcion: ", 100));

    if(a.grabarRegistro(c) == true){
        cout << "Categoria guardado con ID " << c.getIdCategoria() << endl;
        cout << "----------------------------" << endl;

        system("pause");
        system("cls");
    } else{
        cout << "Error: no se pudo guardar" << endl;
    }
}

void listarCategoria(){
    ArchivoCategoria a;

    int cantidad = a.contarRegistros();
    for(int i = 0; i < cantidad; i++){
        Categoria c = a.leerRegistro(i);

        if(c.getEstado() == true){
            cout << c.getIdCategoria() << " | " << c.getNombre() << " | " << c.getDescripcion() << endl;
        }
    }
    system("pause");
    system("cls");
}

void bajaCategoria(){
    ArchivoCategoria a;

    int id = pedirEntero("ID de la categoria para ser dada de baja (0 para cancelar): ", 0, 10000);
    if(id == 0){
        cout << "Operacion cancelada." << endl;

        system("pause");
        system("cls");
        return;
    }

    int pos = a.buscarRegistroId(id);

    if(pos == -1){
        cout << "No existe esa categoria." << endl;

        system("pause");
        system("cls");
        return;
    }
    Categoria c = a.leerRegistro(pos);

    if(c.getEstado() == false){
        cout << "Esa categoria ya fue dada de baja." << endl;

        system("pause");
        system("cls");
        return;
    }

    mostrarCategoria(c);
    if(pedirSiNo("Confirma la baja?") == true){
        c.setEstado(false);

        if(a.modificarRegistro(c, pos) == true){
            cout << "Baja realizada." << endl;
        } else{
            cout << "Error: no se pudo dar de baja el archivo." << endl;
        }
    }
    system("pause");
    system("cls");
}

void reactivarCategoria(){
    ArchivoCategoria a;

    int id = pedirEntero("ID de la categoria para ser reactivado (0 para cancelar): ", 0, 10000);
    if(id == 0){
        cout << "Operacion cancelada." << endl;

        system("pause");
        system("cls");
        return;
    }

    int pos = a.buscarRegistroId(id);

    if(pos == -1){
        cout << "No existe esa categoria." << endl;
        return;
    }

    Categoria c = a.leerRegistro(pos);
    if(c.getEstado() == true){
        cout << "Esa categoria ya estaba activa" << endl;
        return;
    }

    c.setEstado(true);
    if(a.modificarRegistro(c, pos)){
        cout << "Categoria reactivada." << endl;
    } else{
        cout << "Error: no se pudo reactivar el archivo." << endl;
    }
    system("pause");
    system("cls");
}
