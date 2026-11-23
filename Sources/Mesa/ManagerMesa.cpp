#include <iostream>
#include "ManagerMesa.h"
#include "ArchivoMesa.h"
#include "Validaciones.h"
#include "Utilidades.h"
using namespace std;

///convierte el numero de ubicacion en texto
string textoUbicacion(int ubicacion){
    if(ubicacion == 1){
        return "Interior";
    } else{
        return "Terraza";
    }
}

void mostrarMesa(Mesa m){
    cout << m.getIdMesa() << " | Restaurante " << m.getIdRestaurante() << " | " << m.getDescripcion() << " | Sillas: " << m.getCantidadDeSillas()
         << " | " << textoUbicacion(m.getUbicacion()) << " | ";
    if(m.getOcupado() == true){
        cout << "Ocupada" << endl;
    }
    else{
        cout << "Libre" << endl;
    }
}

void cargarMesa(){
    ArchivoMesa a; ///archivo
    Mesa m; ///registro (de mesa)

    m.setIdMesa(a.generarId());
    m.setIdRestaurante(pedirEntero("Id del restaurante en donde se encuentra la mesa: ", 1, 100000));
    m.setDescripcion(pedirTexto("Descripcion: ", 50));
    m.setCantidadDeSillas(pedirEntero("Cantidad de sillas (1 a 50): ", 1, 50));
    m.setUbicacion(pedirEntero("Ubicacion (1: interior, 2: terraza): ", 1, 2));
    m.setOcupado(false); ///una mesa vaa a arrancar libre

    if(a.grabarRegistro(m) == true){
        cout << "Mesa guardada con ID " << m.getIdMesa() << endl;
        cout << "----------------------------" << endl;
    }
    else{
        cout << "Error: no se pudo guardar" << endl;
    }
    system("pause");
    system("cls");
}

void listarMesa(){
    ArchivoMesa a;
    int mostradas = 0;

    int cantidad = a.contarRegistros();
    for(int i = 0; i < cantidad; i++){
        Mesa m = a.leerRegistro(i);

        if(m.getEstado() == true){
            mostrarMesa(m);
            mostradas++;
        }
    }
    if(mostradas == 0){
        cout << "No hay mesas activas" << endl;
    }
    system("pause");
    system("cls");
}

void bajaMesa(){
    ArchivoMesa a;

    int id = pedirEntero("ID de la mesa para ser dada de baja (0 para cancelar): ", 0, 10000);
    if(id == 0){
        cout << "Operacion cancelada." << endl;

        system("pause");
        system("cls");
        return;
    }

    int pos = a.buscarRegistroId(id);

    if(pos == -1){
        cout << "No existe esa mesa." << endl;

        system("pause");
        system("cls");
        return;
    }
    Mesa m = a.leerRegistro(pos);

    if(m.getEstado() == false){
        cout << "Esa mesa ya fue dada de baja." << endl;

        system("pause");
        system("cls");
        return;
    }

    ///una mesa ocupada no se puede dar de baja
    if(m.getOcupado() == true){
        cout << "No se puede dar de baja: la mesa actualmente esta ocupada." << endl;

        system("pause");
        system("cls");
        return;
    }

    mostrarMesa(m);
    if(pedirSiNo("Confirma la baja?") == true){
        m.setEstado(false);

        if(a.modificarRegistro(m, pos)){
            cout << "Baja realizada." << endl;
        } else{
            cout << "Error: no se pudo dar de baja el archivo." << endl;
        }
    }
    system("pause");
    system("cls");
}

void reactivarMesa(){
    ArchivoMesa a;

    int id = pedirEntero("ID de la mesa para ser reactivada (0 para cancelar): ", 0, 10000);
    if(id == 0){
        cout << "Operacion cancelada." << endl;

        system("pause");
        system("cls");
        return;
    }

    int pos = a.buscarRegistroId(id);

    if(pos == -1){
        cout << "No existe esa mesa." << endl;

        system("pause");
        system("cls");
        return;
    }

    Mesa m = a.leerRegistro(pos);
    if(m.getEstado() == true){
        cout << "Esa mesa ya estaba activa." << endl;

        system("pause");
        system("cls");
        return;
    }

    m.setEstado(true);
    if(a.modificarRegistro(m, pos)){
        cout << "Mesa reactivada." << endl;
    } else{
        cout << "Error: no se pudo reactivar el archivo." << endl;
    }
    system("pause");
    system("cls");
}
