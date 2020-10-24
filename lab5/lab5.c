// Variant 8
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void vvod(int* x)
{
    while (!(scanf_s("%d", x))) {
        printf("Данные введены неверно, повторите попытку...\n");
        rewind(stdin);
    }
}

void vvod_array(int* x, int i, int j)
{
    while (!(scanf_s("%d", x))) {
        printf("Данные введены неверно, повторите попытку. Введите элементы, начиная с a[%d][%d]\n", i + 1, j + 1);
        rewind(stdin);
    }
}

int main()
{
    int n, m, a[100][100], min, kol = -1;

    setlocale(LC_ALL, "Rus");

    printf_s("Введите размерность массива\nN = ");
    vvod(&n);
    printf_s("M = ");
    vvod(&m);

    printf_s("Введите элементы массива A[%d][%d]: \n", n, m);
    scanf_s("%d", &a[0][0]);
    min = a[0][0];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i != 0 || j != 0) {
                vvod_array(&a[i][j], i, j);
                min = ((a[i][j] < min) ? a[i][j] : min);
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) if (a[i][j] % min == 0) kol++;

    printf_s("\nВ массиве А количество элементов, кратных минимальному элементу массива - %d, не включая сам элемент, равно - %d.\n", min, kol);

    return 0;
}
