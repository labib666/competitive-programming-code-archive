/*
UVa
dp, graph, dfs
11545 - avoiding jungle in the dark
19.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <vector>
# define inf 0x33333333

using namespace std;

int dp[1005][25][18];
string s;

int solve (int a, int t, int r)
{
    if (s[a] == 'D')
        return 0;

    if (dp[a][t][r] != -1)
        return dp[a][t][r];

    int a1, a2, a3;
    a1 = a2 = a3 = inf;

    if (s[a] == '*'){
        if (t <= 6 || t >= 18) {
            dp[a][t][r] = inf;
            return inf;
        }
        if (r != 0)
            a1 = 1 + solve (a+1, (t + 1)%24, r-1);
        else if ((t+8)%24 > 6 && (t+8)%24 < 18)
            a2 = 9 + solve (a+1, (t + 9)%24, 15);

        dp[a][t][r] = min (a1,a2);
        return dp[a][t][r];
    }

    if (r != 0) a1 = 1 + solve (a+1, (t + 1)%24, r-1);
    a2 = 9 + solve (a+1, (t + 9)%24, 15);
    a3 = 17 + solve (a+1, (t + 17)%24, 15);

    dp[a][t][r] = min (a1, min (a2,a3));
    return dp[a][t][r];
}

int main ()
{
    int t, i, j, k, cnt = 1;

    cin >> t;
    while (cnt <= t){
        cin >> s;

        memset(dp, -1, sizeof (dp));
        int ans = solve(0, 6, 16);

        if (ans >= inf) printf ("Case #%d: -1\n", cnt);
        else  printf ("Case #%d: %d\n", cnt, ans);

        cnt++;
    }
    return 0;
}
