#ifndef INTERPOLATION_H
#define INTERPOLATION_H
#include "ofMain.h"

class Interpolation
{
    public:
        Interpolation();
        virtual ~Interpolation();
        virtual float getValue(float x, float* values)=0;
        virtual float getValue(float x, float y, float** values)=0;
        virtual float getValue(float x, float y, float z, float*** values)=0;
    protected:
    private:
};

#endif // INTERPOLATION_H
