/*
UVa
dp
10072 - 10072 - Bob Laptop Woolmer & Eddie Desktop Barlow
18.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <vector>
# include <sstream>
# define inf -0x33333333

using namespace std;

int dp[105][10][10][10], mem [105][10][10][10];
int s[105][3];
vector <int> team[4];

int conint (double a)
{
    int m;
    stringstream ss;
    string s2;

    ss << a;
    ss >> m;
    ss >> s2;
    if (s2[1] > '4') m++;

    return m;
}

int solve (int a, int s1, int s2, int s3)
{
    if (a == 0)
        return (s1+s2+s3 == 0) ? 0 : inf;
    if (a < s1 + s2 + s3)
        return inf;
    if (s1+s2+s3 == 0)
        return 0;

    if (dp[a][s1][s2][s3] != -1)
        return dp[a][s1][s2][s3];

    int ans, a1, a2, a3, a4;
    double  p1 = s[a][0], p2 = s[a][1], p3 = s[a][2];
    a1 = a2 = a3 = a4 = 0;

    if (s1 != 0)
        a1 = conint(0.8*p1 + 0.2*p3 + solve (a-1, s1-1, s2, s3));
    if (s2 != 0)
        a2 = conint(0.7*p2 + 0.1*p1 + 0.2*p3 + solve (a-1, s1, s2-1, s3));
    if (s3 != 0)
        a3 = conint(0.4*p2 + 0.4*p1 + 0.2*p3 + solve (a-1, s1, s2, s3-1));
    a4 = solve (a-1, s1, s2, s3);

    ans = max (max (a1,a2) , max (a3, a4));

    dp[a][s1][s2][s3] = ans;

    if (ans == a1) mem[a][s1][s2][s3] = 1;
    else if (ans == a2) mem[a][s1][s2][s3] = 2;
    else if (ans == a3) mem[a][s1][s2][s3] = 3;
    else if (ans == a4) mem[a][s1][s2][s3] = 4;

    return dp[a][s1][s2][s3];
}

void pseq (int a, int s1, int s2, int s3)
{
    if (s1 + s2 + s3 == 0) return;

    int k = mem [a][s1][s2][s3];

    if (k < 4){
        team[k].push_back (a);
        if (k == 1) pseq (a-1, s1-1, s2, s3);
        else if (k == 2) pseq (a-1, s1, s2-1, s3);
        else pseq (a-1, s1, s2, s3-1);
    }
    else pseq (a-1, s1, s2, s3);
    return;
}

int main ()
{
    int n, t = 0, i, j, k, l;

    while (1)
    {
        cin >> n;
        if (n == 0) break;

        if (t) cout << endl;

        for (i = 1; i <= n; i++)
            cin >> s[i][0] >> s[i][1] >> s[i][2];

        cin >> j >> k >> l;

        memset(dp, -1, sizeof(dp));

        int ans = solve(n, j, k, l);

        printf ("Team #%d\nMaximum Effective Score = %d\n", ++t, ans);
        pseq (n,j,k,l);
        printf ("Batsmen :");
        for (i = 0; i < j; i++)
            cout << " " << team[1][i];
        cout << endl;
        printf ("Bowlers :");
        for (i = 0; i < k; i++)
            cout << " " << team[2][i];
        cout << endl;
        printf ("All-rounders :");
        for (i = 0; i < l; i++)
            cout << " " << team[3][i];
        cout << endl;

        for (i = 0; i < 4; i++) team[i].clear();
    }
    return 0;
}

