#include <iostream>
#include <cstring>
#include "Utilidades.h"
using namespace std;

int pedirEntero(string mensaje, int minimo, int maximo){
    int valor;
    while(true){
        cout << mensaje;
        cin >> valor;
        if(cin.fail() == true){ ///si el tipo de dato es incorrecto, cin.fail devuelve true
            cin.clear(); ///cin queda en error y cin.clear restablece el estado
            cin.ignore(1000, '\n'); ///limpia el buffer
            cout << "Debe ingresar un numero." << endl;
        }
        else{
            cin.ignore(100, '\n'); ///queda un enter (\0) guardado, esto limpia el buffer de nuevo
            if(valor >= minimo && valor <= maximo){
                return valor;
            }
            cout << "El valor debe estar entre " << minimo << " y " << maximo << "." << endl;
        }
    }
}

///misma logica que pedirEntero, pero con float
float pedirFloat(string mensaje, float minimo, float maximo){
    float valor;
    while(true){
        cout << mensaje;
        cin >> valor;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Debe ingresar un numero (punto para decimales)." << endl;
        }
        else{
            cin.ignore(1000, '\n');
            if(valor >= minimo && valor <= maximo){
                return valor;
            }
            cout << "El valor debe estar entre " << minimo << " y " << maximo << "." << endl;
        }
    }
}

string pedirTexto(string mensaje, int tamanio){
    string texto;

    while(true){
        cout << mensaje;
        getline(cin, texto);
    if((int)texto.size() == 0){
        cout << "No puede estar vacio." << endl;
        }
    else if((int)texto.size() >= tamanio){
        cout << "Maximo " << tamanio - 1 << " caracteres." << endl;
    }
    else{
        return texto;
        }
    }
}
bool pedirSiNo(string mensaje){
    char respuesta;
    while(true){
        cout << mensaje << " (s/n): ";
        cin >> respuesta;
        cin.ignore(1000, '\n');

        if(respuesta == 's' || respuesta == 'S') return true;

        if(respuesta == 'n' || respuesta == 'N'){
        cout << "Responda s o n." << endl;
        return false;
        }
    }
}

bool esBisiesto(int anio){
    if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){
        return true;
    } else{
        return false;
    }
}

int diasDelMes(int mes, int anio){
    if(mes == 2){
        if(esBisiesto(anio) == true){
            return 29;
        } else{
            return 28;
        }
    }
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    } else{
        return 31;
    }
}

Fecha pedirFecha(string mensaje, int anioMinimo, int anioMaximo){
    int dia, mes, anio;
    cout << mensaje << endl;

    anio = pedirEntero("Anio: ", anioMinimo, anioMaximo);
    mes = pedirEntero("Mes: ", 1, 12);
    dia = pedirEntero("Dia: ", 1, diasDelMes(mes, anio));

    return Fecha(dia, mes, anio);
}
