#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "auxiliares.h"


void div_num(int n)
{
    int a = 0;
    while(n>=100)
    {
        a++;
        n = n - 100;
    }
    if(a > 0)
    printf("\n    %d Nota(s) de CC$ 100,00", a);
    a = 0;

    while(n>=50)
    {
        a++;
        n = n - 50;
    }
    if(a > 0)
    printf("\n    %d Nota(s) de CC$ 50,00", a);
    a = 0;

    while(n>=20)
    {
        a++;
        n = n - 20;
    }
    if(a > 0)
    printf("\n    %d Nota(s) de CC$ 20,00", a);
    a = 0;

    while(n>=10)
    {
        a++;
        n = n - 10;
    }
    if(a > 0)
    printf("\n    %d Nota(s) de CC$ 10,00", a);
    a = 0;

    while(n>=5)
    {
        a++;
        n = n - 5;
    }
    if(a > 0)
    printf("\n    %d Nota(s) de CC$ 5,00", a);
    a = 0;

    while(n>=2)
    {
        a++;
        n = n - 2;
    }
    if(a > 0)
    printf("\n    %d Nota(s) de CC$ 2,00", a);
    a = 0;

    if (n > 0)
    printf("\n    %d Nota de CC$ 1,00", n);
    printf("\n");
}


int neg_insu(int m, int *num)
{
    while(1){
        fflush(stdin);
        system("cls");
        caracteres(60, '='); printf("\n");
        printc("Caixa autom\xA0tico do Banco Laivai", 60); printf("\n");
        caracteres(60, '='); printf("\n");
        printf("\n  Seu saldo \x82 de CC$ %d,00\n", m);
        printf("\n  Digite a quantia desejada (zero ou <ENTER> para sair): ");
        *num = le_inteiro();

        if (*num == 0)
        {
            printf("\n  ** Fim do aplicativo **");
            sleep(3);
            return 1;
        }

        if (*num < 0)
        {
            printf("\n  *** Favor, escrever n\xa3mero inteiro positivo. ***");
            sleep(2);
            continue;
        }

        if(*num > m)
        {
            printf("\n  *** Saldo insuficinte ***");
            sleep(2);
            continue;
        }

        return 0;
        }
}


int main()
{
    while(1)
    {
        srand(time(NULL));
        int num;
        int mony = rand()%999;
        if (mony == 0) mony = rand()%999;
        system("cls");
        caracteres(60, '='); printf("\n");
        printc("Caixa autom\xA0tico do Banco Laivai", 60); printf("\n");
        caracteres(60, '='); printf("\n");
        printf("\n  Seu saldo \x82 de CC$ %d,00\n", mony);
        printf("\n  Digite a quantia desejada (zero ou <ENTER> para sair): ");
        num = le_inteiro();

        // INSIRA O PROCESSAMENTO AQUI

        if (num == 0)
        {
            printf("\n  ** Fim do aplicativo **");
            sleep(3);
            break;
        }

        if (num < 0)
        {
            printf("\n  *** Favor, escrever n\xa3mero inteiro positivo. ***");
            sleep(2);
            int a;
            a = neg_insu(mony, &num);
            if(a) break;
        }

        if (num > mony)
        {
            printf("\n  *** Saldo insuficiente ***");
            sleep(2);
            int a;
            a = neg_insu(mony, &num);
            if(a) break;
        }

        div_num(num);

        printf("\n  ");
        system("pause");
    }
    return 0;
}
