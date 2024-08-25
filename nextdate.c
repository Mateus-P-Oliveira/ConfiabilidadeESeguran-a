#include <stdio.h>

int intervaloValido(int d, int m, int a)
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

int diasNoMes(int m, int a)
{
    switch (m)
    {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
            return 29; // Ano bissexto
        else
            return 28;
    default:
        return 31;
    }
}

void proximaData(int d, int m, int a)
{
    int ver = intervaloValido(d, m, a);

    if (ver == 1)
    {
        printf("------\n");
    }
    else
    {
        d = d + 1;
        if (d > diasNoMes(m, a))
        {
            d = 1;
            m = m + 1;
            if (m > 12)
            {
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
