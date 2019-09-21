#include <stdio.h>
#include <Windows.h>
#include "interfaces.h"

//#define COLORS

void gotoxy(int x, int y) //Ŀ�� ��ġ �ű��
{							//�»���� (0,0)������ (1,1)�� �����
	COORD Cur;
	Cur.X = x; Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int now_x() //���� xĿ�� ��ġ
{								//�»���� (1,1)�� �ٲ�������� �����������
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}

int now_y() // ���� yĿ�� ��ġ
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}

int now_Line(int n) //���� �� �� Ȯ��
{
	int now_x_point, now_y_point; //���� Ŀ�� ��ġ ����
	now_x_point = now_x();
	now_y_point = now_y();
	gotoxy(53, 29);
	//dye(0, LIGHTGRAY, BLACK, "");
	printf("[%d]", n); //���� ��ġ �ٲ���
	dye(0, LIGHTGRAY, BLACK, " Line");
	gotoxy(now_x_point, now_y_point); //���� ��ġ�� �ٽ� ���ư�
	return 0;
}