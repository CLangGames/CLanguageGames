#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define WORD 1000    //��ü �ܾ� ���� ����

char eng_word[WORD][100], kor_word[WORD][100];

void en_test(int line) {
	char tmp[WORD][100] = { 0 };
	int result[WORD] = { 0 }, overlap[WORD] = { 0 }, i = 0, cnt = 0;
	word_enroll();
	srand(time(NULL));
	while (1) {
		int rnd = rand() % line;
		if (overlap[rnd] == 1) continue;
		overlap[rnd] = 1;
		system("cls");
		printf("%s\t", eng_word[rnd]);
		//scanf("%[^\n]", tmp[rnd]);
		gets_s(tmp[rnd], 99);
		if (strcmp(tmp[rnd], kor_word[rnd]) == 0) {
			result[rnd] = 1;
			cnt++;
		}
		i++;
		if (i >= line) break;
	}
	system("cls");
	printf("���� ����: %d\nƲ�� ����: %d\n", line, line - cnt);
	printf("Ʋ������\n");
	for (int i = 0; i < line; i++)
	{
		if (result[i] == 0) {
			printf("%s\tƲ����: %s\t����: %s\n", eng_word[i], tmp[i], kor_word[i]);
		}
	}

	system("pause");
}
int word_enroll() {
	char tmp;
	int line = 0;
	FILE* f = NULL;
	f = fopen("word.txt", "r");
	if (f == NULL) {
		printf("word.txt ������ �����ϴ�.\n������ �����ϰ� �ٽ� ��������ּ���\n");
		system("pause");
		exit(1);
	}
	while (fscanf(f, "%c", &tmp) != EOF) {
		if (tmp == '\n')
			line++;
	}
	line++;
	rewind(f);
	for (int i = 0; i < line; i++)
	{
		fscanf(f, "\n%[^\t]\t%[^\n]", eng_word[i], kor_word[i]);
	}
	fclose(f);

	return line;
}