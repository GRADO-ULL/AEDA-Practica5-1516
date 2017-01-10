#include <iostream>
#include <stdlib.h>
#include <vector>

class DNI;

using namespace std;
typedef DNI TDATO;

template<class TDATO>
void imprimir(vector<TDATO> v_)
{
    for(int i=0;i<v_.size();i++)
    {
        cout << v_[i];
        if(i<v_.size()-1)
            cout << ",";
    }
    cout << endl;
}

bool comprobar_pos(int actual,vector<int> posiciones_)
{
    bool resultado = false;
    for(int i=0;i<posiciones_.size();i++)
    {
        if(posiciones_[i] == actual)
        {
            resultado = true;
            break;
        }
        else
        {
            resultado = false;
        }
    }
    return resultado;
}

template<class TDATO>
void imprimir2(vector<TDATO> v_, vector<int> posiciones)
{
    int contador = 0;
    for(int i=0;i<v_.size();i++)
    {
        if(comprobar_pos(i,posiciones))
        {
            cout << "[" << v_[i] << "]";
            contador++;
        }
        else
        {
            cout << v_[i];
        }

        if(i<v_.size()-1)
        {
            cout << ",";
        }
    }
    cout << endl;
}

template<class TDATO>
void inicializacion_vector(vector<TDATO> &v, int tamanio)
{
    v.resize(tamanio);
    for(int i=0;i<tamanio;i++)
    {
        srand(clock());
        int aux = 30000000 + rand()%(80000001-30000000);
        DNI d(aux);
        v[i] = d;
    }
}

template<class TDATO>
void algoritmo_burbuja(vector<TDATO> &v,int tamanio, bool modo_demostracion)
{
    if(modo_demostracion == true)
    {
      cout << "Introduzca ENTER para comenzar..." << endl;
      cout << "-------------------------" << endl;
      cin.get();
    }
    for (int i = 1; i < tamanio; i++)
    {
        vector<int> auxiliar_pos;
        if(modo_demostracion == true)
        {
          cin.get();
          cout << "Iteracion " << i-1 << endl;
          imprimir(v);
        }
        for (int j = tamanio-1; j >= i; j--)
        {
            if(v[j] < v[j-1])
            {
                auxiliar_pos.resize(auxiliar_pos.size()+2);
                auxiliar_pos[0] = j;
                auxiliar_pos[1] = j-1;

                if(modo_demostracion == true)
                {
                    cout << "Cambio " << v[j-1] << " en la posicion " << j-1 << " por " << v[j] << " en la posicion " << j << endl;
                }

                TDATO x = v[j-1];
                v[j-1] = v[j];
                v[j] = x;
                if(modo_demostracion == true)
                {
                    imprimir2(v,auxiliar_pos);
                    cout << endl;
                }
                auxiliar_pos.clear();
            }
        }
        if(modo_demostracion == true)
          cout << "-------------------------" << endl;
    }
    if(modo_demostracion == true)
      cout << "Introduzca enter para mostrar el vector ordenado..." << endl;
}

template<class TDATO>
void algoritmo_insercion(vector<TDATO> &v, int tamanio,bool modo_demostracion)
{
    if(modo_demostracion == true)
    {
      cout << endl;
      cout << "Introduzca ENTER para comenzar..." << endl;
      cout << "-------------------------";
      cin.get();
    }

    for (int i=1; i<tamanio; i++)
    {
        vector<int> auxiliar_pos;
        if(modo_demostracion == true)
        {
          cin.get();
          cout << "Iteracion " << i-1 << endl;
          imprimir(v);
          cout << endl;
        }

        TDATO aux = v[i];
        int j = i - 1;

        while ( (v[j] > aux) && (j >= 0) )
        {
            auxiliar_pos.resize(auxiliar_pos.size()+2);
            auxiliar_pos[0] = j;
            auxiliar_pos[1] = j+1;

            if(modo_demostracion == true)
              cout << "Cambio " << v[j+1] << " en la posicion " << j+1 << " por " << v[j] << " en la posicion " << j << endl;
            v[j+1] = v[j];
            j--;
            v[j+1] = aux;
            if(modo_demostracion == true)
            {
              imprimir2(v,auxiliar_pos);
              cout << endl;
            }
            auxiliar_pos.clear();
        }

        if(modo_demostracion == true)
          cout << "-------------------------" << endl;

        auxiliar_pos.clear();
    }
}

