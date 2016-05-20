/*
UVa
DP
437 -the tower of babylon
4.2.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
# define inf 100000007

using namespace std;

struct tile {
    int l,w,h;

    bool operator < (const tile &p) const{
        if (l == p.l){
            return w < p.w;
        }
        else return l < p.l;
    }
};

tile t[95];
int n;
int dp[95];

int main()
{
    int p, in[3], i, j, cnt = 0;
    int ans;

    while (1)
    {
        cnt++;
        cin >> p;
        if (p == 0) break;

        long long int res;
        t[0].l = t[0].w = t[0].h = inf;

        n = 0;
        for (i=0; i<p; i++)
        {
            cin >> in[0] >> in[1] >> in[2];

            sort(in,in+3);
            reverse(in,in+3);

            n++;
            t[n].l = in[0], t[n].w = in[1], t[n].h = in[2];

            n++;
            t[n].l = in[1], t[n].w = in[2], t[n].h = in[0];

            n++;
            t[n].l = in[0], t[n].w = in[2], t[n].h = in[1];
        }

        sort (t, t+n+1);
        reverse (t, t+n+1);

        for (i = 1; i<n+1; i++) dp[i] = t[i].h;

        for (i = n; i >= 1; i--)
        {
            ans = 0;
            for (j=i+1; j<n+1; j++)
            {
                if (t[i].l > t[j].l && t[i].w > t[j].w)
                    if (ans < dp[j]) ans = dp[j];
            }
            dp[i] += ans;
        }

        ans = 0;
        for (i = n; i >= 1; i--)
            if (dp[i] > ans) ans = dp[i];

        printf ("Case %d: maximum height = %d\n", cnt, ans );
    }

    return 0;
}
