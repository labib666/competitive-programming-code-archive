/*
UVa
DP - MCM
348 - optimal array multiplication
3.2.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# define inf 1000000007

using namespace std;

struct mat{
    int r,c;
};

mat m[12];
long long int dp[12][12];
int br[12][12][12];

inline void paste (int a, int b, int s1, int s2)
{
    if (a == b) return;

    /*if (a == b-1)
    {
        br[s1][s2][a] ++;
        br[s1][s2][b] --;
        return;
    }*/

    for (int i = a; i <= b; i++)
        br[s1][s2][i] += br[a][b][i];

    return;
}

inline long long int mcm (int a, int b)
{
    if (a == b) {
        return 0;
    }
    if (dp[a][b] != -1) return dp[a][b];

    if (a == b-1) {
        br[a][b][a]++;
        br[a][b][b]--;
        dp[a][b] = m[a].r * m[a].c * m[b].c;
        return dp[a][b];
    }

    int i, mm;
    long long int ans = inf, res;

    for (i = a; i < b; i++)
    {
        res = mcm(a,i) + mcm(i+1,b) + m[a].r * m[i].c * m[b].c;
        if (ans > res)
        {
            ans = res;
            mm = i;
        }
    }
    dp[a][b] = ans;

    br[a][b][a]++;
    br[a][b][b]--;
    paste (a,mm,a,b);
    paste (mm+1,b,a,b);

    return ans;
}

int main()
{
    int n,i,cnt = 0;

    while (1)
    {
        cnt++;
        memset (dp, -1, sizeof(dp));
        memset (br, 0, sizeof(br));

        cin >> n;
        if (n == 0) break;

        for (i=0; i<n; i++) cin >> m[i].r >> m[i].c;
        long long int res = mcm (0,n-1);
        //cout << res << endl;

        printf ("Case %d: ", cnt);
        for (i=0; i<n; i++)
        {
            if (i != 0) cout << " x ";
            if (br[0][n-1][i] > 0)
                for (int j = 0;j<br[0][n-1][i];j++)
                    cout << "(";

            cout << "A" << i+1 ;

            if (br[0][n-1][i] < 0)
                for (int j = 0;j < (-1)*br[0][n-1][i]; j++)
                    cout << ")";
        }
        cout << endl;
        //for (i=0; i<n; i++) cout << br[0][n-1][i] << " ";
        //cout << endl;
    }

    return 0;
}
