//
//  breakOut.cpp
//  BreakOut2
//
//  Created by 김주형 on 2021/06/09.
//

#include "breakOut.hpp"
#include "ofApp.h"
Brick game;


// 게임의 초기화
// 공의 초기 위치를 화면의 중앙으로 설정
// 공의 속도를 x, y과 동일한 속도로 설정
void initGame(){
    game.ballX = ofGetWidth() / 2;
    game.ballY = ofGetHeight() / 2;
    game.ballDirX = game.ballDirY = game.ballSpeed = 10;
    
    game.padX = ofGetWidth()/ 2;
    game.padY = ofGetHeight() - 50;
    game.padWidth = 400;
    
    // 벽돌을 위한 2차원 배열 변수의 모든 값을 1로 초기화.
    // 1은 벽돌이 있음.
    // 0은 벽돌이 없음.
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j <32; j++)
        {
            game.bricks[i][j] = 1;
        }
    }
}


// 벽돌을 그리는 함수
// 오픈프레임웍스는 도형의 내부 색상과 외각선 색상을 동일하게 해야한다.
// 그래서 노란색으로 벽돌을 그린 후에
// 다시 ofNoFill()로 도형 내부를 채우지 않은 모드로, 검은 색으로 외각선을 그려야 한다.
void drawBrick(){
    ofFill();
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 32; j++)
        {
            if(game.bricks[i][j] == 1)
            {
                ofSetColor(ofColor :: yellow);
            }
            else
            {
                ofSetColor(ofColor :: white);
            }
            ofRect(j * BRICKWIDTH, i * BRICKHEIGHT, BRICKWIDTH, BRICKHEIGHT);
        }
    }
    ofNoFill();
    ofSetColor(ofColor :: black);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 32; j++)
        {
            if(game.bricks[i][j] == 1)
            {
                ofRect(j * BRICKWIDTH, i * BRICKHEIGHT, BRICKWIDTH, BRICKHEIGHT);
            }
        }
    }
}


void movePad(){
    game.padX = ofGetMouseX();
}


void drawPad(){
    ofFill();
    ofSetColor(ofColor :: black);
    ofLine(game.padX - game.padWidth / 2, game.padY, game.padX + game.padWidth / 2, game.padY);
}

// 매 프레임마도 공을 움직인다.
// 공의 x, y 좌표에 고의 움직임 량을 더해준다.
// bounchBall() 함수를 호출함으로써 공이 경계에서 반사되게 한다.
void moveBall(){
    game.ballX += game.ballDirX;
    game.ballY += game.ballDirY;
    bounceBall();
}


void drawBall(){
    ofFill();
    ofSetColor(ofColor :: black);
    ofCircle(game.ballX, game.ballY, BALLRADIUS);
}


// 공의 좌표가 x, y축 각각 좌우 또는 상하 경계에 부딪히면 공이 움직이는 방향에
// -1를 곱해서 방향을 바꾼다.
void bounceBall(){
    if(game.ballX > ofGetWidth() || game.ballX < 0)
        game.ballDirX *= -1;
    if(game.ballY > ofGetHeight() || game.ballY < 0)
        game.ballDirY *= -1;
    
    // 아래 부분 공이 라켓에 충돌하는지를 체크하는 부분
    if(game.ballY > ofGetHeight())
        game.ballDirY *= -1;
    else if(game.ballY > game.padY - BALLRADIUS &&
            game.ballX >= game.padX - game.padWidth / 2 &&
            game.ballX <= game.padX + game.padWidth /2){
        game.ballDirY *= -1;
    }
    
    // 공의 현재 위치 x, y를 각각 벽돌의 폭과 높이로 정수형 나눗셈을 하면
    // 해당하는 벽돌의 행과 열 번호를 알 수 있다.
    if(game.ballY < BRICKHEIGHT * 5 + BALLRADIUS){
        if(game.bricks[game.ballY / BRICKHEIGHT][game.ballX / BRICKWIDTH] == 1){
            game.bricks[game.ballY / BRICKHEIGHT][game.ballX / BRICKWIDTH] = 0;
            game.ballDirY *= -1;
        }
    }
}ㅃ
