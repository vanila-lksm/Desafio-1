# Desafio-1
**** contenidos dentro del repositorio ****

-carpeta código: lugar donde se encuentra todo el código del programa con todos sus módulos.

*informe 1 info2 Juan gutierrez y David colmenares.docx: primer informe para la entrega del viernes 18 de septiembre.

-informe final desafío 1 informática 2.dox: informe fina con todos los datos requeridos para la entrega final que se pidieron en documento "Desafío 1 2026-2 v 1_02.dox" enviado el domingo 13 de septiembre. 

-readme.md: archivo con toda la información de los contenidos del repositorio y las instrucciones para ejecutar el programa de manera correcta.

-commits: en este repositorio hay 7 commits que muestran el progreso del código teniendo un promedio de 2 días entre cada uno de ellos aquí les pasmos las fechas en orden de cada uno 1.07/09/2026 2.10/09/2026 3.11/09/2026 4.12/09/2026 5.15/09/2026 6.17/09/2026 7.19/09/2026.

**** instrucciones para la correcta ejecución del programa ****

1. reglas en la entrada de variables: 
*-Durante la ejecución del programa constantemente se le pedirá ingresar números ya sea para indicar ubicaciones dentro del tablero, crear el propio tablero ingresando la cantidad de filas y columnas del mismo o para seleccionar la accion que desea realizar para proseguir con el juego.
*-Esta entrada esta delimitada a solo el ingreso de números, por tanto no se permite ningún tipo de letra, carácter especial o comandos; este recibimiento de datos esta protegido por la función validar_entrada() la cual les mostrara mensaje en caso de que lo que ingresen no sea un numero valido.
**-para la correcta y fluida ejecución de este programa se deben respetar todos los rangos y condiciones especiales presentes en todas las partes que pidan el ingreso de información, la omisión de esta regla o el ingreso de caracteres inválidos no permitirán seguir adelante en ningún caso y deberá ingresar una entrada valida o se le pedirá constantemente el ingreso de esta.**

2.paso a paso durante la ejecución: 
*Al inicio de la ejecución el programa le pedirá ingresar la cantidad de filas (dentro del rango 1 a 3494) y columnas (dentro del rango 1 a 50).
*Después se le permitirá escoger una de 6 opciones (en el rango de 0 a 5) 

2.1 al seleccionar la opción 1 (eliminar ficha):
*se le permitirá ingresar tanto la fila (en un rango de 0 a cantidad de filas(f) - 1) como la columna (en un rango de 0 a cantidad de columnas(c) - 1) para poder especificar la posición de la ficha dentro del tablero y poder eliminarla. 

2.2 al seleccionar la opción 2 (agregar fila):
*se le permite ingresar la ubicación donde desea agregar la nueva fila (en un rango de 0 a cantidad de filas(f)) y que además la operación ((f+1)*c*3+7)/8 no sea mayor a 65535

2.3 al seleccionar la opción 3 (eliminar fila):
*Se le permite ingresar la ubicación de la fila que desea eliminar (en un rango de 0 a cantidad de filas(f) - 1). Tenga en cuenta que el programa validará que existan suficientes filas; no le permitirá continuar con esta acción si el tablero actual tiene solo 1 fila (mínimo deben haber 2)

2.4 al seleccionar la opción 4 (agregar columna):
*se le permite ingresar la ubicación donde desea agregar la nueva columna (en un rango de 0 a cantidad de columnas(c)) junto con restricciones de que si c>=50 o si la operación ((f+1)*c*3+7)/8 es mayor a 65535 no se le permitirá ejecutar
esta accion.

2.5 al seleccionar la opción 5 (eliminar columna):
*se le permite ingresar la ubicación de la columna que desea eliminar (en un rango de 0 a cantidad de columnas(c) - 1). El programa no le permitirá realizar esta acción si el tablero actual cuenta con una sola columna (requiere un mínimo de 2).

2.6 al seleccionar la opción 0 (cerrar programa):
*al seleccionar esta opción, el programa liberará toda la memoria dinámica utilizada para el tablero y finalizará la ejecución del juego de manera segura.

**-y eso seria todo les recordamos que el ingreso de entradas invalidas no permitirán la correcta ejecución del programa y esta hará que entren en un bucle hasta que ingresen una entrada valida, muchas gracias**
