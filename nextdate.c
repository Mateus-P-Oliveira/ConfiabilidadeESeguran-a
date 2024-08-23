#include <stdio.h>

int intevaloVAlido(int d, int m, int a)
{

    if (1 > d || d > 31)
    {
        printf("Dia fora do Intervalo\n");
        return 1;
    }

    if (1 > m || m > 12)
    {
        printf("Mes fora do Intervalo\n");
        return 1;
    }

    if (1812 > a || a > 2012)
    {
        printf("Ano fora do Intervalo\n");
        return 1;
    }

    return 0;
}

void proximaData(int d, int m, int a)
{
    int ver = 1;
    ver = intevaloVAlido(d, m, a);

    if (ver == 1)
    {
        printf("------\n");
    }
    else
    { // Mudar aqui para contar 30 e 31
        d = d + 1;
        if (d > 31)
        {
            d = 1;
            m = m + 1;
            if (m > 12)
            {
                d = 1;
                m = 1;
                a = a + 1;
            }
        }
        printf("%d - %d - %d\n", d, m, a);
    }
}

int main(void)
{

    int d, m, a;

    printf("Insira os valores: \n");
    scanf("%d %d %d", &d, &m, &a);

    proximaData(d, m, a);

    return 0;
}
