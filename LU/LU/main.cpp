//
//  main.cpp
//  LU
//
//  Created by grafon100 on 05/01/2022.
//


#include <iostream>
#include <iomanip>
using namespace std;


const int MAX = 100;

void luDecomposition(int mat[][MAX], int n)

{
    int lower[n][n], upper[n][n];
    // Разложение матрицы на верхнюю и нижнюю
    // треугольная матрица
    for (int i = 0; i < n; i++) {
        // Верхняя Треугольная
        for (int k = i; k < n; k++) {
            // Суммирование L (i, j) * U (j, k)
            int sum = 0;
            for (int j = 0; j < i; j++)
                sum += (lower[i][j] * upper[j][k]);
            // Оцениваем U (i, k)
            upper[i][k] = mat[i][k] - sum;
        }


        // Нижняя Треугольная
        for (int k = i; k < n; k++) {
            if (i == k)
                lower[i][i] = 1; // Диагональ как 1
            else {
                // Суммирование L (k, j) * U (j, i)
                int sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (lower[k][j] * upper[j][i]);
                // Оцениваем L (k, i)
                lower[k][i] = (mat[k][i] - sum) / upper[i][i];
            }
        }
    }

  

    // setw для хорошего отображения

    cout << setw(6) << "      Lower Triangular"

         << setw(32) << "Upper Triangular" << endl;

  

    // Отображение результата:

    for (int i = 0; i < n; i++) {

        // ниже

        for (int j = 0; j < n; j++)

            cout << setw(6) << lower[i][j] << "\t";

        cout << "\t";

  

        // Верхний

        for (int j = 0; j < n; j++)

            cout << setw(6) << upper[i][j] << "\t";

        cout << endl;

    }

}

  
// Код драйвера

int main()

{

    int mat[][MAX] = { { 2, -1, -2 },

                       { -4, 6, 3 },

                       { -4, -2, 8 } };

  

    luDecomposition(mat, 3);

    return 0;

}
