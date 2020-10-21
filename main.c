
/*
Aluno: André Geraldo, Professor: Dr. Valtemir Emerencio do Nascimento.

Objetivo: Implementar o método de Newton-Raphson, para determinação de raízes, da disciplina Cálculo Numérico.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 2.71828182845904523536028747135266249775724709369995

//Cabeçalho das funções utilizadas
double f(float x);
double fLinha(float x);
double g(float x);
float newtonRaphson(float x0,float E, int kMax);

int main(void) {
  float x0,E,kMax;

  printf("\nDigite o valor inicial(x0) e a precisão(E) e Número máximo de iteração(kMax):\n");
  scanf("%f %f %f",&x0,&E,&kMax);

  //Result recebe o valor retornado da função com o método de Newton-Rapson.
  float result = newtonRaphson( x0, E, kMax);
  //caso seja diferente de -1, significa que o valor retornado é realmente o valor da raiz aproximada encontrada
  if(result != -1){
      printf("\n>> Raiz aproximada: %.8f\n",result);
  }

  
  return 0;
}

// double f(float x){
//   return pow((x - 2),2) - log(x); 
// }

// double g(float x){
//   return x - (pow((x - 2),2) - log(x))/(2*(x-2)-1/x); 
// }

//Função fornecida para o problema. (A mesma do slide)
double f(float x){
  return (pow(e,-x) - x); 
}

//Derivada da F fornecida para o problema
double fLinha(float x){
  return  (-pow(e,-x) - 1);
}

//Fórmula de Newton-Raphson, Contendo a divisão //entre a função e a sua derivada.
double g(float x){
 //O valor de x em questão é sempre o anterior
 //Xi o retorno do cálculo resulta no Xi+1 (posterior)
  return  x - (f(x)/fLinha(x));
}

//Função contendo o método de Newton-Raphson.
/*
Parametros:

x0 = Aproximação inicial
E = Tolerância/precisão fornecida
kMax = Numero máximo de iterações solicitadas

*/
float newtonRaphson(float x0,float E, int kMax){
  //Contador de iterações
  int k = 0;
  //
  float xM,x = 0.0;
  printf("k     Xk     F(xk)      F'(xk)    Xk+1 ");
  do{
    //printf("\n%d %.f %f %f %f \n",k, x0,f(x0),g(x0),x);
    
    //Critério de parada
    //Se o valor absoluto da função no ponto de aproximação inicial(x0)
    //for menor que a tolerância(E), então a raiz é encontrada e xM atribui/recebe o valor de x0 atual, finalizando o loop.
     if( fabs(f(x0))<E){
      xM = x0;
      printf("\n>>> A raiz, respeitando a tolerância solicitada, foi encontrada após %d iterações\n",k);
      return xM;
    } 
    k++;
    //X recebe o valor da derivada no ponto x0 atual
    x = g(x0);
    // printf("\n%d %f %f %f %f \n",k, x0,f(x0),g(x0),x);

    //Caso o valor absoluto de x-x0 seja menor que a tolerância(E),//então xM atribui/recebe o valor de x atual, finalizando o loop.
    if( fabs(x - x0) <E){
      xM = x;
      printf("\n>>> A raiz, respeitando a tolerância solicitada, foi encontrada após %d iterações\n",k);
      return xM;
    }
    //O próximo x0 será o x, o resultado da derivada no ponto x0 anterior. 
    x0 = x;
    
  }while(k <= kMax);//Enquanto o número de iterações é menor ou igual ao numero máximo permitido, o loop continua.

  //Caso a raiz não foi encontrada com os dados fornecidos:
  printf("\n>>> ERRO! \nChegou ao número máximo de iterações sem alcançar a tolerância solicitada. \nSugestões:\n i) Tentar acrescentar mais iterações \n ii) Chutar um valor inicial mais próximo da raiz\n");
  //O retorno seguinte é apenas para identificar o que aconteceu na função.
  //Como é -1, sabe-se que não deu certo e não se pode imprimir a raiz, já que ela não foi encontrada.
  return -1;

}



