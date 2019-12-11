/*
ID: Labib Rashid
LANG: C++
TASK: necklace
CONTEST: USACO MAR13 GOLD
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

int N, M, f[1002], dp[10002][1002];
string s, str;

int solve (int pos, int vir) {

    if (vir == M) return INF;
    if (pos == N) return 0;

    int &rt = dp[pos][vir], pp;
    if (rt != -1) return rt;

    rt = solve(pos+1,vir)+1;
    pp = vir;

    while (1) {
        if (str[pp] == s[pos]) { pp++; break; }
        if (pp == 0) { break; }
        pp = f[pp];
    }

    rt = min (rt, solve(pos+1,pp));
    return rt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen ("input.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    cin >> s >> str;
    N = s.SZ, M = str.SZ;

    for (int i=2, j=0; i<=M; i++) {
        while (1) {
            if (str[j] == str[i-1]) { j++; f[i] = j; break; }
            if (j==0) break;
            j = f[j];
        }
    }
    MEM(dp, -1);
    cout << solve(0,0) << endl;

    return 0;
}
