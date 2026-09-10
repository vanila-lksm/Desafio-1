#include <iostream>
#include "funciones.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    unsigned short int f,c,fila,columna,decision,estado=1;
    cout<<"ingresa la candtidad de filas: ";
    cin>>f;
    cout<<"ingresa la candtidad de columnas: ";
    cin>>c;
    unsigned char *tablero=creacion_tablero1(f,c);
    unsigned short int total_bytes = ((f*c*3)+7)/8;
    srand(time(NULL));
    while(estado!=0)
    {
        imprimir_tablero(tablero,f,c,total_bytes);
        cout<<"desea eliminar una ficha? (1=si o 2=no): ";
        cin>>decision;
        if(decision==1)
        {
            cout<<"que fila?: ";
            cin>>fila;
            cout<<"que columna?: ";
            cin>>columna;
            eliminar_ficha(tablero,c,fila,columna,total_bytes);
        }
        cout<<"desea finalizar? (1=no 0=si): ";
        cin>>estado;
    }

}
