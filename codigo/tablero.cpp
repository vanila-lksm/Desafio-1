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
    unsigned char figura[8]={'#','!','%','$','+','?','*','-'};
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
    unsigned short int total_bytes=((f*c*3)+7)/8;
    cout<<"bytes de 0 a "<<total_bytes<<":" <<endl;
    for(unsigned short int i=0;i<total_bytes;i++)
    {
        short int b=7;
        while(b>=0)
        {
            cout<<(unsigned short int)((tablero[i]>>b)&1);
            b--;
        }
        cout<<"|";
    }
    cout<<endl;
}


unsigned char * agregar_fila(unsigned char *tablero, unsigned short int &f, unsigned short int c,
                            unsigned short int pos_fila,unsigned short int &magnitud_tablero)
{
    unsigned short int nueva_fila =f+1;
    unsigned char *nuevo_tablero = new unsigned char[(nueva_fila*c*3+7)/8]();
    //new unsigned char[nuevo_total_bytes]
    for (unsigned short int r=0;r<nueva_fila;r++)
    {
        for (unsigned short int col=0;col<c;col++)
        {
            if (r<pos_fila)
            {
                unsigned char val =leer_ficha(tablero,f,c,r,col);
                guardar_ficha(nuevo_tablero,nueva_fila,c,r,col,val);
            }
            else if (r == pos_fila)
            {
                guardar_ficha(nuevo_tablero,nueva_fila,c,r,col,ficha_aleatoria());
            }
            else
            {
                unsigned char val=leer_ficha(tablero,f,c,r - 1,col);
                guardar_ficha(nuevo_tablero,nueva_fila,c,r,col,val);
            }
        }
    }
    delete[] tablero;
    f = nueva_fila;
    magnitud_tablero=(nueva_fila*c*3+7)/8;
    return nuevo_tablero;
}
unsigned char * eliminar_fila(unsigned char *tablero, unsigned short int &f, unsigned short int c,
                             unsigned short int pos_fila,unsigned short int &magnitud_tablero){
    if (f<=1||pos_fila>=f) return tablero;
    unsigned short int nueva_fila=f-1;
    unsigned short int nuevo_total_bytes=((nueva_fila*c*3)+7)/8;
    unsigned short int bytes_usados_despues=nuevo_total_bytes;
    bool reasignar_memoria=(bytes_usados_despues*100<(65*magnitud_tablero));
    unsigned char *destino=tablero;
    if (reasignar_memoria){
        destino=new unsigned char[nuevo_total_bytes]();
    }
    for (unsigned short int r=0;r<nueva_fila;r++) {
        for (unsigned short int col=0;col<c;col++) {
            unsigned short int r_orig=(r<pos_fila)?r:(r+1);
            unsigned char val = leer_ficha(tablero,f,c,r_orig,col);
            guardar_ficha(destino,nueva_fila,c,r,col,val);
        }
    }
    if (reasignar_memoria) {
        delete[] tablero;
        magnitud_tablero=nuevo_total_bytes;
    }
    f=nueva_fila;
    return destino;
}
unsigned char * agregar_columna(unsigned char *tablero, unsigned short int f, unsigned short int &c,
                               unsigned short int pos_col,unsigned short int &magnitud_tablero){
    unsigned short int nueva_c=c+1;
    unsigned short int nuevo_total_bytes=((f*nueva_c*3) +7)/8;
    unsigned char *nuevo_tablero=new unsigned char[nuevo_total_bytes]();
    for (unsigned short int i=0;i<f;i++) {
        for (unsigned short int col=0;col<nueva_c;col++) {
            if (col<pos_col) {
                unsigned char val = leer_ficha(tablero,f,c,i,col);
                guardar_ficha(nuevo_tablero,f,nueva_c,i,col,val);
            } else if (col==pos_col) {
                guardar_ficha(nuevo_tablero,f,nueva_c,i,col,ficha_aleatoria());
            } else {
                unsigned char val =leer_ficha(tablero,f,c,i,col-1);
                guardar_ficha(nuevo_tablero,f,nueva_c,i,col,val);
            }
        }
    }

    delete[] tablero;
    c = nueva_c;
    magnitud_tablero=nuevo_total_bytes;
    return nuevo_tablero;
}
unsigned char * eliminar_columna(unsigned char *tablero, unsigned short int f, unsigned short int &c,
                                unsigned short int pos_col,unsigned short int &magnitud_tablero){
    if (c <= 1 || pos_col >= c) return tablero;
    unsigned short int nueva_c=c-1;
    unsigned short int nuevo_total_bytes=((f*nueva_c*3) +7)/8;
    bool reasignar_memoria=(nuevo_total_bytes*100<(65 * magnitud_tablero));
    unsigned char *destino=tablero;
    if (reasignar_memoria){
        destino=new unsigned char[nuevo_total_bytes]();
    }
    for (unsigned short int r=0;r<f;r++){
        for (unsigned short int col=0;col<nueva_c;col++){
            unsigned short int col_orig=(col < pos_col)?col:(col + 1);
            unsigned char val=leer_ficha(tablero,f,c,r,col_orig);
            guardar_ficha(destino,f,nueva_c,r,col,val);
        }
    }

    if (reasignar_memoria) {
        delete[] tablero;
        magnitud_tablero=nuevo_total_bytes;
    }
    c = nueva_c;
    return destino;
}
