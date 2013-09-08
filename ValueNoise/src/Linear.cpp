#include "Linear.h"

Linear::Linear()
{
    //ctor
}

Linear::~Linear()
{
    //dtor
}

float Linear::getValue(float x, float* values){
    const int xF = floor(x);
    return linearInterpolation(values[xF], values[xF+1], x-xF);
}
float Linear::getValue(float x, float y, float** values){
    const int yF = floor(y);
    const float val1=getValue(x,values[yF]);
    const float val2=getValue(x,values[yF+1]);
    return linearInterpolation(val1, val2, y-yF);
}
float Linear::getValue(float x, float y, float z, float*** values){
    const int zF = floor(z);
    const float val1=getValue(x, y, values[zF]);
    const float val2=getValue(x, y, values[zF+1]);
    return linearInterpolation(val1, val2, z-zF);
}

float Linear::linearInterpolation(float y1, float y2, float x) {
  return (y2-y1)*x+y1;
}
