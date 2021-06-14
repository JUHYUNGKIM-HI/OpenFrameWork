#include "ofApp.h"
#include <time.h>
#include <stdlib.h>

#define BAR_WIDTH 50
#define MAXIMUM 100

int samples[MAXIMUM];
int graph[10];


void frequencyTableGenerate(){
    srand((unsigned)time(NULL));
    
    for(int i = 0; i < 10; i++){
        graph[i] = 0;
    }
    
    for(int i = 0; i < MAXIMUM; i++){
        samples[i] = rand() % MAXIMUM;
        graph[samples[i] / 10]++;
    }
}

void frequencyTableDraw(){
    for(int i = 0; i < 10; i++){
        ofRect(i * BAR_WIDTH, 0, BAR_WIDTH, graph[i] * 10);
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Frequency Table and Graph #1");
    ofSetWindowShape(500, 500);
    ofSetFrameRate(60);
    ofBackground(ofColor :: white);
    ofSetColor(ofColor :: black);
    ofSetLineWidth(1.0);
    ofNoFill();
    
    frequencyTableGenerate();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    frequencyTableDraw();
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
