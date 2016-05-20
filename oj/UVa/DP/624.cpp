/*
UVa
DP
624 - CD
9.3.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int p[20005];
void pseq (int a, int b) {
    if (a == 0) {
        cout << b - a << " ";
        return;
    }
    pseq (p[a], a);
    cout << b - a << " ";
    return;
}

int main()
{
    int n, m, i, j, k;
    int dp[20005] , w[25];

    while (cin >> n >> m){
        for (i=0; i<m; i++)
            cin >> w[i];

        memset (dp, 0, sizeof (dp));
        memset (p, -1, sizeof (p));
        dp[0] = 1;

        for (i = 0; i < m; i++){
            for (j = n; j >= w[i]; j--){
                if (dp[j] == 0) {
                    dp[j] = 1 & dp[j-w[i]];
                    p[j] = j - w[i];
                }
            }
        }

        int ans;
        for (i = n; i >= 0; i--) {
            if (dp[i]) {
                ans = i;
                break;
            }
        }

        pseq (p[ans], ans);
        cout << "sum:" << ans << endl;
    }
    return 0;
}
