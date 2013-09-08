#ifndef FMATH_H
#define FMATH_H
#define ACCURACY 360

#include <math.h>

class FMath
{
    public:
        FMath();
        virtual ~FMath();

        static float cosine(float val){
            return cosineVals[rightAngle(val)];
        }
        static float sine(float val){
            return sineVals[rightAngle(val)];
        }
        static float tang(float val){
            return tangVals[rightAngle(val)];
        }
    protected:
    private:
        static float const FMATH_TWO_PI =  M_PI*2;
        static float* cosineVals;
        static float* sineVals;
        static float* tangVals;
        static float const step= 6.283185307/ACCURACY;
        static int rightAngle(float val){
            val-=FMATH_TWO_PI*int(val/FMATH_TWO_PI);
            return int((val/FMATH_TWO_PI)*ACCURACY);
        }
        static float* getCosineVals(){
            float* tmpCosineVals= new float[ACCURACY];
            for(int i=0;i<ACCURACY;i++){
                tmpCosineVals[i]=cos(step*i);
            }
            return tmpCosineVals;
        }
        static float* getSineVals(){
            float* tmpSineVals= new float[ACCURACY];
            for(int i=0;i<ACCURACY;i++){
                tmpSineVals[i]=sin(step*i);
            }
            return tmpSineVals;
        }
        static float* getTangVals(){
            float* tmpTangVals= new float[ACCURACY];
            for(int i=0;i<ACCURACY;i++){
                tmpTangVals[i]=tan(step*i);
            }
            return tmpTangVals;
        }
};

#endif // FMATH_H
