#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


float funcion_u_inicial(float x);

int main(void){

  int n_points;
  int i;
  int j;
  int k;
  int times;
  float delta_t;
  float alfa;
  float *x;
  float *now;
  float *new;
  float h;
  int contador;
  FILE *Out;
  int numDat;
  char numData[10];

  n_points = 500;
  times = 2.0E6;
  h = 1.0/n_points;
  delta_t = 1.5E-6;
  alfa = delta_t/(h*h);
  contador = 2.0E5;
  numDat = 0;


  x = malloc(n_points * sizeof(float));
  now = malloc(n_points * sizeof(float));
  new = malloc(n_points * sizeof(float));


  if(!x){
    printf("There is something wrong with x\n");
    exit(1);
}



 if(!now){
    printf("There is something wrong with now\n");
    exit(1);
}

 if(!new){
    printf("There is something wrong with new\n");
    exit(1);
}

 

  x[0] = 0;

  for(i=1; i<n_points; i++)
  {
    x[i] = x[i-1] + h;
  }


  now[0]= 0.0;
  now[n_points-1]= 0.0;


  for(i=1; i<n_points-1; i++){
    now[i]= funcion_u_inicial(x[i]);
 }


  for (j=0; j<times; j++){

    for (i=1; i<n_points-1; i++){

      new[0]= 0.0;
      new[n_points-1]= 0.0;
	  new[i]= alfa*now[i+1] + (1-2*alfa)*now[i] + alfa*now[i-1];

	  now[i] = new[i];
	  printf("indice %d matrix %f ind %d\n", i, now[i], j);
    }


   if(j==contador){

     sprintf(numData, "%d", numDat);
     Out= fopen(strcat(numData,"Data.dat"), "w");

     if(!Out){
       printf("There is something wrong with datos.dat\n");
       exit(1);
     }

     for(k=0; k<n_points; k++){

       fprintf(Out, "%f %f\n", x[k], now[k]);

     }

     fclose(Out);

     contador = contador + 2.0E5;
     numDat = numDat + 1;


   }

 }






  return 0;

}


float funcion_u_inicial(float x){

  return 4*x*(1-x);

}
