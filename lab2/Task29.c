#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    
    int a[100][100], n, s=0;
    printf("Введите размерность матрицы N*N. N = ");
    scanf_s("%d", &n);
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf_s("%d", &a[i][j]);
            if (j == n - 1) s += a[i][j];
        }
    printf("Cумма элементов последнего столбца равна %2d ", s);
    return 0;
}   
