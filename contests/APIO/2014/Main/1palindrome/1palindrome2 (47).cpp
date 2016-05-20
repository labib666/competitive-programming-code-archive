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
    if (pow%2ll) {ans = (ans*num)%prime;} return ans;
}



string A;
map <LL,LL> M[10002];
LL H[10002], J[10002], N;

void Hash () {
    LL i, j, k;
    k = 1;
    for (i=0;i<N;i++) {
        if (i>0) H[i] = H[i-1];
        j = A[i]-'a'+1;
        j = (j*k)%INF;
        H[i] = (H[i]+j)%INF;
        k = (k*29ll)%INF;
    }
    return;
}

void findj () {
    FOR(i,0,N) {
        LL j = bigmod (29, i, INF);
        j = bigmod (j, INF-2, INF);
        J[i] = j;
    }
    return;
}

LL getHash (LL u, LL v) {
    LL k = (u>0ll) ? H[v]-H[u-1] : H[v];
    if (k < 0) k += INF;
    LL j = J[u];
    k = (k*j)%INF;
    return k;
}

int main()
{
    //freopen ("1palindrome.txt","r",stdin);
    freopen ("palindrome.in","r",stdin);
    freopen ("palindrome.out","w",stdout);

    LL i, j, k, ans = 1;

    cin >> A;
    N = A.size();

    Hash();
    findj();

    for (i = 0ll; i < N; i++) {

        for (j = i, k = i; j >=0 && k < N; j--, k++) {
            if (A[j] != A[k]) break;
            LL u = getHash (j, k);
            M[k-j+1][u]++;
            ans = max ((k-j+1)*M[k-j+1][u], ans);
        }

        for (j = i, k = i+1; j >=0 && k < N; j--, k++) {
            if (A[j] != A[k]) break;
            LL u = getHash (j, k);
            M[k-j+1][u]++;
            ans = max ((k-j+1)*M[k-j+1][u], ans);
        }
    }

    cout << ans << endl;


    return 0;
}
