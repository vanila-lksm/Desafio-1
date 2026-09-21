#include "tablero.h"
#include "operaciones_fichas.h"

unsigned char * creacion_tablero1(unsigned short int f, unsigned short int c)
{
    unsigned short int total_bytes = ((unsigned int)(f*c*3)+7)>>3;
    unsigned char *tablero = new unsigned char[total_bytes]();
    for(unsigned short int fila=0;fila<f;fila++)
    {
        for(unsigned short int col=0;col<c;col++)
        {
            guardar_ficha(tablero,f,c,fila,col,ficha_aleatoria());
        }
    }
    return tablero;
}

unsigned char * agregar_fila(unsigned char *tablero, unsigned short int &f, unsigned short int c,
                            unsigned short int pos_fila,unsigned short int &magnitud_tablero)
{
    unsigned short int nueva_fila =f+1;
    unsigned short int nuevo_total_bytes=((unsigned int)nueva_fila*c*3+7)>>3;
    if(nuevo_total_bytes<=magnitud_tablero)
    {
        for (int r = (int)f - 1; r >= (int)pos_fila; r--)
        {
            for (unsigned short int col = 0; col < c; col++)
            {
                    guardar_ficha(tablero,nueva_fila,c,r+1,col,leer_ficha(tablero,f,c,r,col));
            }
        }
        for (unsigned short int col = 0; col < c; col++)
        {
            guardar_ficha(tablero, nueva_fila, c, pos_fila, col, ficha_aleatoria());
        }
        f = nueva_fila;
        return tablero;
    }
    unsigned char *nuevo_tablero = new unsigned char[nuevo_total_bytes]();
    for (unsigned short int r=0;r<nueva_fila;r++)
    {
        for (unsigned short int col=0;col<c;col++)
        {
            if (r<pos_fila)
            {
                guardar_ficha(nuevo_tablero,nueva_fila,c,r,col,leer_ficha(tablero,f,c,r,col));
            }
            else if (r == pos_fila)
            {
                guardar_ficha(nuevo_tablero,nueva_fila,c,r,col,ficha_aleatoria());
            }
            else
            {
                guardar_ficha(nuevo_tablero,nueva_fila,c,r,col,leer_ficha(tablero,f,c,r - 1,col));
            }
        }
    }
    delete[] tablero;
    f = nueva_fila;
    magnitud_tablero=nuevo_total_bytes;
    return nuevo_tablero;
}
unsigned char * eliminar_fila(unsigned char *tablero, unsigned short int &f, unsigned short int c,
                             unsigned short int pos_fila,unsigned short int &magnitud_tablero){

    unsigned short int nueva_fila=f-1;
    unsigned short int nuevo_total_bytes=((unsigned int)(nueva_fila*c*3)+7)>>3;
    if (nuevo_total_bytes*100<(65*magnitud_tablero))
    {
            unsigned char *nuevo_tablero=new unsigned char[nuevo_total_bytes]();
        for (unsigned short int r=0;r<nueva_fila;r++) {
            for (unsigned short int col=0;col<c;col++) {
                unsigned short int r_orig=(r<pos_fila)?r:(r+1);
                unsigned char val = leer_ficha(tablero,f,c,r_orig,col);
                guardar_ficha(nuevo_tablero,nueva_fila,c,r,col,val);
            }
        }
        delete[] tablero;
        magnitud_tablero=nuevo_total_bytes;
        f=nueva_fila;
        return nuevo_tablero;
    }
    else
    {
        for(unsigned short int fila=pos_fila;fila<nueva_fila;fila++)
        {
            for(unsigned short int col=0;col<c;col++)
            {
                guardar_ficha(tablero,nueva_fila,c,fila,col,leer_ficha(tablero,f,c,fila+1,col));
            }
        }
        f=nueva_fila;
        return tablero;
    }

}
unsigned char * agregar_columna(unsigned char *tablero, unsigned short int f, unsigned short int &c,
                               unsigned short int pos_col,unsigned short int &magnitud_tablero){
    unsigned short int nueva_c=c+1;
    unsigned short int nuevo_total_bytes=((unsigned int)f*nueva_c*3+7)>>3;
    if(nuevo_total_bytes<=magnitud_tablero)
    {
        for (int fila = (int)f - 1; fila >= 0; fila--)
        {
            for (int col = (int)c - 1; col >= 0; col--)
            {
                unsigned short int destino = (col < pos_col) ? col : col + 1;
                guardar_ficha(tablero, f, nueva_c, fila, destino,leer_ficha(tablero, f, c, fila, col));
            }
        }
            for (unsigned short int i = 0; i < f; i++)
                guardar_ficha(tablero, f, nueva_c, i, pos_col, ficha_aleatoria());
        c = nueva_c;
        return tablero;
    }
    else
    {
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

}
unsigned char * eliminar_columna(unsigned char *tablero, unsigned short int f, unsigned short int &c,
                                unsigned short int pos_col,unsigned short int &magnitud_tablero){
    if (c <= 1 || pos_col >= c) return tablero;
    unsigned short int nueva_c=c-1;
    unsigned short int nuevo_total_bytes=((unsigned int)f*nueva_c*3+7)>>3;
    if (nuevo_total_bytes*100<(65 * magnitud_tablero))
    {
        unsigned char *nuevo_tablero=new unsigned char[nuevo_total_bytes]();
        for (unsigned short int r=0;r<f;r++){
            for (unsigned short int col=0;col<nueva_c;col++)
            {
                unsigned short int col_orig=(col < pos_col)?col:(col + 1);
                guardar_ficha(nuevo_tablero,f,nueva_c,r,col,leer_ficha(tablero,f,c,r,col_orig));
            }
        }
        delete[] tablero;
        magnitud_tablero=nuevo_total_bytes;
        return nuevo_tablero;
    }
    else
    {
        for (unsigned short int r = 0; r < f; r++)
            for (unsigned short int col = 0; col < nueva_c; col++)
            {
                unsigned short int col_orig = (col < pos_col) ? col : col + 1;
                guardar_ficha(tablero, f, nueva_c, r, col, leer_ficha(tablero, f, c, r, col_orig));
            }
        c = nueva_c;
        return tablero;
    }
}