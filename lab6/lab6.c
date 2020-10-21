#include<stdlib.h>
#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "rus");

	int n, * arr;
	printf("Введите размер матрицы, N = ");
	scanf_s("%d", &n);

	arr = (int*)malloc(n * n * sizeof(int));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", arr + i * n + j);

	int  index = n * n, kol = 0, i = 0;
	while (kol < 2 && i < n * n)
	{
		if (*(arr + i) < 0) {
			kol++; index = i;
		}
		i++;
	}

	index++;
	int buf;
	for (int i = index; i < n * n; i++) {
		for (int j = i; j < n * n; j++)
			if (*(arr + i) < *(arr + j))
			{
				buf = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = buf;
			}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d  ", *(arr + i * n + j));
		printf("\n");
	}

	return 0;
}