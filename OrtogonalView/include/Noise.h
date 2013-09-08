#ifndef NOISE_H
#define NOISE_H
#include "Interpolation.h"

class Noise
{
    public:
        Noise();
        virtual ~Noise();
    protected:
    private:
        float* values;
        Interpolation type;

        static const int detailCompound=6;
        static const float contrast=0.55;
        int* detail;
};

#endif // NOISE_H
