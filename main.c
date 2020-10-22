/*
  
  Aluno: André Geraldo.
  
  Professor: Dr. Valtemir Emerencio do Nascimento.

  Objetivo: Implementar o método de Newton-Raphson, para determinação de raízes, na disciplina de Cálculo Numérico.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 2.71828182845904523536028747135266249775724709369995

//Cabeçalho das funções utilizadas
double f(float x);
double fLinha(float x);
double g(float x);
float newtonRaphson(float x0,float E, int iMax);

int main(void) {

  float x0,E,iMax;
  printf("\n<><><><><><><><><><><><><><><><><><><><><><><>><><><><><>");
  printf("\nPROGRAMA PARA ENCONTRAR RAÍZES COM O MÉTODO DE NEWTON-RAPHSON\n");
  printf("<><><><><><><><><><><><><><><><><><><><><><><>><><><><><>\n");
  printf("\nPor favor, digite o VALOR INICIAL(x0), TOLERÂNCIA(E) e NÚMERO MÁX DE ITERAÇÕES(iMax), respectivamente, dando espaço a cada valor solicitado:\n");
  printf("-> ");
  scanf("%f %f %f",&x0,&E,&iMax);

  //Result recebe o valor retornado da função com o método de Newton-Rapson.
  float result = newtonRaphson( x0, E, iMax);

  //caso seja diferente de -1, significa que o valor retornado é realmente o valor da raiz aproximada encontrada
  if(result != -1){
      printf("\n>> Raiz Aproximada Encontrada: %.15f\n",result);
  }
  printf("\n-------------------------------------------------\n");
 

  return 0;
}

// double f(float x){
//   return 2*x-sin(x)-4; 
// }

// //Derivada da F fornecida para o problema
// double fLinha(float x){
//   return  2 - cos(x);
// }

//Função fornecida para o problema. (A mesma do slide)
double f(float x){
  return (pow(e,-x) - x); 
}

//Derivada da F fornecida para o problema
double fLinha(float x){
  return  (-pow(e,-x) - 1);
}

//Fórmula de Newton-Raphson, Contendo a fração 
//entre a função e a sua derivada.
double g(float xi){
 //O valor de xi em questão é sempre o anterior ou atual 
 //e o retorno do cálculo resulta no Xi+1 (posterior)
  return   xi - (f(xi)/fLinha(xi));
}

//Função contendo o método de Newton-Raphson.
/*
Parametros:
  x0 = Aproximação inicial(Xi)
  E = Tolerância/precisão fornecida
  iMax = Numero máximo de iterações solicitadas

Variáveis:
  x = Raiz aproximada posterior(Xi+1)
  xM = Resultado final da raiz aproximada
  i = Contador de iterações
*/
float newtonRaphson(float x0,float E, int iMax){
  
  int i = 0;
 
  float xM,x = 0.0;
  printf("\n--------------------RESULTADO--------------------\n");
  // printf("\n Valor das funções e estimativas de Xi a cada iteração:\n");
  // printf("\nk     Xi      F(xi)         F'(xi)      Xi+1 ");
  do{
    
    // printf("\n%d  %.8f %.8f   %.8f  %.20f \n",i, x0,f(x0),fLinha(x0),x);
    // printf("\n|f(x0)|:%.30f\n",fabs(f(x0)) );
    /*
    Critério de parada:
      Se o valor absoluto da função no ponto de aproximação inicial(x0), ou o atual
      for menor que a tolerância(E), então a raiz é encontrada e xM atribui/recebe o valor de x0 atual, finalizando o loop.
    */

     if( fabs(f(x0))<E){
      xM = x0;
      printf("\n>>> A raiz, respeitando a tolerância solicitada, foi ENCONTRADA após %d iterações.\n",i);
      return xM;
    } 

    i++;

    //X(Xi+1) recebe o valor da derivada no ponto x0 atual(Xi)
    //Que é o valor da raiz da reta tangente gerada
    x = g(x0);

   
    // printf("\n%d  %.8f %.8f   %.8f  %.20f \n",i, x0,f(x0),fLinha(x0),x);
    // printf("\n|(x - x0)|:%.30f\n",fabs(x - x0) );
    // printf("\n - - - - - - - - - - - - \n");

    /*Segundo critério de parada:
      Caso o valor absoluto de x-x0(distância) seja menor que a tolerância(E),então xM atribui/recebe o valor de x atual, finalizando o loop.*/
  
    if( fabs(x - x0) <E){
      xM = x;
      printf("\n>>> A raiz, respeitando a tolerância solicitada, foi ENCONTRADA após %d iterações.\n",i);
      return xM;
    }
    //O próximo x0(Xi) será o x(Xi+1), o resultado da derivada, ou seja, a raiz aproximada com a reta tangete no ponto x0 anterior. 
    x0 = x;

  }while(i <= iMax);//Enquanto o número de iterações é menor ou igual ao numero máximo permitido, o loop continua.

  //Caso a raiz não foi encontrada com os dados fornecidos:
  printf("\n>>> ERRO! \nO método chegou ao número máximo de iterações sem alcançar a tolerância solicitada. \nSugestões:\n i) Tentar acrescentar um número MAIOR de iterações(Recomenda-se sempre um número maior do que o necessário); \n ii) Chutar um valor inicial mais PRÓXIMO da raiz.\n");
  
  //O retorno seguinte é apenas para identificar o que aconteceu na função.
  //Como é -1, sabe-se que não deu certo e não se pode imprimir a raiz, já que ela não foi encontrada.
  return -1;


}

