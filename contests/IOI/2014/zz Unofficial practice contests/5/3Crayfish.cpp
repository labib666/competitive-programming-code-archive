/*
ID: Labib Rashid
LANG: C++
TASK: Crayfish Scrivener
CONTEST: IOI unofficial contest 5
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

#define MAXN 1000005
#define MAXLG 20

int P[MAXLG][MAXN], D[MAXN], N, K;
vector <PII> Q, U;
char C[MAXN], ch;
string S, t = "T", p = "P", u = "U";

int main()
{
    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    cin >> N;
    U.PB (MP (0,-1));

    FOR(i,0,N) {
        cin >> S;
        if (S == t) {
            cin >> ch;
            int now = U.SZ;
            U.PB (MP (now, U[now-1].Y+1));
            D[now] = U[now].Y;
            P[0][now] = U[now-1].X;
            C[now] = ch;
        }

        else if (S == p) {
            int now, cur = (int)U.SZ-1;
            cin >> now;
            Q.PB (MP (U[cur].X, U[cur].Y-now));
        }

        else {
            int now, cur = U.SZ-1;
            cin >> now;
            U.PB (U[cur-now]);
        }
    }

    int now = U.SZ;

    FOR(i,1,20) {
        FOR(j,1,now) {
            int pp = P[i-1][j];
            P[i][j] = (pp == 0) ? 0 : P[i-1][pp];
        }
    }

    FOR(i,0,Q.SZ) {
        int px = Q[i].X, py = Q[i].Y;
        FOR(j,0,20) {
            if (py&(1<<j)) {
                px = P[j][px];
            }
        }
        cout << C[px] << endl;
    }


    return 0;
}
