#include <stdio.h>   // ○○○○○==5  ●●●●● == 9;
#include <windows.h>
#include <conio.h>	//console and port I/O

int arr[20][20];

void f1() // ┌ 첫줄 열기 
{
	if (arr[0][0] == 0)
		printf("┌ ");
	else if (arr[0][0] == 5)
		printf("○");
	else if (arr[0][0] == 9)
		printf("●");
}
void f2() // ┬ 첫줄 중간 (18번)
{
	for (int i = 1; i <= 18; i++)
		if (arr[0][i] == 0)
			printf("┬ ");
		else if (arr[0][i] == 5)
			printf("○");
		else if (arr[0][i] == 9)
			printf("●");
}
void f3() // ┐ 첫줄 닫기
{
	if (arr[0][19] == 0)
		printf("┐ ");
	else if (arr[0][19] == 5)
		printf("○");
	else if (arr[0][19] == 9)
		printf("●");
	printf("\n");
}
void middle()
{
	for (int i = 1; i < 19; i++)
	{
		if (arr[i][0] == 0) // ㅏ 2~19번째 줄  1번째칸 열기
			printf("├ ");
		else if (arr[i][0] == 5)
			printf("○");
		else if (arr[i][0] == 9)
			printf("●");

		for (int j = 1; j < 19; j++)
		{
			if (arr[i][j] == 0) // 2~19번째 줄 2~19째칸 출력
				printf("┼ ");
			else if (arr[i][j] == 5)
				printf("○");
			else if (arr[i][j] == 9)
				printf("●");

		}
		if (arr[i][19] == 0)// 2~18번째줄 20번째 칸 닫기
			printf("┤ ");
		else if (arr[i][19] == 5)
			printf("○");
		else if (arr[i][19] == 9)
			printf("●");

		printf("\n");
	}
}
void e1() // 마지막 줄 열기 └
{
	if (arr[19][0] == 0)
		printf("└ ");
	else if (arr[19][0] == 5)
		printf("○");
	else if (arr[19][0] == 9)
		printf("●");
}
void e2() // 마지막줄 중간 ┴ 
{
	for (int i = 1; i <= 18; i++)
		if (arr[19][i] == 0)
			printf("┴ ");
		else if (arr[19][i] == 5)
			printf("○");
		else if (arr[19][i] == 9)
			printf("●");
}
void e3() // 마지막줄 닫기 ┘
{
	if (arr[19][19] == 0)
		printf("┘ ");
	else if (arr[19][19] == 5)
		printf("○");
	else if (arr[19][19] == 9)
		printf("●");
	printf("\n");
}
void pan() // 아래 함수들을 일일이 쓰면 너무 길기때문에 pan()함수를 만듬
{
	f1();
	f2();
	f3();
	middle();
	e1();
	e2();
	e3();
}
int result_black() //흑돌이 승리했는지 판별
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
		{
			if (arr[i][j] == 5 && arr[i][j + 1] == 5 && arr[i][j + 2] == 5 && arr[i][j + 3] == 5 && arr[i][j + 4] == 5)
				// 가로 5개 검사 
			{
				pan();
				printf("흑돌 승리!!!!\n");
				return 0;
			}
			if (arr[i][j] == 5 && arr[i + 1][j] == 5 && arr[i + 2][j] == 5 && arr[i + 3][j] == 5 && arr[i + 4][j] == 5)
				// 세로 5개 검사
			{
				pan();
				printf("흑돌 승리!!!!\n");
				return 0;
			}
			if (arr[i][j] == 5 && arr[i + 1][j + 1] == 5 && arr[i + 2][j + 2] == 5 && arr[i + 3][j + 3] == 5 && arr[i + 4][j + 4] == 5)
				// 오른쪽 위로가는 대각선 (\) 검사
			{
				pan();
				printf("흑돌 승리!!!!\n");
				return 0;
			}
			if (arr[i][j] == 5 && arr[i - 1][j + 1] == 5 && arr[i - 2][j + 2] == 5 && arr[i - 3][j + 3] == 5 && arr[i - 4][j + 4] == 5)
				// 오른쪽 아래로 가는 대각선 (/) 검사 
			{
				pan();
				printf("흑돌 승리!!!!\n");
				return 0;
			}
		}
}

