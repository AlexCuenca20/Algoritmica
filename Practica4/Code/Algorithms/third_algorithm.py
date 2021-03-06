#!/usr/bin/python

import sys
from time import time

# Parametros:
    # - k : indice del trabajo a asignar.
    # - tiempos : vector con los tiempos de los m trabajos.
    # - solucion_actual : vector con el tiempo de trabajo
    #  asignado a cada maquina.
    # - max_tiempo : Maximo de solucion_actual
    # - maquinas_libres : Numero de maquinas que no tienen asignado un trabajo.
def algoritmo3(k,tiempos, solucion_actual, max_tiempo,maquinas_libres):
    if k < len(tiempos):
    # Comprobamos que hay mas trabajos libres que maquinas libres
        if maquinas_libres < len(tiempos)-k:
            sol = float("Inf")
            for i in xrange(0,len(solucion_actual)):
                if i == 0 or solucion_actual[i-1] > 0:
                    solucion_actual[i] += tiempos[k]
                    sol = min(sol, algoritmo3(k+1,tiempos, solucion_actual,
                        max(max_tiempo, solucion_actual[i]), maquinas_libres + 0 if solucion_actual[i] != 0 else 1))
                    solucion_actual[i] -= tiempos[k]
                else:
                    break
            return sol
        # Si la comprobacion devuelve falso a cada maquina se le asigna un trabajo
        else:
            return max(max_tiempo, max(tiempos[k:]))
    else:
        return max_tiempo


if not len(sys.argv) == 3:
    print "Fallo. Se debe llamar al programa asi: ./first_algorithm <numero trabajos> <numero trabajadores>"

else:
    tiempos = []
    for i in range(int(sys.argv[1])):
        tiempos.append(i+1)

    inicial = time()
    algoritmo3(0,tiempos,[0 for i in range(0, int(sys.argv[2]))],0,int(sys.argv[2]))
    total = time() - inicial

    print total
