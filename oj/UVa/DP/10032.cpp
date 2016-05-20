/*
UVa
dp - knacksap, bitmask
10032 - tug of war
11.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <vector>
# include <algorithm>
# define pb push_back

using namespace std;

long long int dp[45005], v[45005];

int main()
{
    int t, i, j, k, w[105], sum, n, a, fin, ans;

    cin >> t;
    while (t--)
    {
        memset (v, 0, sizeof(v));
        memset (dp, 0, sizeof(dp));
        dp[0] = 1;
        v[0] = 1;
        sum = 0;

        cin >> n;
        for (i=0;i<n;i++){
            cin >> w[i];
            sum += w[i];
        }
        fin = sum;
        sum /= 2;

        for (i=0; i<n; i++){
            k = w[i];
            for (j = sum; j >= k; j--)
            {
                if (v[j - k])
                {
                    v[j] = 1;
                    dp[j] |= (dp[j-k] << 1);
                }
            }
        }

        for (j = sum; j >= 0; j--){
            if (n % 2)
            {
                if ((dp[j]>>n/2+1) & 1 || (dp[j]>>n/2) & 1)
                {
                    ans = j;
                    break;
                }
            }
            else {
                if ((dp[j]>>n/2) & 1)
                {
                    ans = j;
                    break;
                }
            }
        }
        cout << ans << " " << fin - ans << endl;
        if (t) cout << endl;
    }

    return 0;
}
