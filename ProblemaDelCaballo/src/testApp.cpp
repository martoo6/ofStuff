#include "testApp.h"
int matriz[8][8];
ofVec2f mov[8];
ofVec2f pos[64];
//--------------------------------------------------------------
void testApp::setup(){
  //Pensar en tirarlo con threads (ver tema de sincronziacion posible uso de Scala)

    mov[0].set(-1,2);
    mov[1].set(1,2);
    mov[2].set(-2,1);
    mov[3].set(2,1);
    mov[4].set(-2,-1);
    mov[5].set(2,-1);
    mov[6].set(-1,-2);
    mov[7].set(1,-2);

    for(int i=0;i<8;i++){
        for(int e=0;e<8;e++){
            matriz[i][e]=-1;
        }
    }

    if(calculo(0,0,0)) ofBackground(0,255);
    ofSetBackgroundAuto(true);
    myfont.loadFont("arial.ttf", 10);
    ofNoFill();
}

bool movValido(int x, int y){
    //En vez de utilizar este sistema que cada casillero sepa cuales son sus casilleros a moverse validos
    if((x>7)||(y>7)||(x<0)||(y<0)||matriz[x][y]!=-1){
        return false;
    }
    return true;
}

bool testApp::calculo(int x, int y, int currentNumber){
    matriz[x][y]=currentNumber;
    for(int i=0;i<8;i++){
        if(movValido(x+mov[i].x,y+mov[i].y)&&calculo(x+mov[i].x,y+mov[i].y, currentNumber+1)){
            pos[currentNumber].set(x,y);
            return true;
        }
    }
    if(currentNumber==63) {
        pos[63].set(x,y);
        matriz[x][y]=63;
        return true;
    }
    matriz[x][y]=-1;
    return false;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofTranslate(800/3,600/3);

    //Grilla
    for(int i=0;i<=8;i++){
        ofLine(i*40,0,i*40,320);
    }
    for(int e=0;e<=8;e++){
        ofLine(0,e*40,320,e*40);
    }
    //Texto
    for(int i=0;i<8;i++){
        for(int e=0;e<8;e++){
            char text[255];
            sprintf(text,"%d",matriz[e][i]);
            myfont.drawString(text,e*40+5,i*40+15);
        }
    }

    //Camino
    ofBeginShape();
    for(int i=0;i<64;i++){
        ofVertex(pos[i].x*40+20,pos[i].y*40+20);
    }
    ofEndShape();
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
