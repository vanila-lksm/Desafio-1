#include "combinaciones_fichas.h"
#include "operaciones_fichas.h"


void marcar_fichas(unsigned char *eliminaciones, unsigned int indice)
{
    eliminaciones[indice >>3] |= (1 << (indice &7));
}

bool esta_marcada(unsigned char *eliminaciones, unsigned int indice)
{
    return (eliminaciones[indice >>3] >> (indice &7)) & 1;
}

unsigned short int combinaciones_filas(unsigned char *tablero,unsigned short int f,unsigned short int c,
                         unsigned char *eliminaciones)
{
    unsigned short int combinaciones=0;
    for(unsigned short int fila=0;fila<f;fila++)
    {
        unsigned short int inicio=0;
        unsigned char valor=leer_ficha(tablero,f,c,fila,0);
        for(unsigned short int col=1;col<=c;col++)
        {
            unsigned char valor_actual = (col < c) ? leer_ficha(tablero,f,c,fila,col) : 0;
            if(col==c || valor!=valor_actual)
            {
                unsigned short int largo_combinacion=col-inicio;
                if(largo_combinacion>=3)
                {
                    combinaciones++;
                    for (unsigned short int k = inicio; k < col; k++)
                    {
                        marcar_fichas(eliminaciones,fila*c+k);
                    }
                }
                if(col<c)
                {
                    inicio=col;
                    valor = valor_actual;
                }
            }
        }
    }
    return combinaciones;
}

unsigned short int combinaciones_columna(unsigned char *tablero,unsigned short int f,unsigned short int c,
                                       unsigned char *eliminaciones)
{
    unsigned short int combinaciones=0;
    for(unsigned short int col=0;col<c;col++)
    {
        unsigned short int inicio=0;
        unsigned char valor=leer_ficha(tablero,f,c,0,col);
        for(unsigned short int fila=1;fila<=f;fila++)
        {
            unsigned char valor_actual = (fila < f) ? leer_ficha(tablero,f,c,fila,col) : 0;
            if(fila==f || valor!=valor_actual)
            {
                unsigned short int largo=fila-inicio;
                if(largo>=3)
                {
                    combinaciones++;
                    for (unsigned short int k = inicio; k < fila; k++)
                    {
                        marcar_fichas(eliminaciones,k*c+col);
                    }
                }
                if(fila<f)
                {
                    inicio=fila;
                    valor = valor_actual;
                }
            }
        }
    }
    return combinaciones;
}

unsigned short int aplicar_eliminaciones(unsigned char *tablero,unsigned short int f, unsigned short int c,
                           unsigned char *eliminaciones,unsigned short int &cascadas)
{
    unsigned char cas;
    unsigned short int eliminadas=0;
    for(unsigned short int col=0;col<c;col++)
    {
        cas='0';
        for(unsigned short int fila=0;fila<f;fila++)
        {
            if(esta_marcada(eliminaciones,fila*c+col))
            {
                if(fila==0)
                {
                    guardar_ficha(tablero,f,c,fila,col,ficha_aleatoria());
                }
                else
                {
                    cascada(tablero,f,c,fila,col);
                    cas='1';
                }
                eliminadas++;
            }
        }
        if(cas=='1')cascadas++;
    }
    return eliminadas;
}
void completar_tablero(unsigned char *tablero,unsigned char *eliminaciones,unsigned int magnitud_eliminaciones ,unsigned short int f, unsigned short int c,
                        unsigned int &eliminadas,unsigned int &combinaciones,unsigned short int &cascadas)
{
    while(true)
    {
        for(unsigned short int i=0;i<magnitud_eliminaciones;i++)eliminaciones[i]=0;
        unsigned short int combis=combinaciones_filas(tablero,f,c,eliminaciones)+combinaciones_columna(tablero,f,c,eliminaciones);
        if(combis==0)
        {
            break;
        }
            eliminadas+=aplicar_eliminaciones(tablero,f,c,eliminaciones,cascadas);
            combinaciones+=combis;
    }
}