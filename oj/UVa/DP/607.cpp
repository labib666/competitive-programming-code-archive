/*
UVa
classic DP
607 - scheduling lectures
28.2.1013
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define inf 1000000007

using namespace std;

struct data {
    int c, m;
};

data dp [1005];
int n, len, safe, csum [1005], t[1005];

inline data findres (int a)
{
    data p;
    if (a == n+1)
    {
        p.m = 0, p.c = 0;
        return p;
    }

    if (dp[a].m != -1) return dp[a];

    int mm, mc, i, cost, move, sum;
    mm = mc = inf;

    for (i = a; i <= n; i++)
    {
        sum = csum [i] - csum [a-1];
        if (sum > len) break;

        cost = len - sum;
        if (cost)
        {
            if (cost <= 10) cost = (-1)*safe;
            else cost = (cost-10)*(cost-10);
        }

        p = findres(i+1);
        move = p.m + 1;
        cost += p.c;

        if (move < mm) {
            mm = move;
            mc = cost;
        }
        else if (mm == move) mc = min (cost, mc);
    }

    p.m = mm;
    p.c = mc;

    dp[a] = p;
    return p;
}

int main()
{
    int i, c = 0;
    while (1)
    {
        cin >> n;
        if (n == 0) break;

        c++;
        cin >> len >> safe;

        t[0] = 0, csum[0] = 0;
        for (i=1; i<= n; i++){
            cin >> t[i];
            csum[i] = t[i] + csum[i-1];
            dp[i].m = -1;
            dp[i].c = inf;
        }

        data p = findres(1);

        if (c > 1) cout << endl;
        cout << "Case " << c << ":\n";
        cout << "Minimum number of lectures: " << p.m << endl;
        cout << "Total dissatisfaction index: " << p.c << endl;
    }

    return 0;
}
