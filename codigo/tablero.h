#ifndef TABLERO_H
#define TABLERO_H
unsigned char * creacion_tablero1(unsigned short int f, unsigned short int c);
unsigned char * agregar_fila(unsigned char *tablero, unsigned short int &f, unsigned short int c,
                            unsigned short int pos_fila,unsigned short int &magnitud_tablero);
unsigned char * eliminar_fila(unsigned char *tablero, unsigned short int &f, unsigned short int c,
                             unsigned short int pos_fila, unsigned short int &magnitud_tablero);
unsigned char * agregar_columna(unsigned char *tablero, unsigned short int f, unsigned short int &c,
                               unsigned short int pos_col,unsigned short int &magnitud_tablero);
unsigned char * eliminar_columna(unsigned char *tablero, unsigned short int f, unsigned short int &c,
                                unsigned short int pos_col,unsigned short int &magnitud_tablero );


#endif // TABLERO_H
