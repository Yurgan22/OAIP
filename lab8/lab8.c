#include<stdlib.h>
#include<stdio.h>
#include<locale.h>

#define siz 1

int main()
{
	setlocale(LC_ALL, "rus");
	printf("Введите текст:\n");
	char** text;
	int* kol;

	char buffer;
	int length, wordCounter = 0, size = 0, sentens = 0;

	text = (char**)malloc(siz * sizeof(char*));
	text[sentens] = (char*)malloc(siz * sizeof(char));

	kol = (int*)malloc(siz * sizeof(int));
	kol[0] = 1;

	do {
		buffer = getchar();
		if (buffer == '\n') {
            break;
        }
		if (buffer == '.') {
			text[sentens][size] = buffer;
			text[sentens][++size] = '\0';
			size = 0;
			sentens++;
			text = (char**)realloc(text, (sentens + siz) * sizeof(char*));
			text[sentens] = (char*)malloc(siz * sizeof(char));
			kol = (int*)realloc(kol, (sentens + siz) * sizeof(int));
			kol[sentens] = 0;
			continue;
		} else
		text[sentens][size] = buffer;
		if (buffer == ' ') kol[sentens]++;
		size++;
		text[sentens] = (char*)realloc(text[sentens], (size + siz) * sizeof(char));
    } while(1);
	text[sentens][size] = '\0';
	printf("Предложения с четным количеством слов:\n ");
	for (int i = 0; i < sentens; i++) if (kol[i] % 2 == 0){
		printf("%s|", text[i]); printf("%d слов(-а)\n", kol[i]);
    }
	return 0;
}
/*
I get up at seven o’clock. Then I wash myself, put on my clothes and have breakfast. After breakfast I go to school. I usually have four or five lessons at school. I come home at one o’clock. Then I have dinner. I eat soup, chicken or fish and potatoes. After dinner I do my homework. In the evening I read or watch TV. I go to bed at nine o’clock.
*/