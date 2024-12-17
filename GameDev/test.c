//#include <stdio.h>
//#include <Windows.h>
//#include "ElfMath.h"
//#include "Elf2D.h"
//#include "ElfTime.h"
//#include "ElfObject.h"
//
//#define WIDTH 40 //2번 40x24
//#define HEIGHT 24
//// 보기 편하게 콘솔 창 크기 설정
//void SetConsoleSize(int width, int height) {
//    // 콘솔 화면 버퍼 크기 설정
//    COORD bufferSize = { width, height }; // 버퍼 크기 (80x24) 1픽셀 문자열2개 40x2 =80
//    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
//
//    // 콘솔 윈도우 크기 설정
//    SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 }; // 창 크기 (0,0 ~ 39,23)
//    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
//}
//
////4번 삼각형
//void InitializeTri(GameObject_Triangle* obj, int screenWidth, int screenHeight) {
//    // 정삼각형 초기화
//    obj->Position.x = 0;  // 임시 위치 설정
//    obj->Position.y = 0;
//
//    obj->Rotation = 0;  // 회전은 0으로 설정
//
//    // 정삼각형의 세 점 설정
//    obj->Line[0].x = 0;
//    obj->Line[0].y = 10;
//
//    obj->Line[1].x = 10;
//    obj->Line[1].y = 10;
//
//    obj->Line[2].x = 5;
//    obj->Line[2].y = 1.34;
//
//    // 화면 출력 심볼 설정
//    obj->Symbol = "@@";
//
//    // 크기 설정
//    obj->Scale.x = 1;
//    obj->Scale.y = 1;
//
//    // 정삼각형의 중심 계산
//    float centerX = (obj->Line[0].x + obj->Line[1].x + obj->Line[2].x) / 3.0f;
//    float centerY = (obj->Line[0].y + obj->Line[1].y + obj->Line[2].y) / 3.0f;
//
//    // 화면 중앙에 위치시키기 위한 오프셋 계산
//    float offsetX = (screenWidth / 2) - centerX;
//    float offsetY = (screenHeight / 2) - centerY;
//
//    // 위치 이동
//    obj->Position.x += offsetX;
//    obj->Position.y += offsetY;
//}
////5번 상단 꼭짓점에 GameObject로 점 그리기 ElfObject활용
//void InitializeDot(GameObject_Dot* dot, float x, float y, char* symbol) {
//    dot->Position.x = x;
//    dot->Position.y = y;
//    dot->Symbol = symbol;
//}
//
//// 0: 입력없음
//// 99 : 게임 종료
//int Input() {
//    // ESC 키를 눌렀는지 확인
//    if (_kbhit()) {
//        char ch = _getch();
//        //6번 회전 구현
//        if (ch == 27) {  // ESC 키가 눌리면 게임 종료
//            return 99;
//        }
//        if (ch == 'a' || ch == 'A') {  // 'a' 키가 눌리면 좌측 회전
//            return -1; // 좌측 회전 신호
//        }
//        if (ch == 'd' || ch == 'D') {  // 'd' 키가 눌리면 우측 회전
//            return 1; // 우측 회전 신호
//        }
//        //7번 전진 후진 구현
//        if (ch == 'w' || ch == 'W') {
//            return 2;  // 전진
//        }
//        if (ch == 's' || ch == 'S') {
//            return 3;  // 후진
//        }
//    }
//
//    return 0;
//}
//
//void Update(GameObject_Triangle* obj, int objNum, int e)
//{
//    // 회전 값 처리
//    //6. 키 이벤트로 회전을 구현해라 frame당 1도 = 30프레임 =30도?
//    if (e == -1) {
//        obj->Rotation -= 30; // 좌측 회전 (n도 감소)
//    }
//    if (e == 1) {
//        obj->Rotation += 30; // 우측 회전 (n도 증가)
//    }
//
//    const float moveDistance = 0.1f;  // 매 프레임마다 0.1px 이동
//    // 이동 값 처리
//    if (e == 2) {  // 'w' 키: 전진
//        // 현재 회전 각도를 라디안으로 변환
//        float radians = obj->Rotation * (3.14159265359f / 180.0f);
//        // 전진 방향 계산 (회전된 방향으로 이동)
//        obj->Position.x += cosf(radians) * moveDistance;
//        obj->Position.y += sinf(radians) * moveDistance;
//    }
//
//    if (e == 3) {  // 's' 키: 후진
//        // 현재 회전 각도를 라디안으로 변환
//        float radians = obj->Rotation * (3.14159265359f / 180.0f);
//        // 후진 방향 계산 (회전된 방향 반대로 이동)
//        obj->Position.x -= cosf(radians) * moveDistance;
//        obj->Position.y -= sinf(radians) * moveDistance;
//    }
//
//    // 회전값을 -360도에서 360도 사이로 제한
//    if (obj->Rotation < 0) {
//        obj->Rotation += 360;
//    }
//    if (obj->Rotation >= 360) {
//        obj->Rotation -= 360;
//    }
//}
//
////3번 이등변 정삼각형 그리기
//void Render(GameObject_Triangle* obj, int objNum, char* Buf, int width, int height) {
//    Vector3 lineA, lineB;
//
//    // 삼각형의 중심 계산
//    float centerX = (obj->Line[0].x + obj->Line[1].x + obj->Line[2].x) / 3.0f;
//    float centerY = (obj->Line[0].y + obj->Line[1].y + obj->Line[2].y) / 3.0f;
//
//    // 삼각형의 각 선분을 그리기
//    for (int i = 0; i < 3; i++) {
//        int nextIndex = (i + 1) % 3;  // 마지막 선 후에 첫 번째 선으로 돌아옴
//
//        // 현재 점 (lineA)
//        lineA.x = obj->Line[i].x;
//        lineA.y = obj->Line[i].y;
//        lineA.z = 1;
//
//        // 다음 점 (lineB)
//        lineB.x = obj->Line[nextIndex].x;
//        lineB.y = obj->Line[nextIndex].y;
//        lineB.z = 1;
//
//        // 변환 행렬 초기화 (각 선분마다 초기화)
//        Matrix3x3 world = identity_matrix();    // 단위 행렬로 초기화
//        Matrix3x3 scale = scale_matrix(obj->Scale.x, obj->Scale.y); // 크기 조정 행렬
//        Matrix3x3 rotation = rotation_matrix(obj->Rotation); // 회전 행렬
//        Matrix3x3 translation = translation_matrix(obj->Position.x, obj->Position.y); // 이동 행렬
//
//        // 중점을 기준으로 회전하도록 이동 -> 회전 -> 원래 위치로 이동
//        Matrix3x3 centerTranslation = translation_matrix(-centerX, -centerY);  // 중심으로 이동
//        Matrix3x3 reverseTranslation = translation_matrix(centerX, centerY);   // 회전 후 원위치 복원
//
//        // 변환 행렬을 결합
//        world = multiply_matrices(centerTranslation, world); // 중점 이동
//        world = multiply_matrices(scale, world); // 크기 조정
//        world = multiply_matrices(rotation, world); // 회전
//        world = multiply_matrices(reverseTranslation, world); // 원위치 복원
//        world = multiply_matrices(translation, world); // 최종 위치 이동
//
//        // 변환 행렬을 각 점에 적용
//        lineA = multiply_matrix_vector(world, lineA);
//        lineB = multiply_matrix_vector(world, lineB);
//
//        // 계산된 좌표로 선 그리기
//        Elf2DDrawLine2(lineA.x, lineA.y, lineB.x, lineB.y, Buf, width, height);
//    }
//}
////5번 상단 꼭짓점에 GameObject로 점 그리기 ElfObject활용
//void RenderDot(GameObject_Dot* dot, GameObject_Triangle* triangle, char* Buf, int width, int height) {
//    // 삼각형의 상단 꼭짓점 인덱스 (여기서는 0번 인덱스를 기준으로 상단 설정)
//    int topIndex = 2; // 상단 꼭짓점으로 정의된 인덱스
//
//    // 상단 꼭짓점 좌표 가져오기
//    Vector3 topVertex = {
//        triangle->Line[topIndex].x,
//        triangle->Line[topIndex].y,
//        1
//    };
//
//    // 삼각형의 중심 계산
//    float centerX = (triangle->Line[0].x + triangle->Line[1].x + triangle->Line[2].x) / 3.0f;
//    float centerY = (triangle->Line[0].y + triangle->Line[1].y + triangle->Line[2].y) / 3.0f;
//
//    // 변환 행렬 초기화
//    Matrix3x3 world = identity_matrix(); // 단위 행렬
//    Matrix3x3 scale = scale_matrix(triangle->Scale.x, triangle->Scale.y); // 크기 행렬
//    Matrix3x3 rotation = rotation_matrix(triangle->Rotation);            // 회전 행렬
//    Matrix3x3 translation = translation_matrix(triangle->Position.x, triangle->Position.y); // 이동 행렬
//
//    // 중점을 기준으로 회전하도록 이동 -> 회전 -> 원래 위치로 이동
//    Matrix3x3 centerTranslation = translation_matrix(-centerX, -centerY);  // 중심으로 이동
//    Matrix3x3 reverseTranslation = translation_matrix(centerX, centerY);   // 회전 후 원위치 복원
//
//    // 변환 행렬을 결합
//    world = multiply_matrices(centerTranslation, world); // 중점 이동
//    world = multiply_matrices(scale, world); // 크기 조정
//    world = multiply_matrices(rotation, world); // 회전
//    world = multiply_matrices(reverseTranslation, world); // 원위치 복원
//    world = multiply_matrices(translation, world); // 최종 위치 이동
//
//    // 변환된 좌표 계산
//    Vector3 transformedVertex = multiply_matrix_vector(world, topVertex);
//
//    // 변환된 꼭짓점 좌표를 정수형으로 변환
//    int x = (int)transformedVertex.x;
//    int y = (int)transformedVertex.y;
//
//    // 화면 범위 내에 있는지 확인
//    if (x >= 0 && x < width && y >= 0 && y < height) {
//        // 1픽셀에 문자열 2개를 배치
//        Buf[y * (width * 2 + 1) + x * 2] = dot->Symbol[0];   // 첫 번째 문자
//        Buf[y * (width * 2 + 1) + x * 2 + 1] = dot->Symbol[1]; // 두 번째 문자
//    }
//}
//// 게임 루프
//int main() {
//    SetConsoleSize(80, 24); //콘솔창 크기
//    int fps = 30; // 3번 30프레임 만들기
//    double frameTime = 1000.0 / fps;
//
//    // 전역 변수로 스크린 버퍼 선언
//    char screenBuffer[(WIDTH * 2 + 1) * HEIGHT];
//    int screenWidth = WIDTH;
//    int screenHeight = HEIGHT;
//
//    GameObject_Triangle TriangleObj[1];  // GameObject_Triangle 배열로 삼각형 객체 생성
//    GameObject_Dot Dots[3];
//
//    // 게임 초기화
//    //삼각형 초기화
//    InitializeTri(&TriangleObj[0], screenWidth, screenHeight);
//
//    // 점 데이터 초기화(삼각형의 꼭짓점 기준)
//    for (int i = 0; i < 3; i++) {
//        InitializeDot(&Dots[i], TriangleObj[0].Line[i].x, TriangleObj[0].Line[i].y, "++"); //5번 상단꼭짓점 ++로 찍기
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
//        //입력 계산
//        if (gameEvent == 99)
//        {
//            isGameRunning = 0;
//        }
//        // 화면 초기화
//        Elf2DClearScreen(screenBuffer, screenWidth, screenHeight);
//
//        // 게임 업데이트
//        Update(&TriangleObj[0], 1, gameEvent);
//
//        // 스크린버퍼에 게임 렌더링
//        Render(&TriangleObj[0], 1, screenBuffer, screenWidth, screenHeight);
//        // 꼭짓점 점 렌더링
//        for (int i = 0; i < 3; i++) {
//            RenderDot(&Dots[0], &TriangleObj[0], screenBuffer, screenWidth, screenHeight);
//        }
//
//        // 화면 그리기
//        Elf2DDrawBuffer(screenBuffer);
//        // FPS 유지
//        ElfTimeCalculateDeltaTime();
//        Elf2DSleep(frameTime - ElfTimeGetDeltaTime());
//    }
//
//
//    return 0;
//}