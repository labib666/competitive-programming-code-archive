/*
UVa
10229 - Modular Fibonacci
DS - Matrix exponentiation
25 Feb, 2014
*/

#include <cstdio>

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

ll n, m;

struct matrix {
    ll d[2][2];
};
matrix multiply (matrix a, matrix b) {
    matrix ans;
    for (ll i = 0ll; i < 2ll; i++) {
        for (ll j = 0ll; j < 2ll; j++) {
            ans.d[i][j] = 0ll;
            for (ll k = 0ll; k < 2ll; k++) {
                ans.d[i][j] = (ans.d[i][j]+(a.d[i][k]*b.d[k][j])%(1ll<<m))%(1ll<<m);
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
    while (scanf ("%lld%lld",&n,&m) != EOF) {
        if (n > 1) {
            now.d[0][0] = 1ll, now.d[0][1] = 1ll, now.d[1][0] = 1ll, now.d[1][1] = 0ll;
            now = bigmod(now,n-1ll);
            ans = (now.d[0][0]*1ll)%(1ll<<m) + (now.d[0][1]*0ll)%(1ll<<m);
        }
        else ans = (n == 0) ? 0 : 1;
        ans %= (1ll<<m);
        printf ("%lld\n", ans);
    }
    return 0;
}
