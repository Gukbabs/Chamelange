#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int dye(int n, int f_color, int b_color, char* ch) // ���� �� �������� ����!!
{													//n=0�̸� ����, ���ڿ� ��� n>0�̸� �׸�ŭ �ݺ� ���
	int i = 0;
	int color = f_color + b_color * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			printf("%c", ch);
		}
		return 0;
	}
	else if ((n == 0) && (sizeof(ch) == sizeof(char)))
	{
		printf("%c", ch);
		return 0;
	}
	else if ((n == 0) && (sizeof(ch) != sizeof(char)))
	{
		printf("%s", ch);
		return 0;
	}
	return 0;
}