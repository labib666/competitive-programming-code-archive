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

typedef pair<double, double> P;
#define EPS 1e-9
double polarAngle( P p )
{
    if( fabs( p.xx ) <= EPS && fabs( p.yy ) <= EPS ) return -1.0;
    if( fabs( p.xx ) <= EPS ) return ( p.yy > EPS ? 1.0 : 3.0 ) * acos( 0 );
    double theta = atan( 1.0 * p.yy / p.xx );
    if( p.xx > EPS ) return( p.yy >= -EPS ? theta : ( 4 * acos( 0 ) + theta ) );
    return( 2 * acos( 0 ) + theta );
}

P ar[3333];
double tmp[6666];
pair<double,int> tmp1[6666];
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    FOR(ts, 1, T+1){
        int n; cin >> n;
        REP(i, n){
            cin >> ar[i].xx >> ar[i].yy;
        }

        cout << "Case #" << ts << ":" << endl;
        cerr << "Case #" << ts << ":" << endl;

        REP(i, n){
            int cnt1 = 0, cnt = 0;
            REP(j, n){
                if(i == j) continue;
                tmp[cnt1++] = polarAngle(mp(ar[j].xx-ar[i].xx, ar[j].yy-ar[i].yy));
            }

            sort(tmp, tmp + cnt1);
            REP(j, cnt1){
                if(j == 0 || abs(tmp[j]-tmp[j-1])>EPS) tmp1[cnt++] = mp(tmp[j], 1);
                else tmp1[cnt-1].yy++;
            }
            REP(j, cnt) {
                tmp1[j+cnt] = tmp1[j];
                tmp1[j+cnt].xx += PI*2.0;
            }

            int last = -1, res = n-1, cur = n-1;
            while(tmp1[last+1].xx <= tmp1[cnt].xx-PI+EPS) {
                last++;
                cur -= tmp1[last].yy;
            }

//            REP(j, cnt+cnt) cout << tmp1[j].xx << " " << tmp1[j].yy << " " ;
//            cout << endl;

            for(int j = cnt; j < cnt+cnt; j++){
                cur += tmp1[j].yy;
                while(tmp1[last+1].xx <= tmp1[j].xx-PI+EPS) {
                    last++;
                    cur -= tmp1[last].yy;
                }
//                cout << cur << " " << last << " ";
                res = min(res, cur-tmp1[j].yy);
                res = min(res, n-1-cur);
            }
            cout << res << endl;
            cerr << res << endl;
        }


    }

}
