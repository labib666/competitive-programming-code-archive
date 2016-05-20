/*
UVa
DP - distance editing
526 - String Distance and Transform Process
31.1.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# include <algorithm>

using namespace std;

char s1[100], s2[100];
int k1, k2, dp [100][100], mem [100][100], seq;

int mcost (int a, int b)
{
    if (a == k1) return k2 - b;
    if (b == k2) return k1 - a;

    if (dp [a][b] != -1) return dp[a][b];

    if (s1[a] == s2[b]) {
        dp [a][b] = mcost (a+1, b+1);
        mem [a][b] = 0;
        return dp[a][b];
    }

    int a1, a2, a3, ans;
    a1 = 1 + mcost (a+1, b+1);
    a2 = 1 + mcost (a+1, b);
    a3 = 1 + mcost (a, b+1);
    ans = min (a1, min (a2,a3));
    dp [a][b] = ans;

    if (ans == a1) mem[a][b] = 1;
    else if (ans == a2) mem[a][b] = 2;
    else mem[a][b] = 3;

    return ans;
}

void ppath (int a, int b)
{
    int i;
    if (a == k1)
    {
        for (i = b; i < k2; i++){
            printf ("%d Insert %d,%c\n", seq++, i+1, s2[i]);
        }
        return;
    }
    if (b == k2)
    {
        for (i = a; i < k1; i++){
            printf ("%d Delete %d\n", seq++, b+1);
        }
        return;
    }

    if (mem[a][b] == 0) {
        ppath (a+1,b+1);
        return;
    }
    if (mem[a][b] == 1) {
        printf ("%d Replace %d,%c\n", seq++, b+1, s2[b]);
        ppath (a+1,b+1);
        return;
    }
    if (mem[a][b] == 2) {
        printf ("%d Delete %d\n", seq++, b+1);
        ppath (a+1,b);
        return;
    }
    if (mem[a][b] == 3) {
        printf ("%d Insert %d,%c\n", seq++, b+1, s2[b]);
        ppath (a,b+1);
        return;
    }
}

int main()
{
    int n, cnt = 0;

    while (gets (s1) != 0)
    {
        gets (s2);

        k1 = strlen(s1);
        k2 = strlen(s2);

        memset (dp, -1, sizeof (dp));

        n = mcost(0,0);
        seq = 1;

        if (cnt != 0) cout << endl;
        cout << n << endl;
        ppath (0,0);

        cnt++;
    }
    return 0;
}
