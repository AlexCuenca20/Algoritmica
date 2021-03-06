#################################################
# Autor: Andrés Herrera Poyatos
# Estructura de Datos, Práctica 1, Ejercicio 7
#################################################

# Script de bash que genera una fichero de nombre dado
# con los resultados generados por el ejecutable indicado.

#!/bin/bash

# Variables:
INICIO=2
FIN=4002
INCREMENTO=200
EJECUTABLE=$1
SALIDA=$2

i=$INICIO
echo > $SALIDA
while [ $i -le $FIN ]
do
  echo Ejecución tam = $i
  echo `./$EJECUTABLE $i 10000` >> $SALIDA
  i=$((i+$INCREMENTO))
done