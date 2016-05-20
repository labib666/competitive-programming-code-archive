/*
ID: Labib Rashid
LANG: C++
TASK: 2
CONTEST: CodeJam 2014 R2
*/


#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


LL ar[1011], pre[1011], nxt[1011], ans;

main(){
    freopen("B-large.in", "r", stdin);
    freopen("B-large.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);

    LL a, b, ans;

    cin >> a;
    FOR(ts, 1, a + 1){
        cout << "Case #" << ts << ": ";

        cin >> b;
        ans = 0;

        set0(pre); set0(nxt);
        FOR(i, 1, b + 1) cin >> ar[i];

        for(int i = 1; i <= b; i++){
            for(int j = i - 1; j >= 1; j--) if(ar[j] > ar[i]) pre[i]++;
            for(int j = i + 1; j <= b; j++) if(ar[j] > ar[i]) nxt[i]++;
            ans += min(pre[i], nxt[i]);
        }

        cout << ans << endl;
     }
}

