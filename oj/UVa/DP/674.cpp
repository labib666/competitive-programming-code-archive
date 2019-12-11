/*
UVa
DP
674 - Coin Change
07.01.13
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    int v[] = {1,5,10,25,50};
    int dp[7501];
    memset (dp, 0, sizeof(dp));
    dp[0] = 1;


    for (a=0; a<5; a++)
    {
        for (b=v[a]; b<=7500; b++)
            dp[b] += dp[b - v[a]];
    }

    while (scanf ("%d", &n) != EOF)
        printf ("%d\n", dp[n]);

    return 0;
}
