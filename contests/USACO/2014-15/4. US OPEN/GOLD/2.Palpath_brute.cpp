/*
ID: Labib666
LANG: C++
Contest: US OPEN 2015
Task: palpath_brute
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
#define INF 1000000007ll
#define LINF 1000000000000000007ll
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)

#define MAXN

LL n, ans;
string s[512];
map <LL,LL> m[512];


struct data{
    LL count;
    data *child[26];
    data()
    {
        count = 0;
        memset(child, 0, sizeof (child));
    }
} *root[512];

void build (LL px, LL py, data *p) {
	//cout << px << " " << py << endl;
	if (px == 0 && py == 0) {
		p->count++;
		return;
	}
	LL nx = px-1, ny = py-1;
	if (nx >= 0) {
		LL val = (s[nx][py] - 'A');
		if (p->child[val] == NULL) p->child[val] = new data();
		build (nx, py, p->child[val]);
	}
	if (ny >= 0) {
		LL val = (s[px][ny] - 'A');
		if (p->child[val] == NULL) p->child[val] = new data();
		build (px, ny, p->child[val]);
	}
	return;
}

void calc (LL px, LL py, data *p) {
	//cout << px << " " << py << endl;
	if (px == n-1 && py == n-1) {
		ans += p->count; ans %= INF;
		return;
	}
	LL nx = px+1, ny = py+1;
	if (nx < n) {
		LL val = (s[nx][py] - 'A');
		if (p->child[val] != NULL) calc (nx, py, p->child[val]);
	}
	if (ny < n) {
		LL val = (s[px][ny] - 'A');
		if (p->child[val] != NULL) calc (px, ny, p->child[val]);
	}
	return;
}


/*void hsh (LL step, LL px, LL py, LL sum, LL mod) {
	LL val = (s[px][py] - 'A') + 1;
	val = (val * mod) % INF;
	sum = (sum + val) % INF;
	if (step == n) { m[px][sum]++; return; }
	
	mod = (mod * 29ll) % INF;
	LL nx = px+1, ny = py+1;
	hsh(step+1, nx, py, sum, mod);
	hsh(step+1, px, ny, sum, mod);
	return;
}

void calc (LL step, LL px, LL py, LL sum, LL mod) {
	LL val = (s[px][py] - 'A') + 1;
	val = (val * mod) % INF;
	sum = (sum + val) % INF;
	if (step == n) { ans += m[px][sum]; ans %= INF; return; }
	
	mod = (mod * 29ll) % INF;
	LL nx = px-1, ny = py-1;
	calc(step+1, nx, py, sum, mod);
	calc(step+1, px, ny, sum, mod);
	return;
}
*/

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("palpath.in","r",stdin);
    freopen ("palpath.out","w",stdout);
    
    cin >> n; ans = 0;
    for (LL i=0; i<n; i++) cin >> s[i];
    
    /*hsh(1,0,0,0,1);
	calc (1,n-1,n-1,0,1);*/
	
	for (int i=n-1, j=0, k=0; i>=0; i--,j++,k++) {
		//cout << i << " -> " << j << " starts\n";
		root[k] = new data();
		build(i,j,root[k]);
		//cout << "match\n";
		calc(i,j,root[k]);
	}
	
	cout << ans << endl;

    return 0;
}
