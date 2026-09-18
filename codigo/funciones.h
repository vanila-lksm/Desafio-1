#ifndef FUNCIONES_H
#define FUNCIONES_H
//crear/imprimir tablero
unsigned char * creacion_tablero1(unsigned short int f, unsigned short int c);
unsigned char ficha_aleatoria();
void imprimir_tablero(unsigned char *tablero,unsigned short int f,
                      unsigned short int c);
void imprimir_bytes(unsigned char *tablero,unsigned short int f,
                    unsigned short int c);

//operaciones de bits
void guardar_ficha(unsigned char *tablero,unsigned short int f,unsigned short int c,
                   unsigned short int fil,unsigned short int col,unsigned char valor);
unsigned char leer_ficha(unsigned char *tablero,unsigned short int f,unsigned short int c,
                         unsigned short int fil,unsigned short int col);
void cascada(unsigned char *tablero, unsigned short int f, unsigned short int c,
             unsigned short int pos_fil, unsigned short int pos_col);

//modificacion_tablero
unsigned char * agregar_fila(unsigned char *tablero, unsigned short int &f, unsigned short int c,
                            unsigned short int pos_fila,unsigned short int &magnitud_tablero);
unsigned char * eliminar_fila(unsigned char *tablero, unsigned short int &f, unsigned short int c,
                             unsigned short int pos_fila, unsigned short int &magnitud_tablero);
unsigned char * agregar_columna(unsigned char *tablero, unsigned short int f, unsigned short int &c,
                               unsigned short int pos_col,unsigned short int &magnitud_tablero);
unsigned char * eliminar_columna(unsigned char *tablero, unsigned short int f, unsigned short int &c,
                                unsigned short int pos_col,unsigned short int &magnitud_tablero );

//eliminacion_combinaciones
unsigned short int leer_numero(const char *mensaje, unsigned short int min, unsigned short int max);
void marcar(unsigned char *marcas, unsigned int indice);
bool esta_marcada(unsigned char *marcas, unsigned int indice);
unsigned short int combinaciones_filas(unsigned char *tablero,unsigned short int f,unsigned short int c,
                        unsigned char *marcas);
unsigned short int combinaciones_columna(unsigned char *tablero,unsigned short int f,unsigned short int c,
                                         unsigned char *marcas);
unsigned char * crear_marcas(unsigned short int f, unsigned short int c);
unsigned short int aplicar_eliminaciones(unsigned char *tablero,unsigned short int f,unsigned short int c,
                           unsigned char *marcas,unsigned short int &cascadas);
void completar_tablero(unsigned char *tablero,unsigned short int f, unsigned short int c,
                       unsigned short int &eliminadas,unsigned short int &combinaciones,unsigned short int &cascadas);
#endif // FUNCIONES_H
