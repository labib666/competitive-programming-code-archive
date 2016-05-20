/*
UVa
dp - bitmask
10651 - Pebble Solitaire
14.3.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int dp [10000];

int res (int mask)
{
    if (mask == 1) return 0;
    if (dp[mask] != -1) return dp[mask];

    int i, j, k;
    j = k = 0;
    for (i = 1; i <= 12; i++)
        if (mask >> i & 1)
            j++, k++;

    for (i = 1; i <= 11; i++)
    {
        if (((mask >> i) & 1) && ((mask >> (i+1)) & 1))
        {
            int mask2 = mask;
            mask2 &= (~(1 << i+1));
            mask2 &= (~(1 << i));
            if (i-1 > 0 && !(mask >> (i-1) & 1)){
                mask2 |= (1 << i-1);
                j = min (j,res(mask2));
                mask2 &= (~(1 << i-1));
            }
            if (i+2 < 13 && !(mask >> (i+2) & 1)){
                mask2 |= (1 << i+2);
                k = min (k,res(mask2));
                mask2 &= (~(1 << i+2));
            }
        }
    }
    dp[mask] = min (j,k);
    return dp[mask];
}

int main()
{
    int msk, i, t;
    string s;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof (dp));
        msk = 1;
        cin >> s;
        for (i = 0; i < 12; i++)
            if (s[i] == 'o')
                msk |= (1 << i+1);
        int ans = res(msk);
        cout << ans << endl;
    }
    return 0;
}
