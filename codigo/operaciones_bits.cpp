#include <iostream>
#include "funciones.h"
#include <cstdlib>
using namespace std;
unsigned char leer_ficha(unsigned char *tablero,unsigned short int f,unsigned short int c,
                         unsigned short int fil,unsigned short int col)
{
    unsigned short int total_bytes = ((f*c*3)+7)/8;
    //unsigned int total_bytes=(((unsigned int)f*c*3)+7)/8;
    unsigned int bit_inicial=(fil*c+col)*3;
    unsigned int cual_byte=bit_inicial/8,cual_bit_byte=bit_inicial%8;
    unsigned short int combinado=tablero[cual_byte];
    if(cual_byte+1<total_bytes)
        combinado|=(tablero[cual_byte+1]<<8);
    unsigned char ficha=(combinado>>cual_bit_byte)&0x07;
    return ficha;
}

void guardar_ficha(unsigned char *tablero,unsigned short int f,unsigned short int c,
                   unsigned short int fil,unsigned short int col,unsigned char valor)
{
    unsigned short int total_bytes=((f*c*3)+7)/8;
    //unsigned int total_bytes=(((unsigned int)f*c*3)+7)/8;
    unsigned int bit_inicial=(fil*c+col)*3;
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
unsigned short int leer_numero(const char *mensaje, unsigned short int min, unsigned short int max)
{
    char buffer[10];
    while (true)
    {
        cout << mensaje;
        cin.getline(buffer, 10);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "numero demasiado largo" << endl;
            continue;
        }
        bool valido = (buffer[0] != '\0');
        for (unsigned short int i = 0; buffer[i] != '\0'; i++)
            if (buffer[i] < '0' || buffer[i] > '9') valido = false;
        if (!valido)
        {
            cout << "entrada no valida: solo numeros" << endl;
            continue;
        }
        unsigned int valor = 0;
        for (unsigned short int i = 0; buffer[i] != '\0'; i++)
            valor = valor*10 + (buffer[i] - '0');
        if (valor < min || valor > max)
        {
            cout << "debe estar entre " << min << " y " << max << endl;
            continue;
        }
        return (unsigned short int)valor;
    }
}