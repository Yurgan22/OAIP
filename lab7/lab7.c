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
	str = (char*)malloc( n * sizeof(char));
	fflush(stdin);
	getchar(); fgets(str, n + 1 , stdin);
	int j = n;
	for (int i = 0; i < n; i++)
		if (*(str + i) == ':') { j = i; break; }
	if (j == n) { printf("Упс. Двоеточий нет..."); return 0; }
	if (j == n - 1) { printf("Упс. После двоеточия нет символов..."); return 0; }
	while ( (*(str + j + 1) != ':') && (j<n-1) )
	{
		j++;
		printf("%c", *(str + j));
	}
	return 0;
}
