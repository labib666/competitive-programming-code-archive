/*
ID: Labib666
LANG: C++
Contest: IOI practice contest (unofficial) - 1
Task:
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

int DP[1002][2][1002], P[1002], N, M, C;
bool E[1002][1002];

int solve (int pos, int side, int des) {
    if (pos == des) {
        P[C--] = pos;
        return 1;
    }
    int &ret = DP[pos][side][des];
    if (ret != -1) return ret;

    if (side == 0) {
        int k = pos==1 ? N : pos-1;
        if (E[pos][des] && solve(des,1,k) == 1) {
            P[C--] = pos;
            return 1;
        }
        if (E[pos][k] && solve(k,0,des) == 1) {
            P[C--] = pos;
            return 1;
        }
    }
    else if (side == 1) {
        int k = pos%N + 1;
        if (E[pos][des] && solve(des,0,k) == 1) {
            P[C--] = pos;
            return 1;
        }
        if (E[pos][k] && solve(k,1,des) == 1) {
            P[C--] = pos;
            return 1;
        }
    }
    ret = 0;
    return ret;
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("2The Valley of Mexico.txt","r",stdin);

    int u, v;

    cin >> N >> M;
    REP (i,M) {
        cin >> u >> v;
        E[u][v] = 1;
        E[v][u] = 1;
    }

    MEM(DP,-1);
    C = N;

    FOR(i,1,N+1) {
        if (solve(i,0,i%N+1) == 0) continue;
        break;
    }

    if (C == N) cout << "-1\n";
    else {
        FOR(i,1,N+1)
            cout << P[i] << endl;
    }



    return 0;
}
