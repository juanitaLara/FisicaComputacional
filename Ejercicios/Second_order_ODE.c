#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float funcion_1(float y_1);
float funcion_2(float y_1, float y_2);
float *runge_kutta_slope(float h_i, float x_i, float y_i, float y_j);

int main(void){

  float h=0.01;
  int i;
  int n_points;
  float *x;
  float *y_1;
  float *y_2;
  float slope_1;
  float slope_2;
  FILE *fileout;

  n_points=(int)((6.0+h)/h);

  x= malloc(n_points * sizeof(float));
  y_1= malloc(n_points * sizeof(float));
  y_2= malloc(n_points * sizeof(float));

  if(!x){
    printf("There is something wrong with x\n");
    exit(1);
  }


 if(!y_1){
    printf("There is something wrong with y_1\n");
    exit(1);
  }

 if(!y_2){
    printf("There is something wrong with y_2\n");
    exit(1);
  }

 x[0]=0.0;
 y_1[0]=1;
 y_2[0]=0.0;
 slope_1=0.0;
 slope_2=0.0;

 fileout= fopen("second_order2.dat", "w");
 if(!fileout){
    printf("There is something wrong with second_order.dat\n");
    exit(1);
  }

 for(i=0; i<n_points; i++){

   slope_1= runge_kutta_slope(h,x[i],y_1[i],y_2[i])[0];
   slope_2= runge_kutta_slope(h,x[i],y_1[i],y_2[i])[1];
   x[i+1] = x[i]+h;
   y_1[i+1] = y_1[i]+h*slope_1;
   y_2[i+1] = y_2[i]+h*slope_2;

   fprintf(fileout,"%f %f %f\n", x[i], y_1[i], y_2[i]);
   

 }
 fclose(fileout);



  return 0;

}




float *runge_kutta_slope(float h_i, float x_i, float y_i, float y_j){

  float *slope;
  float slope1;
  float slope2;
 
  float k1;
  float k2;
  float k3;
  float k4;
  float k1_;
  float k2_;
  float k3_;
  float k4_;
  float x1;
  float x2;
  float x3;
  float x4;
  float y1;
  float y2;
  float y3;
  float y4;
  float y1_;
  float y2_;
  float y3_;
  float y4_;

  k1 = funcion_1(y_j);
  k1_ = funcion_2(y_i,y_j);

  x1 = x_i + (h_i/2.0);
  y1 = y_i + (h_i/2.0)*k1;
  y1_=y_j + (h_i/2.0)*k1_;

  k2 = funcion_1(y1_);
  k2_ = funcion_2(y1,y1_);

  x2 = x_i + (h_i/2.0);
  y2 = y_i + (h_i/2.0)*k2;
  y2_=y_j + (h_i/2.0)*k2_;

  k3 = funcion_1(y2_);
  k3_ = funcion_2(y2,y2_);

  x3 = x_i + (h_i);
  y3 = y_i + (h_i)*k3;
  y3_=y_j + (h_i)*k3_;

  k4 = funcion_1(y3_);
  k4_ = funcion_2(y3,y3_);

  slope1 = (k1 + 2.0*k2 + 2.0*k3 + k4)/6.0;
  slope2 = (k1_ + 2.0*k2_ + 2.0*k3_ + k4_)/6.0;

  slope = malloc(2 * sizeof(float));
 if(!slope){
    printf("There is something wrong with slope\n");
    exit(1);
  }

 slope[0]= slope1;
 slope[1]=slope2;


  return slope;

}



float funcion_1(float y_1){

  float y_prime;
  y_prime = y_1;

  return y_prime;

}

float funcion_2(float y_1, float y_2){

  float y_prime2;
  y_prime2 = -4.0*y_1;

  return y_prime2;

}
