/*
USACO
coin change
2.2.1 - preface numbering
27.3.2013
*/
/*
ID: Labib Rashid
LANG: C++
TASK: preface
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int dp[3502], mem[3502][10], p[3502], tot[10], faw[3502], fawp[3502];
int coin[15] = {1000, 500, 100, 50, 10, 5, 1, 4 , 9, 40, 90, 400, 900};
string s = "0IVXLCDM";

int main ()
{
    int n, i, j, k, x;

    freopen ("preface.in", "r", stdin);
    freopen ("preface.out", "w", stdout);

    cin >> n;

//initialize
    for (i = 1; i <= n; i++)
        dp[i] = 0x33333333;

    dp[0] = 0, p[0] = 0;

    for (i = 1; i < 8; i++)
        mem[0][i] = 0;

//taking care of normal coins
    for (i = 0; i < 7; i++)
    {
        for (j = coin[i]; j <= n; j++) {
            if (dp[j-coin[i]] + 1 < dp[j]) {
                dp[j] = dp[j-coin[i]] + 1;
                p[j] = j - coin[i];
            }
        }
    }

// taking care of groups, no use of two groups at once
    for (i = 0; i <= n; i++)
        faw[i] = dp[i], fawp[i] = p[i];

    for (i = 7; i < 13; i++)
    {
        for (j = n; j >= coin[i]; j--) {
            if (dp[j-coin[i]] + 1 < dp[j]) {
                faw[j] = dp[j-coin[i]] + 1;
                fawp[j] = j - coin[i];
            }
        }
    }

    for (i = 0; i <= n; i++)
        dp[i] = faw[i], p[i] = fawp[i];


    for (i = 1; i <= n; i++)
    {
        k = i-p[i], x = p[i];
        for (j = 1; j < 8; j++)
            mem[i][j] = mem[x][j];

        if (k == 1) mem[i][1]++;
        else if (k == 4) mem[i][1]++, mem[i][2]++;
        else if (k == 5) mem[i][2]++;
        else if (k == 9) mem[i][1]++, mem[i][3]++;
        else if (k == 10) mem[i][3]++;
        else if (k == 40) mem[i][3]++, mem[i][4]++;
        else if (k == 50) mem[i][4]++;
        else if (k == 90) mem[i][3]++, mem[i][5]++;
        else if (k == 100) mem[i][5]++;
        else if (k == 400) mem[i][6]++, mem[i][5]++;
        else if (k == 500) mem[i][6]++;
        else if (k == 900) mem[i][7]++, mem[i][5]++;
        else if (k == 1000) mem[i][7]++;
    }

    fill (tot, tot+10, 0);
    for (i=1; i<8; i++)
        for (j = 1; j <= n; j++)
            tot[i] += mem[j][i];

    for (i=1; i<8; i++)
        if (tot[i])
            cout << s[i] << " " << tot[i] << endl;

    return 0;
}
