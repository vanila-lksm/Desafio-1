#ifndef COMBINACIONES_FICHAS_H
#define COMBINACIONES_FICHAS_H
void marcar_fichas(unsigned char *eliminaciones, unsigned int indice);
bool esta_marcada(unsigned char *eliminaciones, unsigned int indice);
unsigned short int combinaciones_filas(unsigned char *tablero,unsigned short int f,unsigned short int c,
                                       unsigned char *eliminaciones);
unsigned short int combinaciones_columna(unsigned char *tablero,unsigned short int f,unsigned short int c,
                                         unsigned char *eliminaciones);
unsigned short int aplicar_eliminaciones(unsigned char *tablero,unsigned short int f,unsigned short int c,
                                         unsigned char *eliminaciones,unsigned short int &cascadas);
void completar_tablero(unsigned char *tablero,unsigned char *eliminaciones,unsigned int magnitud_eliminaciones,unsigned short int f, unsigned short int c,
                       unsigned int &eliminadas,unsigned int &combinaciones,unsigned short int &cascadas);
#endif // COMBINACIONES_FICHAS_H
