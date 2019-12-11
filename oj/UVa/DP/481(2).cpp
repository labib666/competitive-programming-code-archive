/*
UVa
DP - LIS
481 - what goes up
28.1.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <vector>
# include <algorithm>
# define inf 1000000007

using namespace std;

vector <int> n, dp, c, seq;

inline int bs(int k)
{
    int hi, lo, mid;
    hi = c.size() - 1;
    lo = 1;
    while (hi >= lo){

        mid = (hi + lo) / 2;

        if (c[mid] > k)
            lo = mid+1;

        else
            hi = mid-1;
    }

    return lo;
}

int main()
{
    int a, i, j, p = 0, k, mx;

    while (scanf ("%d", &a)!=EOF)
    {
        n.push_back(a);
        dp.push_back(1);
        p++;
    }

    c.push_back(inf);
    for (i = 1; i<=p; i++) c.push_back(-1*inf);

    mx = 0;
    for (i = p-1; i >= 0; i--)
    {
        k = bs(n[i]);
        dp[i] = k;
        c[k] = n[i];
        if (k > mx) mx = k;
    }

    cout << mx << "\n-" << endl;

    for (i=0; i<=mx; i++) seq.push_back(0);
    seq.push_back(-1*inf);

    j = mx;
    for (i = 0; i < p ; i++)
    {
        if(dp[i] == j && n[i] > seq[j+1])
        {
            seq[j] = n[i];
            j--;
        }

        else if(dp[i] > j)
        {
            if (n[i] < seq[dp[i]+1]) continue;
            else {
                j = dp[i] - 1;
                seq[j+1] = n[i];
            }
        }
    }

    for (i = mx; i > 0 ; i--) cout << seq[i] << endl;

    return 0;
}

