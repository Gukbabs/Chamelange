#include <stdio.h>
#include "interfaces.h"

int key_ck(char ch)
{
	int checker;
	checker = ch;
	if ((checker == 224) || (checker == 0))
	{
		checker = getch();
		return 0;
	}
	if ((GetAsyncKeyState(VK_HANGUL) & 0x8000)) //�ѿ� ��ȯŰ �ԷµǸ� -2 ���� ���۷� ����
	{
		return -2;
	}
	else if ((GetAsyncKeyState(VK_LEFT) & 0x8000))
	{
		return 0;
	}
	else if ((checker >= 48) && (checker <= 57))
	{
		return 1;  //���ڸ� 1 ��ȯ
	}
	else if ((checker >= 65) && (checker <= 90))
	{
		return 2; //�빮�� ���ĺ��̸� 2 ��ȯ
	}
	else if ((checker >= 97) && (checker <= 122))
	{
		return 3; //���ĺ� �ҹ��ڸ� 3 ��ȯ
	}
	else if ((checker >= 32) && (checker <= 126))
	{
		return 4; //������ ���ڵ�(����ڳ� �ٸ� ����)�̸� 4 ��ȯ
	}
	else if ((checker >= 0) && (checker <= 127))
	{
		return 0;
	}
	else
	{
		return -1;
	}
}