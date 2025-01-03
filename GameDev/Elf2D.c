#include <stdio.h>
#include <Windows.h>
#include "Elf2D.h"


void Elf2DInitScreen()
{
    //커서 숨기기
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE;  // 커서를 숨김
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
} 

// 화면 초기화 함수
void Elf2DClearScreen(char* Buffer, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width * 2; j++) 
        {
            Buffer[i * (width * 2 + 1) + j] = ' ';  // 화면 초기화 2번 1픽셀 2문자
        }
        Buffer[i * (width * 2 + 1) + width * 2] = '\n';  // 개행 문자
    }
    Buffer[(width * 2 + 1) * height - 1] = '\0';  // 개행 문자
}


// 스크린버퍼를 이용하여 화면을 그리는 함수
void Elf2DDrawBuffer(char* Buffer)
{
    //0,0으로 이동
    COORD coord = { 0, 0 };  // 좌표 (0, 0)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // 스크린 버퍼 출력
    printf("%s", Buffer);  // 화면 출력
}

// 두 점을 연결하는 직선을 그리는 함수 (브레젠햄 알고리즘)
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
            Buffer[(int)y1 * (width * 2 + 1) + (int)x1 * 2] = '+'; //2번 1픽셀 2개문자 
            Buffer[(int)y1 * (width * 2 + 1) + (int)x1 * 2 + 1] = '+'; //4번 drawline이용 @@기호
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
//float형 새로만들기
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
            Buffer[(int)y1 * (width * 2 + 1) + (int)x1 * 2] = '@'; //2번 1픽셀 2개문자 
            Buffer[(int)y1 * (width * 2 + 1) + (int)x1 * 2 + 1] = '@'; //4번 drawline이용 @@기호
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