#ifndef FUNCIONES_H
#define FUNCIONES_H
unsigned char * creacion_tablero1(unsigned short int f, unsigned short int c);
unsigned char ficha_aleatoria();
unsigned char leer_ficha(unsigned char *tablero,unsigned short int f,unsigned short int c,
                         unsigned short int fil,unsigned short int col);
void imprimir_tablero(unsigned char *tablero,unsigned short int f,
                      unsigned short int c);
void imprimir_bytes(unsigned char *tablero,unsigned short int f,
                    unsigned short int c);
void guardar_ficha(unsigned char *tablero,unsigned short int f,unsigned short int c,
                   unsigned short int fil,unsigned short int col,unsigned char valor);
unsigned char * agregar_fila(unsigned char *tablero, unsigned short int &f, unsigned short int c,
                            unsigned short int pos_fila,unsigned short int &magnitud_tablero);
unsigned char * eliminar_fila(unsigned char *tablero, unsigned short int &f, unsigned short int c,
                             unsigned short int pos_fila, unsigned short int &magnitud_tablero);
unsigned char * agregar_columna(unsigned char *tablero, unsigned short int f, unsigned short int &c,
                               unsigned short int pos_col,unsigned short int &magnitud_tablero);
unsigned char * eliminar_columna(unsigned char *tablero, unsigned short int f, unsigned short int &c,
                                unsigned short int pos_col,unsigned short int &magnitud_tablero );
unsigned short int leer_numero(const char *mensaje, unsigned short int min, unsigned short int max);
#endif // FUNCIONES_H
