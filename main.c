#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double f(float x){
  return pow((x - 2),2) - log(x); 
}


double g(float x){
  return x - (pow((x - 2),2) - log(x))/(2*(x-2)-1/x); 
}

float newtonRaphson(float x0,float E1, float E2){
  int k = 0;
  float xM,x = 0.0;
  printf("k     Xk     F(xk)      F'(xk)    Xk+1 ");
  do{
    printf("\n%d %.f %f %f %f \n",k, x0,f(x0),g(x0),x);
     if( fabs(f(x0))<E1){
      xM = x0;
      return xM;
    } 
    k++;
    x = g(x0);
     printf("\n%d %f %f %f %f \n",k, x0,f(x0),g(x0),x);
    if( fabs(x - x0) <E2){
      xM = x;
    return xM;
    }

    x0 = x;
    

  }while(1);


}


int main(void) {
  float x0,E1,E2;

  printf("\nType the initial values of x0, E1 and E2\n");
  scanf("%f %f %f",&x0,&E1,&E2);

  float result = newtonRaphson( x0, E1,E2);
  printf("\nFinal Result:%.6f\n",result);
  return 0;
}


