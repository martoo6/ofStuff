#ifndef LINEAR_H
#define LINEAR_H

#include <Interpolation.h>


class Linear : public Interpolation
{
    public:
        Linear();
        virtual ~Linear();
        virtual float getValue(float x, float* values);
        virtual float getValue(float x, float y, float** values);
        virtual float getValue(float x, float y, float z, float*** values);
    protected:
    private:
        float linearInterpolation(float y1, float y2, float x);
};

#endif // LINEAR_H
