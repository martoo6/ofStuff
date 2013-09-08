#ifndef COLORGENERATOR_H
#define COLORGENERATOR_H
#include "ofMain.h"
#include <vector>

class ColorGenerator
{
    public:
        ColorGenerator();
        virtual ~ColorGenerator();
        static vector<ofColor> getPalete(int palette){
            return palettes[palette];
        }
        static int getSize(){
            return palettes.size();
        }
        static void setCurrentPalette(){
            currentPalette = palettes[int(ofRandom(palettes.size()))];
        }
        static vector< vector<ofColor> > palettes;
        static vector<ofColor> currentPalette;
    protected:
    private:
};

#endif // COLORGENERATOR_H
