#include "Noise.h"

Noise::Noise(int* detail, Interpolation* type)
{
    detailCompound=6;
    contrast=0.55;
    this->detail=detail;

    values = new float**[detail[2]+3];
    for (int i = 0; i < detail[2]+3; i++) {
        values[i] = new float*[detail[1]+3];
        for (int e = 0; e < detail[1]+3; e++) {
            values[i][e] = new float[detail[0]+3];
            for(int j=0;j< detail[0]+3;j++){
                int val1=i;
                int val2=e;
                int val3=j;
                bool flag=false;
                if(j>=detail[0]){
                    val3-=detail[0];
                    flag=true;
                }
                if(e>=detail[1]){
                    val2-=detail[1];
                    flag=true;
                }
                if(i>=detail[2]){
                    val1-=detail[2];
                    flag=true;
                }
                if(flag){
                    values[i][e][j] = values[val1][val2][val3];
                }else{
                    values[i][e][j] = ofRandom(1);
                }
            }
        }
    }

    this->type = type;
}

Noise::~Noise()
{
    //dtor
}

float Noise::getValue(float x) {
    if(x>=detail[0]){
      x-=detail[0]*floor(x/detail[0]);
    }
    //x++;
    return type->getValue(x, values[0][0]);
}
float Noise::getValue(float x, float y) {
    if(x>=detail[0]){
      x-=detail[0]*floor(x/detail[0]);
    }
    if(y>=detail[1]){
      y-=detail[1]*floor(y/detail[1]);
    }
    //x++;
    //y++;
    return type->getValue(x, y, values[0]);
}
float Noise::getValue(float x, float y, float z) {
    if(x>=detail[0]){
      x-=detail[0]*floor(x/detail[0]);
    }
    if(y>=detail[1]){
      y-=detail[1]*floor(y/detail[1]);
    }
    if(z>=detail[2]){
      z-=detail[2]*floor(z/detail[2]);
    }
    //x++;
    //y++;
    //z++;
    return type->getValue(x, y, z, values);
}

float Noise::getCompoundValue(float x) {
    float total=0;
    int freq=1;
    float amp=contrast;
    for (int i=0;i<detailCompound;i++) {
      total+=getValue(x*freq)*amp;
      freq*=2;//Siempre duplicamos la frecuencia, equivalente a cambiar de octava
      amp*=contrast;
    }
    return total;
  }
float Noise::getCompoundValue(float x, float y) {
    float total=0;
    int freq=1;
    float amp=contrast;
    for (int i=0;i<detailCompound;i++) {
      total+=getValue(x*freq, y*freq)*amp;
      freq*=2;//Siempre duplicamos la frecuencia, equivalente a cambiar de octava
      amp*=contrast;
    }
    return total;
  }
 float Noise::getCompoundValue(float x, float y, float z) {
    float total=0;
    int freq=1;
    float amp=contrast;
    for (int i=0;i<detailCompound;i++) {
      total+=getValue(x*freq, y*freq, z*freq)*amp;
      freq*=2;//Siempre duplicamos la frecuencia, equivalente a cambiar de octava
      amp*=contrast;
    }
    return total;
  }
