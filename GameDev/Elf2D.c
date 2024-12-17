#include <stdio.h>
#include <Windows.h>
#include "Elf2D.h"


void Elf2DInitScreen()
{
    //Ŀ�� �����
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE;  // Ŀ���� ����
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
} 

// ȭ�� �ʱ�ȭ �Լ�
void Elf2DClearScreen(char* Buffer, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width * 2; j++) 
        {
            Buffer[i * (width * 2 + 1) + j] = ' ';  // ȭ�� �ʱ�ȭ 2�� 1�ȼ� 2����
        }
        Buffer[i * (width * 2 + 1) + width * 2] = '\n';  // ���� ����
    }
    Buffer[(width * 2 + 1) * height - 1] = '\0';  // ���� ����
}


// ��ũ�����۸� �̿��Ͽ� ȭ���� �׸��� �Լ�
void Elf2DDrawBuffer(char* Buffer)
{
    //0,0���� �̵�
    COORD coord = { 0, 0 };  // ��ǥ (0, 0)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // ��ũ�� ���� ���
    printf("%s", Buffer);  // ȭ�� ���
}

// �� ���� �����ϴ� ������ �׸��� �Լ� (�극���� �˰���)
void Elf2DDrawLine(int x1, int y1, int x2, int y2, char* Buffer, int width, int height)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if ((int)x1 >= 0 && (int)x1 < width && (int)y1 >= 0 && (int)y1 < height)
        {
            Buffer[(int)y1 * (width * 2 + 1) + (int)x1 * 2] = '+'; //2�� 1�ȼ� 2������ 
            Buffer[(int)y1 * (width * 2 + 1) + (int)x1 * 2 + 1] = '+'; //4�� drawline�̿� @@��ȣ
        }

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}
//float�� ���θ����
void Elf2DDrawLine2(float x1, float y1, float x2, float y2, char* Buffer, int width, int height)
{
    int dx = abs((int)x2 - (int)x1);
    int dy = abs((int)y2 - (int)y1);
    int sx = ((int)x1 < (int)x2) ? 1 : -1;
    int sy = ((int)y1 < (int)y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if ((int)x1 >= 0 && (int)x1 < width && (int)y1 >= 0 && (int)y1 < height)
        {
            Buffer[(int)y1 * (width * 2 + 1) + (int)x1 * 2] = '@'; //2�� 1�ȼ� 2������ 
            Buffer[(int)y1 * (width * 2 + 1) + (int)x1 * 2 + 1] = '@'; //4�� drawline�̿� @@��ȣ
        }

        if ((int)x1 == (int)x2 && (int)y1 == (int)y2)
            break;

        int e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy; x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void Elf2DSleep(int ms)
{
    Sleep(ms);
}