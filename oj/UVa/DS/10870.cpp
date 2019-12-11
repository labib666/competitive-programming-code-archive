/*
UVa
10870 - Recurrences
DS - Matrix exponentiation
26 Feb, 2014
*/

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define x first
#define y second
#define inf 1000000007
#define pi 2*asin(1)
#define PII pair<int,int>
#define VI vector <int>
#define eps 1e-9

using namespace std;

ll n, m, r;
ll f[20];

struct matrix {
    ll d[20][20];
};
matrix multiply (matrix a, matrix b) {
    matrix ans;
    for (ll i = 0ll; i < r; i++) {
        for (ll j = 0ll; j < r; j++) {
            ans.d[i][j] = 0ll;
            for (ll k = 0ll; k < r; k++) {
                ans.d[i][j] = (ans.d[i][j]+(a.d[i][k]*b.d[k][j])%m)%m;
            }
        }
    }
    return ans;
}
matrix bigmod (matrix m, ll p) {
    if (p == 1ll) return m;
    matrix ans = bigmod(m,p/2ll);
    ans = multiply(ans,ans);
    if (p%2ll) ans = multiply(ans,m);
    return ans;
}

int main()
{
    ll i, j, k, ans;
    matrix now;
    while (1)
    {
        scanf ("%lld%lld%lld", &r, &n, &m);

        if (r+n+m == 0) break;
        memset(now.d, 0, sizeof(now.d));

        for (i = 0; i < r; i++)
            scanf ("%lld", &now.d[0][i]);
        for (i = 1; i <= r; i++)
            scanf ("%lld", &f[i]);

        if (n <= r) {printf ("%lld\n", f[n]); continue;}

        for (i = 1; i < r; i++)
            now.d[i][i-1] = 1;

        now = bigmod(now, n-r);

        ans = 0;
        for (i = 1; i <= r; i++)
            ans = (ans+(now.d[0][r-i]*f[i])%m)%m;

        printf ("%lld\n", ans);
    }
    return 0;
}

