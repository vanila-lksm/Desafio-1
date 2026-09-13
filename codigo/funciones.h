#ifndef FUNCIONES_H
#define FUNCIONES_H
unsigned char * creacion_tablero1(unsigned short int f, unsigned short int c);
unsigned char ficha_aleatoria();
unsigned char leer_ficha(unsigned char *tablero, unsigned short int c,unsigned short int fil,
                         unsigned short int col, unsigned short int total_bytes);
void imprimir_tablero(unsigned char *tablero,unsigned short int f,
                      unsigned short int c,unsigned short int total_bytes);
void imprimir_bytes(unsigned char *tablero,unsigned short int total_bytes);
void guardar_ficha(unsigned char *tablero,unsigned short int c,unsigned short int fil,
                   unsigned short int col,unsigned short int total_bytes,unsigned char valor);
void eliminar_ficha(unsigned char *tablero,unsigned short int c,unsigned short int fil,
                    unsigned short int col,unsigned short int total_bytes);
#endif // FUNCIONES_H
