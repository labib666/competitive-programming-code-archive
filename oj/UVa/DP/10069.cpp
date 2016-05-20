/*
UVa
DP - LCS
10069 - distinct subsequences
2.2.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

char n1 [10005], n2 [105];
int dp [10005][105][13], check[10005][105];
int k1, k2;

inline void add (int a,int b,int s1,int s2)
{
    if (a == k1 || b == k2) return;
    int c = 0;
    for (int i = 12; i>=0; i--)
    {
        int sum = dp[s1][s2][i] + dp[a][b][i] + c;
        c = sum / 100000000;
        dp[s1][s2][i] = sum % 100000000;
    }
    return;
}

inline void lcs (int a, int b, int s1, int s2)
{
    if (b == k2) {
        dp[s1][s2][12] += 1;
        //cout << 1 << endl;
        return;
    }
    if (a == k1 ) return;

    if (check[a][b] == 1)
        return;

    if (n1[a] == n2[b])
    {
        lcs (a+1,b+1,a,b);
        lcs (a+1, b, a, b);

        add (a+1,b+1,a,b);
        add (a+1,b,a,b);

        check[a][b] = 1;
        return;
    }

    lcs (a+1, b, a, b);
    add(a+1,b,a,b);
    check[a][b] = 1;
    return;
}

inline void kickstart()
{
    if (n1[0] == n2[0]) {
        lcs (1,1,0,0);
        add (1,1,0,0);
    }
    lcs (1,0,0,0);
    add (1,0,0,0);
}

int main()
{
    int res, c = 0, t;
    cin >> t;
    while (1)
    {
        c++;
        if (c > t) break;

        memset (dp, 0, sizeof(dp));
        memset (check, 0, sizeof(check));

        cin >> n1 >> n2;
        k1 = strlen (n1);
        k2 = strlen (n2);

        kickstart ();

        int k = 0,j;
        for (int i=0; i<13; i++)
        {
            if (dp[0][0][i] > 0 && k == 0) {
                k = 1;
                cout << dp[0][0][i];
            }
            else if (k == 1) {
                for (j = 10000000; j > 0; j /= 10)
                {
                    if (dp[0][0][i] / j > 0) break;
                    cout << "0" ;
                }
                cout << dp [0][0][i];
            }
        }
        cout << endl;
    }

    return 0;
}

