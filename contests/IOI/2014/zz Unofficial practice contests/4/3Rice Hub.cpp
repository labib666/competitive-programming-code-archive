/*
ID: Labib666
LANG: C++
Contest: IOI unofficial practice 4
Task: Rice hub
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

#define MAXN 100005ll

LL N, L, B, A[MAXN], S1[MAXN], S2[MAXN], Ans;

bool Check (LL val) {
    LL u, v, w, s1, s2;

    for (u=0, v=val-1, w=v/2; v < N; u++, v++, w++) {
        s1 = S1[w]-S1[u]-u*(A[w]-A[u]);
        s2 = S2[w]-S2[v]-(N-v-1)*(A[v]-A[w]);
        if (s1+s2 <= B) return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("3Rice Hub.txt","r",stdin);

    LL hi, lo, mid, u;

    cin >> N >> L >> B;

    FOR(i,0,N)
        cin >> A[i];

    FOR(i,1,N) {
        S1[i] = S1[i-1] + i*(A[i]-A[i-1]);
    }

    for (u=N-2;u>=0;u--) {
        S2[u] = S2[u+1]+(N-u-1)*(A[u+1]-A[u]);
    }

    hi = N, lo = 0;
    while (hi >= lo) {
        mid = (hi+lo)/2;
        if (Check(mid)) lo = mid+1;
        else hi = mid-1;
    }

    Ans = hi;

    cout << Ans << endl;

    return 0;
}
