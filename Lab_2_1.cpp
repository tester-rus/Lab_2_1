#include <iostream>
#include <omp.h>
#include <string>
#include <sstream>

int main() 
{
    setlocale(LC_ALL, "rus");
    // Проверка поддержки OpenMP
#ifdef _OPENMP
    std::cout << "OpenMP поддерживается.\n";
#else
    std::cout << "OpenMP не поддерживается.\n";
    return 1;
#endif

    // Определение версии OpenMP
    int openmpVersion = _OPENMP;
    std::stringstream ss;
    ss << openmpVersion;
    std::string versionString = ss.str();

    // Преобразование даты в номер версии
    int majorVersion = std::stoi(versionString.substr(0, 2));
    int minorVersion = std::stoi(versionString.substr(2, 2));

    std::cout << "Версия OpenMP: " << majorVersion << "." << minorVersion << "\n";

    // Определение количества ядер процессора
    int num_cores = omp_get_num_procs();
    std::cout << "Количество ядер процессора: " << num_cores << "\n";

    return 0;
}