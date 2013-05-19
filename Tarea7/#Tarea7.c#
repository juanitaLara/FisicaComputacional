#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14
#define M 1.0E31
#define m 1.0E26
#define gamma 5.0/3.0
#define g 6.67E-11
#define c 7.9512E55


float funcion_1(float y1, float y2);
float funcion_2(float y1, float y2);
float *runge_kutta_slope(float h, float t, float y1, float y2);

int main(void){

  float h = 1.0E3;
  int i;
  int n_points;
  float *p;
  float *t;
  float *y1;
  float *y2;
  float slopey1;
  float slopey2;
  FILE *fileout;

  n_points=(int)((1.5E6+h)/h);

  t = malloc(n_points * sizeof(float));
  y1 = malloc(n_points * sizeof(float));
  y2 = malloc(n_points * sizeof(float));
  p = malloc(n_points * sizeof(float));

  if(!t){
    printf("There is something wrong with t\n");
    exit(1);
  }


 if(!y1){
    printf("There is something wrong with y_1\n");
    exit(1);
  }

 if(!y2){
    printf("There is something wrong with y_2\n");
    exit(1);
  }

if(!p){
    printf("There is something wrong with p\n");
    exit(1);
  }

 /*Condiciones iniciales*/
 t[0]=0.0;
 y1[0]=1.7E10;
 y2[0]=0.0;
 p[0]=5.6E5;
 slopey1=0.0;
 slopey2=0.0;


 fileout= fopen("Data.dat", "w");
 if(!fileout){
    printf("There is something wrong with datos.dat\n");
    exit(1);
  }

 
 for(i=0; i<n_points; i++){

     float *slopes;
     slopes = runge_kutta_slope(h,t[i],y1[i],y2[i]);
   slopey1= slopes[0];
   slopey2= slopes[1];
   t[i+1] = t[i] + h;
   y1[i+1] = y1[i] + h*slopey1;
   y2[i+1] = y2[i] + h*slopey2;
   p[i+1] = c*pow(y1[i],-5);

   fprintf(fileout,"%f %f %f %f\n", t[i], y1[i], y2[i], p[i]);
   

 }
 fclose(fileout);



  return 0;

}



float *runge_kutta_slope(float h, float t, float y1, float y2){

  /*Define una pendiente para cada función*/
  float *slope;
  float slopey1;
  float slopey2;

  /*Define 4 k's para cada función. Primer índice hace referencia a el número de k, segundo índice hace referencia a la función (y1 o y2)*/ 
  float k1_1;
  float k2_1;
  float k3_1;
  float k4_1;
  float k1_2;
  float k2_2;
  float k3_2;
  float k4_2;

  /*Tres variables de tiempo*/
  float t1;
  float t2;
  float t3;

  /*Variables para cada paso de Runge-Kutta. Primer índice hace referencia al paso. Segundo índice hace referencia a la función*/
  float y1_1;
  float y2_1;
  float y3_1;
  
  float y1_2;
  float y2_2;
  float y3_2;
 

 
  k1_1 = funcion_1(y1,y2);
  k1_2 = funcion_2(y1,y2);

  /*First step*/
  t1 = t + (h/2.0);
  y1_1 = y1 + (h/2.0)*k1_1;
  y1_2 = y2 + (h/2.0)*k1_2;

  k2_1 = funcion_1(y1_1,y1_2);
  k2_2 = funcion_2(y1_1,y1_2);

  /*Second step*/
  t2 = t + (h/2.0);
  y2_1 = y1 + (h/2.0)*k2_1;
  y2_2 = y2 + (h/2.0)*k2_2;

  k3_1 = funcion_1(y2_1,y2_2);
  k3_2 = funcion_2(y2_1,y2_2);

  /*Third step*/
  t3 = t + h;
  y3_1 = y1 + (h)*k3_1;
  y3_2 = y2 + (h)*k3_2;

  k4_1 = funcion_1(y3_1,y3_2);
  k4_2 = funcion_2(y3_1,y3_2);

  /*Fourth step*/
  slopey1 = (k1_1 + 2.0*k2_1 + 2.0*k3_1 + k4_1)/6.0;
  slopey2 = (k1_2 + 2.0*k2_2 + 2.0*k3_2 + k4_2)/6.0;

  slope = malloc(2 * sizeof(float));
 if(!slope){
    printf("There is something wrong with slope\n");
    exit(1);
  }

 slope[0] = slopey1;
 slope[1] = slopey2;


  return slope;

}



float funcion_1(float y1,float y2){


  return y2;

}

float funcion_2(float y1, float y2){

  return -(g*M)/(y1*y1) + (4*PI*c*pow(y1,-3))/m;

}
