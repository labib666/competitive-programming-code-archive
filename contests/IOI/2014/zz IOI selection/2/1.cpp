/*
ID: Labib666
LANG: C++
Contest: IOI TST 2
Task: 1
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

#define MAXN 52002
VI V1[55], V2[55];
int A[2*MAXN], N, P, L;
char S1[MAXN], S2[MAXN];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("1.txt","r",stdin);

    scanf ("%d%d", &P, &L);

    scanf ("%s%s", S1, S2);
    N = strlen (S1);

    FOR(i,0,N) {
        if (S1[i]>='A' && S1[i]<='Z') V1[S1[i]-'A'].PB (i);
        else V1[26+S1[i]-'a'].PB (i);
    }

    FOR(i,0,N) {
        if (S2[i]>='A' && S2[i]<='Z') V2[S2[i]-'A'].PB (i);
        else V2[26+S2[i]-'a'].PB (i);
    }

    FOR(i,0,52) {
        FOR(j,0,V1[i].SZ) {
            int u = V1[i][j];
            FOR(k,0,V2[i].SZ) {
                int v = V2[i][k];
                A[u-v+N]++;
            }
        }
    }

    int ans = -INF;
    FOR(i,1,2*N) {
        int k = i>N ? N-(i-N): i;
        k -= A[i];
        ans = max (ans, A[i]*P+k*L);
    }

    printf ("%d\n", ans);


    return 0;
}
