#include "ofApp.h"
#include "breakOut.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("2D Brick Break Out Game");
    ofSetWindowShape(1024, 768);
    ofSetFrameRate(40);
    ofBackground(ofColor :: white);
    ofSetColor(ofColor :: black);
    ofSetLineWidth(1);
    ofFill();
    
    initGame();
}

//--------------------------------------------------------------
void ofApp::update(){
    moveBall();
    movePad();
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawBrick();
    drawBall();
    drawPad();
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
void ofApp::mousePressed(int x, int y, int button){

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
