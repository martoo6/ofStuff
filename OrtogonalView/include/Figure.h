#ifndef FIGURE_H
#define FIGURE_H
#include "ofMain.h"
#include "ColorGenerator.h"

class Figure
{
    public:
        Figure();
        Figure(int xPos, int yPos);
        virtual ~Figure();
        void render();
        void update();
        ofVec2f pos;
        ofColor mainColor;

    protected:
    private:
};

#endif // FIGURE_H
