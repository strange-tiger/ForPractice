#include <stdio.h>

void Print(int n, int r, int c)
{
    if (n == 0)
    {
        putchar('*');

        return;
    }

    // (r / 3^0) % 3 == 1 && (c / 3^0) % 3 == 1 or
    // (r / 3^1) % 3 == 1 && (c / 3^1) % 3 == 1 or
    // (r / 3^2) % 3 == 1 && (c / 3^2) % 3 == 1 or
    // ...
    // (r / 3^(K - 1)) % 3 == 1 && (c / 3^(K - 1)) % 3 == 1
    if ((r / n) % 3 == 1 && (c / n) % 3 == 1)
        putchar(' ');
    else
        Print(n / 3, r, c);
}

int main(void)
{
    int N;
    scanf_s("%d", &N);

    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < N; ++c)
        {
            Print(N, r, c);
        }
        puts("");
    }
}   // 경일아카데미 최선문 교수님