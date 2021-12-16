// Щетинин2 Матрицы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <clocale>
#include <iostream>
#include <time.h>
#include <omp.h>
#include <chrono>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    const int n = 1000;
    int** Bsgl = new int* [n];
    int** Csgl = new int* [n];
    int** Bdbl = new int* [n];
    //  int** Cdbl = new int*[n];
    for (int i = 0; i < n; i++)
    {
        Bsgl[i] = new int[n];
        Csgl[i] = new int[n];
        Bdbl[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            Bsgl[i][j] = rand();
            Bdbl[i][j] = rand();
        }
    }
    unsigned int t;
    t = clock();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            Csgl[i][j] = 0;
            for (int k = 0; k < n; k++)
                Csgl[i][j] += Bsgl[i][k] * Bdbl[k][j];
        }
    t = clock() - t;
    cout << "\nВремя затраченное на умножение (последовательное): " << "\t" << t;
    t = clock();
#pragma omp parallel num_threads(2)
    {
#pragma omp for
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                Csgl[i][j] = 0;
                for (int k = 0; k < n; k++)
                    Csgl[i][j] += Bsgl[i][k] * Bdbl[k][j];
            }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на умножение (2 потока): " << "\t" << t;

    t = clock();
#pragma omp parallel num_threads(4)
    {
#pragma omp for
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                Csgl[i][j] = 0;
                for (int k = 0; k < n; k++)
                    Csgl[i][j] += Bsgl[i][k] * Bdbl[k][j];
            }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на умножение (4 потока): " << "\t" << t;

    t = clock();
#pragma omp parallel num_threads(8)
    {
#pragma omp for
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                Csgl[i][j] = 0;
                for (int k = 0; k < n; k++)
                    Csgl[i][j] += Bsgl[i][k] * Bdbl[k][j];
            }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на умножение (8 потока): " << "\t" << t;

    t = clock();
#pragma omp parallel num_threads(16)
    {
#pragma omp for
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                Csgl[i][j] = 0;
                for (int k = 0; k < n; k++)
                    Csgl[i][j] += Bsgl[i][k] * Bdbl[k][j];
            }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на умножение (16 потока): " << "\t" << t;

    t = clock();
#pragma omp parallel num_threads(32)
    {
#pragma omp for
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                Csgl[i][j] = 0;
                for (int k = 0; k < n; k++)
                    Csgl[i][j] += Bsgl[i][k] * Bdbl[k][j];
            }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на умножение (32 потока): " << "\t" << t;


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
