#include "ofApp.h"

#define DIGIT_RESOLUTION 5 //입력 이미지의 해상도는 5x5.
#define BRICK_SIZE 50 // 화면에 출력되는 숫자 격자의 픽셀 개수
#define RECOGNITION_BUTTON_Y 300 // 인식 실행 버튼 기능을 담당하는 화면 하단의 y좌표

// 사용자가 마우스로 그린 숫자 그림을 저장하는 변수
// 마우스로 클릭되는 숫자 비트 값을 저장할 배열, 1이면 검은색, 0이면 흰색
int digit[DIGIT_RESOLUTION][DIGIT_RESOLUTION];

int startRecognition; // 인식 버튼이 클릭되면 1로 세팅되는 변수
int recognitionResult = 0; // 매칭 결과(동일한 값을 가진 픽셀의 개수)를 저장하는 변수

int doRecognition(); // 숫자 인식 함수 선언

//--------------------------------------------------------------
void ofApp::setup(){ // setup() 함수는 모든 변수를 초기화한다.
    ofSetWindowTitle("Recognition V0.1");
    ofSetWindowShape(250, 400);
    ofSetFrameRate(40);
    ofBackground(ofColor :: white);
    ofSetColor(ofColor :: black);
    ofSetLineWidth(1);
    
    //화면에 그려지는 글자를 0으로 초기화
    for(int i = 0; i < DIGIT_RESOLUTION; i++){
        for(int j = 0; j < DIGIT_RESOLUTION; j++){
            digit[i][j] = 0;
        }
    }
    // 숫자 인식을 실행할지 여부를 결정하는 변수를 0으로 초기화
    startRecognition = 0;
}

// update() 함수는 계속적으로 반복된다.
// 따라서 언제 인식을 실행해야 할지를 결정하기 위해서
// 마우스를 하단 부에 크릭하면 startRecognition 변수 값이 1로 변경되는데,
// 이 값이 1이면 인식 함수인 doRecognition()을 실행한다.
//--------------------------------------------------------------
void ofApp::update(){
    int num = doRecognition();
    if(startRecognition == 1){
        recognitionResult = num;
        startRecognition = 0;
    }
}


// draw() 함수는 화면에 글자 픽셀을 그려주고,
// 실행 결과도 출력하고, 실행 버튼도 그려준다.
//--------------------------------------------------------------
void ofApp::draw(){
    //인식 결과 출력
    ofSetColor(ofColor :: black);
    ofDrawBitmapString("result : " + ofToString(recognitionResult), 10, 280); // 그래픽 화면에 글자를 출력할 수 있다.
    
    // 실행 시작 버튼 그리기
    ofSetColor(ofColor :: blue);
    ofRect(0, RECOGNITION_BUTTON_Y, ofGetWidth(), 100);
    ofDrawBitmapString("Do Recognition ~~~", 50, 350);
    
    // 글자 픽셀 그리기
    ofFill();
    for(int i = 0; i < DIGIT_RESOLUTION; i++){
        for(int j = 0; j < DIGIT_RESOLUTION; j++){
            if(digit[i][j] == 1){
                ofSetColor(ofColor :: black);
            }
            else{
                ofSetColor(ofColor :: white);
            }
            ofRect(j * BRICK_SIZE, i * BRICK_SIZE, BRICK_SIZE, BRICK_SIZE);
        }
    }
    
    // 글자의 외각선 그리기
    ofNoFill();
    ofSetColor(ofColor :: black);
    for(int i = 0; i < DIGIT_RESOLUTION; i++){
        for(int j = 0; j < DIGIT_RESOLUTION; j++){
            ofRect(j * BRICK_SIZE, i * BRICK_SIZE, BRICK_SIZE, BRICK_SIZE);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
// 마우스가 클릭될 때 마다 자동으로 호출되는 함수이다.
void ofApp::mousePressed(int x, int y, int button){
    if(x < DIGIT_RESOLUTION * BRICK_SIZE && y < DIGIT_RESOLUTION * BRICK_SIZE){
        digit[y / BRICK_SIZE][x / BRICK_SIZE] = 1 - digit[y / BRICK_SIZE][x / BRICK_SIZE]; // 1에서 현재 값을 뺄셈 함으로써 눌린 곳의 픽셀 값을 반전한다.
    } // digit[][]에서 반드시 y -> x 순으로 해야한다.
    // 인식 버튼을 눌렀는지 체크하는 부분
    if(y > RECOGNITION_BUTTON_Y) startRecognition = 1;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

// 실제 글자를 인식하는 함수
// 사용자에 의해서 입력된 숫자 모양과 이미 프로그램에서 정해 놓은 표준 숫자 모양과 일치하는 픽셀 개수를 반환한다.
int doRecognition(){
    int no[10][5][5] =
    {
        {
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
        },
        {
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0}
        },
        {
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1}
        },
        {
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
        },
        {
            {1, 0, 0, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1}
        },
        {
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
        },
        {
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
        },
        {
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1}
        },
        {
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
        },
        {
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
        },
    };
    
    int sum, max, maxDigit;
    max = 0; // 가장 많이 매칭된 픽셀의 개수를 저장하는 변수
    maxDigit = 0; // 현재까지 가장 비슷한 숫자 번호를 저장하는 변수
    
    // 입력된 숫자를 10개의 표준 숫자 모두와 비교해서, 가장 매칭이 잘되는(비슷한) 숫자 인덱스를 결정하는 부분
    for(int d = 0; d < 10; d++){
        sum = 0;
        for(int i = 0; i < DIGIT_RESOLUTION; i++){
            for(int j = 0; j < DIGIT_RESOLUTION; j++){
                if(no[d][i][j] == digit[i][j]) sum++;
            }
        }
        if(sum > max){
            max = sum;
            maxDigit = d;
        }
    }
    return maxDigit;
}
