#include "funciones.h"

unsigned char * crear_marcas(unsigned short int f, unsigned short int c)
{
    unsigned int total = (f * c + 7) / 8;
    unsigned char *marcas = new unsigned char[total];
    for (unsigned int i = 0; i < total; i++) marcas[i] = 0;
    return marcas;
}

void marcar(unsigned char *marcas, unsigned int indice)
{
    marcas[indice / 8] |= (1 << (indice % 8));
}

bool esta_marcada(unsigned char *marcas, unsigned int indice)
{
    return (marcas[indice / 8] >> (indice % 8)) & 1;
}

unsigned short int combinaciones_filas(unsigned char *tablero,unsigned short int f,unsigned short int c,
                         unsigned char *marcas)
{
    unsigned short int combinaciones=0;
    for(unsigned short int fila=0;fila<f;fila++)
    {
        unsigned short int inicio=0;
        unsigned char valor=leer_ficha(tablero,f,c,fila,0);
        for(unsigned short int col=1;col<=c;col++)
        {
            unsigned char actual=leer_ficha(tablero,f,c,fila,col);
            if(col==c || valor!=actual)
            {
                unsigned short int largo=col-inicio;
                if(largo>=3)
                {
                    combinaciones++;
                    for (unsigned short int k = inicio; k < col; k++)
                    {
                        marcar(marcas,fila*c+k);
                    }
                }
                if(col<c)
                {
                    inicio=col;
                    valor = actual;
                }
            }
        }
    }
    return combinaciones;
}

unsigned short int combinaciones_columna(unsigned char *tablero,unsigned short int f,unsigned short int c,
                                       unsigned char *marcas)
{
    unsigned short int combinaciones=0;
    for(unsigned short int col=0;col<c;col++)
    {
        unsigned short int inicio=0;
        unsigned char valor=leer_ficha(tablero,f,c,0,col);
        for(unsigned short int fila=1;fila<=f;fila++)
        {
            unsigned char actual=leer_ficha(tablero,f,c,fila,col);
            if(fila==f || valor!=actual)
            {
                unsigned short int largo=fila-inicio;
                if(largo>=3)
                {
                    combinaciones++;
                    for (unsigned short int k = inicio; k < fila; k++)
                    {
                        marcar(marcas,k*c+col);
                    }
                }
                if(fila<f)
                {
                    inicio=fila;
                    valor = actual;
                }
            }
        }
    }
    return combinaciones;
}

unsigned short int aplicar_eliminaciones(unsigned char *tablero,unsigned short int f, unsigned short int c,
                           unsigned char *marcas,unsigned short int &cascadas)
{
    unsigned char cas='-';
    unsigned short int eliminadas=0;
    for(unsigned short int fila=0;fila<f;fila++)
    {
        for(unsigned short int col=0;col<c;col++)
        {
            if(esta_marcada(marcas,fila*c+col))
            {
                if(fila==0)
                {
                    guardar_ficha(tablero,f,c,fila,col,ficha_aleatoria());
                    eliminadas++;
                }
                else
                {
                    cascada(tablero,f,c,fila,col);
                    eliminadas++;
                    cas='+';
                }
            }
        }
    }
    if(cas=='+')cascadas++;
    return eliminadas;
}
void completar_tablero(unsigned char *tablero,unsigned short int f, unsigned short int c,
                        unsigned short int &eliminadas,unsigned short int &combinaciones,unsigned short int &cascadas)
{
    unsigned short int total = (f * c + 7) / 8;
    unsigned char *marcas=new unsigned char[total]();
    while(true)
    {
        for (unsigned int i = 0; i < total; i++) marcas[i] = 0;
        unsigned short int combis=combinaciones_filas(tablero,f,c,marcas)+combinaciones_columna(tablero,f,c,marcas);
        if(combis==0)
        {
            break;
        }
            eliminadas+=aplicar_eliminaciones(tablero,f,c,marcas,cascadas);
            combinaciones+=combis;
    }
    delete[] marcas;
}