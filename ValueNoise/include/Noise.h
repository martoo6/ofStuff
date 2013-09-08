#ifndef NOISE_H
#define NOISE_H

#include "testApp.h"
#include "Interpolation.h"

class Noise
{
    public:
        Noise(int* detail ,Interpolation * type);
        virtual ~Noise();
        float getValue(float x);
        float getValue(float x, float y);
        float getValue(float x, float y, float z);
        float getCompoundValue(float x);
        float getCompoundValue(float x, float y);
        float getCompoundValue(float x, float y, float z);
    protected:
    private:
        float*** values;
        Interpolation* type;

        int detailCompound;
        float contrast;
        int* detail;
};

#endif // NOISE_H
