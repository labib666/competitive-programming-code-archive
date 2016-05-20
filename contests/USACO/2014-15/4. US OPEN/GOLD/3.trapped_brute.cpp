/*
ID: Labib666
LANG: C++
Contest: US OPEN 2015
Task: trapped_brute
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

PLL p[100005];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("trapped.in","r",stdin);
    freopen ("trapped.out","w",stdout);
    
    LL n;
    
    cin >> n;
    for (LL i=1; i<=n; i++) cin >> p[i].Y >> p[i].X;
    
    sort (p+1,p+n+1);
    
    LL ans = 0;
    for (int i=1; i<n; i++) {
		LL lft, ryt; lft = i, ryt = i+1;
		while ( (lft != 0ll) && (ryt != n+1ll) ) {
			if ( (p[ryt].X - p[lft].X) > p[ryt].Y ) {
				ryt++;
				continue;
			}
			else if ( (p[ryt].X - p[lft].X) > p[lft].Y ) {
				lft--;
				continue;
			}
			ans += p[i+1].X-p[i].X;
			break;
		}
	}
	
	cout << ans << endl;


    return 0;
}
