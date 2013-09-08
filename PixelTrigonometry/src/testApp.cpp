#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    img.allocate(ofGetWidth(),ofGetHeight(), OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0;i<ofGetWidth();i++){
        a = FMath::cosine(i*0.2)*50;
        b =FMath::tang(i*0.02);
        for(int e=0;e<ofGetHeight();e++){
            img.setColor(i,e,ofColor::fromHsb(100+(FMath::tang(e*0.02)*a+b*FMath::cosine(e*0.2)*50)*FMath::cosine(ofGetFrameNum()*0.1),255,255));
        }
    }
    img.update();
    img.draw(0,0);
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