int result_white()// 백돌이 승리했는지 판별
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
		{
			if (arr[i][j] == 9 && arr[i][j + 1] == 9 && arr[i][j + 2] == 9 && arr[i][j + 3] == 9 && arr[i][j + 4] == 9)
				// 가로 5개 검사
			{
				pan();
				printf("백돌 승리!!!!\n");
				return 0;
			}

			if (arr[i][j] == 9 && arr[i + 1][j] == 9 && arr[i + 2][j] == 9 && arr[i + 3][j] == 9 && arr[i + 4][j] == 9)
				// 세로 5개 검사
			{
				pan();
				printf("백돌 승리!!!!\n");
				return 0;
			}

			if (arr[i][j] == 9 && arr[i + 1][j + 1] == 9 && arr[i + 2][j + 2] == 9 && arr[i + 3][j + 3] == 9 && arr[i + 4][j + 4] == 9)
				// 오른쪽 위로가는 대각선 (/) 검사
			{
				pan();
				printf("백돌 승리!!!!\n");
				return 0;
			}
			if (arr[i][j] == 9 && arr[i - 1][j + 1] == 9 && arr[i - 2][j + 2] == 9 && arr[i - 3][j + 3] == 9 && arr[i - 4][j + 4] == 9)
				// 오른쪽 아래로 가는 대각선 (\) 검사 
			{
				pan();
				printf("백돌 승리!!!!\n");
				return 0;
			}
		}
}
void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 }; // coord 구조체 변수 Pos 선언과 동시에 초기화
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); // 콘솔에서 Pos에 저장된 좌표로 위치 바꾸기
}
void key_move(int sw)
{
	static int x = 19; //정적 변수 (처음 1번만 초기화)
	static int y = 10; //정적 변수 (처음 1번만 초기화)
	int chr;
	gotoxy(x, y); // 콘솔에서 커서 위치 바꾸는 함수
	while (1) {
	rescan:
		chr = getch();
		if (kbhit()) {
			gotoxy(x, y);
			system("cls");
			pan();
			chr = getch();
			if (chr == 72) { //상
				y--;
				if (y < 1) y = 1;
			}
			else if (chr == 80) { //하
				y++;
				if (y > 20) y = 20;
			}
			else if (chr == 75) { //좌
				x -= 2;
				if (x < 1) x = 1;
			}
			else if (chr == 77) { //우
				x += 2;
				if (x > 39) x = 39;
			}
			gotoxy(x, y);// 콘솔에서 커서 위치 바꾸는 함수
			if (sw == 0) printf("○");
			else printf("●");
		}
		else if (getch() == 32 || getch() == 13)
		{
			if (arr[y - 1][x / 2] == 5 || arr[y - 1][x / 2] == 9)
			{
				system("cls");
				pan();
				printf("\n이미 선택된 칸입니다.\n다시 선택해주세요.\n");
				goto rescan;
			}
			else
			{
				if (sw == 0) arr[y - 1][x / 2] = 5; //흑돌인지 확인 후 돌 놓음
				if (samsam() == 1 && sw == 0) { //흑돌이면서 삼삼이면
					arr[y - 1][x / 2] = 0; //돌을 빼버림
					system("cls");
					pan();
					printf("\n삼삼 입니다.\n다시 입력해 주세요");
					goto rescan;
				}
				if(sw==1) arr[y - 1][x / 2] = 9;
				system("cls");
				break;
			}
		}
	}
}

int samsam() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++)
		{
			if (arr[i - 1][j - 1] == 5 && arr[i - 1][j + 1] == 5 && arr[i + 1][j - 1] == 5 && arr[i + 1][j + 1] == 5 && arr[i][j]) // O
			{
				return 1;
			}
			else if (arr[i][j + 1] == 5 && arr[i][j + 2] == 5 && arr[i + 1][j] == 5 && arr[i + 2][j] == 5 && arr[i][j]) // O
			{
				return 1;
			}
			else if (arr[i][j]==5&&arr[i+1][j]==5&&arr[i+2][j]==5&&arr[i+1][j+1]==5&&arr[i+1][j+2]==5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i][j+1] == 5 && arr[i][j+2] == 5 && arr[i + 1][j + 1] == 5 && arr[i + 2][j + 1] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j]==5 && arr[i-1][j]==5&&arr[i+1][j]==5&&arr[i][j-1]==5&&arr[i][j+1]==5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i + 1][j] == 5 && arr[i + 2][j] == 5 && arr[i + 2][j-1] == 5 && arr[i+2][j + 1] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j-1] == 5 && arr[i + 1][j] == 5 && arr[i + 2][j] == 5 && arr[i + 2][j - 1] == 5 && arr[i + 2][j + 1] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j + 2] == 5 && arr[i + 1][j+2] == 5 && arr[i + 2][j+2] == 5 && arr[i + 2][j +1] == 5 && arr[i + 2][j] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i + 1][j] == 5 && arr[i + 2][j] == 5 && arr[i + 2][j + 1] == 5 && arr[i + 2][j + 2] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i][j + 1] == 5 && arr[i][j + 2] == 5 && arr[i + 1][j + 2] == 5 && arr[i + 2][j + 2] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i+1][j -1] == 5 && arr[i+1][j] == 5 && arr[i + 1][j + 1] == 5 && arr[i + 2][j + 2] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i][j + 1] == 5 && arr[i][j + 2] == 5 && arr[i + 1][j + 2] == 5 && arr[i - 1][j + 2] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i+1][j] == 5 && arr[i+1][j + 1] == 5 && arr[i + 1][j + 2] == 5 && arr[i + 2][j + 2] == 5) // O
			{
				return 1;
			}
			else if (arr[i][j] == 5 && arr[i][j+1] == 5 && arr[i+1][j - 1] == 5 && arr[i + 2][j - 2] == 5 && arr[i][j + 2] == 5) // O
			{
				return 1;
			}
		}
	}
	return 0;
}

void reset()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			arr[i][j] = 0;
		}
	}
}

void ohmok()
{
	while (1)
	{

		//흑돌 시작
		pan();  // 바둑판 출력

		key_move(0);  // 키보드로 흑돌 조작
		if (result_black() == 0)
		{
			reset();
			break;
		}//흑돌 승리여부 판별

		//백돌 시작
		pan(); // 바둑판 출력

		key_move(1);  // 키보드로 백돌 조작

		if (result_white() == 0)
		{
			reset();
			break;	//백돌 승리여부 판별
		}

	}
		system("pause"); // .exe파일로 만들었을때 한쪽이 승리하면 바로 꺼져버리는걸 방지하기 위해 
}