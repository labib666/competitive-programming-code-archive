/*
UVa
DP
166 - making change
14.1.13
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int dp[501];
int c[6]={5,10,20,50,100,200};
int q[6];

int main()
{
    int d, i, j, k, n;
    double m;
    int add[501];
    char out[] = " 123456789";
    while (1)
    {
        d = 0;
        for (i=0; i<6; i++) {
            scanf ("%d", &q[i]);
            d += q[i];
        }

        if (d == 0) break;

        scanf ("%lf", &m);
        n = (int) (m*100 + 0.0001);

        for (i=1; i<=500; i++) dp[i] = 500;
        dp[0] = 0;

        for (j=0; j<6; j++)
        {
            for (i=0; i<=500; i++) add[i] = dp[i];

            for (i=1; i <= q[j]; i++)
            {
                for (k=i*c[j]; k<= 500; k++){
                    if (dp[k] > dp[k - i*c[j]] + 1)
                        if (add[k] > dp[k - i*c[j]] + i) add[k] = dp[k - i*c[j]] + i;
                }
            }

            for (i=0; i<=500; i++) dp[i] = add[i];
        }

        for (j=0; j<6; j++)
        {
            for (i=1; i*c[j] <= 500; i++)
            {
                for (k = i*c[j]; k <= 500; k++)
                    if(dp[k- i*c[j]] > dp[k]+i)
                        dp[k- i*c[j]] = dp[k]+i;
            }
        }

        if (dp[n] < 100) {
            if (dp[n] < 10) cout << "  " << dp[n] << endl;
            else cout << " " << dp[n] << endl;
        }
        else cout << dp[n] << endl;
    }

    return 0;
}
