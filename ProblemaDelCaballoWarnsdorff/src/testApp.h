#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
#define ALTO 8
#define ANCHO 8
//Debido a que utilizo uint_fast8_t el tamaño maximo es de 10*10
static const int_fast8_t ultimoNumero = ALTO*ANCHO;
struct celda{
    uint_fast8_t valor;
    vector<celda *> mov;
    uint_fast8_t x;
    uint_fast8_t y;
};
celda matriz[ANCHO][ALTO];
celda* pos[ultimoNumero];

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        bool calculo(celda* cell, uint_fast8_t currentNumber);

        ofTrueTypeFont myfont;

};
