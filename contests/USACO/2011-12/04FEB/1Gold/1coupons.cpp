/*
ID: Labib Rashid
LANG: C++
TASK:
CONTEST: February 2012 Gold
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector <int>
#define VLL vector <LL>
#define PQI priority_queue <int>
#define PQLL priority_queue <LL>
#define QI queue <int>
#define QLL queue <LL>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define SZ size()
#define INF 1000000007
#define LINF 1000000000000000007
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)


int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

LL N, M, K;
PLL p[50004];

bool check (LL vl) {
    vector <PLL> v;
    priority_queue <PLL> q1, q2;
    LL cost = 0, k = min(K, vl);

    if (vl == 0) return 1;

    FOR (i,1,vl+1) { v.PB (MP(p[i].X-p[i].Y, i)); cost += p[i].X; }
    sort (v.begin(), v.end());
    reverse (v.begin(), v.end());

    FOR(i,0,k) {
        q1.push (MP (p[v[i].Y].Y, v[i].Y));
        cost -= v[i].X;
    }
    FOR(i,k,vl) {
        q2.push (MP (p[v[i].Y].X, v[i].Y));
    }

    if (k == 0) return (cost <= M);

    FOR(i,vl+1,N+1) {
        if (p[i].Y < q1.top().X) {
            PLL pp = q1.top(); q1.pop();
            q1.push(MP (p[i].Y,i)); cost += p[i].Y;
            if (!q2.empty() && p[pp.Y].X < q2.top().X) {
                PLL pp2 = q2.top(); q2.pop();
                q2.push(MP(p[pp.Y].X, pp.Y)); cost -= pp2.X;
            }
            else cost -= pp.X;
        }
    }

    if (cost < M) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen ("input.txt","r",stdin);
    //freopen ("coupons.in","r",stdin);
    //freopen ("coupons.out","w",stdout);

    LL hi, lo, mid;

    cin >> N >> K >> M;
    hi = N, lo = 0;

    FOR(i,1,N+1) cin >> p[i].X >> p[i].Y;
    sort (p+1,p+1+N);

    while (hi >= lo) {
        mid = (hi+lo)/2;
        if (check(mid)) lo = mid+1;
        else hi = mid-1;
    }

    cout << hi << endl;


    return 0;
}
