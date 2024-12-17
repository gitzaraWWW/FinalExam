#ifndef ELFOBJECT_H  // 정의되어 있지 않으면
#define ELFOBJECT_H  // 정의하고 아래 코드를 컴파일

#include "ElfMath.h"

//게임 오브젝트
typedef struct
{
    //Transform
    Vector2 Position;
    float Rotation;
    Vector2 Scale;

    //Geometry
    Vector2 Line[2];

    //픽셀채울 글자
    char* Symbol;

}GameObject_Line;

//ElfObject.h에 GameObject_Triangle이란 자료구조를 만들어서 선3개를 관리해 보시오 (+5점
typedef struct
{
    //Transform
    Vector2 Position;
    float Rotation;
    Vector2 Scale;

    //Geometry
    Vector2 Line[3]; //점3개

    //픽셀채울 글자
    char* Symbol;

}GameObject_Triangle;

//  ElfObject.h에 GameObject_Dot이란 자료구조를 만들어서 점을 관리해 보시오 (+5점)
typedef struct 
{
    // Transform
    Vector2 Position;

    // 픽셀 채울 글자
    char* Symbol;
}GameObject_Dot;
#endif