/*
UVa
DP - 0-1 knapsack
10664 - luggage
8.2.2013
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <sstream>

using namespace std;

int bag[25], dp [101];

int main()
{
    int t, n, i, j, k, sum;
    string s;

    cin >> t;
    getline (cin,s);
    for (i = 0; i<t; i++)
    {
        memset (dp, 0, sizeof(dp));
        dp[0] = 1;

        getline (cin, s);
        stringstream ss(s);

        int in;
        n = sum = 0;
        while (ss >> in)
        {
            sum += in;
            bag[n++] = in;
        }
        if (sum % 2 == 1)
        {
            cout << "NO\n";
            continue;
        }

        for (j = 0; j < n; j++)
        {
            for (k = sum/2; k>= bag[j]; k--)
            {
                dp[k] += dp [k - bag[j]];
            }
        }

        if (dp[sum/2] == 0) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
