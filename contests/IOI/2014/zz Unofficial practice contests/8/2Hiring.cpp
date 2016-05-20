/*
ID: Labib Rashid
LANG: C++
TASK: 2Hiring
CONTEST: IOI 2009 (IOI14 practice)
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
#define LINF 1000000000000000007ll
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

#define MAXN 500005

struct data {
    LL s, q, id;
    bool operator < (const data &b) const {
        return MP (b.q, b.s) > MP (q, s);
    }
};

bool cmp (data a, data b) {
    return b.s * a.q > a.s * b.q;
}

LL N, W, ans, pos, now; double vl;
data P[MAXN];
priority_queue < data > Q;

int main()
{
    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> W;
    FOR(i,1,N+1) {
        cin >> P[i].s >> P[i].q;
        P[i].id = i;
    }

    sort (P+1, P+1+N, cmp);
    ans = 0, vl = 1e16, now = 0;

    FOR(i,1,N+1) {
        Q.push(P[i]);
        now += P[i].q;
        while (!Q.empty()) {
            data aa = Q.top();
            if (P[i].q * W >= P[i].s * now) break;
            Q.pop(); now -= aa.q;
        }
        if (Q.size() > ans) {
            pos = i;
            ans = Q.size();
            vl = (double) P[i].s * now / (double) P[i].q;
        }
        else if (Q.size() == ans) {
            double cc = (double) P[i].s * now / (double) P[i].q;
            if (vl > cc) {
                vl = cc;
                pos = i;
            }
        }
    }

    while (!Q.empty()) Q.pop();
    now = 0;


    FOR(i,1,pos+1) {
        Q.push(P[i]);
        now += P[i].q;
        while (!Q.empty()) {
            data aa = Q.top();
            if (P[i].q * W >= P[i].s * now) break;
            Q.pop(); now -= aa.q;
        }
    }

    cout << ans << endl;
    while (!Q.empty()) {
        data aa = Q.top();
        Q.pop();
        cout << aa.id << endl;
    }

    return 0;
}
