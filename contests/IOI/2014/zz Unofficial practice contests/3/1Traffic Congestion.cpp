/*
ID: Labib Rashid
LANG: C++
TASK: Traffic Congestion
CONTEST: unofficial ioi14 practice contest
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

using namespace std;

int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

#define MAXN 1000006
int A[MAXN], N, B[MAXN];
VI V[MAXN];

int dfs1 (int pos, int par) {
    FOR(i,0,V[pos].SZ) {
        int j = V[pos][i];
        if (j == par) continue;
        int k = dfs1(j, pos);
        B[pos] = max (B[pos], k);
        A[pos] += k;
    }
    return A[pos];
}

void dfs2 (int pos, int par) {
    int k = par==-1 ? 0 : A[par]-A[pos];
    B[pos] = max(B[pos], k);
    A[pos] += k;
    FOR(i,0,V[pos].SZ) {
        int j = V[pos][i];
        if (j == par) continue;
        dfs2(j, pos);
    }
    return;
}

int main()
{
    //freopen ("1Traffic Congestion.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    cin >> N;
    REP(i,N) {
        cin >> A[i];
    }

    REP(i,N-1) {
        int j, k;
        cin >> j >> k;
        V[j].PB (k);
        V[k].PB (j);
    }

    dfs1(0,-1);
    dfs2(0,-1);

    int ans = 2*INF, city;
    REP(i,N) {
        ans = min (B[i], ans);
        if (ans == B[i]) city = i;
    }

    cout << city << endl;

    return 0;
}
