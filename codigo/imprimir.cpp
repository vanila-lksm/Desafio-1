#include <iostream>
#include "operaciones_fichas.h"
#include "imprmir.h"
using namespace std;

void imprimir_tablero(unsigned char *tablero,unsigned short int f,
                      unsigned short int c)
{
    unsigned char figura[6]={'#','=','%','$','+','?'};
    for(unsigned short int fila=0;fila<f;fila++)
    {
        if(fila<=9)cout<<"   " <<fila<<"|";
        else if(fila<=99)cout<<"  " <<fila<<"|";
        else if(fila<=999)cout<<" " <<fila<<"|";
        else cout<<fila <<"|";
        for(unsigned short int columna=0;columna<c;columna++)
        {
            unsigned char valor = leer_ficha(tablero,f,c,fila,columna);
            cout<<figura[valor-1];
            if (columna < c-1) cout << "  ";
        }
        cout<<"|"<<endl;
    }
    unsigned short int col=0;
    cout<<"   ";
    while(col<c)
    {
        if(col<=9)cout<<"  "<<col;
        else if(col<=99)cout<<" "<<col;
        else cout<<col;
        col++;
    }
    cout<<endl;
}

void imprimir_bytes(unsigned char *tablero,unsigned short int f,
                    unsigned short int c)
{
    for(unsigned short int fila=0;fila<f;fila++)
    {
        if(fila<=9)cout<<"   " <<fila;
        else if(fila<=99)cout<<"  " <<fila;
        else if(fila<=999)cout<<" " <<fila;
        else cout<<fila;
        for(unsigned short int columna=0;columna<c;columna++)
        {
            unsigned char valor = leer_ficha(tablero,f,c,fila,columna);
            short int b=2;
            cout<<"|";
            while(b>=0)
            {
            cout<<((valor>>b)&1);
            b--;
            }
        }
        cout<<"|"<<endl;
    }
    unsigned short int col=0;
    cout<<"     ";
    while(col<c)
    {
        if(col<=9)cout<<col<<"   ";
        else if(col<=99)cout<<col<<"  ";
        else cout<<col;
        col++;
    }
    cout<<endl<<endl;
}






