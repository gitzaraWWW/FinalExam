//#include <stdio.h>
//#include <Windows.h>
//#include "ElfMath.h"
//#include "Elf2D.h"
//#include "ElfTime.h"
//#include "ElfObject.h"
//
//#define WIDTH 40 //2�� 40x24
//#define HEIGHT 24
//// ���� ���ϰ� �ܼ� â ũ�� ����
//void SetConsoleSize(int width, int height) {
//    // �ܼ� ȭ�� ���� ũ�� ����
//    COORD bufferSize = { width, height }; // ���� ũ�� (80x24) 1�ȼ� ���ڿ�2�� 40x2 =80
//    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
//
//    // �ܼ� ������ ũ�� ����
//    SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 }; // â ũ�� (0,0 ~ 39,23)
//    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
//}
//
////4�� �ﰢ��
//void InitializeTri(GameObject_Triangle* obj, int screenWidth, int screenHeight) {
//    // ���ﰢ�� �ʱ�ȭ
//    obj->Position.x = 0;  // �ӽ� ��ġ ����
//    obj->Position.y = 0;
//
//    obj->Rotation = 0;  // ȸ���� 0���� ����
//
//    // ���ﰢ���� �� �� ����
//    obj->Line[0].x = 0;
//    obj->Line[0].y = 10;
//
//    obj->Line[1].x = 10;
//    obj->Line[1].y = 10;
//
//    obj->Line[2].x = 5;
//    obj->Line[2].y = 1.34;
//
//    // ȭ�� ��� �ɺ� ����
//    obj->Symbol = "@@";
//
//    // ũ�� ����
//    obj->Scale.x = 1;
//    obj->Scale.y = 1;
//
//    // ���ﰢ���� �߽� ���
//    float centerX = (obj->Line[0].x + obj->Line[1].x + obj->Line[2].x) / 3.0f;
//    float centerY = (obj->Line[0].y + obj->Line[1].y + obj->Line[2].y) / 3.0f;
//
//    // ȭ�� �߾ӿ� ��ġ��Ű�� ���� ������ ���
//    float offsetX = (screenWidth / 2) - centerX;
//    float offsetY = (screenHeight / 2) - centerY;
//
//    // ��ġ �̵�
//    obj->Position.x += offsetX;
//    obj->Position.y += offsetY;
//}
////5�� ��� �������� GameObject�� �� �׸��� ElfObjectȰ��
//void InitializeDot(GameObject_Dot* dot, float x, float y, char* symbol) {
//    dot->Position.x = x;
//    dot->Position.y = y;
//    dot->Symbol = symbol;
//}
//
//// 0: �Է¾���
//// 99 : ���� ����
//int Input() {
//    // ESC Ű�� �������� Ȯ��
//    if (_kbhit()) {
//        char ch = _getch();
//        //6�� ȸ�� ����
//        if (ch == 27) {  // ESC Ű�� ������ ���� ����
//            return 99;
//        }
//        if (ch == 'a' || ch == 'A') {  // 'a' Ű�� ������ ���� ȸ��
//            return -1; // ���� ȸ�� ��ȣ
//        }
//        if (ch == 'd' || ch == 'D') {  // 'd' Ű�� ������ ���� ȸ��
//            return 1; // ���� ȸ�� ��ȣ
//        }
//        //7�� ���� ���� ����
//        if (ch == 'w' || ch == 'W') {
//            return 2;  // ����
//        }
//        if (ch == 's' || ch == 'S') {
//            return 3;  // ����
//        }
//    }
//
//    return 0;
//}
//
//void Update(GameObject_Triangle* obj, int objNum, int e)
//{
//    // ȸ�� �� ó��
//    //6. Ű �̺�Ʈ�� ȸ���� �����ض� frame�� 1�� = 30������ =30��?
//    if (e == -1) {
//        obj->Rotation -= 30; // ���� ȸ�� (n�� ����)
//    }
//    if (e == 1) {
//        obj->Rotation += 30; // ���� ȸ�� (n�� ����)
//    }
//
//    const float moveDistance = 0.1f;  // �� �����Ӹ��� 0.1px �̵�
//    // �̵� �� ó��
//    if (e == 2) {  // 'w' Ű: ����
//        // ���� ȸ�� ������ �������� ��ȯ
//        float radians = obj->Rotation * (3.14159265359f / 180.0f);
//        // ���� ���� ��� (ȸ���� �������� �̵�)
//        obj->Position.x += cosf(radians) * moveDistance;
//        obj->Position.y += sinf(radians) * moveDistance;
//    }
//
//    if (e == 3) {  // 's' Ű: ����
//        // ���� ȸ�� ������ �������� ��ȯ
//        float radians = obj->Rotation * (3.14159265359f / 180.0f);
//        // ���� ���� ��� (ȸ���� ���� �ݴ�� �̵�)
//        obj->Position.x -= cosf(radians) * moveDistance;
//        obj->Position.y -= sinf(radians) * moveDistance;
//    }
//
//    // ȸ������ -360������ 360�� ���̷� ����
//    if (obj->Rotation < 0) {
//        obj->Rotation += 360;
//    }
//    if (obj->Rotation >= 360) {
//        obj->Rotation -= 360;
//    }
//}
//
////3�� �̵ ���ﰢ�� �׸���
//void Render(GameObject_Triangle* obj, int objNum, char* Buf, int width, int height) {
//    Vector3 lineA, lineB;
//
//    // �ﰢ���� �߽� ���
//    float centerX = (obj->Line[0].x + obj->Line[1].x + obj->Line[2].x) / 3.0f;
//    float centerY = (obj->Line[0].y + obj->Line[1].y + obj->Line[2].y) / 3.0f;
//
//    // �ﰢ���� �� ������ �׸���
//    for (int i = 0; i < 3; i++) {
//        int nextIndex = (i + 1) % 3;  // ������ �� �Ŀ� ù ��° ������ ���ƿ�
//
//        // ���� �� (lineA)
//        lineA.x = obj->Line[i].x;
//        lineA.y = obj->Line[i].y;
//        lineA.z = 1;
//
//        // ���� �� (lineB)
//        lineB.x = obj->Line[nextIndex].x;
//        lineB.y = obj->Line[nextIndex].y;
//        lineB.z = 1;
//
//        // ��ȯ ��� �ʱ�ȭ (�� ���и��� �ʱ�ȭ)
//        Matrix3x3 world = identity_matrix();    // ���� ��ķ� �ʱ�ȭ
//        Matrix3x3 scale = scale_matrix(obj->Scale.x, obj->Scale.y); // ũ�� ���� ���
//        Matrix3x3 rotation = rotation_matrix(obj->Rotation); // ȸ�� ���
//        Matrix3x3 translation = translation_matrix(obj->Position.x, obj->Position.y); // �̵� ���
//
//        // ������ �������� ȸ���ϵ��� �̵� -> ȸ�� -> ���� ��ġ�� �̵�
//        Matrix3x3 centerTranslation = translation_matrix(-centerX, -centerY);  // �߽����� �̵�
//        Matrix3x3 reverseTranslation = translation_matrix(centerX, centerY);   // ȸ�� �� ����ġ ����
//
//        // ��ȯ ����� ����
//        world = multiply_matrices(centerTranslation, world); // ���� �̵�
//        world = multiply_matrices(scale, world); // ũ�� ����
//        world = multiply_matrices(rotation, world); // ȸ��
//        world = multiply_matrices(reverseTranslation, world); // ����ġ ����
//        world = multiply_matrices(translation, world); // ���� ��ġ �̵�
//
//        // ��ȯ ����� �� ���� ����
//        lineA = multiply_matrix_vector(world, lineA);
//        lineB = multiply_matrix_vector(world, lineB);
//
//        // ���� ��ǥ�� �� �׸���
//        Elf2DDrawLine2(lineA.x, lineA.y, lineB.x, lineB.y, Buf, width, height);
//    }
//}
////5�� ��� �������� GameObject�� �� �׸��� ElfObjectȰ��
//void RenderDot(GameObject_Dot* dot, GameObject_Triangle* triangle, char* Buf, int width, int height) {
//    // �ﰢ���� ��� ������ �ε��� (���⼭�� 0�� �ε����� �������� ��� ����)
//    int topIndex = 2; // ��� ���������� ���ǵ� �ε���
//
//    // ��� ������ ��ǥ ��������
//    Vector3 topVertex = {
//        triangle->Line[topIndex].x,
//        triangle->Line[topIndex].y,
//        1
//    };
//
//    // �ﰢ���� �߽� ���
//    float centerX = (triangle->Line[0].x + triangle->Line[1].x + triangle->Line[2].x) / 3.0f;
//    float centerY = (triangle->Line[0].y + triangle->Line[1].y + triangle->Line[2].y) / 3.0f;
//
//    // ��ȯ ��� �ʱ�ȭ
//    Matrix3x3 world = identity_matrix(); // ���� ���
//    Matrix3x3 scale = scale_matrix(triangle->Scale.x, triangle->Scale.y); // ũ�� ���
//    Matrix3x3 rotation = rotation_matrix(triangle->Rotation);            // ȸ�� ���
//    Matrix3x3 translation = translation_matrix(triangle->Position.x, triangle->Position.y); // �̵� ���
//
//    // ������ �������� ȸ���ϵ��� �̵� -> ȸ�� -> ���� ��ġ�� �̵�
//    Matrix3x3 centerTranslation = translation_matrix(-centerX, -centerY);  // �߽����� �̵�
//    Matrix3x3 reverseTranslation = translation_matrix(centerX, centerY);   // ȸ�� �� ����ġ ����
//
//    // ��ȯ ����� ����
//    world = multiply_matrices(centerTranslation, world); // ���� �̵�
//    world = multiply_matrices(scale, world); // ũ�� ����
//    world = multiply_matrices(rotation, world); // ȸ��
//    world = multiply_matrices(reverseTranslation, world); // ����ġ ����
//    world = multiply_matrices(translation, world); // ���� ��ġ �̵�
//
//    // ��ȯ�� ��ǥ ���
//    Vector3 transformedVertex = multiply_matrix_vector(world, topVertex);
//
//    // ��ȯ�� ������ ��ǥ�� ���������� ��ȯ
//    int x = (int)transformedVertex.x;
//    int y = (int)transformedVertex.y;
//
//    // ȭ�� ���� ���� �ִ��� Ȯ��
//    if (x >= 0 && x < width && y >= 0 && y < height) {
//        // 1�ȼ��� ���ڿ� 2���� ��ġ
//        Buf[y * (width * 2 + 1) + x * 2] = dot->Symbol[0];   // ù ��° ����
//        Buf[y * (width * 2 + 1) + x * 2 + 1] = dot->Symbol[1]; // �� ��° ����
//    }
//}
//// ���� ����
//int main() {
//    SetConsoleSize(80, 24); //�ܼ�â ũ��
//    int fps = 30; // 3�� 30������ �����
//    double frameTime = 1000.0 / fps;
//
//    // ���� ������ ��ũ�� ���� ����
//    char screenBuffer[(WIDTH * 2 + 1) * HEIGHT];
//    int screenWidth = WIDTH;
//    int screenHeight = HEIGHT;
//
//    GameObject_Triangle TriangleObj[1];  // GameObject_Triangle �迭�� �ﰢ�� ��ü ����
//    GameObject_Dot Dots[3];
//
//    // ���� �ʱ�ȭ
//    //�ﰢ�� �ʱ�ȭ
//    InitializeTri(&TriangleObj[0], screenWidth, screenHeight);
//
//    // �� ������ �ʱ�ȭ(�ﰢ���� ������ ����)
//    for (int i = 0; i < 3; i++) {
//        InitializeDot(&Dots[i], TriangleObj[0].Line[i].x, TriangleObj[0].Line[i].y, "++"); //5�� ��ܲ����� ++�� ���
//    }
//    Elf2DInitScreen();
//    Elf2DClearScreen(screenBuffer, screenWidth, screenHeight);
//    Elf2DDrawBuffer(screenBuffer);
//
//    ElfTimeInitialize();
//
//    int isGameRunning = 1;
//    while (isGameRunning) {
//        int gameEvent = Input();
//
//        //�Է� ���
//        if (gameEvent == 99)
//        {
//            isGameRunning = 0;
//        }
//        // ȭ�� �ʱ�ȭ
//        Elf2DClearScreen(screenBuffer, screenWidth, screenHeight);
//
//        // ���� ������Ʈ
//        Update(&TriangleObj[0], 1, gameEvent);
//
//        // ��ũ�����ۿ� ���� ������
//        Render(&TriangleObj[0], 1, screenBuffer, screenWidth, screenHeight);
//        // ������ �� ������
//        for (int i = 0; i < 3; i++) {
//            RenderDot(&Dots[0], &TriangleObj[0], screenBuffer, screenWidth, screenHeight);
//        }
//
//        // ȭ�� �׸���
//        Elf2DDrawBuffer(screenBuffer);
//        // FPS ����
//        ElfTimeCalculateDeltaTime();
//        Elf2DSleep(frameTime - ElfTimeGetDeltaTime());
//    }
//
//
//    return 0;
//}