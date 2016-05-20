/*
UVa
Dp - coin change
357 - let me count ...
30.1.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

long long int dp[30001];

int main()
{
    int n;
    int coin[] = {1,5,10,25,50};
    memset (dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i=0; i<5; i++)
    {
        for (int j=coin[i];j<=30000;j++)
        {
            dp[j] += dp[j-coin[i]];
        }
    }

    while (cin >> n)
    {
        if (dp[n] != 1) printf ("There are %lld ways to produce %d cents change.\n", dp[n], n);
        else printf ("There is only 1 way to produce %d cents change.\n", n);
    }

    return 0;
}
