#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

#include "DNI.h"
#include "ordenacion.h"
typedef DNI TDATO;

struct Estadistica
{
  string nombre;
  int mayor;
  int menor;
  double media;
};

void imprimir_estadisticas(vector<Estadistica> est)
{
  cout << "Tabla de estadisticas:" << endl;
  cout << "\t\t"<<"Mayor"<<"\t"<<"Media"<<"\t"<<"Menor"<<endl;
  cout<<est[0].nombre<<"\t\t"<<est[0].mayor<<"\t"<<est[0].media<<"\t"<<est[0].menor<<endl;
  for(int i=1;i<est.size();i++)
  {
      cout<<est[i].nombre<<"\t"<<est[i].mayor<<"\t"<<est[i].media<<"\t"<<est[i].menor<<endl;
  }
}
int main()
{
  int tam_secuencia;
  int num_vectores;
  vector<Estadistica> estadisticas;
  vector< vector<TDATO> > vectores;
  cout << "---------------------PRACTICA 5----------------" << endl;
  cout << "Introduzca Numero de elementos del vector => ";
  cin >> tam_secuencia;
  cout << endl;
  cout << "Introduzca el numero de vectores sobre los que ejecutar las pruebas => ";
  cin >> num_vectores;
  cout << endl;

  for(int i=0;i<num_vectores;i++)
  {
    vector<TDATO> aux;
    inicializacion_vector(aux,tam_secuencia);
    vectores.resize(vectores.size()+1);
    vectores[i] = aux;
  }

  cout << "Mostrando vectores aleatorios no ordenador:" << endl;
  for(int i=0;i<vectores.size();i++)
  {
    cout << "Vector " << i << " =>\t" ;
    for(int contador = 0;contador<tam_secuencia;contador++)
    {
      cout << vectores[i][contador];
      if(contador <tam_secuencia-1)
            cout << ",";
    }
    cout << endl;
  }

  //Método de ordenación de la Burbuja
  struct Estadistica e_burbuja;
  e_burbuja.nombre = "Burbuja";
  e_burbuja.mayor = 0;
  e_burbuja.menor = 1000000;
  vector<int> comparaciones_burbuja;
  double suma = 0;
  comparaciones_burbuja.resize(tam_secuencia);

  for(int i=0;i<num_vectores;i++)
  {
    vector<TDATO> copia = vectores[i];
    //cout << "Algoritmo copia => ";
    //imprimir(copia);
    //cout << endl;
    //cout << "DNI::comparaciones->PRE_BURBUJA:" << DNI::comparaciones <<endl;
    algoritmo_burbuja(copia,tam_secuencia,false);
    //cout << "DNI::comparaciones->POST_BURBUJA:" << DNI::comparaciones <<endl;
    comparaciones_burbuja[i] = DNI::comparaciones;
    if(e_burbuja.mayor < DNI::comparaciones)
    {
      e_burbuja.mayor = DNI::comparaciones;
    }
    if(e_burbuja.menor > DNI::comparaciones)
    {
      e_burbuja.menor = DNI::comparaciones;
    }
    suma += comparaciones_burbuja[i];
    DNI::comparaciones = 0;
  }
  e_burbuja.media = (suma / num_vectores);
  estadisticas.resize(estadisticas.size()+1);
  estadisticas[0] = e_burbuja;
  DNI::comparaciones = 0;

  /*cout << "Comprobando el estado los vectores despues de quicksort:" << endl;
  for(int i=0;i<num_vectores;i++)
  {
    imprimir(vectores[i]);
    cout << endl;
  }*/

  //Método de ordenación de Inserción
  struct Estadistica e_insercion;
  e_insercion.nombre = "Insercion";
  e_insercion.mayor = 0;
  e_insercion.menor = 1000000;
  vector<int> comparaciones_insercion;
  double suma1 = 0;
  comparaciones_insercion.resize(tam_secuencia);
  for(int i=0;i<num_vectores;i++)
  {
    //vector<TDATO> v;
    //inicializacion_vector(v,tam_secuencia);
    vector<TDATO> copia = vectores[i];
    algoritmo_insercion(copia,tam_secuencia,false);
    comparaciones_insercion.resize(comparaciones_insercion.size()+1);
    comparaciones_insercion[i] = DNI::comparaciones;
    if(e_insercion.mayor < DNI::comparaciones)
    {
      e_insercion.mayor = DNI::comparaciones;
    }
    if(e_insercion.menor > DNI::comparaciones)
    {
      e_insercion.menor = DNI::comparaciones;
    }

    DNI::comparaciones = 0;
    suma1 += comparaciones_insercion[i];
  }
  e_insercion.media = (suma1 / num_vectores);
  estadisticas.resize(estadisticas.size()+1);
  estadisticas[1] = e_insercion;

  //Método de ordenación de Quicksort
  struct Estadistica e_quicksort;
  e_quicksort.nombre = "Quicksort";
  e_quicksort.mayor = 0;
  e_quicksort.menor = 100000;
  vector<int> comparaciones_quicksort;
  double suma2 = 0;
  comparaciones_quicksort.resize(tam_secuencia);
  for(int i=0;i<num_vectores;i++)
  {
    vector<TDATO> copia = vectores[i];
    algoritmo_quicksort(copia,0,tam_secuencia-1,false);
    comparaciones_quicksort.resize(comparaciones_quicksort.size()+1);
    comparaciones_quicksort[i] = DNI::comparaciones;
    if(e_quicksort.mayor < DNI::comparaciones)
    {
      e_quicksort.mayor = DNI::comparaciones;
    }

    if(e_quicksort.menor > DNI::comparaciones)
    {
      e_quicksort.menor = DNI::comparaciones;
    }
    suma2 += comparaciones_quicksort[i];
    DNI::comparaciones = 0;
  }
  e_quicksort.media = (suma2 / num_vectores);
  estadisticas.resize(estadisticas.size()+1);
  estadisticas[2] = e_quicksort;

  /*cout << "Comprobando el estado los vectores despues de quicksort:" << endl;
  for(int i=0;i<num_vectores;i++)
  {
    imprimir(vectores[i]);
    cout << endl;
  }*/
  cout << endl;
  //Método de ordenación Mergesort
  struct Estadistica e_mergesort;
  e_mergesort.nombre = "Mergesort";
  e_mergesort.mayor = 0;
  e_mergesort.menor = 100000;
  vector<int> comparaciones_mergesort;
  double suma3 = 0;
  comparaciones_mergesort.resize(tam_secuencia);
  for(int i=0;i<num_vectores;i++)
  {
    //vector<TDATO> v;
    //inicializacion_vector(v,tam_secuencia);
    vector<TDATO> copia = vectores[i];
    algoritmo_mergesort(copia,0,tam_secuencia-1,false);
    comparaciones_mergesort.resize(comparaciones_mergesort.size()+1);
    comparaciones_mergesort[i] = DNI::comparaciones;
    if(e_mergesort.mayor < DNI::comparaciones)
    {
      e_mergesort.mayor = DNI::comparaciones;
    }

    if(e_mergesort.menor > DNI::comparaciones)
    {
      e_mergesort.menor = DNI::comparaciones;
    }
    DNI::comparaciones = 0;
    suma3 += comparaciones_mergesort[i];
  }
  e_mergesort.media = (suma3 / num_vectores);
  estadisticas.resize(estadisticas.size()+1);
  estadisticas[3] = e_mergesort;

  struct Estadistica e_seleccion;
  e_seleccion.nombre = "Seleccion";
  e_seleccion.mayor = 0;
  e_seleccion.menor = 100000;
  vector<int> comparaciones_seleccion;
  double suma4 = 0;
  comparaciones_seleccion.resize(tam_secuencia);
  for(int i=0;i<num_vectores;i++)
  {
    //vector<TDATO> v;
    //inicializacion_vector(v,tam_secuencia);
    vector<TDATO> copia = vectores[i];
    algoritmo_seleccion(copia,tam_secuencia,false);
    comparaciones_seleccion.resize(comparaciones_seleccion.size()+1);
    comparaciones_seleccion[i] = DNI::comparaciones;
    if(e_seleccion.mayor < DNI::comparaciones)
    {
      e_seleccion.mayor = DNI::comparaciones;
    }

    if(e_seleccion.menor > DNI::comparaciones)
    {
      e_seleccion.menor = DNI::comparaciones;
    }
    DNI::comparaciones = 0;
    suma4 += comparaciones_seleccion[i];
  }
  e_seleccion.media = (suma4 / num_vectores);
  estadisticas.resize(estadisticas.size()+1);
  estadisticas[4] = e_seleccion;

  struct Estadistica e_shellsort;
  e_shellsort.nombre = "ShellSort";
  e_shellsort.mayor = 0;
  e_shellsort.menor = 100000;
  vector<int> comparaciones_shellsort;
  double suma5 = 0;
  comparaciones_shellsort.resize(tam_secuencia);
  double alfa = 0;
  cout << "Introduzca alfa:[entre 0 y 1] => ";
  cin >> alfa;
  cout << endl;
  for(int i=0;i<num_vectores;i++)
  {
    //vector<TDATO> v;
    //inicializacion_vector(v,tam_secuencia);
    vector<TDATO> copia = vectores[i];
    algoritmo_shellshort(copia,tam_secuencia,alfa, false);
    comparaciones_shellsort.resize(comparaciones_shellsort.size()+1);
    comparaciones_shellsort[i] = DNI::comparaciones;
    if(e_shellsort.mayor < DNI::comparaciones)
    {
      e_shellsort.mayor = DNI::comparaciones;
    }

    if(e_shellsort.menor > DNI::comparaciones)
    {
      e_shellsort.menor = DNI::comparaciones;
    }
    DNI::comparaciones = 0;
    suma5 += comparaciones_shellsort[i];
  }
  e_shellsort.media = (suma5 / num_vectores);
  estadisticas.resize(estadisticas.size()+1);
  estadisticas[5] = e_shellsort;

  imprimir_estadisticas(estadisticas);

  return 0;
}
