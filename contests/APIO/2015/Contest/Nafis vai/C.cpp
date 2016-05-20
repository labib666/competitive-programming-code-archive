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

pair < int, int > pp[100001], ar[200001];
LL sum_f[200001], sum_b[200001], on[200001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int K, N; cin >> K >> N;
    LL tmp = 0;
    int cnt = 0;
    REP(i, N){
        string s1, s2; cin >> s1 >> pp[cnt].xx >> s2 >> pp[cnt].yy;
        tmp += abs(pp[cnt].yy - pp[cnt].xx);
        if(s1 == s2){
            continue;
        }
        if(pp[cnt].xx > pp[cnt].yy)swap(pp[cnt].xx, pp[cnt].yy);
        cnt++;
        tmp++;
    }
    int cc = 0;
    REP(i, cnt){
        ar[cc++] = mp(pp[i].xx, -(i+1));
        ar[cc++] = mp(pp[i].yy, i+1);
    }
    sort(ar, ar + cc);
    if(K == 1){
        LL t = 0, d = 0;
        LL res = linf;
        if(cc == 0) res = 0;
        REP(i, cc){
            if(ar[i].yy > 0){
                t++; d += ar[i].xx;
            }
            sum_f[i] = (t*ar[i].xx - d) * 2ll;
        }
        t = d = 0;
        for(int i = cc-1; i >= 0; i--){
            if(ar[i].yy < 0){
                t++; d += (1000000000ll - ar[i].xx);
            }
            sum_b[i] = (t*(1000000000ll - ar[i].xx) - d) * 2ll;
//            cout << sum_f[i] << " " << sum_b[i] << endl;
            res = min(res, sum_b[i] + sum_f[i]);
        }
        cout << res+tmp << endl;
    } else {
        LL res = linf;
        if(cc == 0) res = 0;
        LL t = 0, d = 0;
        REP(i, cc){
            if(ar[i].yy > 0){
                t++; d += ar[i].xx;
            }
            sum_f[i] = (t*ar[i].xx - d) * 2ll;
        }
        t = d = 0;
        for(int i = cc-1; i >= 0; i--){
            if(ar[i].yy < 0){
                t++; d += (1000000000ll - ar[i].xx);
            }
            sum_b[i] = (t*(1000000000ll - ar[i].xx) - d) * 2ll;
//            cout << sum_f[i] << " " << sum_b[i] << endl;
            res = min(res, sum_b[i] + sum_f[i]);
        }

        REP(i, cc){
            REP(j, cnt) on[j] = 0;
            priority_queue < pair < LL, LL >, vector < pair < LL, LL > >, greater < pair < LL, LL > > > pq;
            t = d = 0;
            LL v = 0;
            for(int j = i + 1; j < cc; j++){
                while(pq.size() > 0){
                    pair < LL, LL > p1 = pq.top();
                    if(p1.xx < ar[j].xx) {
                        t--;
                        d -= pp[p1.yy].yy;
                        pq.pop();
                        v += pp[p1.yy].xx - ar[i].xx;
                    }
                    else break;
                }
                if(ar[j].yy < 0){
                    on[(-ar[j].yy) - 1] = 1;
                } else {
                    if(on[ar[j].yy - 1]){
                        pq.push(mp(ar[j].xx + pp[ar[j].yy-1].xx - ar[i].xx ,ar[j].yy - 1));
                        t++;
                        d += ar[j].xx;
                    }
                }
                res = min(res, sum_f[i] + sum_b[j] + ((t*ar[j].xx)-d + v)*2ll);
            }
        }
        cout << res+tmp << endl;
    }

}
