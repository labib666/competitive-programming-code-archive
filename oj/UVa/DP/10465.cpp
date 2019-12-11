/*
UVa
10465 - homer simpson
knapsack
18.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>

using namespace std;

int dp [10005];

int main()
{
    int n[2], m, fin, i, j, ans;
    while (cin >> n[0] >> n[1] >> fin){
        memset (dp, -1, sizeof (dp));
        dp[0] = 0;

        for (i=0; i<2; i++)
        {
            for (j=n[i]; j<= fin; j++)
            {
                if (dp[j-n[i]] != -1)
                    if (dp[j] < dp[j-n[i]] + 1)
                        dp[j] = dp[j-n[i]] + 1;
            }
        }

        for (i = fin; i >= 0; i--)
            if (dp[i] != -1) {
                ans = dp[i];
                m = fin - i;
                break;
            }

        if (m) cout << ans << " " << m << endl;
        else cout << ans << endl;
    }
    return 0;
}
