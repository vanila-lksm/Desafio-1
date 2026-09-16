#include <iostream>
#include "funciones.h"
#include <cstdlib>
#include <ctime>
#include <new>
using namespace std;

int main()
{
    unsigned short int f,c,fila,columna,decision;
    f=leer_numero("ingresa la candtidad de filas: ",1, 65535);
    cout<<f<<endl;
    c=leer_numero("ingresa la candtidad de columnas: ",1,(174760/f > 65535) ? 65535 : 174760/f);
    srand(time(NULL));
    unsigned char *tablero=creacion_tablero1(f,c);
    unsigned short int magnitud_tablero=(f*c*3+7)/8;
    while(true)
    {
        imprimir_tablero(tablero,f,c);
        imprimir_bytes(tablero,f,c);
        cout<<"magnitud: "<<magnitud_tablero<<endl;
        decision=leer_numero("que desea hacer? (0=cerrar programa, 1=eliminar ficha, 2=agregar fila,"
                               " 3=eliminar fila, 4=agregar columna, 5=eliminar columna): ",0,5);
        if(decision==1)
        {
            fila=leer_numero("que fila?: ",0,f-1);
            columna=leer_numero("que columna?: ",0,c-1);
            //if(fila==0)
            guardar_ficha(tablero,f,c,fila,columna,ficha_aleatoria());
        }
        else if(decision==2)
        {
            if (f == 65535 || ((f+1) * c  * 3 + 7) / 8 > 65535)
            {
                cout<<"***No hay memoria suficiente para agregar la fila***";
            }
            else
            {
            fila=leer_numero("en que posicion desea agregar la fila?: ",0,f+1);
            tablero = agregar_fila(tablero,f,c,fila,magnitud_tablero);
            }
        }
        else if(decision==3)
        {
            if(f>1)
            {
            fila=leer_numero("que fila desea eliminar?: ",0,f-1);
            tablero=eliminar_fila(tablero,f,c,fila,magnitud_tablero);
            }
            else
            {
                cout<<"***no puedes seguir eliminando filas (minimo deben haber 2)***"<<endl;
            }
        }
        else if (decision == 4)
        {
            if (f == 65535 || (f * (c+1)  * 3 + 7) / 8 > 65535)
            {
                cout << "***No hay memoria suficiente para agregar la columna***" << endl;
            }
            else
            {
                columna = leer_numero("en que posicion desea agregar la columna?: ", 0, c);
                tablero = agregar_columna(tablero, f, c, columna,magnitud_tablero);
            }
        }
        else if(decision==5)
        {
            if(c>1)
            {
            columna=leer_numero("que columna desea eliminar?: ",0,c-1);
            tablero = eliminar_columna(tablero,f,c,columna,magnitud_tablero);
            }
            else
            {
                cout<<"***no puedes seguir eliminando columnas (minimo deben haber 2)***"<<endl;
            }
        }
        else if(decision==0)
        {
            delete[] tablero;
            return 0;
        }
    }
}
