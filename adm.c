#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#ifdef __linux__
#define SISTEMA 0 // Linux
#endif

#ifdef _WIN32
#define SISTEMA 1 // Windows
#endif

void limpaTela(){
    if (SISTEMA == 0)
        system("clear");
    else
        system("cls");
}


void pausa(){
    if (SISTEMA == 0)
        system("read -p \"Pressione <ENTER> para continuar...\"");
    //system("sleep 5 | echo Processando...");
    else
        system("pause");
}


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
      printf("%.2f\n",fluxo[i] / pow((1 + taxInter),i+1));
    }

    return vpl;
}

float payback(int t,float taxInter,float inIni){
    int i;
    float fluxo[t];
    float soma=0;
    float vpl=0;
    float payback=0;
    float acumulado[t+1];

    for(i=0;i<t;i++){
        printf("\nDigite o Fluxo %d: ",i+1);
        scanf("%f",&fluxo[i]);
    }

    vpl +=inIni;
    acumulado[0]=inIni;
    for(i=0;i<t;i++){
      vpl += fluxo[i] / pow((1 + taxInter),i+1);
      acumulado[i+1] = vpl;
      if(acumulado[i+1]>0){
        payback=(i)+((abs(acumulado[i]))/(fluxo[i] / pow((1 + taxInter),i+1)));
        return payback;
      }
    }

    payback=(i)+((abs(acumulado[i]))/(fluxo[i] / pow((1 + taxInter),i+1)));
    return payback;


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
    limpaTela();
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
        pausa();
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
        pausa();
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
        pausa();
      break;
      case 4:
        printf("\nDigite Qtd Periodos: ");
        scanf("%d",&t);
        printf("\nDigite a taxa Interna: ");
        scanf("%f",&taxInter);
        printf("\nDigite Investimento Inicial: ");
        scanf("%f",&inIni);

        vpl = payback(t,taxInter,inIni);
        if(vpl<t){
          printf("\nPayback Viavel: %.2f\n",vpl);
        }else if(vpl=t){
          printf("\nPayback Indiferente: %.2f\n",vpl);
        }else{
          printf("\nPayback Inviavel: %.2f\n",vpl);
        }
        pausa();
      break;
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
