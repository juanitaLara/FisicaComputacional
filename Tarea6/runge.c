#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "funcion.h"


float *runge_kutta_step(float h, float t, float x, float y, float z){
    /*el resultado de esta función es la pendiente para definit el siguiente punto*/
    /*para cada dimensión se define una pendiente*/
    float *slope;
    float slope_x;
    float slope_y;
    float slope_z;
    /*acá se tiene que definir un k de 1 a 4*/
    /* para cada dimensión, por eso se declaran 12*/
    float kx_1;
    float kx_2;
    float kx_3;
    float kx_4;
    float ky_1;
    float ky_2;
    float ky_3;
    float ky_4;
    float kz_1;
    float kz_2;
    float kz_3;
    float kz_4;
    /*... y se definen también 3 variables de tiempo*/
    float t1;
    float t2;
    float t3;
    /*como este método funciona con 3 puntos en el intervalo (inicio, medio y fin)*/
    /*uno para cada dimensión */
    float x1;
    float x2;
    float x3;
    
    float y1;
    float y2;
    float y3;
    
    float z1;
    float z2;
    float z3;
    
    /*k1 en runge kutta es simplemente la función sin alteraciones*/
    kx_1 = funcion_x(x,y,z);
    ky_1 = funcion_y(x,y,z);
    kz_1 = funcion_z(x,y,z);
    /*el primer paso vuelve a ejecutar la función partiendo de los valores anteriores*/
    /*k1, etc según la función definida, es una linealización con los k y recalcula los*/
    /* puntos en el espacio*/
    /*First step*/
    t1 = t + (h/2.0);
    x1 = x + (h/2.0)*kx_1;
    y1 = y + (h/2.0)*ky_1;
    z1 = z + (h/2.0)*kz_1;
    /*los siguientes ks se encuentran evaluando la función con los nuevos puntos en el espacio*/
    kx_2 = funcion_x(x1,y1,z1);
    ky_2 = funcion_y(x1,y1,z1);
    kz_3 = funcion_z(x1,y1,z1);
    /*así se siguen calculando entre ks y puntos hasta llegar a calcular la pendiente*/
    /*Second step*/
    t2 = t + (h/2.0);
    x2 = x + (h/2.0)*kx_2;
    y2 = y + (h/2.0)*ky_2;
    z2 = z + (h/2.0)*kz_2;
    
    kx_3 = funcion_x(x2,y2,z2);
    ky_3 = funcion_y(x2,y2,z2);
    kz_3 = funcion_z(x2,y2,z2);
    
    /*Third step*/
    t3 = t + h;
    x3 = x + h*kx_3;
    y3 = y + h*ky_3;
    z3 = z + h*kz_3;
    
    kx_4 = funcion_x(x3,y3,z3);
    ky_4 = funcion_y(x3,y3,z3);
    kz_4 = funcion_z(x3,y3,z3);
    /*la pendiente se calcula promediando los ks obtenidos para cada dimensión según la definición del método,*/
    /* en este caso en un runge kutta de cuarto orden */
    
    /*Fourth step*/
    slope_x = (kx_1 + 2.0*kx_2 + 2.0*kx_3 + kx_4)/6.0;
    slope_y = (ky_1 + 2.0*ky_2 + 2.0*ky_3 + ky_4)/6.0;
    slope_z = (kz_1 + 2.0*kz_2 + 2.0*kz_3 + kz_4)/6.0;
    
    slope = malloc(3 * sizeof(float));
    if(!slope){
        printf("There is something wrong with slope\n");
        exit(1);
    }
    /*definición del arreglo para el resultado de la función*/
    slope[0] = slope_x;
    slope[1] = slope_y;
    slope[2] = slope_z;
    
    return slope;
    
}