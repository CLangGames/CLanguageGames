#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include "games.h"

void menu() {
	system("cls");
	printf("1.오목\n2.타이밍맞추기\n3.가위바위보\n4.묵찌빠\n5.거꾸로 숫자 외우기\n6.숫자열 외우기");
}
void title()
{
	static char title[40];

	while (1)
	{
		system("cls");
		printf("■■■■■■■■■■■■■■■■\n");
		printf("----------C언어 게임들----------\n");
		printf("□□□□□□□□□□□□□□□□\n");
		printf("시작하려면 아무키나 누르십시오.");
		Sleep(100);
		system("cls");
		printf("□□□□□□□□□□□□□□□□\n");
		printf("----------C언어 게임들----------\n");
		printf("■■■■■■■■■■■■■■■■\n");
		printf("시작하려면 아무키나 누르십시오.");
		Sleep(100);

		if (kbhit())
		{
			
			menu();
			getch();
			int a = getch();
			if (a == '1') {
				system("cls");
			}
			else if (a == '2') timergame();
			else if (a == '3')rcsgame();
			else if (a == '4')mjb();
			else if (a == '5')cctgame();
			else if (a == '6')gnumber();
			else continue;
		}

	}
}