#include <iostream>
#include <cstdio>
#include <string>
#include "ArchivoMesa.h"
#include "Utilidades.h"
using namespace std;

ArchivoMesa::ArchivoMesa(std::string nombre){
    _nombre = nombre;
}

///lee el registro que esta en pos
Mesa ArchivoMesa::leerRegistro(int pos){
    Mesa reg;

    FILE *archivo = fopen(_nombre.c_str(), "rb");
    if(archivo == nullptr) return reg;

    fseek(archivo, pos * sizeof(Mesa), SEEK_SET); ///seek_set, empieza a contar desde el principio del archivo
    fread(&reg, sizeof(Mesa), 1, archivo);
    fclose(archivo);

    return reg;
}

///agrega un registro al final del archivo
bool ArchivoMesa::grabarRegistro(Mesa reg){
    FILE *archivo = fopen(_nombre.c_str(), "ab");
    if(archivo == nullptr) return false;

    bool ok = fwrite(&reg, sizeof(Mesa), 1, archivo); ///fwrite devuelve 1 si pudo escribir
    fclose(archivo);

    return ok;
}

///pisa el registro de la posicion pos con uno nuevo
bool ArchivoMesa::modificarRegistro(Mesa reg, int pos){
    FILE *archivo = fopen(_nombre.c_str(), "rb+");
    if(archivo == nullptr) return false;

    fseek(archivo, pos * sizeof(Mesa), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Mesa), 1, archivo);
    fclose(archivo);

    return ok;
}

///cuantos registros hay
int ArchivoMesa::contarRegistros(){
    FILE *archivo = fopen(_nombre.c_str(), "rb");
    if(archivo == nullptr) return 0;

    fseek(archivo, 0, SEEK_END); ///va al final del archivo
    int bytes = ftell(archivo); ///estando en el final, ese numero es el tamanio total
    fclose(archivo);

    return bytes / sizeof(Mesa);
}

///devuelve la posicion del registro con ese id o -1 si no esta
int ArchivoMesa::buscarRegistroId(int id){
    int cantidad = contarRegistros();

    for(int i = 0; i < cantidad; i++){
        Mesa reg = leerRegistro(i);
        if(reg.getIdMesa() == id){
            return i;
        }
    }
    return -1;
}

///el proximo id es la cantidad de registros + 1
int ArchivoMesa::generarId(){
    return contarRegistros() + 1;
}
