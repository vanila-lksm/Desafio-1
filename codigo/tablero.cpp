#include <iostream>
#include "funciones.h"
#include <cstdlib>
using namespace std;
unsigned char * creacion_tablero1(unsigned short int f, unsigned short int c)
{
    //aqui para mirar el tamaño del arreglo, cuantos bytes debe tener
    unsigned int total_bits = f*c*3;
    unsigned short int total_bytes = (total_bits+7)/8;
    //el arreglo en memoria heap
    unsigned char *tablero = new unsigned char[total_bytes];
    //hacemos que cada byte este totalmente lleno de 0 para quitar la basura
    for (unsigned short int i = 0; i < total_bytes; i++)
    {
        tablero[i] = 0;
    }
    for(unsigned short int fila=0;fila<f;fila++)
    {
        for(unsigned short int col=0;col<c;col++)
        {
            unsigned short int valor=ficha_aleatoria();
            unsigned int indice=fila*c+col;
            unsigned int bit_inicial=indice*3;
            unsigned int cual_byte=bit_inicial/8,cual_bit_byte=bit_inicial%8;
            unsigned short int valor_en_pocision=(valor&0x07)<<cual_bit_byte;
            tablero[cual_byte]|=valor_en_pocision&0xff;
            if(cual_byte+1<total_bytes)
            {
                tablero[cual_byte+1]|=(valor_en_pocision>>8)&0xff;
            }
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

unsigned char leer_ficha(unsigned char *tablero, unsigned short int c,unsigned short int fil,
                         unsigned short int col, unsigned short int total_bytes)
{
    unsigned int indice=fil*c+col;
    unsigned int bit_inicial=indice*3;
    unsigned int cual_byte=bit_inicial/8,cual_bit_byte=bit_inicial%8;
    unsigned short int combinado=tablero[cual_byte];
    if(cual_byte+1<total_bytes)
        combinado|=(tablero[cual_byte+1]<<8);
    unsigned char ficha=(combinado>>cual_bit_byte)&0x07;
    return ficha;
}

void imprimir_tablero(unsigned char *tablero,unsigned short int f,
                      unsigned short int c,unsigned short int total_bytes)
{
    unsigned char figura[6]={'#','!','%','$','+','?'};
    for(unsigned short int fila=0;fila<f;fila++)
    {
        //cout<<fila <<"  |";
        (fila<=9)? cout<<fila <<"  |" : cout<<fila <<" |";
        for(unsigned short int columna=0;columna<c;columna++)
        {
            unsigned char valor = leer_ficha(tablero, c,fila, columna,total_bytes);
            cout<<figura[valor]<<" |";
        }
        cout<<endl;
    }
    short int col=0;
    cout<<"   ";
    while(col<c)
    {
        (col<=9)? cout<<"  "<<col : cout<<col <<" ";
        col++;

    }
    cout<<endl;
}

void guardar_ficha(unsigned char *tablero,unsigned short int c,unsigned short int fil,
                   unsigned short int col,unsigned short int total_bytes, unsigned char valor)
{
    unsigned int indice=fil*c+col;
    unsigned int bit_inicial=indice*3;
    unsigned int cual_byte=bit_inicial/8,cual_bit_byte=bit_inicial%8;
    unsigned short int combinado=tablero[cual_byte];
    if(cual_byte+1<total_bytes)
        combinado|=(tablero[cual_byte+1]<<8);
    unsigned short int mascara= 0x07<<cual_bit_byte;
    combinado=(combinado & ~mascara) | ((valor & 0x07)<<cual_bit_byte);
    tablero[cual_byte] = combinado & 0xff;
    if (cual_byte + 1 < total_bytes)
        tablero[cual_byte + 1] = (combinado >> 8) & 0xff;

}

void eliminar_ficha(unsigned char *tablero,unsigned short int c,unsigned short int fil,
                    unsigned short int col,unsigned short int total_bytes)
{
    unsigned char valor=ficha_aleatoria();
    guardar_ficha(tablero,c,fil,col,total_bytes,valor);
}










