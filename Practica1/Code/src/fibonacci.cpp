/**
   @file C�lculo de la sucesi�n de Fibonacci
*/

   
#include <iostream>
using namespace std;
#include <ctime>

# include <sys/time.h>  // gettimeofday(), struct timeval
# include <stdio.h>     // printf()


/**
   @brief Calcula el t�rmino n-�simo de la sucesi�n de Fibonacci.

   @param n: n�mero de orden del t�rmino buscado. n >= 1.

   @return: t�rmino n-�simo de la sucesi�n de Fibonacci.
*/
int fibo(int n)
{
  if (n < 2)
    return 1;
  else
    return fibo(n-1) + fibo(n-2);
}


int main()
{

  int n;
  int f;
 
  cout << "�N�mero del t�rmino: ";
  cin >> n;

// Variables para medir el tiempo
    struct timeval tv1, tv2; // gettimeofday() secs-usecs
    double           tv_usecs; // y sus cuentas
    
    //----------- Ejecuci�n del algoritmo -----------//
    gettimeofday(&tv1,NULL);

  f = fibo(n);

  gettimeofday(&tv2,NULL);

  tv_usecs= ((tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec)) / 1000000.0;
    cout << tv_usecs << endl;

  return 0;
}
 
