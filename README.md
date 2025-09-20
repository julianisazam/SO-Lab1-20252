
# Informe Laboratorio #1




##                  Integrantes

- [Julian Isaza Marin](https://github.com/julianisazam)
- [Sebastian Pelaez Acevedo](https://github.com/SPelaez122)
- [Simon Sanchez Sepulveda](https://github.com/Simonsanchezs)


## Forma de trabajo
 Los integrantes del equipo no contaban con mucho conocimiento del lenguaje C, sin embargo, tenían muy buenas bases en Java lo que les permitió adaptarse de una manera rápida a la lógica de dicho lenguaje. 
 
 Para el desarrollo efectivo y correcto entendimiento por parte de todos los integrantes del equipo, la forma de trabajo fue reunirse a través de la aplicación Discord y desarrollar el código en conjunto, tomando las opiniones de todos los integrantes por igual y teniendo la mejor comunicación; es por esto que no se realizaron Branch diferente a la main y los commits que se realizaron se hicieron con la etiqueta 'Co-Author' ya que cada avance se hizo en conjunto para entender todas las funciones y lógica del mismo.

 ## Primer commit
 Esta Versión la tomamos como introducción para planificar la estructura o camino para el desarrollo del código, teníamos tres caminos correspondientes a las tres funcionalidades principales del laboratorio, por lo tanto, para esta primera versión la funcionalidad que realizamos fue Leer un archivo `.txt` (ingresando el nombre del archivo de manera quemada en el código) y que se imprimiera en consola el revés de su contenido tal como se puede observar en el primer commit del fork. Sin embargo, se realizó de manera muy básica, limitada y no cumplía con los requisitos de la práctica por lo que sufriría muchos cambios para que cumpliera con los estandares de calidad, modularidad, buenas prácticas y requisitos del laboratorio.

 ## Segundo commit
En esta versión se busca refactorizar el código para hacerlo más dinámico, se crea la función `countLines`, que recorre el archivo para calcular la cantidad de líneas antes de leerlas, para poder implementar la reserva de memoria dinámica `malloc` y guardar cada línea en un arreglo de punteros usando la instrucción `getline` para finalmente imprimirlas de forma inversa, haciendo  al código más flexible y permitiendo manipular las líneas, aunque a costa de mayor complejidad y necesidad de gestión manual de memoria por lo que todavía había cosas por implementar y refactorizar.

## Tercer commit
En esta versión se realizó la obtención de los archivos no de forma quemada como se tenía sino de forma dinámica donde el usuario especificara el nombre del archivo, también se introdujo la nueva función `readLineAndInversePrint`, que combina el conteo de líneas con `countLines`, la reserva de memoria dinámica con `malloc`, y la lectura de cada línea con `getline`, aumentando la modularidad del código y acércandose más a los requisitos del laboratorio.

## Cuarto commit
Es la versión con cambios más exponenciales en el código respecto a las anteriores versiones, como:

`readAndPrintConsole:` Que permite ingresar texto desde la consola y mostrarlo en orden inverso.

`readFileAndReturnOutputFile:` añade la posibilidad de leer un archivo de entrada y escribir el resultado invertido en un archivo de salida.

`Manejo de opciones desde el main:`
El main ahora interpreta los argumentos pasados por consola:

0 argumento → lee desde consola (`readAndPrintConsole`).

1 argumento → lee un archivo y lo imprime invertido en consola(`readFileAndInversePrint`).

2 argumentos → lee un archivo y guarda la salida invertida en un archivo nuevo (`readFileAndReturnOutputFile`).
Esto hace que el programa soporte tres modos de uso diferentes, lo que no existía en versiones anteriores.

## Quinto commit
**feat:** manejo de excepciones y refactorización de funcionalidades  
- Se añadieron controles de errores en las funciones principales para mejorar la robustez.  
- Se refactorizó `readAndPrintConsole` para que funcione de manera dinámica para la cantidad de lineas que requiera el usuario.  
- Utilizacion de un control de parada para la funcion `readAndPrintConsole` utilizando Control + D
- Se mejoró la legibilidad y el flujo de ejecución en caso de errores.  

---

## Commits extras
**feat:** correccion de error pequeños y refactorizacion final
