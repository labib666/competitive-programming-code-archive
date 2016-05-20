/*
UVa
DP - distance editing
164 - string computer
31.1.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# include <algorithm>

using namespace std;

char s1[22], s2[22];
int k1,k2;
int dp [22][22];
int mem [22][22];

int ed (int a, int b)
{
    if (k1 == a )
        return (k2 - b);
    else if (k2 == b)
        return (k1 - a);

    if (dp[a][b] != -1) return dp[a][b];

    if (s1[a] == s2[b])
    {
        dp[a][b] = ed(a+1,b+1);
        mem[a][b] = 0;
        return dp[a][b];
    }
    int ans[3];

    ans[0] = 1+ed(a+1,b);
    ans[1] = 1+ed(a+1,b+1);
    ans[2] = 1+ed(a,b+1);
    dp[a][b] = min (ans[0],min(ans[1],ans[2]));

    if (dp[a][b] == ans[0]) mem[a][b] = 1;
    else if (dp[a][b] == ans[1]) mem[a][b] = 2;
    else mem[a][b] = 3;

    return dp[a][b];
}

void mt (int a, int b)
{
    if (a == k1)
    {
        int i;
        for (i = b; i < k2; i++)
            printf ("I%c%.2d", s2[i], i+1);
        cout << "E" << endl;
        return;
    }
    if (b == k2)
    {
        int i;
        for (i = a; i < k1; i++)
            printf ("D%c%.2d", s1[i], b+1);
        cout << "E" << endl;
        return;
    }

    if (mem[a][b] == 0) {
        mt (a+1,b+1);
        return;
    }

    if (mem[a][b] == 1){
        printf ("D%c%.2d", s1[a], b+1);
        mt (a+1,b);
        return;
    }
    if (mem[a][b] == 2){
        printf ("C%c%.2d", s2[b], b+1);
        mt (a+1,b+1);
        return;
    }
    if (mem[a][b] == 3){
        printf ("I%c%.2d", s2[b], b+1);
        mt (a,b+1);
        return;
    }
}

int main()
{
    while (1)
    {
        memset (dp, -1, sizeof(dp));
        memset (mem, -1, sizeof (mem));
        cin >> s1;
        if (s1[0] == '#') break;

        cin >> s2;
        k1 = strlen (s1);
        k2 = strlen (s2);

        int n = ed(0,0);
        mt (0,0);
    }
    return 0;
}
