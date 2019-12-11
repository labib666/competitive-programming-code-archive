/*
UVa
DP - LCS
10635 - prince n princess
6.2.2013
*/

# include <cstdio>
# include <iostream>
# include <string>
# include <cstring>
# include <map>
# define inf 1000000007

using namespace std;

int c[62500], n[62500], p[62500], k;
map <int, int> tag;

inline int bs (int a)
{
    int hi = k-1, lo = 1, mid;

    while (hi >= lo)
    {
        mid = (hi+lo)/ 2;

        if (p[mid] > a) lo = mid + 1;

        else hi = mid - 1;
    }

    return lo;
}

int main()
{
    int t, i, k1, k2, j, sz, res, num;

    cin >> t;
    for (i = 1; i <= t; i++)
    {
        tag.clear();
        memset (c, 0, sizeof(c));

        cin >> sz >> k1 >> k2;
        k1 ++;
        k2 ++;

        for (j = 0; j < k1; j++)
        {
            cin >> num;
            c [num] = 1;
            tag [num] = j+1;
        }

        k = 0;
        for (j = 0; j < k2; j++)
        {
            cin >> num;
            if (c[num] == 1) n[k++] = tag[num];
        }

        p[0] = inf;
        for (j = 1; j <= k; j++) p[j] = -1*inf;

        res = 0;
        for (j = k-1; j >= 0; j--)
        {
            int in = bs (n[j]);
            p [in] = n[j];

            if (res < in) res = in;
        }

        printf ("Case %d: %d\n", i, res);
    }

    return 0;
}
