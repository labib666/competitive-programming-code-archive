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

using namespace std;

vector <int> n, dp, t;

inline void find_path(int a, int b)
{
    if (b == 0)
    {
        printf("%d\n", n[a]);
        return;
    }

    printf("%d\n", n[a]);
    find_path(t[a],b-1);
}

int main()
{
    int a, i, j, p=0;

    while (scanf ("%d", &a)!=EOF)
    {
        n.push_back(a);
        dp.push_back(1);
        t.push_back(p++);
    }

    int mx = 0;
    int start = p;

    for (i = p-2; i >= 0; i--)
    {
        for (j=i+1; j<p; j++)
        {
            if (n[j] > n[i] && dp[i] <= dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                t[i] = j;
                if (dp[i] > mx)
                {
                    mx = dp[i];
                    start = i;
                }
            }
        }
    }

    printf("%d\n-\n", mx);;
    find_path (start,mx - 1);

    return 0;
}
