#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include "combinaciones_fichas.h"
#include "operaciones_fichas.h"
#include "imprmir.h"
#include "operacion_control.h"
using namespace std;

int main()
{
    unsigned short int f,c,fila,columna,decision;
    f=validar_entradas("ingresa la candtidad de filas: ",1, 174724/50);
    c=validar_entradas("ingresa la candtidad de columnas: ",1,50);
    srand(time(NULL));
    unsigned char *tablero=creacion_tablero1(f,c);
    unsigned short int magnitud_eliminaciones = (f * c + 7) >>3;
    unsigned char *eliminaciones=new unsigned char[magnitud_eliminaciones];
    unsigned short int magnitud_tablero=((unsigned int)f*c*3+7)>>3,cascadas=0,movimientos_totales = 0;
    unsigned int eliminadas=0,combinaciones=0;
    while(true)
    {
        unsigned short int necesita = ((unsigned int)f * c + 7) >> 3;
        if(necesita > magnitud_eliminaciones || necesita*100<65*magnitud_eliminaciones)
        {
            delete [] eliminaciones;
            magnitud_eliminaciones = necesita;
            eliminaciones=new unsigned char[magnitud_eliminaciones]();
        }
        completar_tablero(tablero,eliminaciones,magnitud_eliminaciones,f,c,eliminadas,combinaciones,cascadas);
        cout<<"--------------"<<endl;
        imprimir_tablero(tablero,f,c);
        cout<<"--------------"<<endl;
        imprimir_bytes(tablero,f,c);
        cout<<"--------------"<<endl;
        cout<<"*** fichas eliminadas: "<<eliminadas<<", combinaciones: "<<combinaciones<<", cascadas: "<<cascadas<<" juagadas: "<<movimientos_totales<< "***"<<endl;
        cout<<"--------------"<<endl;
        decision=validar_entradas("que desea hacer? (0=cerrar programa, 1=eliminar ficha, 2=agregar fila,"
                               " 3=eliminar fila, 4=agregar columna,5=eliminar columna): ",0,5);
        if(decision==1)
        {
            fila=validar_entradas("que fila?: ",0,f-1);
            columna=validar_entradas("que columna?: ",0,c-1);
            if(fila==0)
            {
                guardar_ficha(tablero,f,c,fila,columna,ficha_aleatoria());
                eliminadas++;
            }
            else
            {
                cascada(tablero,f,c,fila,columna);
                cascadas++;
                eliminadas++;
            }
            movimientos_totales++;
        }
        else if(decision==2)
        {
            if (f >= 3494 || ((unsigned int)(f+1) * c  * 3 + 7) / 8 > 65535)
            {
                cout<<"***No hay memoria suficiente para agregar la fila***";
            }
            else
            {
            fila=validar_entradas("en que posicion desea agregar la fila?: ",0,f);
            tablero = agregar_fila(tablero,f,c,fila,magnitud_tablero);
            movimientos_totales++;
            }
        }
        else if(decision==3)
        {
            if(f>1)
            {
            fila=validar_entradas("que fila desea eliminar?: ",0,f-1);
            tablero=eliminar_fila(tablero,f,c,fila,magnitud_tablero);
            movimientos_totales++;
            }
            else
            {
                cout<<"***no puedes seguir eliminando filas (minimo deben haber 2)***"<<endl;
            }
        }
        else if (decision == 4)
        {
            if (c >= 50 || ((unsigned int)f * (c+1)  * 3 + 7) / 8 > 65535)
            {
                cout << "***No hay memoria suficiente para agregar la columna***" << endl;
            }
            else
            {
                columna = validar_entradas("en que posicion desea agregar la columna?: ", 0, c);
                tablero = agregar_columna(tablero, f, c, columna,magnitud_tablero);
                movimientos_totales++;
            }
        }
        else if(decision==5)
        {
            if(c>1)
            {
            columna=validar_entradas("que columna desea eliminar?: ",0,c-1);
            tablero = eliminar_columna(tablero,f,c,columna,magnitud_tablero);
            movimientos_totales++;
            }
            else
            {
                cout<<"***no puedes seguir eliminando columnas (minimo deben haber 2)***"<<endl;
            }
        }
        else if(decision==0)
        {
            delete[] tablero;
            delete [] eliminaciones;
            return 0;
        }
    }
}
