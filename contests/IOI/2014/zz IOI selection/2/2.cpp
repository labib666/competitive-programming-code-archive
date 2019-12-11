/*
ID: Labib666
LANG: C++
Contest: IOI TST 2
Task: 2
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
    if (num%2ll) ans = (ans*num)%prime; return ans;
}

int BIT[100002], S[100002], A[100002], N;

int Q(int pos) {
    int ans = 0;
    while (pos > 0) {
        ans += BIT[pos];
        pos -= pos&-pos;
    }
    return ans;
}

void U(int pos) {
    while (pos <= N) {
        BIT[pos]++;
        pos += pos&-pos;
    }
    return;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("2.txt","r",stdin);

    scanf ("%d", &N);
    FOR(i,1,N+1)
        scanf ("%d", &S[i]);

    FOR(i,1,N+1) {
        if (S[i] <= (N+1)/2)
            A[S[i]] = Q(N-S[i]+1)-Q(S[i]);
        U(S[i]);
    }

    MEM(BIT,0);

    for (int i=N; i>=1; i--) {
        if (S[i] > (N+1)/2)
            A[S[i]] = Q(S[i])-Q(N-S[i]+1);
        U(S[i]);
    }

    for (int i=1, j=N; i<j; i++, j--)
        printf ("%d\n%d\n", A[i], A[j]);


    if (N%2) printf ("0\n");

    return 0;
}
