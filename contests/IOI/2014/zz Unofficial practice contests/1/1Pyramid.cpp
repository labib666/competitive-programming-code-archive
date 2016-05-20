/*
ID: Labib666
LANG: C++
Contest: IOI practise contest (unofficial) - 1
Task: Pyramid
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

int B[1002][1002], T[1002][1002], C[1002][1002];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("1Pyramid.txt","r",stdin);

    int n, m, a, b, c, d, i, j, k, sum, tmp;

    cin >> m >> n >> b >> a >> d >> c;
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            cin >> B[i][j];
            T[i][j] = B[i][j];
        }
    }

    for (j=1;j<=n;j++) {
        for (i=1,sum=0;i<b;i++) sum += B[j][i];
        for (k = 1; i <= m; i++,k++) {
            sum += B[j][i];
            tmp = B[j][k];
            B[j][k] = sum;
            sum -= tmp;
        }
    }

    for (j=1;j<=m;j++) {
        for (i=1,sum=0;i<a;i++) sum += B[i][j];
        for (k = 1; i <= n; i++,k++) {
            sum += B[i][j];
            tmp = B[k][j];
            B[k][j] = sum;
            sum -= tmp;
        }
    }

    for (j=1;j<=n;j++) {
        for (i=1,sum=0;i<d;i++) sum += T[j][i];
        for (k = 1; i <= m; i++,k++) {
            sum += T[j][i];
            tmp = T[j][k];
            T[j][k] = sum;
            sum -= tmp;
        }
    }

    for (j=1;j<=m;j++) {
        for (i=1,sum=0;i<c;i++) sum += T[i][j];
        for (k = 1; i <= n; i++,k++) {
            sum += T[i][j];
            tmp = T[k][j];
            T[k][j] = sum;
            sum -= tmp;
        }
    }

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            C[i][j] = T[i][j];

    for (j=1;j<=n;j++) {
        priority_queue <PII> Q;
        bool V[1002]; MEM(V,0);
        for (i=2;i+d!=b;i++) Q.push( MP(-T[j][i], i));
        for (k = 2; i <= m-1; i++,k++) {
            Q.push( MP(-T[j][i], i));
            while (V[Q.top().Y]) Q.pop();
            T[j][k] = -Q.top().X;
            V[k] = 1;
        }
    }

    for (j=1;j<=m;j++) {
        priority_queue <PII> Q;
        bool V[1002]; MEM(V,0);
        for (i=2;i+c!=a;i++) Q.push( MP(-T[i][j], i));
        for (k = 2; i <= n-1; i++,k++) {
            Q.push( MP(-T[i][j], i));
            while (V[Q.top().Y]) Q.pop();
            T[k][j] = -Q.top().X;
            V[k] = 1;
        }
    }

    int ans = 0;
    PII now, cur;

    for (i=1; i+a<=n+1; i++) {
        for (j=1; j+b<=m+1; j++) {
            if (B[i][j] - T[i+1][j+1] > ans) {
                now = MP (i,j);
                ans = B[i][j] - T[i+1][j+1];
            }
        }
    }

    cout << now.Y << " " << now.X << endl;

    k = T[now.X+1][now.Y+1];
    for (i=now.X+1; i+c<now.X+a; i++) {
        for (j=now.Y+1; j+d<now.Y+b;j++) {
            if (T[now.X+1][now.Y+1] == C[i][j])
                cur = MP (i,j);
        }
    }

    cout << cur.Y << " " << cur.X << endl;



    return 0;
}
