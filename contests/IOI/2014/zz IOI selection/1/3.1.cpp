/*
ID: Labib666
LANG: C++
Contest: IOI TST 1
Task: 3
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

LL gcd (LL a, LL b){return (b > a) ? gcd (b,a) : (b == 0ll) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (num%2ll) ans = (ans*num)%prime; return ans;
}

map <PLL,int> M;
PLL P[1502];
vector <PLL> V[1502];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("3.1.txt","r",stdin);

    LL N, i, j, k, xx, yy, sum = 0;

    cin >> N;

    for (i=0;i<N;i++) cin >> P[i].X >> P[i].Y;

    for (i=0;i<N;i++)
    {
        for (j=i+1;j<N;j++) {
            xx = P[i].X - P[j].X;
            yy = P[i].Y - P[j].Y;
            k = gcd (abs(xx),abs(yy));
            xx /= k, yy /= k;
            V[i].PB (MP (xx,yy));
            V[j].PB (MP (xx,yy));
        }
    }

    for (i=0;i<N;i++) {
        M.clear();
        for (j=0;j<V[i].SZ; j++) {
            PLL now = V[i][j];
            M[now]++;
        }
        for (j=0,k=0;j<V[i].SZ; j++)
            sum += M[MP(-V[i][j].Y,V[i][j].X)] + M[MP(V[i][j].Y,-V[i][j].X)];

    }

    cout << sum/2 << endl;


    return 0;
}
