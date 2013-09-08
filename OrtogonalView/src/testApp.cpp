#include "testApp.h"
#define N_FIGURAS 100

Figure* figuras[N_FIGURAS];
//--------------------------------------------------------------
void testApp::setup(){
    ofSetFullscreen(true);
    ofSetBackgroundAuto(true);
    ofBackground(ofColor(0,0));
    ColorGenerator::setCurrentPalette();
    for(int i=0;i<N_FIGURAS;i++){
            figuras[i] = new Figure();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0;i<N_FIGURAS;i++){
            figuras[i]->update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    for(int i=0;i<N_FIGURAS;i++){
            figuras[i]->render();
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
    ColorGenerator::setCurrentPalette();
    for(int i=0;i<N_FIGURAS;i++){
            delete figuras[i];
            figuras[i] = new Figure();
    }
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
