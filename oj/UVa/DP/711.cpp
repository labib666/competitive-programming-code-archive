/*
UVa
DP - 0-1 knacksap
711 - dividing up
11.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

bool dp[60005];
int m[60005];

int main()
{
    int i, j, k, x, sum, coin[7], cnt = 1, top;

    while (1)
    {
        sum = 0;
        for (i=1; i<7; i++)
        {
            cin >> coin[i];
            sum += ((i)*coin[i]);
        }

        if (sum == 0) break;

        if (sum % 2 == 1) {
            printf ("Collection #%d:\nCan't be divided.\n\n", cnt++);
            continue;
        }

        memset (dp, false, 60005*sizeof(bool));
        dp[0] = true;

        for (i = 1; i<=6; i++)
        {
            memset (m, 0, sizeof(m));

            for (k = i; k <= sum/2; k++)
            {
                if (dp[k] == true) continue;
                if (dp[k-i] == true) {
                    m[k] = m[k-i] + 1;
                    if (m[k] > coin[i])
                        break;
                    else dp[k] = true;
                }
            }
            if (dp[sum/2] == true) break;
        }

        if (dp[sum/2] != true) printf ("Collection #%d:\nCan't be divided.\n\n", cnt++);
        else printf ("Collection #%d:\nCan be divided.\n\n", cnt++);
    }

    return 0;
}
