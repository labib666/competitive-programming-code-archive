// The path finding and other things need fixing
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
#define inf 100000000000ll
using namespace std;

long long int s[11][110];
long long int dp[11][110];
long long int path[11][110];
long long int m,n;

inline void find_path(long long int r,int c)
{
    int next_row;
    //c--;

    if(c != n-1)
    {
        cout << r+1 << " ";
        find_path(path[r][c],c+1);
        return;
    }

    cout << r+1 << endl;

    return;
}

int main()
{
    long long int i,j,k;

    while( scanf("%lld %lld", &m, &n) != EOF){
        //memset (s, 0, sizeof(s));
        //memset(dp, -1, sizeof(dp));
        memset(path,0, sizeof(path));

        for (i = 0; i<m; i++)
            for (j = 0; j<n; j++)
                scanf("%lld", &s[i][j]);

        // Watch this portion:
        for (i = 0; i<m; i++) dp[i][n-1] = s[i][n-1];

        long long from_row;
        long long cost;

        for(i = n-2 ; i>=0 ; i--)
        {
            for(j = 0; j<m ; j++)
            {
                dp[j][i] = inf;
                path[j][i] = inf;
                for(k = -1; k<2 ; k++)
                {
                    from_row = (j+k+m)%m;
                    cost = dp[from_row][i+1] + s[j][i];
                    if(cost == dp[j][i])
                        path[j][i]  = min(path[j][i],from_row);
                    else
                    {
                        if(cost<dp[j][i])
                        {
                            dp[j][i] = cost;
                            path[j][i]= from_row;
                        }
                    }
                }
            }
        }
        // Eituku bujho ki na bolo?

        /// ager shob n-1 er jay gay 0 bosbe.
        /// age jevabe path print korso, ebar ulta vabe korba.
        /// dhoro age jodi column 1,2,3....., n giye thako, ekhon n, n-1,....3,2,1 jabe.
        // path prininting ta nije change kore nio.
        long long int mn = dp[0][0];
        for (i=0;i<m; i++)
        {
            if (mn > dp[i][0]) {
                mn = dp[i][0];
            }
        }

        for (i=0;i<m; i++){
            if (mn == dp[i][0]){
                find_path (i,0);
                break;
            }
        }
        cout << mn << endl;

    }

    return 0;
}
