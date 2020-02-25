#include<stdio.h>
#include<stdlib.h>

void mostrarValores(int x0,int x1,int x2,int y0,int y1,int y2);
int mmc(int x1,int x2,int x3);
int main(){
    int L0,L1,L2, Ld0,Ld1,Ld2; ///L0,L1,L2 são os númeradores da função, Ld0,Ld1,Ld2 são os denominadores da função
    int x0,x1,x2; ///os valores de x
    int y0,y1,y2; ///os valores de y
    int P0=0,P1=0,P2=0; ///o valor do polinômio separado por x0,x1,x2
    int XL0=0,XL1=0,XL2=0; ///são variáveis usadas para cacular o valor de X, como x+x..
    int MMC=0; ///para armazenar o valor do mmc
    int XX0=0,XX1=0,XX2=0; ///para fazer a soma dos x²
    int MC1=0,MC2=0; ///Armazena a simplificação de mmc

    printf("#### METODO DE LAGRANGE ####\n");
    printf("Digite os 3 valores de X separados por espaco:\n");
    scanf("%d %d %d",&x0, &x1, &x2);
    printf("Digite os 3 valores de Y separados por espaco:\n");
    scanf("%d %d %d",&y0, &y1, &y2);
    mostrarValores(x0,x1,x2,y0,y1,y2);

    ///L0///
    L0 = - x1 * (-x2);
    Ld0 = (x0 - x1) * (x0 - x2);
    if(x1!=0){
        XL0 = - x1;
    }
    if(x2!=0){
        XL0+= - x2;
    }
    if(L0==0){ ///verifica se terá número normal
        if(XL0==1){ ///verifica se terá número com X
            printf("L0 = (x^2 + x)/%d\n\n",Ld0);
        }else{
            printf("L0 = (x^2 + (%dx))/%d\n\n",XL0,Ld0);
        }
    }else{
        if(XL0==1){
            if(L0>0){
                printf("L0 = (x^2 + x + %d)/%d\n\n",L0,Ld0);
            }else{
                printf("L0 = (x^2 + x %d)/%d\n\n",L0,Ld0);
            }
        }else{
            if(L0>0){
                printf("L0 = (x^2 + (%dx) + %d)/%d\n\n",XL0,L0,Ld0);
            }else{
                printf("L0 = (x^2 + (%dx) %d)/%d\n\n",XL0,L0,Ld0);
            }
        }
    }

    ///L1///
    L1 = - x0 * (-x2);
    Ld1 = (x1 - x0) * (x1 - x2);
    if(x0!=0){
        XL1 = - x0;
    }
    if(x2!=0){
        XL1+= - x2;
    }
    if(L1==0){ ///verifica se terá número normal
        if(XL1==1){ ///verifica se terá número com x
            printf("L1 = (x^2 + x)/%d\n\n",Ld1);
        }else{
            printf("L1 = (x^2 + (%dx))/%d\n\n",XL1,Ld1);
        }
    }else{
        if(XL1==1){
            if(L1>0){
                printf("L1 = (x^2 + x + %d)/%d\n\n",L1,Ld1);
            }else{
                printf("L1 = (x^2 + x %d)/%d\n\n",L1,Ld1);
            }
        }else{
            if(L1>0){
                printf("L1 = (x^2 + (%dx) + %d)/%d\n\n",XL1,L1,Ld1);
            }else{
                printf("L1 = (x^2 + (%dx) %d)/%d\n\n",XL1,L1,Ld1);
            }
        }
    }

    ///L2///
    L2 = - x0 * (-x1);
    Ld2 = (x2 - x0) * (x2 - x1);
    if(x0!=0){
        XL2 = - x0;
    }
    if(x1!=0){
        XL2+= - x1;
    }
    if(L2==0){ ///verifica se terá número normal
        if(XL2==1){ ///verifica se terá número com x
            printf("L2 = (x^2 + x)/%d\n\n",Ld2);
        }else{
            printf("L2 = (x^2 + (%dx))/%d\n\n",XL2,Ld2);
        }
    }else{
        if(XL2==1){
            if(L2>0){
                printf("L2 = (x^2 + x + %d)/%d\n\n",L2,Ld2);
            }else{
                printf("L2 = (x^2 + x %d)/%d\n\n",L2,Ld2);
            }
        }else{
            if(L2>0){
                printf("L2 = (x^2 + (%dx) + %d)/%d\n\n",XL2,L2,Ld2);
            }else{
                printf("L2 = (x^2 + (%dx) %d)/%d\n\n",XL2,L2,Ld2);
            }
        }
    }

    printf("P2(x) = %d * [(x^2 + (%dx) + (%d))/%d] + (%d) * [(x^2 + (%dx) + (%d))/%d] + (%d) * [(x^2 + (%dx) + (%d))/%d]\n",
           y0,XL0,L2,Ld0,y1,XL1,L1,Ld1,y2,XL2,L2,Ld2);
    ///reuso das variaveis XL0,XL1,XL2
    XL0 *= y0; ///o valor de X multiplicado pelo y
    P0 = y0 * L0; ///multiplica o y por um possível valor contido em L

    XL1 *= y1; ///o valor de X multiplicado pelo y
    P1 = y1 * L1; ///multiplica o y por um possível valor contido em L

    XL2 *= y2; ///o valor de X multiplicado pelo y
    P2 = y2 * L2; ///multiplica o y por um possível valor contido em L

    MMC = mmc(Ld0,Ld1,Ld2); ///recebe o mmc da função

    ///Atualiza os Ld (denominadores) com o novo valor, depois de dividir pelo mmc
    if(MMC>=Ld0){
        Ld0 = MMC/Ld0;
    }else{
        Ld0 = Ld0/MMC;
    }
    if(MMC>=Ld1){
        Ld1 = MMC/Ld1;
    }else{
        Ld1 = Ld1/MMC;
    }
    if(MMC>=Ld2){
        Ld2 = MMC/Ld2;
    }else{
        Ld2 = Ld2/MMC;
    }

    XX0 = y0 * Ld0; ///recebe o valor de x²
    XL0 *= Ld0; ///atualiza o valor de XL que significa o valor de X normal, multiplicando pelo mmc
    P0 *= Ld0;

    XX1 = y1 * Ld1; ///recebe o valor de x²
    XL1 *= Ld1; ///atualiza o valor de XL que significa o valor de X normal, multiplicando pelo mmc
    P1 *= Ld1;

    XX2 = y2 * Ld2; ///recebe o valor de x²
    XL2 *= Ld2; ///atualiza o valor de XL que significa o valor de X normal, multiplicando pelo mmc
    P2 *= Ld2;
    printf("P2(x) = [%dx^2 + (%dx) + (%d) + (%dx^2) + (%dx) + (%d) + (%dx^2) + (%dx) + (%d)]/%d\n",XX0,XL0,P0,XX1,XL1,P1,XX2,XL2,P2,MMC);

    ///Realiza a soma de tudo
    XX2 = XX0 + XX1 + XX2;
    XL2 = XL0 + XL1 + XL2;
    P2 = P0 + P1 + P2;
    printf("P2(x) = (%dx^2 %dx + (%d))/%d\n",XX2,XL2,P2,MMC);

    if(XX2%2==0 && MMC%2==0){ ///Tenta fazer uma simplificação por 2
        XX2 = XX2/2;
        MC1 = MMC/2;
        MC2 = MMC;
    }
    if(XL2%2==0 && MMC%2==0){ ///Tenta fazer uma simplificação por 2
        XL2 = XL2/2;
        MC2 = MMC/2;
        if(MC1==0){
            MC1 = MMC;
        }
    }
    if(XX2%3==0 && MMC%3==0){ ///Tenta fazer uma simplificação por 3
        XX2 = XX2/3;
        MC1 = MMC/3;
        if(MC2==0){
            MC2 = MMC;
        }
    }
    if(XL2%3==0 && MMC%3==0){ ///Tenta fazer uma simplificação por 3
        XL2 = XL2/3;
        MC2 = MMC/3;
        if(MC1==0){
            MC1 = MMC;
        }
    }

    ///Mostra o último resultado
    if(P2!=0){ ///verifica se o número normal não é zero
//        if(P2 >= MMC){ ///verifica se o número normal não é igual ou maior do valor do mmc
//            P2 = P2/MMC;
//        }
        if(P2>0){ ///faz uma verificação se o número normal é positivo
            printf("P2(x) = (%dx^2)/%d %dx/%d + %d\n",XX2,MC1,XL2,MC2,P2/MMC); ///se o mmc for maior que P2, é necessário remover a divisão
        }else{
            printf("P2(x) = (%dx^2)/%d %dx/%d %d\n",XX2,MC1,XL2,MC2,P2/MMC); ///se o mmc for maior que P2, é necessário remover a divisão
        }
    }else{
        printf("P2(x) = (%dx^2)/%d %dx/%d\n",XX2,MC1,XL2,MC2);
    }
    return 0;
}
void mostrarValores(int x0,int x1,int x2,int y0,int y1,int y2){
    printf("\nX | %d  %d  %d",x0,x1,x2);
    printf("\nY | %d  %d  %d\n\n",y0,y1,y2);
}
int mmc(int x1,int x2,int x3){
    int result=1;
    if(x1<0){
        x1 = -x1;
    }
    if(x2<0){
        x2 = -x2;
    }
    if(x3<0){
        x3 = -x3;
    }
    while(x1!=1 || x2!=1 || x3!=1){
        if(x1==25 || x1==5){
            x1 = x1/5;
            result*= 5;
        }
        if(x2==25 || x2==5){
            x2 = x2/5;
            result*= 5;
        }
        if(x3==25 || x3==5){
            x3 = x3/5;
            result*= 5;
        }
        if(x1==7){
            x1 = x1/7;
            result*= 7;
        }
        if(x2==7){
            x2 = x2/7;
            result*= 7;
        }if(x3==7){
            x3 = x3/7;
            result*= 7;
        }
        if(x1%2==0 && x2%2==0 && x3%2==0){
            x1 = x1/2;
            x2 = x2/2;
            x3 = x3/2;
            result*= 2;
        }else if(x1%2==0 && x2%2==0){
            x1 = x1/2;
            x2 = x2/2;
            result*= 2;
        }else if(x1%2==0 && x3%2==0){
            x1 = x1/2;
            x3 = x3/2;
            result*= 2;
        }else if(x2%2==0 && x3%2==0){
            x2 = x2/2;
            x3 = x3/2;
            result*= 2;
        }else if(x1%2==0 && (x2%2!=0 || x3%2!=0)){
            x1 = x1/2;
            result*= 2;
        }else if(x2%2==0 && (x1%2!=0 || x3%2!=0)){
            x2 = x2/2;
            result*= 2;
        }else if(x3%2==0 && (x1%2!=0 || x2%2!=0)){
            x3 = x3/2;
            result*= 2;
        }else if(x1%3==0 && x2%3==0 && x3%3==0){
            x1 = x1/3;
            x2 = x2/3;
            x3 = x3/3;
            result*= 3;
        }else if(x1%3==0 && x2%3==0){
            x1 = x1/3;
            x2 = x2/3;
            result*= 3;
        }else if(x1%3==0 && x3%3==0){
            x1 = x1/3;
            x3 = x3/3;
            result*= 3;
        }else if(x2%3==0 && x3%3==0){
            x2 = x2/3;
            x3 = x3/3;
            result*= 3;
        }else if(x1%3==0 && (x2%3!=0 || x3%3!=0)){
            x1 = x1/3;
            result*= 3;
        }else if(x2%3==0 && (x1%3!=0 || x3%3!=0)){
            x2 = x2/3;
            result*= 3;
        }else if(x3%3==0 && (x1%3!=0 || x2%3!=0)){
            x3 = x3/3;
            result*= 3;
        }
    }
    return result;
}
