//
//  breakOut.hpp
//  BreakOut2
//
//  Created by 김주형 on 2021/06/09.
//

#ifndef breakOut_h
#define breakOut_h

#define BALLRADIUS 15
#define BRICKWIDTH 64
#define BRICKHEIGHT 40


// 벽돌 깨기 게임을 위한 공의 위치와 움직이는 방향, 공의 속도를 가지는 구조체
typedef struct
{
    int ballX, ballY;
    int ballDirX, ballDirY;
    int ballSpeed;
    int padX, padY, padWidth;
    int bricks[5][32]; // 5행, 32열의 벽돌을 위한 2차원 배열 변수
} Brick;


// 함수의 선언들
void initGame();
void moveBall();
void drawBall();
void bounceBall();

void movePad();
void drawPad();

void drawBrick();

#endif /* breakOut_h */

