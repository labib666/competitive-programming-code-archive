
/*
UVa
DP - max sum
10684 - The Jackpot
27.1.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int stop [10005];

int main()
{
    int t, i, sum, n, mx, j;

    while(1)
    {
        scanf ("%d", &n);
        if (n == 0) break;

        for (j=0;j<n; j++) scanf ("%d", &stop[j]);

        mx = 0;
        sum = 0;

        for (j=0;j<n;j++)
        {
            sum += stop[j];
            sum = max (sum,0);

            if (sum > mx) mx = sum;
        }

        if (mx > 0) printf ("The maximum winning streak is %d.\n", mx);
        else printf ("Losing streak.\n");
    }
    return 0;
}
