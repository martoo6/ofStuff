#include "Figure.h"

Figure::Figure()
{
    pos.set(int(ofRandom(ofGetWidth())),int(ofRandom(600)));
    vector<ofColor> vec = ColorGenerator::currentPalette;
    mainColor.set(vec[int(ofRandom(vec.size()))]);
}

void Figure::update(){
    pos.y=ofNoise(ofGetFrameNum()*0.01,pos.x)*ofGetHeight();
    //printf("%d\n",ofGetFrameNum());
}

void Figure::render(){
    //mainColor.lerp();
    ofPushMatrix();
    ofTranslate(pos.x,pos.y);
    ofFill();

    ofSetColor(mainColor.getLerped(ofColor(0,0,0), 0.5));
    ofRect(0,20,20,ofGetHeight());

    ofSetColor(mainColor.getLerped(ofColor(0,0,0), 0.7));
    ofRect(20,20,20,ofGetHeight());

    ofSetColor(mainColor);

    ofBeginShape();
    ofVertex(0,20);
    ofVertex(20,0);
    ofVertex(40,20);
    ofVertex(20,40);
    ofEndShape();

    ofPopMatrix();
}

Figure::~Figure()
{
    //dtor
}
