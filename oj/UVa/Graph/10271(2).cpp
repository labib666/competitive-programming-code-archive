/*
UVa
10271 - chopsticks
DP + greedy
15.03.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# define inf 1 << 30

using namespace std;

int dp[5010][1010], a[5010];
int N, K;

int solve (int n, int k)
{
    if (k == 0)
        return 0;
    if (n < 2*k)
        return inf;

    if (dp[n][k] != -1)
        return dp[n][k];

    int ans, d = (a[n]-a[n-1])*(a[n]-a[n-1]);

    if ((N-n+1) < 3*(K-k+1)-1) ans = solve(n-1,k);
    else ans = min ( solve(n-1,k) ,solve(n-2,k-1) + d);

    dp[n][k] = ans;
    return ans;
}

int main()
{
    int i, j, k, t;

    cin >> t;
    while (t--)
    {
        cin >> K >> N;
        K += 8;

        for (i=1; i <= N; i++)
            cin >> a[i];

        memset(dp, -1, sizeof (dp));
        cout << solve(N,K) << endl;
    }
    return 0;
}
