/*
ID: Labib666
LANG: C++
Contest: US OPEN 2015
Task: Googol (brute)
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

LL googol (LL par) {
	LL c1, c2;
	cout << par << endl;
	cin >> c1 >> c2;
	LL v1 = (c1 == 0ll) ? 0ll : googol (c1);
	LL v2 = (c2 == 0ll) ? 0ll : googol (c2);
	return 1ll + v1 + v2;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);
    
    cout << "Answer " << googol (1ll) << endl;


    return 0;
}
