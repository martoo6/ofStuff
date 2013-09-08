#include "ColorGenerator.h"

vector<ofColor> tmpPalete1({ofColor(0,134,252), ofColor(211,157,249), ofColor(180,238,249), ofColor(170,50,252), ofColor(50,157,252)});
vector<ofColor> tmpPalete2({ofColor(236,217,172), ofColor(226,149,131), ofColor(165,102,114), ofColor(126,63,119), ofColor(73,27,85)});
vector<ofColor> tmpPalete3({ofColor(118,163,29), ofColor(253,255,250), ofColor(250,217,203), ofColor(238,167,136), ofColor(128,168,187)});
vector<ofColor> tmpPalete4({ofColor(236,199,160), ofColor(93,199,138), ofColor(252,98,66), ofColor(182,57,92), ofColor(62,153,120)});
vector<ofColor> tmpPalete5({ofColor(255,153,102), ofColor(242,128,102), ofColor(230,102,102), ofColor(217,77,102), ofColor(204,51,102)});

vector< vector<ofColor> > ColorGenerator::palettes = vector< vector<ofColor> >({tmpPalete1, tmpPalete2, tmpPalete3, tmpPalete4, tmpPalete5});
vector<ofColor> ColorGenerator::currentPalette = palettes[int(ofRandom(palettes.size()))];

ColorGenerator::ColorGenerator()
{
    //ctor
}

ColorGenerator::~ColorGenerator()
{
    //dtor
}
