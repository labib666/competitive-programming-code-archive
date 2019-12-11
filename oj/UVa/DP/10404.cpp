# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int dp[1000005], mov[15], m;

int main()
{
    int n, i, j, k;

    while (cin >> n >> m){
        for (i = 0; i < m; i++)
            cin >> mov[i];

        memset (dp, 0, sizeof (dp));
        dp[0] = 1;

        for (j = 0; j <= n; j++)
        {
            for (i = 0; i < m; i++)
            {
                if (mov[i]+j > n || dp[j]) continue;

                if (!dp[j+mov[i]]){
                    dp[j+mov[i]] = 1;
                }
            }
            //cout << dp[j] << " j >> " << j << endl;
        }

        if (dp[n]) cout << "Stan wins\n";
        else cout << "Ollie wins\n";
    }

    return 0;
}
