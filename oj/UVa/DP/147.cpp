/*
UVa
DP
147 - Dollars
07.01.13
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    int v[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
    long long int dp[30001];
    memset (dp, 0, sizeof(dp));
    dp[0] = 1;


    for (a=0; a<11; a++)
    {
        for (b=v[a]; b<=30000; b++)
            dp[b] += dp[b - v[a]];
    }

    while (1){
        scanf ("%d.%d", &a,&b);
        if(a==0 && b==0 ) break;
        n = 100*a + b;
        double m = n;
        printf ("%6.2lf%17lld\n", m/100, dp[n]);
    }

    return 0;
}

