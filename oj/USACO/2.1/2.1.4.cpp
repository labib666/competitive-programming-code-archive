/*
USACO
bitmask, complete search
2.1.4 - healthy holsteins
26.3.2013
*/
/*
ID: Labib Rashid
LANG: C++
TASK: holstein
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int bit (int n){
    int c = 0;
    while (n > 0){
        c++;
        n &= (n-1);
    }
    return c;
}

int main()
{
    int v, n, lim, i, j, k, x;
    int req[30], s[20][30];

    freopen ("holstein.in", "r", stdin);
    freopen ("holstein.out", "w", stdout);

    cin >> v;
    for (i=0; i<v; i++)
        cin >> req[i];

    cin >> n;
    for (i=0; i<n; i++)
        for (j=0; j<v; j++)
            cin >> s[i][j];

    int bestc = 999, best;
    for (k = 0; k < (1 << n); k++)
    {
        x = bit(k);
        if (x >= bestc) continue;

        int t[30];
        fill (t, t+30, 0);

        for (i=0; i<n; i++)
        {
            if ((k >> i) & 1) {
                for (j = 0; j < v; j++)
                    t[j] += s[i][j];
            }
        }

        int fail = 0;
        for (i=0; i<v; i++)
            if (t[i] < req[i])
                fail = 1;

        if (!fail)
            bestc = x, best = k;
    }

    printf("%d", bestc);
    for (i = 0; i < n; i++)
        if ((best >> i) & 1)
            cout << " " << i+1;
    cout << endl;

    return 0;
}
