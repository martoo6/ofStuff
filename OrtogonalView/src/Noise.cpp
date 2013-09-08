#include "Noise.h"

Noise::Noise()
{
    this.detail=detail;
    values = new float[detail[2]+4][detail[1]+4][detail[0]+4]; //Sumo 3 valores mas para poder calcular cubicas.
    for (int i = 0; i < detail[2]+3; i++) {
      for (int e = 0; e < detail[1]+3; e++) {
        for (int j = 0; j < detail[0]+3; j++) {
          int val1=i;
          int val2=e;
          int val3=j;
          boolean flag=false;
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
            values[i][e][j] =  values[val1][val2][val3];
          }else{
            values[i][e][j] = random(1);
          }
        }
      }
    }
    this.type = type;
}

Noise::~Noise()
{
    //dtor
}


float Noise::getValue(float x) {
    if(x>=detail[0]){
      x-=detail[0]*floor(x/detail[0]);
    }
    x++;
    return type.getValue(x, values[0][0]);
}
float Noise::getValue(float x, float y) {
    if(x>=detail[0]){
      x-=detail[0]*floor(x/detail[0]);
    }
    if(y>=detail[1]){
      y-=detail[1]*floor(y/detail[1]);
    }
    x++;
    y++;
    return type.getValue(x, y, values[0]);
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
    x++;
    y++;
    z++;
    return type.getValue(x, y, z, values);
}
