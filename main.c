#include<stdio.h>
int main()
{
    int n, k = 1;
    scanf("%d", &n);
    while (n + 1 != k)
    {
        char a[1000], b[1000];
        int c[1000] = { 0 }, d[1000] = { 0 }, n[1000] = { 0 };
        int lena = 0, lenb = 0, i, lenmin, lenmax;
        scanf("%s %s", a, b);
        while (a[lena++]);
        lena--;
        while (b[lenb++]);
        lenb--;
        for (i = 0; i < lena; i++)
            c[i] = a[lena - 1 - i] - '0';
        for (i = 0; i < lenb; i++)
            d[i] = b[lenb - 1 - i] - '0';

        lenmin = lena < lenb ? lena : lenb;
        lenmax = lena > lenb ? lena : lenb;
        for (i = 0; i < lenmin; i++)
        {
            n[i] += c[i] + d[i];
            if (n[i] >= 10)
            {
                n[i] -= 10;
                n[i + 1]++;
            }
        }
        for (i = lenmin; i < lenmax; i++)
        {

            if (lenmax == lena)
            {
                n[i] += c[i];
                if (n[i] >= 10)
                {
                    n[i] -= 10;
                    n[i + 1]++;
                }
            }
            else
            {
                n[i] += d[i];
                if (n[i] >= 10)
                {
                    n[i] -= 10;
                    n[i + 1]++;
                }

            }
        }
        printf("Case %d:\n", k);
        for (i = lena - 1; i >= 0; i--)
            printf("%d", c[i]);
        printf(" + ");
        for (i = lenb - 1; i >= 0; i--)
            printf("%d", d[i]);
        printf(" = ");
        int f = 1;
        for (i = lenmax; i >= 0; i--)
        {
            if (n[i] != 0)
            {
                f = 0;
            }
            if (f == 0)
            printf("%d", n[i]);
        }
        printf("\n"); printf("\n");
        k++;
    }
    return 0;
}