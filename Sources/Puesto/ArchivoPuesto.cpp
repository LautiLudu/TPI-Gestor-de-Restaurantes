#include <iostream>
#include <string>
#include <cstdio>
#include "ArchivoPuesto.h"
#include "Utilidades.h"
using namespace std;

ArchivoPuesto::ArchivoPuesto(std::string nombre){
    _nombre = nombre;
}

///lee el registro que esta en pos
Puesto ArchivoPuesto::leerRegistro(int pos){
    Puesto reg;

    FILE *archivo = fopen(_nombre.c_str(), "rb");
    if(archivo == nullptr) return reg;

    fseek(archivo, pos * sizeof(Puesto), SEEK_SET); ///seek_set, empieza a contar desde el principio del archivo
    fread(&reg, sizeof(Puesto), 1, archivo);
    fclose(archivo);

    return reg;
}

///agrega un registro al final del archivo
bool ArchivoPuesto::grabarRegistro(Puesto reg){
    FILE *archivo = fopen(_nombre.c_str(), "ab");
    if(archivo == nullptr) return false;

    bool ok = fwrite(&reg, sizeof(Puesto), 1, archivo); ///fwrite devuelve 1 si pudo escribir
    fclose(archivo);

    return ok;
}

///pisa el registro de la posicion pos con uno nuevo
bool ArchivoPuesto::modificarRegistro(Puesto reg, int pos){
    FILE *archivo = fopen(_nombre.c_str(), "rb+");
    if(archivo == nullptr) return false;

    fseek(archivo, pos * sizeof(Puesto), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Puesto), 1, archivo);
    fclose(archivo);

    return ok;
}

///cuantos registros hay
int ArchivoPuesto::contarRegistros(){
    FILE *archivo = fopen(_nombre.c_str(), "rb");
    if(archivo == nullptr) return 0;

    fseek(archivo, 0, SEEK_END); ///va al final del archivo
    int bytes = ftell(archivo); ///estando en el final, ese numero es el tamanio total
    fclose(archivo);

    return bytes / sizeof(Puesto);
}

///devuelve la posicion del registro con ese id o -1 si no esta
int ArchivoPuesto::buscarRegistroId(int id){
    int cantidad = contarRegistros();

    for(int i = 0; i < cantidad; i++){
        Puesto reg = leerRegistro(i);
        if(reg.getIdPuesto() == id){
            return i;
        }
    }
    return -1;
}

///el proximo id es la cantidad de registros + 1
int ArchivoPuesto::generarId(){
    return contarRegistros() + 1;
}
