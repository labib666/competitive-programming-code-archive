/*
ID: Labib666
LANG: C++11
Contest: COCI Contest #5
Task: B
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

string s[1002];
int sum[1002];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("test.txt","r",stdin);
    
    int r, c, cnt, pos = 0, tot = 0;
    
    cin >> r >> c;
    for (int i=r-1; i>=0; i--) cin >> s[i];
    
    for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (s[i][j] == 'J') sum[i]++, tot++;
		}
	}
    
	for (int i=0; i<r; i++) {
		int lft, rgt;
		lft = c, rgt = -1;
		for (int j=0; j<c; j++) {
			if (s[i][j] == 'J') lft = min (lft,j), rgt = max (rgt, j);
		}
		if (rgt ==  -1) {
			cnt++; continue;
		}
		
		if ( i%2 ) {
			if (rgt > pos) cnt += (rgt-pos), pos = rgt;
			cnt += (pos -lft), pos = lft;
		}
		else {
			if (lft < pos) cnt += (pos-lft), pos = lft;
			cnt += (rgt -pos), pos = rgt;
		}
		
		tot -= sum[i];
		if (tot == 0) break;
		cnt++;
	}
	
	cout << cnt << endl;

    return 0;
}
