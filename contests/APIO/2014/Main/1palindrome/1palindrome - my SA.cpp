/*
ID: Labib Rashid
LANG: C++
TASK: 1palindrome
CONTEST: APIO
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
#include <string>
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
#define INF 1000000007ll
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

#define MAXN 300005
#define MAXLG 21

struct Data {
    int    e[2], p;
    bool operator < (const Data &d) const {
        return make_pair(e[0], e[1]) < make_pair(d.e[0], d.e[1]);
    }
} T[MAXN];

LL P[MAXLG][MAXN], D[MAXN], N, N1, stp, cnt, i, j, k;
string A, B;

int main()
{
    //freopen ("1palindrome.txt","r",stdin);
    //freopen ("palindrome.in","r",stdin);
    //freopen ("palindrome.out","w",stdout);

    cin >> A;
    N = A.size();



    for (i = 0; i < N; i++)
        P[0][i] = A[i]-'a';

    for (stp = 1, cnt = 1; cnt >> 1 < N; cnt <<= 1, stp++) {
        for (i=0; i<N; i++) {
            T[i].e[0] = P[stp-1][i];
            T[i].e[1] = (i+cnt < N) ? P[stp-1][i+cnt] : -1;
            T[i].p = i;
        }
        sort (T, T+N);
        for (i=0;i<N;i++) {
            P[stp][T[i].p] = (i>0 && T[i].e[0] == T[i-1].e[0] && T[i].e[1] == T[i-1].e[1]) ? P[stp][T[i-1].p] : i;
        }
    }



    for (i=1; i<N; i++) {
        int x = T[i-1].p, y = T[i].p;
        for (j = stp-1; j >= 0 && x < N && y < N; j--) {
            if (P[j][x] == P[j][y])
                x += (1<<j), y += (1<<j), D[i] += (1<<j);
        }
    }

    LL ans = 0;

    for (i=1; i<N-1; i++) {
        LL u, v, len;
        u = i, v = i+1; k = 0;
        len = max(D[u], D[v]);
        while (len != 0) {
            for (; u > 0; u--) {
                if (D[u] >= len) {if (T[u-1].p < N1) {k++;} continue;}
                break;
            }
            for (; v < N; v++) {
                if (D[v] >= len) {if (T[v].p < N1) { k++;} continue;}
                break;
            }
            ans = max (ans, k*len);
            len = max (D[u],D[v]);
        }
    }

    cout << ans << endl;


    return 0;
}
