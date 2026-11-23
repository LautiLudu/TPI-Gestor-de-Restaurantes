#include <iostream>
#include "MenuPrincipal.h"
#include "Utilidades.h"
#include "ManagerRestaurante.h"
#include "ManagerEmpleado.h"
#include "ManagerPuesto.h"
#include "ManagerMesa.h"
#include "ManagerCategoria.h"
#include "ManagerProducto.h"
using namespace std;

///muestra el submenu de una entidad (todos tienen las mismas 4 opciones) y devuelve la opcion elegida
int pedirOpcionSubmenu(string titulo){
    cout << "====  " << titulo << "  ====" << endl;
    cout << "1) Cargar                   " << endl;
    cout << "2) Listar                   " << endl;
    cout << "3) Baja                     " << endl;
    cout << "4) Reactivar                " << endl;
    cout << "  ------------------------  " << endl;
    cout << "0) Volver                   " << endl;

    int opcion = pedirEntero("Opcion: ", 0, 4);
    system("cls");
    return opcion;
}

void menuRestaurante(){
    int opcion;
    do{
        opcion = pedirOpcionSubmenu("RESTAURANTES");
        switch(opcion){
            case 1: cargarRestaurante(); break;
            case 2: listarRestaurante(); break;
            case 3: bajaRestaurante(); break;
            case 4: reactivarRestaurante(); break;
        }
    }while(opcion != 0);
}

void menuEmpleado(){
    int opcion;
    do{
        opcion = pedirOpcionSubmenu("EMPLEADOS");
        switch(opcion){
            case 1: cargarEmpleado(); break;
            case 2: listarEmpleado(); break;
            case 3: bajaEmpleado(); break;
            case 4: reactivarEmpleado(); break;
        }
    }while(opcion != 0);
}

void menuPuesto(){
    int opcion;
    do{
        opcion = pedirOpcionSubmenu("PUESTOS");
        switch(opcion){
            case 1: cargarPuesto(); break;
            case 2: listarPuesto(); break;
            case 3: bajaPuesto(); break;
            case 4: reactivarPuesto(); break;
        }
    }while(opcion != 0);
}

void menuMesa(){
    int opcion;
    do{
        opcion = pedirOpcionSubmenu("MESAS");
        switch(opcion){
            case 1: cargarMesa(); break;
            case 2: listarMesa(); break;
            case 3: bajaMesa(); break;
            case 4: reactivarMesa(); break;
        }
    }while(opcion != 0);
}

void menuCategoria(){
    int opcion;
    do{
        opcion = pedirOpcionSubmenu("CATEGORIAS");
        switch(opcion){
            case 1: cargarCategoria(); break;
            case 2: listarCategoria(); break;
            case 3: bajaCategoria(); break;
            case 4: reactivarCategoria(); break;
        }
    }while(opcion != 0);
}
/*
void menuProducto(){
    int opcion;
    do{
        opcion = pedirOpcionSubmenu("PRODUCTOS");
        switch(opcion){
            case 1: cargarProducto(); break;
            case 2: listarProducto(); break;
            case 3: bajaProducto(); break;
            case 4: reactivarProducto(); break;
        }
    }while(opcion != 0);
}
*/
void menuPrincipal(){
    int opcion;
    do{
        cout << "==== GESTOR DE RESTAURANTES ====" << endl;
        cout << "1) Restaurantes                 " << endl;
        cout << "2) Empleados                    " << endl;
        cout << "3) Puestos                      " << endl;
        cout << "4) Mesas                        " << endl;
        cout << "5) Categorias                   " << endl;
        cout << "6) Productos                    " << endl;
        cout << "--------------------------------" << endl;
        cout << "0) Salir                        " << endl;

        opcion = pedirEntero("Opcion: ", 0, 6);
        system("cls");
        switch(opcion){
            case 1: menuRestaurante(); break;
            case 2: menuEmpleado(); break;
            case 3: menuPuesto(); break;
            case 4: menuMesa(); break;
            case 5: menuCategoria(); break;
            ///case 6: menuProducto(); break;
        }
    }while(opcion != 0);
}
