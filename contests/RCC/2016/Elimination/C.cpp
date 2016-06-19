/***********Template Starts Here***********/
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <climits>
#include <iomanip>
#include <cassert>
#include <sstream>
//#include <unordered_map>

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(int i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(int i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((int)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((int)(x).size())

using namespace std;

#define LL long long
typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<pii> vii;
typedef vector<int> vi;

const vlong inf = 2147383647;
const vlong mod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp printf("Execution Time: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC)
#else
    #define debug(args...)  // Just strip off all debug tokens
    #define timeStamp
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};


inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x, y, u, v, m, n, a, b, q, r;
    x = 0; y = 1;
    u = 1; v = 0;
    for (a = A, b = B; 0 != a; b = a, a = r, x = u, y = v, u = m, v = n) {
        q = b / a;
        r = b % a;
        m = x - (u * q);
        n = y - (v * q);
    }
    *X = x; *Y = y;
    return b;
}

inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    if ( x < 0 ) x += m; //modInv is never negative
    return x;
}

inline vlong power ( vlong a, vlong p ) {
    vlong res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}

/***********Template Ends Here***********/
int t, tc;
int n, uu, vv, p[200005], d[200005], cc;int up[200005], best[200005], st[200005], en[200005];pii e[200005][2];vi v[200005];void balance(int p1, int p2) {	pii pp[4];	pp[0] = e[p1][0];	pp[1] = e[p1][1];	pp[2] = e[p2][0];	sort(pp,pp+3);	reverse(pp,pp+3);	e[p1][0] = pp[0];	e[p1][1] = pp[1];	return;}void dfs(int pos, int par, int dep) {	p[pos] = par;	d[pos] = dep;	cc++;	st[pos] = cc;	e[pos][0] = MP(dep,pos); e[pos][1] = MP(-1,-1);	//debug(pos, "----", e[pos][0].ss, e[pos][1].ss);	for (int i=0; i<v[pos].size(); i++) {		int j = v[pos][i];		if (j == par) continue;		dfs(j,pos,dep+1);		balance(pos,j);		//debug(pos, "----", e[pos][0].ss, e[pos][1].ss);	}	en[pos] = cc;	return;}void prec(int pos, int par) {	best[pos] = ( d[ e[pos][0].ss ] - d[pos] );	//debug("pos =", pos, par, e[pos][0].ss, e[pos][1].ss);	if (pos == 1) {		up[pos] = 0;	}	else {		up[pos] = 1+up[par];		int jj = e[par][0].ss;		int kk = e[par][1].ss;		if (st[jj] >= st[pos] && en[jj] <= en[pos]) {			up[pos] = MAX(up[pos], 1+d[kk]-d[par]);		}		else {			up[pos] = MAX(up[pos], 1+d[jj]-d[par]);		}	}	//debug("pos =", pos, par, up[pos], best[pos]);	best[pos] = MAX(up[pos],best[pos]);	for (int i=0; i<v[pos].size(); i++) {		int j = v[pos][i];		if (j == par) continue;		prec(j,pos);	}	return;}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    ios_base::sync_with_stdio(0);
    cin.tie(0);

	tc = 0;	cin >> t;	while (tc<t) {		tc++;		//debug("------------------", tc, "--------------------");		cin >> n;		for (int i=1; i<=n; i++) {			v[i].clear();		}		for (int i=1; i<n; i++) {			cin >> uu >> vv;			v[uu].pb(vv);			v[vv].pb(uu);		}		int fail = 0;		vector<int> pro;		for (int i=1; i<=n; i++) {			if (v[i].size() > 3) {				fail = 1;				break;			}			if (v[i].size() < 3) {				pro.pb(i);			}		}		if (fail || pro.size() == 0) {			cout << "-1\n";			continue;		}		sort(ALL(pro));		cc = 0;		dfs(1,0,1);		prec(1,0);		int res = pro[0], bestsofar = inf;		for (int i=0; i<pro.size(); i++) {			int j = pro[i];			//debug(j, "best[j] =", best[j], up[j]);			if (best[j] < bestsofar) {				bestsofar = best[j];				res = j;			}		}		//debug(res, "--", bestsofar);		int tot = bigmod(2ll,bestsofar+1,mod);		tot--;		while (tot < 0) tot += mod;		tot -= n;		while(tot < 0) tot += mod;		cout << res << " " << tot << endl;	}


    return 0;
}
