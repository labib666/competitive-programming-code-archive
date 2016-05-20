/*
USACO
dp, GT
1.5.1 - number triangles
25.2.2013
/*
ID: Labib Rashid
LANG: C++
TASK: numtri
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

vector <int> r[1005], dp[1005];

int main()
{
    int n, i, j, x;

    freopen ("numtri.in", "r", stdin);
    freopen ("numtri.out", "w", stdout);

    cin >> n;
    for (i=0;i<n;i++){
        for (j=0;j<=i;j++){
            cin >> x;
            r[i].push_back(x);
        }
    }

    for (i=0;i<n;i++) dp[n-1].push_back(r[n-1][i]);

    for (i=n-2;i>=0;i--)
    {
        for (j=0;j<=i;j++)
        {
            x = max(dp[i+1][j],dp[i+1][j+1]);
            x += r[i][j];
            dp[i].push_back(x);
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}
