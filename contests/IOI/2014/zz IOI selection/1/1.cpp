/*
ID: Labib666
LANG: C++
Contest: IOI TST 1
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

VI V[100005];
int C[100005], L[100005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("1.txt","r",stdin);

    int N, E, i, j, k;

    cin >> N >> E;

    while (E--) {
        cin >> j >> k;
        if (j > k) swap (j, k);
        V[j].PB (k);
    }

    for (i = 1; i <= N; i++) sort ALL (V[i]);

    LL sum = 0;

    for (i = 1; i <= N; i++) {
        for (int u=0; u<V[i].size(); u++) {
            j = V[i][u];
            //cout << i << " " << j << " = " << C[j] << " " << L[j] << endl;
            if (L[j] == i) sum += C[j];
            for (int v=0; v<V[j].size(); v++) {
                k = V[j][v];
                //cout << i << " " << j << " " << k << endl;
                if (L[k] != i) {
                    L[k] = i;
                    C[k] = 1;
                }
                else C[k]++;
            }
        }
    }

    cout << sum << endl;


    return 0;
}
