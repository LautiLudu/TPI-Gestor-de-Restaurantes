#include <iostream>
#include <cstdio>
#include <string>
#include "ArchivoDetalleFacturacion.h"
#include "Utilidades.h"
using namespace std;

ArchivoDetalleFacturacion::ArchivoDetalleFacturacion(std::string nombre){
    _nombre = nombre;
}

///lee el registro que esta en pos
DetalleFacturacion ArchivoDetalleFacturacion::leerRegistro(int pos){
    DetalleFacturacion reg;

    FILE *archivo = fopen(_nombre.c_str(), "rb");
    if(archivo == nullptr) return reg;

    fseek(archivo, pos * sizeof(DetalleFacturacion), SEEK_SET); ///seek_set, empieza a contar desde el principio del archivo
    fread(&reg, sizeof(DetalleFacturacion), 1, archivo);
    fclose(archivo);

    return reg;
}

///agrega un registro al final del archivo
bool ArchivoDetalleFacturacion::grabarRegistro(DetalleFacturacion reg){
    FILE *archivo = fopen(_nombre.c_str(), "ab");
    if(archivo == nullptr) return false;

    bool ok = fwrite(&reg, sizeof(DetalleFacturacion), 1, archivo); ///fwrite devuelve 1 si pudo escribir
    fclose(archivo);

    return ok;
}

///pisa el registro de la posicion pos con uno nuevo
bool ArchivoDetalleFacturacion::modificarRegistro(DetalleFacturacion reg, int pos){
    FILE *archivo = fopen(_nombre.c_str(), "rb+");
    if(archivo == nullptr) return false;

    fseek(archivo, pos * sizeof(DetalleFacturacion), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(DetalleFacturacion), 1, archivo);
    fclose(archivo);

    return ok;
}

///cuantos registros hay
int ArchivoDetalleFacturacion::contarRegistros(){
    FILE *archivo = fopen(_nombre.c_str(), "rb");
    if(archivo == nullptr) return 0;

    fseek(archivo, 0, SEEK_END); ///va al final del archivo
    int bytes = ftell(archivo); ///estando en el final, ese numero es el tamanio total
    fclose(archivo);

    return bytes / sizeof(DetalleFacturacion);
}

///devuelve la posicion del registro con ese id o -1 si no esta
int ArchivoDetalleFacturacion::buscarRegistroId(int id){
    int cantidad = contarRegistros();

    for(int i = 0; i < cantidad; i++){
        DetalleFacturacion reg = leerRegistro(i);
        if(reg.getIdDetalleFactura() == id){
            return i;
        }
    }
    return -1;
}

///el proximo id es la cantidad de registros + 1
int ArchivoDetalleFacturacion::generarId(){
    return contarRegistros() + 1;
}
