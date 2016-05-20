/*
ID: Labib666
LANG: C++
Contest: Hacker Cup Round 1
Task: A
*/

#include <bits/stdc++.h>

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
#define LINF 1000000000000000007ll
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)

#define MAXN

int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

int s[10000007];

void FP () {
	for (int i=2; i<=10000000; i++) {
		if (s[i] != 0) continue;
		for (int j=1; j*i<=10000000; j++) s[i*j]++;
	}
	return;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen ("in.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    
    int t, tc=0, a, b, k, cnt;
    FP();
    
    scanf ("%d", &t);
    while (tc<t) {
		tc++;
		scanf ("%d%d%d", &a, &b, &k);
		
		cnt = 0;
		for (int i=a; i<=b; i++) if (s[i] == k) cnt++;
		printf ("Case #%d: %d\n", tc, cnt);
	}


    return 0;
}
