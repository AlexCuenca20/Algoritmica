//////////////////////////////////////////////////
// Autor: Andrés Herrera Poyatos
// Estructura de Datos, Práctica 1, Ejercicio 6
///////////////////////////////////////////////////

/* Programa que devuelve el tiempo que el algoritmo de ordenación burbuja
   tarda en ordenar un array de tamaño dado como parámetro */

# include <iostream>
# include <ctime>    // Recursos para medir tiempos
# include <cstdlib>  // Para generación de números pseudoaleatorios
# include <algorithm>

using namespace std;

// Función que ordena un array mediante el algoritmo burbuja:
void ordenarBurbuja(int *v, int n) 
{
    bool cambio = true;
    for (int i = 0; i < n-1 && cambio; i++){
        cambio = false;
        for (int j = 0; j < n-i-1; j++)
            if (v[j] > v[j+1]){
                cambio = true;
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
    }
}

// Sintaxis del programa:
void sintaxis()
{
    cerr << "Sintaxis:" << endl;
    cerr << "  TAM: Tamaño del vector (>0)" << endl;
    cerr << "  VMAX: Valor máximo (>0)" << endl;
    cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    // Lectura de parámetros
    if (argc != 3)
        sintaxis();
    int size = atoi(argv[1]);     // Tamaño del vector
    int vmax = atoi(argv[2]);    // Valor máximo
    if (size <=0 || vmax <=0)
        sintaxis();
    
    // Generación del vector aleatorio
    int *v = new int[size];       // Reserva de memoria
    for (int i = 0; i < size; i++){  // Recorrer vector
        v[i] = i;
    }
    random_shuffle(v, v + size);

    clock_t tini;    // Anotamos el tiempo de inicio
    tini=clock();
    
    ordenarBurbuja(v, size); 

    clock_t tfin;    // Anotamos el tiempo de finalización
    tfin = clock();

    // Mostramos resultados
    cout << size << "\t" << (tfin - tini) / (double) CLOCKS_PER_SEC << endl;
    
    delete [] v;     // Liberamos memoria dinámica
}
