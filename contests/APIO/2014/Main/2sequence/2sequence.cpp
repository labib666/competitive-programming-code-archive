/*
ID: Labib Rashid
LANG: C++
TASK: 2sequence
CONTEST: APIO
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
#define INF 1000000007ll
#define LINF 1000000000000000007ll
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
    if (num%2ll) ans = (ans*num)%prime; return ans;
}

LL DP[10002][202], T[10002][202], A[10002], N, K;

LL solve (LL pos, LL pas) {
    if (pas == 0) return 0;
    if (pos > N) return -LINF;

    LL &ret = DP[pos][pas];
    if (ret != -1ll) return ret;

    ret = -LINF;

    for (LL i=pos; i<N; i++) {
        LL k = solve(i+1,pas-1)+(A[i]-A[pos-1])*(A[N]-A[i]);
        if (ret < k){
            ret = k;
            T[pos][pas] = i;
        }
    }
    return ret;
}

void path (LL pos, LL pas) {
    if (pas == 0) return;
    if (pos > N) return;

    if (pas != K) cout << " ";
    cout << T[pos][pas];
    path(T[pos][pas]+1,pas-1);
    return;
}

int main()
{
    //freopen ("2sequence.txt","r",stdin);
    freopen ("sequence.in","r",stdin);
    freopen ("sequence.out","w",stdout);

    LL i, j, k;
    MEM(DP,-1);
    MEM(T,-1);

    cin >> N >> K;

    for (i=1; i<=N; i++) cin >> A[i];

    for (i=1; i<=N; i++) A[i] += A[i-1];

    cout << solve(1,K) << endl;
    path(1,K);
    cout << endl;


    return 0;
}
