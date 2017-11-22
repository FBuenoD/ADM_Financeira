#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float valorFuturo(float vp, float i, int t){
 float vf=0;
 float num = 1+i;
    vf = vp * pow((1 + i),t);
 return vf;
}

float valorPresente(float vf, float i, int t){
 float vp=0;
 float num = 1+i;
    vp = vf / pow((1 + i),t);
 return vp;
}

float valorPresenteLiquido(int t,float taxInter,float inIni){
    int i;
    float fluxo[t];
    float soma=0;
    float vpl=0;

    for(i=0;i<t;i++){
        printf("\nDigite o Fluxo %d: ",i+1);
        scanf("%f",&fluxo[i]);
    }

    vpl +=inIni;

    for(i=0;i<t;i++){
      vpl += fluxo[i] / pow((1 + taxInter),i+1);
    }

    return vpl;
}

float payback(int t,float taxInter,float inIni){
    int i;
    float fluxo[t];
    float soma=0;
    float vpl=0;
    float payback=0;
    float acumulado=0;

    for(i=0;i<t;i++){
        printf("\nDigite o Fluxo %d: ",i+1);
        scanf("%f",&fluxo[i]);
    }

    vpl +=inIni;
    acumulado=inIni;
    for(i=0;i<t;i++){
      vpl += fluxo[i] / pow((1 + taxInter),i+1);
      acumulado = fluxo[i]-acumulado;
      if(acumulado>0){
        payback=((i-1)+((abs(fluxo[i-1] / pow((1 + taxInter),i-1))))/fluxo[i]);
        return payback;
      }
    }
}

void menu(){
    printf("\n########################################");
    printf("\n########   Calculadora ADM  ############");
    printf("\n##### 1 - Valor Futuro            ######");
    printf("\n##### 2 - Valor Presente          ######");
    printf("\n##### 3 - Valor Presente Liquido  ######");
    printf("\n##### 4 - Payback                 ######");
    printf("\n##### 0 - Sair                    ######");
    printf("\n########################################");
}

int main(){

    float vp, i,vf=0;
    int t;
    int inte;
    float taxInter, inIni;
    float vpl;

    while(inte!=0){
    system("cls");
    menu();
    printf("\nDigite uma Opcao: ");
    scanf("%d",&inte);

    switch(inte){
      case 1:
        printf("\nDigite VP: ");
        scanf("%f",&vp);
        printf("\nDigite %: ");
        scanf("%f",&i);
        printf("\nDigite Tempo: ");
        scanf("%d",&t);

        vf = valorFuturo(vp,i,t);

        printf("\nValor Final %.2f", vf);
        system("pause");
      break;
      case 2:
        printf("\nDigite VF: ");
        scanf("%f",&vf);
        printf("\nDigite %: ");
        scanf("%f",&i);
        printf("\nDigite Tempo: ");
        scanf("%d",&t);

        vp = valorPresente(vf,i,t);

        printf("\nValor Presente %.2f", vp);
        system("pause");
      break;
      case 3:
        printf("\nDigite Qtd Periodos: ");
        scanf("%d",&t);
        printf("\nDigite a taxa Interna: ");
        scanf("%f",&taxInter);
        printf("\nDigite Investimento Inicial: ");
        scanf("%f",&inIni);

        vpl = valorPresenteLiquido(t,taxInter,inIni);

        printf("\nValor Presente Liquido: %.2f\n",vpl);
        system("pause");
      break;
      case 4:
        printf("\nDigite Qtd Periodos: ");
        scanf("%d",&t);
        printf("\nDigite a taxa Interna: ");
        scanf("%f",&taxInter);
        printf("\nDigite Investimento Inicial: ");
        scanf("%f",&inIni);

        vpl = payback(t,taxInter,inIni);

        printf("\nPayback: %.2f\n",vpl);
        system("pause");

      case 0:
        return 0;
      break;
      default:
          printf("Opcao Invalida!!");
      break;
      }

    }



 return 0;
}
