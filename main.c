#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 2.71828182845904523536028747135266249775724709369995

// double f(float x){
//   return pow((x - 2),2) - log(x); 
// }

// double g(float x){
//   return x - (pow((x - 2),2) - log(x))/(2*(x-2)-1/x); 
// }

double f(float x){
  return (pow(e,-x) - x); 
}

double fLinha(float x){
  return  (-pow(e,-x) - 1);
}

double g(float x){
  return  x - (f(x)/fLinha(x));
}

float newtonRaphson(float x0,float E, int kMax){
  int k = 0;
  float xM,x = 0.0;
  printf("k     Xk     F(xk)      F'(xk)    Xk+1 ");
  do{
    printf("\n%d %.f %f %f %f \n",k, x0,f(x0),g(x0),x);
     if( fabs(f(x0))<E){
      xM = x0;
      printf("\n>>> A raiz, respeitando a tolerância solicitada, foi encontrada após %d iterações\n",k);
      return xM;
     
   
    } 
    k++;
    x = g(x0);
     printf("\n%d %f %f %f %f \n",k, x0,f(x0),g(x0),x);
    if( fabs(x - x0) <E){
      xM = x;
      printf("\n>>> A raiz, respeitando a tolerância solicitada, foi encontrada após %d iterações\n",k);
      return xM;
    }

    x0 = x;
    
  }while(k <= kMax);

  printf("\n>>> ERRO! \nChegou ao número máximo de iterações sem alcançar a tolerância solicitada. \nSugestões:\n i) Tentar acrescentar mais iterações \n ii) Chutar um valor inicial mais próximo da raiz\n");
  return -1;

}


int main(void) {
  float x0,E,kMax;

  printf("\nDigite o valor inicial(x0) e a precisão(E) e Número máximo de iteração(kMax):\n");
  scanf("%f %f %f",&x0,&E,&kMax);

  float result = newtonRaphson( x0, E, kMax);

  if(result != -1){
      printf("\n>> Raiz aproximada: %.8f\n",result);
  }

  
  return 0;
}


