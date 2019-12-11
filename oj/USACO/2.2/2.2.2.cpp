/*
ID: Labib Rashid
LANG: C++
TASK: subset
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# define ll long long

using namespace std;

ll dp [1600];

int main()
{
    ll n, i, j, k, ans, s;

    freopen ("subset.in", "r", stdin);
    freopen ("subset.out", "w", stdout);

    cin >> n;
    if ((n+1)%4 && n%4) {
        cout << 0 << endl;
        return 0;
    }

    for (i = 1; i < 1600; i++)
        dp[i] = 0;
    dp[0] = 1;

    s = ((n+1)*n)/4;

    for (i = 1; i <= n; i++) {
        for (j = s; j >= i; j--)
            dp[j] += dp[j-i];
    }

    ans = dp[s]/2;

    cout << ans <<  endl;

    return 0;
}
