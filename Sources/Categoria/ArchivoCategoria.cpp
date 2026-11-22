#include <iostream>
#include <string>
#include "ArchivoCategoria.h"
#include "Utilidades.h"

using namespace std;

ArchivoCategoria::ArchivoCategoria(std::string nombre){
    _nombre = nombre;
}

///misma logica que en ArchivoRestaurante
Categoria ArchivoCategoria::leerRegistro(int pos){
    Categoria reg;

    FILE *archivo = fopen(_nombre.c_str(), "rb");
    if(archivo == nullptr) return reg;

    fseek(archivo, pos * sizeof(Categoria), SEEK_SET);
    fread(&reg, sizeof(Categoria), 1, archivo);
    fclose(archivo);

    return reg;
}

bool ArchivoCategoria::grabarRegistro(Categoria reg){
    FILE *archivo = fopen(_nombre.c_str(), "ab");
    if(archivo == nullptr) return false;

    bool ok = fwrite(&reg, sizeof(Categoria), 1, archivo);
    fclose(archivo);

    return ok;
}

bool ArchivoCategoria::modificarRegistro(Categoria reg, int pos){
    FILE *archivo = fopen(_nombre.c_str(), "rb+");
    if(archivo == nullptr) return false;

    fseek(archivo, pos * sizeof(Categoria), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Categoria), 1, archivo);
    fclose(archivo);

    return ok;
}

int ArchivoCategoria::contarRegistros(){
    FILE *archivo = fopen(_nombre.c_str(), "rb");
    if(archivo == nullptr) return 0;

    fseek(archivo, 0, SEEK_END);
    int bytes = ftell(archivo);
    fclose(archivo);

    return bytes / sizeof(Categoria);
}

int ArchivoCategoria::buscarRegistro(int id){
    int cantidad = contarRegistros();

    for(int i = 0; i < cantidad; i++){
        Categoria reg = leerRegistro(i);
        if(reg.getIdCategoria() == id){
            return i;
        }
    }
    return -1;
}

int ArchivoCategoria::generarId(){
    return contarRegistros() + 1;
}
