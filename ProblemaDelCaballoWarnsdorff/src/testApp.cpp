#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup(){
    for(uint_fast8_t i=0;i<ANCHO;i++){
        for(uint_fast8_t e=0;e<ALTO;e++){
            matriz[i][e].x=i;
            matriz[i][e].y=e;
            matriz[i][e].valor=0;

            if(e+2<ALTO && i-1>=0) matriz[i][e].mov.push_back(&matriz[i-1][e+2]);
            if(e+2<ALTO && i+1<ANCHO) matriz[i][e].mov.push_back(&matriz[i+1][e+2]);
            if(e+1<ALTO && i-2>=0) matriz[i][e].mov.push_back(&matriz[i-2][e+1]);
            if(e+1<ALTO && i+2<ANCHO) matriz[i][e].mov.push_back(&matriz[i+2][e+1]);
            if(e-1>=0 && i-2>0) matriz[i][e].mov.push_back(&matriz[i-2][e-1]);
            if(e-1>=0 && i+2<ANCHO) matriz[i][e].mov.push_back(&matriz[i+2][e-1]);
            if(e-2>=0 && i-1>=0) matriz[i][e].mov.push_back(&matriz[i-1][e-2]);
            if(e-2>=0 && i+1<ANCHO) matriz[i][e].mov.push_back(&matriz[i+1][e-2]);

            ofSort(matriz[i][e].mov, [](celda *a, celda *b){return a->mov.size()<b->mov.size(); });
        }
    }
    calculo(&matriz[0][0],1); //Current Number debe comenzar en 1 !

    //Visualizacion
    ofBackground(0,255);
    ofSetBackgroundAuto(true);
    myfont.loadFont("arial.ttf", 10);
    ofNoFill();
}

bool testApp::calculo(celda* cell, uint_fast8_t currentNumber){
    cell->valor=currentNumber;
    for(uint_fast8_t i=0;i<cell->mov.size(); i++){
        if((cell->mov[i]->valor==0) && calculo(cell->mov[i], currentNumber+1)){
            pos[currentNumber-1]=cell;
            return true;
        }
    }
    if(currentNumber==ultimoNumero) {
        pos[ultimoNumero-1]=cell;
        cell->valor=ultimoNumero;
        return true;
    }
    cell->valor=0;
    return false;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofTranslate(800/3,600/3);

    //Grilla
    for(uint_fast8_t i=0;i<=ANCHO;i++) ofLine(i*40,0,i*40,ALTO*40);
    for(uint_fast8_t e=0;e<=ALTO;e++) ofLine(0,e*40,ANCHO*40,e*40);
    //Texto
    for(uint_fast8_t i=0;i<ALTO;i++){
        for(uint_fast8_t e=0;e<ANCHO;e++){
            char text[255];
            sprintf(text,"%d",matriz[e][i].valor);
            myfont.drawString(text,e*40+5,i*40+15);
        }
    }

    //Camino
    ofBeginShape();
    for(uint_fast8_t i=0;i<ultimoNumero;i++) ofVertex(pos[i]->x*40+20,pos[i]->y*40+20);
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
