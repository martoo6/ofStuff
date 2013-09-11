#include "testApp.h"
#define ALTO 8
#define ANCHO 8
//Debido a que utilizo uint_fast8_t el tamaño maximo es de 10*10
const int_fast8_t ultimoNumero = ALTO*ANCHO;
struct vector2i{
    int_fast8_t x;
    int_fast8_t y;
    vector2i(int_fast8_t newX, int_fast8_t newY){
        x=newX;
        y=newY;
    }
    vector2i(){}
};
typedef struct{
    uint_fast8_t valor;
    vector<vector2i> mov;
}celda;
celda matriz[ANCHO][ALTO];
vector2i pos[ultimoNumero];
//--------------------------------------------------------------
void testApp::setup(){
    for(uint_fast8_t i=0;i<ANCHO;i++){
        for(uint_fast8_t e=0;e<ALTO;e++){
            matriz[i][e].valor=0;
            if(e+2<ALTO && i-1>=0) matriz[i][e].mov.push_back(vector2i(-1,2));
            if(e+2<ALTO && i+1<ANCHO) matriz[i][e].mov.push_back(vector2i(1,2));
            if(e+1<ALTO && i-2>=0) matriz[i][e].mov.push_back(vector2i(-2,1));
            if(e+1<ALTO && i+2<ANCHO) matriz[i][e].mov.push_back(vector2i(2,1));
            if(e-1>=0 && i-2>0) matriz[i][e].mov.push_back(vector2i(-2,-1));
            if(e-1>=0 && i+2<ANCHO) matriz[i][e].mov.push_back(vector2i(2,-1));
            if(e-2>=0 && i-1>=0) matriz[i][e].mov.push_back(vector2i(-1,-2));
            if(e-2>=0 && i+1<ANCHO) matriz[i][e].mov.push_back(vector2i(1,-2));
        }
    }
    calculo(1,1,1); //Current Number debe comenzar en 1 !

    //Visualizacion
    ofBackground(0,255);
    ofSetBackgroundAuto(true);
    myfont.loadFont("arial.ttf", 10);
    ofNoFill();
}

bool testApp::calculo(uint_fast8_t x, uint_fast8_t y, uint_fast8_t currentNumber){
    matriz[x][y].valor=currentNumber;
    for(uint_fast8_t i=0;i<matriz[x][y].mov.size(); i++){
        const vector2i vec = matriz[x][y].mov[i];
        if((matriz[x+vec.x][y+vec.y].valor==0) && calculo(x+vec.x, y+vec.y, currentNumber+1)){
            pos[currentNumber-1].x=x;
            pos[currentNumber-1].y=y;
            return true;
        }
    }
    if(currentNumber==ultimoNumero) {
        pos[ultimoNumero-1].x=x;
        pos[ultimoNumero-1].y=y;
        matriz[x][y].valor=ultimoNumero;
        return true;
    }
    matriz[x][y].valor=0;
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
    for(uint_fast8_t i=0;i<ultimoNumero;i++) ofVertex(pos[i].x*40+20,pos[i].y*40+20);
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
