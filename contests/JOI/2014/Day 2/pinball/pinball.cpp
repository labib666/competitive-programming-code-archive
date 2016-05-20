/*
ID: Labib Rashid
LANG: C++
TASK: pinball
CONTEST: JOI 2014 Day 2
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
#define INF 1000000007ll
#define LINF 1000000000000000007ll
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(LL I = (A); I < (B); ++I)
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

LL M, N, a[100005], b[100005], c[100005], d[100005];
LL dps[202][202][202]; //sub1 & sub2


LL solves (LL row, LL lft, LL ryt) {
    if (row == 0)
        return (a[lft]==1 && b[ryt]==N) ? 0 : LINF;

    LL &rt = dps[row][lft][ryt];
    if (rt != -1) return rt;

    LL nlft, nryt;
    rt = LINF;

    rt = min(rt,solves(row-1,lft,ryt));
    if (a[lft] <= c[row] && b[ryt] >= c[row]) {
        nlft = (a[lft]<=a[row]) ? lft : row;
        nryt = (b[ryt]>=b[row]) ? ryt : row;
        rt = min(rt, d[row]+solves(row-1,nlft,nryt));
    }

    return rt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    cin >> M >> N;
    FOR(i,1,M+1) cin >> a[i] >> b[i] >> c[i] >> d[i];

    // sub1 & sub2
    if (M <= 200) {
        MEM (dps, -1);
        LL ans = LINF;

        FOR(i,1,M+1) {
            ans = min (ans, d[i]+solves(i-1,i,i));
        }
        if (ans == LINF) ans = -1;

        cout << ans << endl;

        return 0;
    }

    // sub 3

    // sub 4

    cout << "0\n";

    return 0;
}
