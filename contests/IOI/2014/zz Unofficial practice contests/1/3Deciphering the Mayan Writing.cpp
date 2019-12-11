/*
ID: Labib666
LANG: C++
Contest: IOI practise contest (unofficial) - 1
Task: Deciphering the Mayan Writing
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

int N, M;
int A[55], B[55], C[55];
string S1, S2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("3Deciphering the Mayan Writing.txt","r",stdin);

    int Ans = 0, total = 0;

    cin >> N >> M;
    cin >> S1 >> S2;

    REP(i,N) {
        if (S1[i] >= 'A' && S1[i] <= 'Z') A[S1[i]-'A']++;
        else  A[26+S1[i]-'a']++;
    }

    REP(i,N) {
        if (S2[i] >= 'A' && S2[i] <= 'Z') B[S2[i]-'A']++;
        else  B[26+S2[i]-'a']++;
    }

    REP(i,52) {
        if (A[i]==B[i]) continue;
        C[i] = 1; total++;
    }
    if (total == 0) Ans++;

    FOR(i,N,M) {
        int k = i-N, u;
        if (S2[k] >= 'A' && S2[k] <= 'Z') {
            u = S2[k]-'A';
            B[u]--;
            if (B[u] == A[u]) total--, C[u] = 0;
            else if (C[u] == 0) C[u] = 1, total++;
        }
        else {
            u = S2[k]-'a'+26;
            B[u]--;
            if (B[u] == A[u]) total--, C[u] = 0;
            else if (C[u] == 0) C[u] = 1, total++;
        }
        if (S2[i] >= 'A' && S2[i] <= 'Z') {
            u = S2[i]-'A';
            B[u]++;
            if (B[u] == A[u]) total--, C[u] = 0;
            else if (C[u] == 0) C[u] = 1, total++;
        }
        else {
            u = S2[i]-'a'+26;
            B[u]++;
            if (B[u] == A[u]) total--, C[u] = 0;
            else if (C[u] == 0) C[u] = 1, total++;
        }

        if (total == 0) Ans++;
    }

    cout << Ans << endl;


    return 0;
}
