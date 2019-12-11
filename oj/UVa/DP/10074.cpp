/*
UVa
DP - max sum
10074 - take the land
28.1.13
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int dp[105][105];
int colsum [105][105];

int main()
{
    int a, b, i, j, k, sum, mx, l, w;
    int temp [105];

    while (1)
    {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;

        for (i=1;i<a+1;i++)
            for (j=1;j<b+1;j++)
                scanf ("%d", &dp[i][j]);

        memset (colsum, 0, sizeof(colsum));

        for (i=1;i<b+1;i++)
            for (j=1;j<a+1;j++)
                colsum[i][j] = dp[j][i] + colsum[i][j-1];

        mx = 0;
        for (k=1;k<a+1;k++)
        {
            for (i=a;i>=k;i--)
            {
                for (j=1;j<b+1;j++)
                    temp[j] = colsum[j][i] - colsum[j][k-1];

                l = i - k + 1;
                w = 0;
                for (j=1;j<b+1;j++)
                {
                    if (temp[j] > 0)
                    {
                        if (w*l > mx) mx = w*l;
                        w = 0;
                    }
                    else w++;
                }
                if (w*l > mx) mx = w*l;
            }
        }

        cout << mx << endl;
    }

    return 0;
}
