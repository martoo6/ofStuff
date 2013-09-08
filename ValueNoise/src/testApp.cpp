#include "testApp.h"
int detail[3]={50,50,5};
Noise* noiser=new Noise(detail, new Linear());;
//--------------------------------------------------------------
void testApp::setup(){
    ofDisableAntiAliasing();
    ofDisableSmoothing();
    ofDisableDepthTest();
    ofDisableAlphaBlending();
    ofDisableBlendMode();
    ofDisablePointSprites();
    //noiser = new Noise(detail, new Linear());
    //noiser = new Noise(detail, new Cubic());
    ofFill();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetWindowTitle(to_string(ofGetFrameRate()));
    for (int i = 0; i < 500; i++) {
        for (int e = 0; e < 500; e++) {
            val=noiser->getValue(i*0.05, e*0.05, ofGetFrameNum()*0.05)*250;
            ofSetColor(val,255);
            ofRect(i*step, e*step, step, step);
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
