#include "DyV.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <string>

template <typename T>
void MeasureQuickSort(std::vector<T>& vec, const std::string& method, int (*partition)(std::vector<T>&, int, int)) {
    auto vec_copy = vec;
    auto start = std::chrono::system_clock::now();

    QuickSort(vec_copy, 0, vec_copy.size() - 1, partition);

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float, std::milli> duration = end - start;

    std::cout << method << ": Time = " << duration.count() << " ms" << std::endl;
}

int main() {
    try {

        std::vector<int> vec_asc{1, 3, 5, 7, 9};
        int pos = BusquedaBinaria(5, vec_asc, 0, vec_asc.size() - 1);
        std::cout << "Ascendente: Valor 5 encontrado en posición: " << pos << "\n";


        std::vector<int> vec_desc{9, 7, 5, 3, 1};
        pos = BusquedaBinaria_INV(5, vec_desc, 0, vec_desc.size() - 1);
        std::cout << "Descendente: Valor 5 encontrado en posición: " << pos << "\n";
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << "\n";
    }


    std::vector<int> vec_int{10, 7, 8, 9, 1, 5};


    std::cout << "\nQuickSort for int vector:\n";
    MeasureQuickSort(vec_int, "Pivot: Last", Partition_Last<int>);
    MeasureQuickSort(vec_int, "Pivot: First", Partition_First<int>);
    MeasureQuickSort(vec_int, "Pivot: Random", Partition_Random<int>);
    MeasureQuickSort(vec_int, "Pivot: Center", Partition_Center<int>);

    return 0;
}
