/*
UVa
DP - LCS
531 - compromise
6.2.2013
*/

# include <cstdio>
# include <iostream>
# include <string>
# include <cstring>

using namespace std;

int dp [105][105], mem[105][105], k1, k2;
string word, s1[105], s2[105], hash = "#";

int lis (int a, int b)
{
    //cout << " dealing >> " << a << " , " << b << endl;
    if (a == k1 || b == k2) return 0;

    if (dp[a][b] != -1) return dp[a][b];

    int ans, a1, a2;
    if (s1[a] == s2[b])
    {
        ans = 1 + lis (a+1, b+1);
        dp[a][b] = ans;
        mem[a][b] = 0;

        return ans;
    }

    a1 = lis (a, b+1);
    a2 = lis (a+1, b);

    ans = max (a1,a2);
    dp[a][b] = ans;

    if (a1 == ans) mem[a][b] = 1;
    else mem[a][b] = 2;

    return ans;
}

void pseq (int a, int b, int n)
{
    if (mem[a][b] == 0) {
        cout << s1[a];
        if (n != 0) {
            cout << " ";
            pseq (a+1, b+1, n-1);
        }
        else cout << endl;
        return;
    }

    else if (mem[a][b] == 1) {
        pseq (a, b+1, n);
        return;
    }

    else pseq (a+1, b, n);

    return;
}

int main ()
{
    int i, j, res;

    while (cin >> word)
    {
        memset (dp, -1, sizeof(dp));
        memset (mem, 0, sizeof (mem));

        k1 = 1;
        s1[0] = word;
        while (1)
        {
            cin >> word;
            if (word == hash) break;

            s1[k1] = word;
            k1++;
        }

        k2 = 0;
        while (1)
        {
            cin >> word;
            if (word == hash) break;

            s2[k2] = word;
            k2++;
        }

        res = lis (0,0);

        pseq(0,0,res - 1);

        //cout << res << " "  << k1 << " " << k2 <<  endl;
    }

    return 0;
}

