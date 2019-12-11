/*
UVa
DP
10337 - flight planner
31.1.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <queue>

using namespace std;

int c[10][1005], dp[10][1005], vis[10][1005];
int x, d;

struct edge {
    int x,y,c;
    bool operator < (const edge &p) const{
        return c > p.c;
    }
};

priority_queue <edge> q;
edge ne;

inline void find_min(int a, int b, int t)
{
    q.pop();
    vis[a][b] = 1;
    dp[a][b] = t;

    if (b == d-1) {
        return;
    }

    int m, k;
    for (int i=-1; i<2; i++)
    {
        if (i == -1){
            if (vis[a+i][b+1] == 1) continue;
            if (a == 0) continue;
            k = 20 - c[a][b];
            m = t + k;
        }

        else if (i == 0){
            if (vis[a+i][b+1] == 1) continue;
            k = 30 - c[a][b];
            m = t + k;
        }

        else if (i == 1){
            if (a == 9) continue;
            if (vis[a+i][b+1] == 1) continue;
            k = 60 - c[a][b];
            m = t + k;
        }

        ne.x = a+i;
        ne.y = b+1;
        ne.c = m;

        q.push (ne);
    }
    return;
}

int main()
{
    int t, i, j, k;

    cin >> t;
    for (i=0; i<t; i++)
    {
        memset (dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));

        cin >> x;
        d = x/100;

        for (j=9; j>=0; j--)
            for (k=0; k<d; k++)
                scanf ("%d", &c[j][k]);

        ne.x = 1, ne.y = 1, ne.c = 60 - c[0][0];
        q.push(ne);
        ne.x = 0, ne.y = 1, ne.c = 30 - c[0][0];
        q.push(ne);

        while (!q.empty())
        {
            ne = q.top();
            if (vis[ne.x][ne.y] == 1) {
                q.pop();
                continue;
            }
            find_min(ne.x,ne.y,ne.c);
        }
        //for (j=9; j>=0; j--){
           // for (k=0; k<d; k++)
               // printf ("%d ", dp[j][k]);
               // cout << endl;
        //}

        cout << min (dp[1][d-1] + 20 - c[1][d-1], dp[0][d-1]+ 30 - c[0][d-1])  << endl << endl;
    }

    return 0;
}
