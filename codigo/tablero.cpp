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
            guardar_ficha(tablero,c,fila,col,total_bytes,ficha_aleatoria());
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
    unsigned int bit_inicial=(fil*c+col)*3;
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
        // (fila<=9)? cout<<fila <<" |" : cout<<fila <<"|";
        if(fila<=9)cout<<"  " <<fila<<"|";
        else if(fila<=99)cout<<" " <<fila<<"|";
        else cout<<fila <<"|";
        for(unsigned short int columna=0;columna<c;columna++)
        {
            unsigned char valor = leer_ficha(tablero, c,fila, columna,total_bytes);
            cout<<" "<<figura[valor]<<" |";
        }
        cout<<endl;
    }
    short int col=0;
    cout<<"   ";
    while(col<c)
    {
        //if(col==10)
            //cout<<" ";
        //(col>9)? cout<<col<<" ": cout<<" "<<col<<" ";
        if(col<=9)cout<<"  "<<col<<" ";
        else if(col<=99)cout<<"  "<<col;
        else cout<<" "<<col;
        col++;
    }
    cout<<endl;
    imprimir_bytes(tablero,total_bytes);
}
void imprimir_bytes(unsigned char *tablero,unsigned short int total_bytes)
{
    for(unsigned short int i=0;i<total_bytes;i++)
    {
        short int b=7;
        while(b>0)
        {
            cout<<(unsigned short int)((tablero[i]>>b)&1);
            b--;
        }
        cout<<"|";
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










