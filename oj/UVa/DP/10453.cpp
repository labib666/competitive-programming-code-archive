/*
UVa
10453 - make palindrome
dp
21.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int dp[1005][1005], m[1005][1005];
char s[1005];

int solve (int a, int b)
{
    if (a >= b)
        return 0;
    if (dp[a][b] != -1)
        return dp[a][b];

    int a1, a2;

    if (s[a] == s[b])
    {
        dp[a][b] = solve(a+1, b-1);
        m[a][b] = 3;
        return dp[a][b];
    }

    a1 = 1 + solve(a+1, b);
    a2 = 1 + solve(a, b-1);

    dp[a][b] = min (a1, a2);
    if (a1 <= a2)
        m[a][b] = 1;
    else
        m[a][b] = 2;

    return dp[a][b];
}

void pseq (int a, int b)
{
    if (a == b)
    {
        cout << s[a] ;
        return;
    }

    if (m[a][b] == 2)
    {
        cout << s[b];
        pseq(a,b-1);
        cout << s[b];
        return;
    }

    if (m[a][b] == 1)
    {
        cout << s[a];
        pseq(a+1, b);
        cout << s[a];
        return;
    }
    if (m[a][b] == 3)
    {
        cout << s[a] ;
        pseq(a+1, b-1);
        cout << s[b];
        return;
    }
}

int main()
{
    int i, j, ans;

    while (gets(s) != NULL)
    {
        i = strlen (s);
        for (j=0; j<=i; j++)
            for (int k=0; k<= i; k++)
                dp[j][k] = -1;

        ans = solve(0, i-1);

        cout << ans << " ";
        pseq (0, i-1);
        cout << endl;
    }
    return 0;
}
