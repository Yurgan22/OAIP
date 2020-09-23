#include <stdio.h>
#include <locale.h>


int main() {

    setlocale(LC_ALL, "Russian");

    int a[100][100], n, s = 0, error;

    do {
        printf("Введите размерность матрицы N*N. N = ");
        error = scanf_s("%d", &n);
        if (error == 0)
        {
            printf("Неверный ввод, потворите попытку.\n");
            rewind(stdin);
        }
    } while (error == 0);

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            do {
                error = scanf_s("%d", &a[i][j]);
                if (error == 0)
                {
                    printf("Неверный ввод, потворите попытку. Введите элементы, начиная с a[%d,%d]\n",i+1,j+1);
                    rewind(stdin);
                }
            } while (error == 0);
            if (j == n - 1) s += a[i][j];
        }
    printf("Cумма элементов последнего столбца равна - %d \n", s);
    return 0;
}
