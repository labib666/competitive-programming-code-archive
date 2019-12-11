/*
UVa
DP
371 - Ackermann function
30.1.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# define sz 100000

using namespace std;

long long int dp [sz+1];

inline long long int f(long long int a)
{
    if (a > sz)
    {
        if (a % 2 == 1) return 1 + f (3*a + 1);
        else return 1 + f(a/2);
    }

    if (a == 1) return 1;

    if (dp[a] != -1)
        return dp[a];

    long long int k;
    if (a % 2 == 1) k = 1 + f(3*a + 1);
    else k = 1 + f(a/2);

    dp[a] = k;
    return k;
}

int main()
{
    long long int a, b;
    memset (dp, -1, sizeof(dp));

    while (1)
    {
        cin >> a >> b;
        if (a == 0 && b == 0) break;

        if (a > b) swap(a,b);

        long long int max, k, i;
        max = 0;
        k = 0;

        for (i=a; i<=b; i++)
        {
            long long int p;
            if (i == 1)
                p = 3;
            else{
                if (i%2==1) p = f(3*i+1);
                else p = f(i/2);
            }

            if (max < p)
            {
                max = p;
                k = i;
            }
        }

        printf ("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", a,b,k,max);
    }
    return 0;
}
