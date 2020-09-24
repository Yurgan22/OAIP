#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main()
{
    int n, a[100], buf, f_el, left = 0, right = 0;

    setlocale(LC_ALL, "Rus");

    printf_s("Введите размерность массива N = ");
    scanf_s("%d", &n);
    printf_s("Введите элементы массива A[%d]: ", n);
    scanf_s("%d", &a[0]);
    for (int i = 1; i < n; i++)
    {
        scanf_s("%d", &a[i]);
        if (a[i] > a[0]) right++; else left++;
    }

    f_el = a[0];
    int i = n - 1;

    while (i > 0)
        if (a[i] > f_el && right != 0)
        {
            buf = a[i];
            for (int j = i; j > 0; j--)
                a[j] = a[j - 1];
            a[0] = buf;
            right--;
        }
        else i--;

    bool graniza = 0;
    printf_s("Массив после перестановок: \n");
    for (int i = 0; i < n; i++)
    {
        if (a[i] == f_el && !graniza) {
            printf_s("| %d | ", a[i]); graniza = 1;
        }
        else
            printf_s("%d ", a[i]);
    }
    return 0;
}


