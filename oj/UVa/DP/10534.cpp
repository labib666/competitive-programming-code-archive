/*
UVa
dp
10534 - wavio sequence
20.3.2013
*/

# include <iostream>
# include <cstring>
# include <cstdio>
# define inf 0x33333333

using namespace std;

int m[10005], s1[10005], s2[10005];
int c1[10005], c2[10005], n;

int bs1 (int a)
{
    int hi = n, lo = 0, mid;

    while (hi >= lo)
    {
        mid = (hi+lo)/2;
        if (s1[mid] >= m[a])
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return lo;
}

int bs2 (int a)
{
    int hi = n, lo = 0, mid;

    while (hi >= lo)
    {
        mid = (hi+lo)/2;
        if (s2[mid] >= m[a])
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return lo;
}

int main()
{
    int i, j, k;

    while (cin >> n)
    {
        for (i = 0; i < n; i++)
            cin >> m[i];

        for (i = 1; i <= n; i++)
            s1[i] = inf;
        s1[0] = (-1)*inf;

        for (i = 1; i <= n; i++)
            s2[i] = inf;
        s2[0] = (-1)*inf;

        for (i = 0; i < n; i++)
        {
            j = bs1 (i);
            s1 [j] = m[i];
            c1[i] = j-1;
        }

        for (i = n-1; i >= 0; i--)
        {
            j = bs2 (i);
            s2 [j] = m[i];
            c2[i] = j-1;
        }

        k = -1 * inf;
        for (i = 0; i < n; i++)
            k = max (k, 1+2*(min (c1[i],c2[i])));

        cout << k << endl;
    }
    return 0;
}
