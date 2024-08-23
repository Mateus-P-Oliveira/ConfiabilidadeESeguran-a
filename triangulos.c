#include <stdio.h>

int verificaValoresValidos(int a, int b, int c)
{

    if (1 > a || a > 200)
    {
        printf("A nao e um valor valido\n");
        return 1;
    }

    if (1 > b || b > 200)
    {
        printf("B nao e um valor valido\n");
        return 1;
    }

    if (1 > c || c > 200)
    {
        printf("C nao e um valor valido\n");
        return 1;
    }

    return 0;
}

void triangulosTeste(int a, int b, int c)
{
    if (a == b && b == c)
    {
        printf("Triangulo Equilátero\n");
    }
    else if (a == b || b == c || a == c)
    {
        printf("Triangulo Isósceles");
    }
    else
    {
        printf("Triangulo Escaleno\n");
    }
}

void verificaTriangulo(int a, int b, int c)
{

    int ver = 1;

    ver = verificaValoresValidos(a, b, c);

    if (ver == 0)
    {
        if ((a + b) <= c || (a + c) <= b || (b + c) <= a)
        {
            printf("Nao é um triangulo\n");
        }
        else
        {
            triangulosTeste(a, b, c);
        }
    }
    else
    {
        printf("Valores Nao validos \n");
    }
}

int main(void)
{

    int a, b, c;

    printf("Insira os valores: \n");
    scanf("%d %d %d", &a, &b, &c);

    verificaTriangulo(a, b, c);

    return 0;
}