template<class TDATO>
void algoritmo_quicksort(vector<TDATO> &v, int inicio, int final, bool modo_demostracion)
{
    int i = inicio;
    int f = final;
    int contador = 0;
    TDATO p = v[(i+f)/2];
    while (i <= f)
    {
      if(modo_demostracion == true)
      {
        cin.get();
        cout << "Vector => ";
        imprimir(v);
        cout << endl;

      }

      while (v[i] < p) i++;
      while (v[f] > p) f--;
      if(i <= f)
      {
          contador++;
          vector<int> auxiliar_pos;
          auxiliar_pos.resize(auxiliar_pos.size()+2);
          auxiliar_pos[0] = i;
          auxiliar_pos[1] = f;
          if(modo_demostracion == true)
          {
            cout << "Cambio " << v[i] << " en la posicion " << i << " por " << v[f] << " en la posicion " << f;
            cout << endl;
          }

            TDATO x = v[i];
            v[i] = v[f];
            v[f] = x;
            i++;
            f--;
            if(modo_demostracion == true)
              imprimir2(v,auxiliar_pos);
            auxiliar_pos.clear();
        }
        if(modo_demostracion == true)
          cout << "-------------------------" << endl;
    }

    if (inicio < f)
        algoritmo_quicksort(v, inicio, f,false);

    if (i < final)
        algoritmo_quicksort(v, i, final,false);
}

template<class TDATO>
void mezclado(vector<TDATO> &v, int ini, int cen, int fin, bool modo_demostracion)
{
    int i = ini;
    int j = cen + 1;
    int k = ini;
    vector<TDATO> aux;
    aux.resize(v.size());

    while((i <= cen) && (j <= fin))
    {
        if (v[i] < v[j])
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
        k++;
    }

    if (i > cen)
    {
        while(j <= fin)
        {
            aux[k] = v[j] ;
            j++;
            k++;
        }
    }
    else
    {
        while (i <= cen)
        {
            aux[k] = v[i];
            i++;
            k++;
        }
    }

    for(int k = ini; k <= fin; k++)
        v[k] = aux[k];
    if(modo_demostracion == true)
    {
      cout << "Vector => ";
      imprimir(v);
      cin.get();
      cout << endl;
    }
}

template<class TDATO>
void algoritmo_mergesort(vector<TDATO> &v, int inicio, int final, bool modo_demostracion)
{
    int centro;
    if(inicio < final)
    {
        centro = (inicio + final) / 2;
        algoritmo_mergesort(v, inicio, centro, modo_demostracion);
        algoritmo_mergesort(v, centro+1, final, modo_demostracion);
        mezclado(v, inicio, centro, final, modo_demostracion);
    }
}

template<class TDATO>
void algoritmo_seleccion(vector<TDATO> &v, int tamanio, bool modo_demostracion)
{
    if(modo_demostracion == true)
    {
      cout << endl;
      cout << "Introduzca ENTER para comenzar..." << endl;
      cout << "-------------------------";
      cin.get();
    }

    for (int i = 0; i < tamanio-1; i++)
    {
        vector<int> auxiliar_pos;
        if(modo_demostracion == true)
        {
          cin.get();
          cout << "Iteracion " << i << endl;
          imprimir(v);
          cout << endl;
        }

        int min = i ;
        for (int j = i+1; j < tamanio; j++)
        {
            if(v[j] < v[min])
            {
                int min = j;

                if(modo_demostracion == true)
                {
                  auxiliar_pos.resize(auxiliar_pos.size()+2);
                  auxiliar_pos[0] = i;
                  auxiliar_pos[1] = min;
                  cout << "Cambio " << v[min] << " en la posicion " << min << " por " << v[i] << " en la posicion " << i;
                }

                TDATO x = v[min] ;
                v[min] = v[i] ;
                v[i] = x ;
                if(modo_demostracion == true)
                  imprimir2(v,auxiliar_pos);
            }
            auxiliar_pos.clear();
        }
        if(modo_demostracion == true)
        {
          auxiliar_pos.clear();
          cout << "-------------------------" << endl;
        }
    }
}

template<class TDATO>
void deltasort(int d, vector<TDATO> &v_, int n, bool modo_demostracion)
{
 for (int i = d; i < n; i++)
 {
   if(modo_demostracion == true)
   {
     cout << "Introduzca enter para siguiente iteracion..." << endl;
   }
   vector<int> auxiliar_pos;
   TDATO x = v_[i];
   int j = i;
   while ((j >= d) && (x < v_[j-d]))
   {
     v_[j] = v_[j-d];
     j = j - d;
   };
   if(modo_demostracion == true)
   {
     auxiliar_pos.resize(auxiliar_pos.size()+2);
     auxiliar_pos[0] = i;
     auxiliar_pos[1] = j;
     //cout << "Cambio " << x << " en la posicion " << i << " y " << sec[j] << " en la posicion " << j << endl;
   }
   v_[j] = x;
   if(modo_demostracion == true)
   {
     cout << "Vector => ";
     imprimir2(v_,auxiliar_pos);
     cin.get();
     auxiliar_pos.clear();
     cout << endl;
     cout << "----------------------------------------" << endl;
   }
 };
};

template<class TDATO>
void algoritmo_shellshort(vector<TDATO> &v, int tamanio, double alfa, bool modo_demostracion)
{
  int del = tamanio;
  while(del > 1)
  {
    del = del * alfa;
    deltasort(del,v, tamanio, modo_demostracion);
  };
}
