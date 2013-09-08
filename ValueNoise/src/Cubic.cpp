#include "Cubic.h"
/*
Cubic::Cubic()
{
    //ctor
}

Cubic::~Cubic()
{
    //dtor
}

float Cubic::getValue(float x, float* values)
  {
    int xF = floor(x);

    return cubicInterpolation(values[xF-1], values[xF], values[xF+1], values[xF+2], x-xF);
  }
float Cubic::getValue(float x, float y, float** values)
  {
    int yF = floor(y);

    float val1=getValue(x,values[yF-1]);
    float val2=getValue(x,values[yF]);
    float val3=getValue(x,values[yF+1]);
    float val4=getValue(x,values[yF+2]);

    return cubicInterpolation(val1, val2, val3, val4, y-yF);
  }

float Cubic::getValue(float x, float y, float z, float*** values)
  {
    int zF = floor(z);

    float val1=getValue(x,y,values[zF-1]);
    float val2=getValue(x,y,values[zF]);
    float val3=getValue(x,y,values[zF+1]);
    float val4=getValue(x,y,values[zF+2]);

    return cubicInterpolation(val1, val2, val3, val4, z-zF);
  }

float Cubic::cubicInterpolation(float y1, float y2, float y3, float y4, float x) {
  return 0.5*(3*(y2 - y3) + y4 -y1)*pow(x, 3)+(y1-2.5*y2+2*y3-0.5*y4)*pow(x, 2) +0.5*(y3-y1)*x+y2;
}

*/
