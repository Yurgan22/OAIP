// 8 Лабараторная работа 15 Вариант
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
int main()
{
	system("chcp 1251");
	system("cls");
	int p, n, m;
	char* podstr;
	char** text;
	printf("Введите кол-во строк\n");
	scanf_s("%d", &n);
	text = (char**)malloc((n + 2) * sizeof(char*));
	printf("Введите кол-во символов в строке\n");
	scanf_s("%d", &m);
	for (int i = 0; i < n; i++)
	{
		text[i] = (char*)malloc((m + 2) * sizeof(char));
	}
	printf("Введите строки \n");
	for (int i = 0; i < n; i++)
	{
		rewind(stdin);
		fgets(text[i], m, stdin);
		text[i] += '\0';
	}
	printf("Введите размер подстроки\n");
	scanf_s("%d", &p);
	printf("Введите подстроку\n");
	podstr = (char*)malloc((p + 2) * sizeof(char));
	rewind(stdin);
	fgets(podstr, p + 1, stdin);
	podstr += '\0';
	int f = 0, j = 0, index;
	for (int i = 0; i < n; i++)
	{
		j = 0;
		index = 0;
		while (text[i][j] != '\n' && text[i][j] != '\0')
		{
			if (text[i][j] == ' ') index = j + 1;
			if (text[i][j] == podstr[0])
			{
				while (text[i][j] == podstr[f] && podstr[f] != '\n' && text[i][j] != '\n' && text[i][j] != ' ')
				{
					j++;
					f++;
				}
			}
			if (f == p) {
				j = index;
				while (text[i][j] != ' ' && text[i][j] != '\n' && text[i][j] != '\0')
				{
					text[i][j] -= 32;
					j++;
				}
			}
			else if (!f) j++;
			f = 0;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		printf("%s", text[i]);
	}
	for (int i = 0; i < n; i++)
		free(text[i]);
	free(text);
	free(podstr);
	return 0;
}

//ghghghgh popopopo
//fghghghg adfdsffsfgrffhgh
//sdafdssdfdsf jhkhhjgghf
