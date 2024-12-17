#ifndef ELFOBJECT_H  // ���ǵǾ� ���� ������
#define ELFOBJECT_H  // �����ϰ� �Ʒ� �ڵ带 ������

#include "ElfMath.h"

//���� ������Ʈ
typedef struct
{
    //Transform
    Vector2 Position;
    float Rotation;
    Vector2 Scale;

    //Geometry
    Vector2 Line[2];

    //�ȼ�ä�� ����
    char* Symbol;

}GameObject_Line;

//ElfObject.h�� GameObject_Triangle�̶� �ڷᱸ���� ���� ��3���� ������ ���ÿ� (+5��
typedef struct
{
    //Transform
    Vector2 Position;
    float Rotation;
    Vector2 Scale;

    //Geometry
    Vector2 Line[3]; //��3��

    //�ȼ�ä�� ����
    char* Symbol;

}GameObject_Triangle;

//  ElfObject.h�� GameObject_Dot�̶� �ڷᱸ���� ���� ���� ������ ���ÿ� (+5��)
typedef struct 
{
    // Transform
    Vector2 Position;

    // �ȼ� ä�� ����
    char* Symbol;
}GameObject_Dot;
#endif