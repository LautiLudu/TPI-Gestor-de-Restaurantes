#include <iostream>
#include <cstdio>
#include <string>
#include "ArchivoFacturacion.h"
#include "Utilidades.h"
using namespace std;

ArchivoFacturacion::ArchivoFacturacion(std::string nombre){
    _nombre = nombre;
}

///lee el registro que esta en pos
Facturacion ArchivoFacturacion::leerRegistro(int pos){
    Facturacion reg;

    FILE *archivo = fopen(_nombre.c_str(), "rb");
    if(archivo == nullptr) return reg;

    fseek(archivo, pos * sizeof(Facturacion), SEEK_SET); ///seek_set, empieza a contar desde el principio del archivo
    fread(&reg, sizeof(Facturacion), 1, archivo);
    fclose(archivo);

    return reg;
}

///agrega un registro al final del archivo
bool ArchivoFacturacion::grabarRegistro(Facturacion reg){
    FILE *archivo = fopen(_nombre.c_str(), "ab");
    if(archivo == nullptr) return false;

    bool ok = fwrite(&reg, sizeof(Facturacion), 1, archivo); ///fwrite devuelve 1 si pudo escribir
    fclose(archivo);

    return ok;
}

///pisa el registro de la posicion pos con uno nuevo
bool ArchivoFacturacion::modificarRegistro(Facturacion reg, int pos){
    FILE *archivo = fopen(_nombre.c_str(), "rb+");
    if(archivo == nullptr) return false;

    fseek(archivo, pos * sizeof(Facturacion), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Facturacion), 1, archivo);
    fclose(archivo);

    return ok;
}

///cuantos registros hay
int ArchivoFacturacion::contarRegistros(){
    FILE *archivo = fopen(_nombre.c_str(), "rb");
    if(archivo == nullptr) return 0;

    fseek(archivo, 0, SEEK_END); ///va al final del archivo
    int bytes = ftell(archivo); ///estando en el final, ese numero es el tamanio total
    fclose(archivo);

    return bytes / sizeof(Facturacion);
}

///devuelve la posicion del registro con ese id o -1 si no esta
int ArchivoFacturacion::buscarRegistroId(int id){
    int cantidad = contarRegistros();

    for(int i = 0; i < cantidad; i++){
        Facturacion reg = leerRegistro(i);
        if(reg.getIdFactura() == id){
            return i;
        }
    }
    return -1;
}

///el proximo id es la cantidad de registros + 1
int ArchivoFacturacion::generarId(){
    return contarRegistros() + 1;
}
