// B/***********Template Starts Here***********/
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
vlong t, tc = 0;vlong n;char s1[100004], s2[100004];
vlong dp[100005][4];void convert (vlong typ, vlong &b1, vlong &b2) {	if (typ == 0) return;	if (typ == 1) {		b1 ^= 1;		return;	}	if (typ == 2) {		b2 ^= 1;		return;	}	if (typ == 3) {		b1 ^= 1;		b2 ^= 1;		return;	} return;}vlong solve(vlong pos, vlong last) {	vlong b1 = s1[pos]-'0';	vlong b2 = s2[pos]-'0';	convert(last,b1,b2);	if (pos == n-1) {		return (b1 == b2) ? 0 : inf;	}	if (dp[pos][last] != -1) return dp[pos][last];	dp[pos][last] = inf;	if (b1 == b2) {		dp[pos][last] = MIN(dp[pos][last], solve(pos+1,0));		dp[pos][last] = MIN(dp[pos][last], solve(pos+1,3)+2);	}	else {		dp[pos][last] = MIN(dp[pos][last], solve(pos+1,1)+1);		dp[pos][last] = MIN(dp[pos][last], solve(pos+1,2)+1);	}	return dp[pos][last];}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

	scanf("%lld", &t);	while (tc<t) {		tc++;		scanf("%lld", &n);		scanf("%s", s1);		scanf("%s", s2);		for (vlong i=0; i<=n; i++) {			dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = -1;		}		vlong ans = solve(0,0);		if (ans >= inf) {			printf("-1\n");		}		else {			printf("%lld\n", ans);		}	}


    return 0;
}
