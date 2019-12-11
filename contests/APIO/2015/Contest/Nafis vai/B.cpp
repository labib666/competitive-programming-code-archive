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

map < int, int > mm[30001];
vector < int > vc[30001];
int vis[30001], ar[30001][301], on[30001], cnt[30001];
pair < int, int > pc[30001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    int st, ed;
    REP(i, m){
        int b, p; cin >> b >> p;
        vc[b].pb(p);
        cnt[p]++;
        if(i == 0) st = b;
        if(i == 1) ed = b;
    }

    for(int i = 1; i <= 30000; i++){
        pc[i] = mp(cnt[i], i);
    }
    sort(pc + 1, pc + 30001);
    reverse(pc + 1, pc + 30001);

    for(int i = 1; i <= 300; i++){
        on[pc[i].yy] = i;
    }

    queue < pair < int, pair < int, int > > > Q;
    REP(i, vc[st].size()){
        if(on[vc[st][i]] == 0)mm[st][vc[st][i]] = 1;
        else ar[st][on[vc[st][i]]] = 1;
        Q.push(mp(1, mp(st, vc[st][i])));
    }
    vis[st] = 1;
    while(!Q.empty()){
        pair < int, pair < int, int > > pp = Q.front();
        Q.pop();
        if(pp.yy.xx == ed){
            cout << pp.xx-1 << endl;
            return 0;
        }
        int c = pp.yy.xx + pp.yy.yy, v = pp.yy.yy;
        if(c < n && ((on[v] == 0 && mm[c][v] == 0) || (on[v] && ar[c][on[v]] == 0))){
            if(on[v] == 0)mm[c][v] = 1;
            else ar[c][on[v]] = 1;
            Q.push(mp(pp.xx + 1, mp(c, v)));
            if(vis[c] == 0){
                REP(j, vc[c].size()){
                    if(((on[vc[c][j]] == 0 && mm[c][vc[c][j]] == 0) || (on[vc[c][j]] && ar[c][on[vc[c][j]]] == 0))){
                        if(on[vc[c][j]] == 0)mm[c][vc[c][j]] = 1;
                        else ar[c][on[vc[c][j]]] = 1;
                        Q.push(mp(pp.xx+1, mp(c, vc[c][j])));
                    }
                }
                vis[c] = 1;
            }
        }
        c = pp.yy.xx - pp.yy.yy, v = pp.yy.yy;
        if(c >= 0 && ((on[v] == 0 && mm[c][v] == 0) || (on[v] && ar[c][on[v]] == 0))){
            if(on[v] == 0)mm[c][v] = 1;
            else ar[c][on[v]] = 1;
            Q.push(mp(pp.xx + 1, mp(c, v)));
            if(vis[c] == 0){
                REP(j, vc[c].size()){
                    if(((on[vc[c][j]] == 0 && mm[c][vc[c][j]] == 0) || (on[vc[c][j]] && ar[c][on[vc[c][j]]] == 0))){
                        if(on[vc[c][j]] == 0)mm[c][vc[c][j]] = 1;
                        else ar[c][on[vc[c][j]]] = 1;
                        Q.push(mp(pp.xx+1, mp(c, vc[c][j])));
                    }
                }
                vis[c] = 1;
            }
        }

    }
    cout << -1 << endl;
}