//
//  tarea6.c
//  mainR.c
//
//  Created by Juan Carlos Hernandez Ramos on 16/04/13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "runge.h"


int main(void){
	/*define el paso del método como 0.01, es el paso con el que el método avanza*/
    float h=0.01;
    /*contadores*/
    int i;
    int j;
    int n_points;
    float *t;
    float *x;
    float *y;
    float *z;
    float *num_rand;
    FILE *fileout;
    float slope_x;
    float slope_y;
    float slope_z;
    
    /*establece tantos intervalos como quepan en 30 y suma 1, en este caso (con 0.01) serán 3000*/
    n_points = (int)((30.0+h)/h);
    
    /*inicialice las variables que conservan el punto actual en 3 dimensiones y tiempo*/
    t = malloc(n_points * sizeof(float));
    x = malloc(n_points * sizeof(float));
    y = malloc(n_points * sizeof(float));
    z = malloc(n_points * sizeof(float));
    num_rand = malloc(30 * sizeof(float));
    
    if(!t){
        printf("There is something wrong with t\n");
        exit(1);
    }
    
    if(!x){
        printf("There is something wrong with x\n");
        exit(1);
    }
    
    if(!y){
        printf("There is something wrong with y\n");
        exit(1);
    }
    
    if(!z){
        printf("There is something wrong with z\n");
        exit(1);
    }
    
    if(!num_rand){
        printf("There is something wrong with num_rand\n");
        exit(1);
    }
    
    for(i=0; i<30; i+=1){
        
        num_rand[i] = rand() % 20 - 10;
        printf("%f random \n ", num_rand[i]);
    }
    
    /*inicializa las pendientes en cada una de las dimensiones*/
    slope_x = 0.0;
    slope_y = 0.0;
    slope_z = 0.0;
    int numDat=0;
    char numData[20];
    
    for(j=0; j<30; j+=3){
        
        t[0] =0.0;
        x[0] = num_rand[j];
        y[0] = num_rand[j+1];
        z[0] = num_rand[j+2];
        
        sprintf(numData, "%d", numDat);
        fileout = fopen(strcat(numData,"Data.dat"), "w");
        if(!fileout){
            printf("There is something wrong with Data.dat");
            exit(1);
        }
        
        for(i=0; i<n_points; i++){
            
            float *slopes;
            slopes = runge_kutta_step(h, t[i], x[i], y[i], z[i]);
            slope_x = slopes[0];
            slope_y = slopes[1];
            slope_z = slopes[2];
            
            /*  calcula el método hasta que converge*/
            t[i+1] = t[i] + h;
            x[i+1] = x[i] + h*slope_x;
            y[i+1] = y[i] + h*slope_y;
            z[i+1] = z[i] + h*slope_z;
            
            
            fprintf(fileout, "%f %f %f %f\n", t[i], x[i], y[i], z[i]);
            
        }
        
        numDat++;
        printf("%f %f %f %f se trabajo con las condiciones iniciales: \n ", t[0], x[0], y[0], z[0]);
        
        fclose(fileout);
        
    }
    
    return 0;
    
}





