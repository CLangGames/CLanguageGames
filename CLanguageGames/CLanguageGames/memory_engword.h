#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define WORD 1000    //전체 단어 개수 제한

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
	printf("문제 개수: %d\n틀린 개수: %d\n", line, line - cnt);
	printf("틀린문제\n");
	for (int i = 0; i < line; i++)
	{
		if (result[i] == 0) {
			printf("%s\t틀린답: %s\t정답: %s\n", eng_word[i], tmp[i], kor_word[i]);
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
		printf("word.txt 파일이 없습니다.\n파일을 생성하고 다시 실행시켜주세요\n");
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