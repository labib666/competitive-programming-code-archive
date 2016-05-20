/*
UVa
DP
116 - UTSP
22.1.13
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <vector>

using namespace std;

long long int s[11][110];
long long int dp[11][110];
long long int path[11][110];
long long int m,n,x,cancel,assure;
vector <long long int> final;

void dfs (long long int a)
{
    x--;
    if (x == 0)
    {
        if (final[x] < a)
        {
            cancel = 1;
        }
        else if (final[x] > a)
        {
            final[x] = a;
            assure = 1;
        }
        cout << a+1 << " ";
        x++;
        return;
    }
    cout << a+1 << " ";
    dfs(path[a][x]);

    if (assure == 1) {
        final[x] = a;
        x++;
        return;
    }
    else if (cancel == 1)
    {
        x++;
        return;
    }

    if (final[x] < a)
    {
        cancel = 1;
    }
    else if (final[x] > a)
    {
        final[x] = a;
        assure = 1;
    }

    x++;
    return;
}

int main()
{
    long long int i,j;

    while( scanf("%lld %lld", &m, &n) != EOF){
        memset (s, 0, sizeof(s));
        memset(dp, -1, sizeof(dp));
        memset(path, 0, sizeof(path));

        for (i = 0; i<m; i++)
            for (j = 0; j<n; j++)
                scanf("%lld", &s[i][j]);

        for (i = 0; i<m; i++) dp[i][0] = s[i][0];

        for (i = 0; i<n-1; i++)
        {
            for (j=0; j<m; j++)
            {
                // #1
                long long int cost = dp[j][i] + s[j][i+1];
                if (j != 0) {
                    if (cost < dp[j][i+1]) {
                        dp[j][i+1] = cost;
                        path[j][i+1] = j;
                    }
                }
                else {
                    dp[j][i+1] = cost;
                    path[j][i+1] = j;
                }

                // #2
                if (j != 0) {
                    cost = dp[j][i] + s[j - 1][i+1];
                    if(cost < dp[j-1][i+1]) {
                        dp[j-1][i+1] = cost;
                        path[j-1][i+1] = j;
                    }
                }

                else {
                    cost = dp[j][i] + s[m-1][i+1];
                    dp[m-1][i+1] = cost;
                    path[m-1][i+1] = j;
                }

                // #3
                if (j != m-1) {
                    cost = dp[j][i] + s[j + 1][i+1];
                    if (j == m-2)
                    {
                        if (cost < dp[j+1][i+1]) {
                            dp[j+1][i+1] = cost;
                            path[j+1][i+1] = j;
                        }
                    }
                    else {
                        dp[j+1][i+1] = cost;
                        path[j+1][i+1] = j;
                    }
                }

                else {
                    cost = dp[j][i] + s[0][i+1];
                    if (cost < dp[0][i+1]) {
                        dp[0][i+1] = cost;
                        path[0][i+1] = j;
                    }
                }
            }
        }

        cout << endl;
        for (i = 0; i<m; i++)
        {
            for (j=0; j<n; j++)
                cout << dp[i][j] << " " ;
            cout << endl;
        }
        cout << endl;

        cout << endl;
        for (i = 0; i<m; i++)
        {
            for (j=0; j<n; j++)
                cout << path[i][j] << " " ;
            cout << endl;
        }
        cout << endl;

        long long int mn = dp[0][n-1];
        for (i=0;i<m; i++)
        {
            if (mn > dp[i][n-1]) {
                mn = dp[i][n-1];
            }
        }

        for (i=0; i<=100; i++)final.push_back(2100000000);
        x = n;
        cout << endl;
        for (i=0;i<m; i++){
            if (mn == dp[i][n-1]){
                cout << i+1 << " >> ";
                assure = 0;
                cancel = 0;
                dfs (i);
                cout << endl;
            }
        }

        for (i=0;i<n - 1; i++) cout << final[i] + 1 << " ";
        cout << final[i]+1 << endl;

        cout << mn << endl;

        final.clear();
    }

    return 0;
}
