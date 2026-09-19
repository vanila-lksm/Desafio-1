#include "operaciones_fichas.h"
#include <cstdlib>
unsigned char leer_ficha(unsigned char *tablero,unsigned short int f,unsigned short int c,
                         unsigned short int fil,unsigned short int col)
{
    unsigned short int total_bytes = ((unsigned int)(f*c*3)+7)>>3;
    unsigned int bit_inicial=(fil*c+col)*3;
    unsigned int cual_byte=bit_inicial>>3,cual_bit_byte=bit_inicial&7;
    unsigned short int combinado=tablero[cual_byte];
    if(cual_byte+1<total_bytes)
      combinado |= (tablero[cual_byte + 1] << 8);

    return (combinado >> cual_bit_byte) & 0x07;
}

void guardar_ficha(unsigned char *tablero,unsigned short int f,unsigned short int c,
                   unsigned short int fil,unsigned short int col,unsigned char valor)
{
    unsigned short int total_bytes=((unsigned int)(f*c*3)+7)>>3;
    unsigned int bit_inicial=(fil*c+col)*3;
    unsigned int cual_byte=bit_inicial>>3,cual_bit_byte=bit_inicial&7;
    unsigned short int combinado=tablero[cual_byte];
    if(cual_byte+1<total_bytes)
        combinado|=(tablero[cual_byte+1]<<8);
    unsigned short int mascara= 0x07<<cual_bit_byte;
    combinado=(combinado & ~mascara) | ((valor & 0x07)<<cual_bit_byte);
    tablero[cual_byte] = combinado & 0xff;
    if (cual_byte + 1 < total_bytes)
        tablero[cual_byte + 1] = (combinado >> 8) & 0xff;
}

void cascada (unsigned char *tablero, unsigned short int f, unsigned short int c,unsigned short int pos_fil, unsigned short int pos_col){
    for (short int r = pos_fil; r > 0; r--)
    {
        unsigned char ficha_superior = leer_ficha(tablero, f, c, r - 1, pos_col);
        guardar_ficha(tablero, f, c, r, pos_col, ficha_superior);
    }
    guardar_ficha(tablero, f, c, 0, pos_col, ficha_aleatoria());
}
unsigned char ficha_aleatoria()
{
    //funcion de una libreria para numeros del 1 a 6 (nuestar fichas)
    unsigned char valor = 1+ (rand() % 6);
    return valor;
}