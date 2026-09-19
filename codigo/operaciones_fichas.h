#ifndef OPERACIONES_FICHAS_H
#define OPERACIONES_FICHAS_H
void guardar_ficha(unsigned char *tablero,unsigned short int f,unsigned short int c,
                   unsigned short int fil,unsigned short int col,unsigned char valor);
unsigned char leer_ficha(unsigned char *tablero,unsigned short int f,unsigned short int c,
                         unsigned short int fil,unsigned short int col);
void cascada(unsigned char *tablero, unsigned short int f, unsigned short int c,
             unsigned short int pos_fil, unsigned short int pos_col);
unsigned char ficha_aleatoria();
#endif // OPERACIONES_FICHAS_H
