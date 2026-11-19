#include <iostream>
#include <cstring>
#include <clocale>
#include "ArchivoRestaurante.h"
#include <cstdio>

using namespace std;

ArchivoRestaurante::ArchivoRestaurante(std::string nombre){
    _nombre = nombre;
}

///agrega registros al final del archivo
bool ArchivoRestaurante::grabarRegistro(Restaurante reg){
    FILE *archivo = fopen(_nombre.c_str(), "ab");
    if(archivo == nullptr) return false;

    bool ok = fwrite(&reg, sizeof(Restaurante), 1, archivo);
    fclose(archivo);

    return ok;
}

///lee el registro que esta en pos
Restaurante ArchivoRestaurante::leerRegistro(int pos){
    Restaurante reg;

    FILE *archivo = fopen(_nombre.c_str(), "rb");
    if(archivo == nullptr) return reg;

    fseek(archivo, pos * sizeof(Restaurante), SEEK_SET);
    fread(&reg, sizeof(Restaurante), 1, archivo);
    fclose(archivo);

    return reg;
}

///pisa el registro de la posición pos con uno nuevo
bool ArchivoRestaurante::modificarRegistro(Restaurante reg, int pos){
    FILE *archivo = fopen(_nombre.c_str(), "rb+");
    if(archivo == nullptr) return false;

    fseek(archivo, pos * sizeof(Restaurante), SEEK_SET);

    bool ok = fwrite(&reg, sizeof(Restaurante), 1, archivo);
    fclose(archivo);

    return ok;
}

///cuantos registros hay
int ArchivoRestaurante::contarRegistros(){
    FILE *archivo = fopen(_nombre.c_str(), "rb");
    if(archivo == nullptr) return 0;

    fseek(archivo, 0, SEEK_END);

    int bytes = ftell(archivo);
    fclose(archivo);

    return bytes / sizeof(Restaurante);
}

///devuelve la posicion del registro con ese id o -1 si no esta
int ArchivoRestaurante::buscarRegistro(int id){
    int cantidad = contarRegistros();

    for(int i = 0; i < cantidad; i++){
        Restaurante reg = leerRegistro(i);
        if(reg.getIdRestaurante() == id){
            return i;
        }
    }
    return -1;
}

///el proximo id es la cantidad de registros + 1
int ArchivoRestaurante::generarId(){
    return contarRegistros() + 1;
}


