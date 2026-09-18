#include <iostream>
#include "funciones.h"
#include <cstdlib>
using namespace std;
unsigned char * creacion_tablero1(unsigned short int f, unsigned short int c)
{
    //aqui para mirar el tamaño del arreglo, cuantos bytes debe tener
    unsigned short int total_bytes = ((f*c*3)+7)/8;
    //el arreglo en memoria heap
    unsigned char *tablero = new unsigned char[total_bytes]();
    //hacemos que cada byte este totalmente lleno de 0 para quitar la basura
    for (unsigned short int i = 0; i < total_bytes; i++)
    {
        tablero[i] = 0;
    }
    for(unsigned short int fila=0;fila<f;fila++)
    {
        for(unsigned short int col=0;col<c;col++)
        {
            guardar_ficha(tablero,f,c,fila,col,ficha_aleatoria());
        }
    }
    return tablero;
}

unsigned char ficha_aleatoria()
{
    //funcion de una libreria para numeros del 0 a 5 (nuestar fichas)
    unsigned char valor = rand() % 6;
    return valor;
}


void imprimir_tablero(unsigned char *tablero,unsigned short int f,
                      unsigned short int c)
{
    unsigned char figura[6]={'#','=','%','$','+','?'};
    for(unsigned short int fila=0;fila<f;fila++)
    {
        if(fila<=9)cout<<"  " <<fila<<"|";
        else if(fila<=99)cout<<" " <<fila<<"|";
        else cout<<fila <<"|";
        for(unsigned short int columna=0;columna<c;columna++)
        {
            unsigned char valor = leer_ficha(tablero,f,c,fila,columna);
            cout<<" "<<figura[valor]<<" ";
        }
        cout<<endl;
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
    cout<<endl<<endl;
}

void imprimir_bytes(unsigned char *tablero,unsigned short int f,
                    unsigned short int c)
{
    unsigned short int total_bytes=((f*c*3)+7)>>3;
    cout<<"bytes de 0 a "<<total_bytes<<":" <<endl;
    for(unsigned short int i=0;i<total_bytes;i++)
    {
        short int b=7;
        while(b>=0)
        {
            cout<<((tablero[i]>>b)&1);
            b--;
        }
        cout<<"|";
    }
    cout<<endl;
}






