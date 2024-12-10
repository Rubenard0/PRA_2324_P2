#ifndef DYC_H
#define DYC_H

#include <vector>
#include <stdexcept>
#include <utility>
#include <cstdlib>
#include <ctime>


template <typename T>
int BusquedaBinaria(const T& x, const std::vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        throw std::runtime_error("No se encuentra en el array");
    }
    int medio = (ini + fin) / 2;
    if (v[medio] == x) return medio;
    else if (v[medio] > x) return BusquedaBinaria(x, v, ini, medio - 1);
    else return BusquedaBinaria(x, v, medio + 1, fin);
}


template <typename T>
int BusquedaBinaria_INV(const T& x, const std::vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        throw std::runtime_error("No se encuentra en el array");
    }
    int medio = (ini + fin) / 2;
    if (v[medio] == x) return medio;
    else if (v[medio] < x) return BusquedaBinaria_INV(x, v, ini, medio - 1);
    else return BusquedaBinaria_INV(x, v, medio + 1, fin);
}


template <typename T>
int Partition_Last(std::vector<T>& V, int ini, int fin) {
    T x = V[fin];
    int i = ini; 
    for (int j = ini; j < fin; j++) {
        if (V[j] <= x) {
            std::swap(V[i], V[j]);
            i++;
        }
    }
    std::swap(V[i], V[fin]);
    return i;
}


template <typename T>
int Partition_First(std::vector<T>& V, int ini, int fin) {
    std::swap(V[ini], V[fin]); 
    return Partition_Last(V, ini, fin);
}


template <typename T>
int Partition_Random(std::vector<T>& V, int ini, int fin) {
    std::srand(std::time(nullptr)); 
    int random_index = ini + std::rand() % (fin - ini + 1); 
    std::swap(V[random_index], V[fin]); 
    return Partition_Last(V, ini, fin);
}


template <typename T>
int Partition_Center(std::vector<T>& V, int ini, int fin) {
    int mid = ini + (fin - ini) / 2; 
    std::swap(V[mid], V[fin]); 
    return Partition_Last(V, ini, fin);
}


template <typename T>
void QuickSort(std::vector<T>& V, int ini, int fin, int (*partition)(std::vector<T>&, int, int)) {
    if (ini < fin) {
        int pivot = partition(V, ini, fin);
        QuickSort(V, ini, pivot - 1, partition); 
        QuickSort(V, pivot + 1, fin, partition);  
    }
}

#endif
