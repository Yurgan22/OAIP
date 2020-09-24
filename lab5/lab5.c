#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main()
{
    int n, m, a[100][100], min, kol = -1, error;

    setlocale(LC_ALL, "Rus");

    do {
        printf_s("Введите размерность массива N*M = ");
        error = scanf_s("%d", &n);
        error = scanf_s("%d", &m);
        if (error == 0)
        {
            printf("Данные введены неверно, повторите попытку...\n");
            rewind(stdin);
        }
    } while (error == 0);

    printf_s("Введите элементы массива A[%d][%d]: \n", n, m);
    scanf_s("%d", &a[0][0]);
    min = a[0][0];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i != 0 || j != 0) {
                do {
                    error = scanf_s("%d", &a[i][j]);
                    if (error == 0)
                    {
                        printf("Неверный ввод, потворите попытку. Введите элементы, начиная с a[%d,%d]\n", i + 1, j + 1);
                        rewind(stdin);
                    }
                } while (error == 0);
                min = ((a[i][j] < min) ? a[i][j] : min);
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (a[i][j] % min == 0) kol++;

    printf_s("\nВ массиве А количество элементов, кратных минимальному элементу массива - %d, не включая сам элемент, равно - %d.\n", min, kol);

    return 0;
}