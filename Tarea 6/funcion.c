//
//  funcion.c
//  
//
//  Created by Juan Carlos Hernandez Ramos on 16/04/13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


/*definición de la función en x*/
float funcion_x(float x, float y, float z){
    
    return 10.0*(y-x);
    
}


/*definición de la función en y*/
float funcion_y(float x, float y, float z){
    
    return x*(28.0-z)-y;
    
}


/*definición de la función en z*/
float funcion_z(float x, float y, float z){
    
    return x*y-(8.0/3.0)*z;
    
}