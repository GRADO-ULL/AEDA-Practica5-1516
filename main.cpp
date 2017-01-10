#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

#include "DNI.h"
#include "ordenacion.h"
typedef DNI TDATO;


int menu(void)
{
    int op;
    cout << "Seleccion el algoritmo de busqueda" << endl;
    cout << "1.-Insercion" << endl;
    cout << "2.-Burbuja" << endl;
    cout << "3.-Seleccion" << endl;
    cout << "4.-QuickSort" << endl;
    cout << "5.-MergeSort" << endl;
    cout << "6.-ShellSort" << endl;
    cout << "0.-Salir" << endl;
    cout << "Opcion: ";
    cin >> op;
    cout << "----------------------------------------" << endl;
    return op;
}

int main()
{
    vector<TDATO> v;

    int tam_secuencia;

    cout << "---------------------PRACTICA 5----------------" << endl;
    cout << "Introduzca Numero de elementos del vector => ";
    cin >> tam_secuencia;

    //Redimensionamos e inicializamos el vector
    inicializacion_vector(v,tam_secuencia);
    /*inicializacion_vector(v3,tam_secuencia);
    inicializacion_vector(v4,tam_secuencia);
    inicializacion_vector(v5,tam_secuencia);*/

    //Accedemos al menu
    int opcion = menu();
    switch(opcion)
    {
        case 1:
        {
            cout << "Ha introducido opcion 1 => Algoritmo de Insercion" << endl;
            cout << "Vector aleatorio desordenador => ";
            imprimir(v);
            cout << endl;
            algoritmo_insercion(v,tam_secuencia,true);
            break;
        }
        case 2:
        {
            cout << "Ha introducido opcion 2 => Algoritmo de Burbuja" << endl;
            cout << "Vector aleatorio desordenador => ";
            imprimir(v);
            cout << endl;
            algoritmo_burbuja(v,tam_secuencia,true);
            break;
        }
        case 3:
        {
            cout << "Ha introducido la opcion 3 => Algoritmo de Seleccion" << endl;
            cout << "Vector aleatorio desordenador => ";
            imprimir(v);
            cout << endl;
            algoritmo_insercion(v,tam_secuencia,true);
            break;
        }
        case 4:
        {
            cout << "Ha introducido opcion 4 => Algoritmo de Quicksort" << endl;
            cout << "Vector aleatorio desordenador => ";
            imprimir(v);
            cout << endl;
            algoritmo_quicksort(v,0,tam_secuencia-1,true);
            break;
        }
        case 5:
        {
            cout << "Ha introducido opcion 5 => Algoritmo de Mergesort" << endl;
            cout << "Vector aleatorio desordenador => ";
            imprimir(v);
            cout << endl;
            algoritmo_mergesort(v,0,tam_secuencia-1,true);
            break;
        }
        case 6:
        {
            cout << "Ha introducido opcion 6 => Algoritmo de ShellSort" << endl;
            double alfa;
            cout << "Introduzca valor de alfa:[entre 0 y 1]:";
            cin >> alfa;
            cout << "Vector aleatorio desordenado => ";
            imprimir(v);
            cout << endl;
            algoritmo_shellshort(v,tam_secuencia, alfa, true);
            cout << "Vector ordenado => ";
            imprimir(v);
            cout << endl;
            break;
        }
        case 0:
        {
            cout << "Vector aleatorio desordenador => ";
            imprimir(v);
            cout << endl;
            cout << "Ha introducido opcion 0. Saliendo del sistema..." << endl;
            break;
        }
        default:
            cerr << "No ha elegido una opcion correcta. Saliendo del sistema..." << endl;
            exit(-1);
    }

    cout << endl;
    cout << "Vector ordenado:" << endl;
    imprimir(v);
    cout << endl;
    return 0;
}
