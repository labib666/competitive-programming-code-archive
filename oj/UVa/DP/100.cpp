/*
UVa
DP
100 - The 3n+1 problem
04.1.13
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

# define maxm 100001

int score[maxm];

int update (int a)
{
    if (a == 1) return 1;

    if (a < maxm)
    {
        if (score[a] != 0) return score[a];

        if (a % 2 == 0) score[a] = 1 + update (a / 2);
        else score[a] = 1 + update (3*a + 1);
    }

    else
    {
        if (a % 2 == 0) return 1 + update (a / 2);
        else return 1 + update (3*a + 1);
    }
    return score[a];
}

int main()
{
    int a, b, i, j, k, val, mx;
    memset (score, 0, sizeof(score));

    while (scanf("%d %d", &a, &b) != EOF)
    {
        mx = 0;
        i = min(a,b);
        j = max (a,b);
        for (k = i; k <= j; k++)
        {
            val = update(k);
            if (val > mx) mx = val;
        }

        printf ("%d %d %d\n", a, b, mx);
    }

    return 0;
}
