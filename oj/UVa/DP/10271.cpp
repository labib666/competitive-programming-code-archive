/*
UVa
10271 - chopsticks
DP + greedy
15.03.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# define inf 1000000007

using namespace std;

int a[5010], f[1010], g[1010];

int main ()
{
    int t, i, j, k, N, K;

    cin >> t;
    while (t--)
    {
        cin >> K >> N;
        K += 8;

        for (i = 0; i <= K; i++)
            f[i] = g[i] = 0x33333333;
        f[0] = g[0] = 0;

        for (i = 0; i < N; i++)
            cin >> a[i];

        for (i = N-1; i >= 0; i--)
        {
            for (j = K; j > 0; j--)
            {
                k = f[j];

                if (N-i >= 3*j)
                    if (f[j] > g[j-1] + (a[i]-a[i+1])*(a[i]-a[i+1]))
                        f[j] = g[j-1] + (a[i]-a[i+1])*(a[i]-a[i+1]);

                g[j] = k;
            }
        }
        cout << f[K] << endl;
    }
    return 0;
}
