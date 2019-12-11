/*
ID: Labib666
LANG: C++
Contest: IOI TST 1
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

LL A[500005];
stack <PLL> S;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("2.txt","r",stdin);

    LL N, sum = 0, i, j, k;

    cin >> N;
    for (i=N; i>0; i--) cin >> A[i];

    for (i = 1; i <= N; i++) {

        while (!S.empty()) {
            PLL now = S.top();
            if (now.X < A[i]) {
                sum++;
                S.pop();
            }
            else break;
        }

        if (S.empty()) {S.push (MP(A[i],0)); continue;}
        if (S.top().X == A[i]) {
            sum += S.top().Y+1;
            S.push (MP(A[i], S.top().Y+1));
        }
        else {
            sum++;
            S.push (MP(A[i], 1));
        }
    }

    cout << sum << endl;

    return 0;
}
