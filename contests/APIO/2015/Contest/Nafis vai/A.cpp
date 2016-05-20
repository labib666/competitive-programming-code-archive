/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int dp[101][101][61], ar[61], pp[2001];
int go(int p, int g, int n, int b){
    if(p >= n){
        if(g == 0) return 1;
        return 0;
    }
    int &ret = dp[p][g][b];
    if(ret != -1) return ret;
    ret = 0;
    LL sum = 0;
    for(int i = p; i < n; i++){
        sum += pp[i];
        int fl = 0;
        for(int j = 45; j >= b; j--){
            if(ar[j] == 0 && (sum & 1ll<<j) > 0) fl = 1;
        }
        if(fl == 0){
            ret |= go(i + 1, g - 1, n, b);
        }
    }
    return ret;
}
int dp1[2001][61];
LL v;
int go1(int p, int b, int n){
    if(p >= n) return 0;
    int &ret = dp1[p][b];
    if(ret != -1) return ret;
    ret = 4000;
    LL sum = 0;
    for(int i = p; i < n; i++){
        sum += pp[i];
        int fl = 0;
//        for(int j = 45; j >= b; j--){
//            if(ar[j] == 0 && (sum & 1ll<<j) > 0) fl = 1;
//        }
        if((sum & v) > 0) fl = 1;
        if(fl == 0){
            ret = min(ret, go1(i + 1, b, n) + 1);
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, A, B; cin >> N >> A >> B;
    REP(i, N) cin >> pp[i];
    if(N <= 100 && A > 1){
        LL res = 0;
        memset(dp, -1, sizeof dp);
        for(int i = 45; i >= 0; i--){
            int fl = 0;
            for(int j = A; j <= B; j++){
                if(go(0, j, N, i)) {
                    fl = 1;
                    break;
                }
            }
            if(fl == 0) {
                ar[i] = 1;
                res |= 1ll<<i;
            }
        }
        cout << res << endl;
    } else {
        memset(dp1, -1, sizeof dp1);
        v = 0;
        for(int i = 45; i >= 0; i--){
            v |= 1ll<<i;
            if(go1(0, i, N) > B) {
                ar[i] = 1;
                v ^= 1ll<<i;
            }
        }
        LL res = 0;
        for(int i = 0; i <= 45; i++){
            if(ar[i]) res |= 1ll<<i;
        }
        cout << res << endl;
    }
}