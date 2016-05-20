/*
UVa
DP - LIS
497 - Strategic Defence initiative
5.2.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <vector>
# define inf 1000000007

using namespace std;

vector <int> n, dp, c;
char in[20], dummy[2];
int k, cnt;

inline void takeinput()
{
    n.clear();
    dp.clear();
    c.clear();
    cnt = 0;

    while (gets (in) != NULL)
    {
        if (strlen (in) == 0 ) break;
        sscanf (in, "%d", &k);

        n.push_back(k);
        dp.push_back(1);
        cnt++;
    }
    return;
}

inline int bs (int p)
{
    int hi = cnt, lo = 1, mid;

    while(hi >= lo)
    {
        mid = (hi + lo) / 2;

        if (c[mid] > p) lo = mid + 1;
        else hi = mid - 1;
    }

    return lo;
}

inline void pseq(int mx)
{
    int v = (-1)*inf;

    for (int i = 0; i < cnt; i++)
    {
        if (dp[i] == mx && n[i] > v)
        {
            v = n[i];
            cout << n[i] << endl;
            mx --;
            if (mx == 0) break;
        }
    }
    return;
}

int main()
{
    int t, i, j;
    cin >> t;
    gets (dummy);
    gets (dummy);

    for(i=0;i<t; i++)
    {
        takeinput();

        c.push_back (inf);
        for (j=1; j<=cnt; j++) c.push_back (-1*inf);

        for (j = cnt-1; j >= 0; j--)
        {
            k = bs (n[j]);
            dp[j] = k;
            c[k] = n[j];
        }

        int res = 0;
        for (j=0; j<cnt; j++) {
            if (res < dp[j])
                res = dp[j];
        }

        printf ("Max hits: %d\n", res);
        pseq (res);
        if (i != t-1) cout << endl;
    }

    return 0;
}
