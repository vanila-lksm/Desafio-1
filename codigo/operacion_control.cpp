#include "operacion_control.h"
#include <iostream>
using namespace std;
unsigned short int validar_entradas(const char *mensaje, unsigned short int min, unsigned short int max)
{
    char espacio[10];
    while (true)
    {
        cout << mensaje;
        cin.getline(espacio, 10);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "numero demasiado largo" << endl;
            continue;
        }
        bool valido = (espacio[0] != '\0');
        for (unsigned short int i = 0; espacio[i] != '\0'; i++)
            if (espacio[i] < '0' || espacio[i] > '9') valido = false;
        if (!valido)
        {
            cout << "entrada no valida: solo numeros" << endl;
            continue;
        }
        unsigned int valor = 0;
        for (unsigned short int i = 0; espacio[i] != '\0'; i++)
            valor = valor*10 + (espacio[i] - '0');
        if (valor < min || valor > max)
        {
            cout << "debe estar entre " << min << " y " << max << endl;
            continue;
        }
        return (unsigned short int)valor;
    }
}