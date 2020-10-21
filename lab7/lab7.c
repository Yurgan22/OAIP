#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<malloc.h>

int main()
{
	setlocale(LC_ALL, "rus");

	int n;
	char* str;
	printf("Введите количество символов, N = ");
	scanf_s("%d", &n);
	getchar();
	str = (char*)calloc(n + 2, sizeof(char));
	fgets(str, n + 1, stdin);
	
	int j;
	for (int i = 0; i < n; i++)
		if (*(str + i) == ':') { j = i; break; }

	while ( (*(str + j + 1) != ':') && (j<n) )
	{
		j++;
		printf("%c", *(str + j));
	}

	return 0;
}