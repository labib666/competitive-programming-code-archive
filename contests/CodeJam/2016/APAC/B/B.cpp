/*
    CodeJam APAC 2017
    Round: B
    Task: B
*/

/***********Template Starts Here***********/
//#include <bits/stdc++.h>#include <sys/resource.h>
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
//#include <sys/resource.h>
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

/*** FAST I/O ***/

//#define gc getchar
#define gc getchar_unlocked

void readInt(int &x){
    register char c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

void readVlong (vlong &x){
    register char c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

void readChar ( char &x ) {
    register char c = gc();
    while (c < 33) c = gc();
    x = c;
}

void readString(char *str){
    register char c = 0;
    register int i = 0;
    while (c < 33)
        c = gc();
    while (c != '\n') {
        str[i] = c;
        c = gc();
        i = i + 1;
    }
    str[i] = '\0';
}

/*** FAST I/O Ends ***/

/***********Template Ends Here***********/

int t, tc;vlong a, b, n, k;vlong ck[100005], ka[100005], kb[100005];vlong kd[22][100005], da[100005], db[100005];

int main () {

    /*** Stack Memory Increase ***/
    const rlim_t kStackSize = 256 * 1024 * 1024; // min stack size = 256 MB
    struct rlimit rl;
    int result;
    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0) {
        if (rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0) {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
    /*** Stack Memory Increase ends ***/


    #ifdef forthright48
    //freopen ( "input.txt", "r", stdin );
    freopen ( "B10.in", "r", stdin );
    freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    scanf("%d", &t);
    tc = 0;

    while (tc<t) {
        tc++;        cerr << "---------------- Case: " << tc << " ----------------------\n";
        printf("Case #%d:", tc);
        //nl;
        sp;

		scanf("%lld", &a);		scanf("%lld", &b);		scanf("%lld", &n);		scanf("%lld", &k);		CLR(ck, 0);		CLR(ka, 0);		CLR(kb, 0);		vlong tmp = n/k;		for (vlong i=0; i<k; i++) {			ck[i] = tmp;			if (i>0 && i<=n%k) ck[i]++;			//debug(i, ck[i])		}		for(vlong i=0; i<k; i++) {			kd[0][i] = i;		}		for (vlong pp=1; pp<22; pp++) {			for(vlong i=0; i<k; i++) {				kd[pp][i] = ( kd[ pp-1 ][ i ] * kd[ pp-1 ][ i ] ) % k;			}		}		for (vlong i=0; i<k; i++) {			vlong now = 1%k;			for (vlong j=0; j<22; j++) {				if (a&(1<<j)) {					now = (kd[j][i] * now) % k;				}			}			da[i] = now;		}		for (vlong i=0; i<k; i++) {			vlong now = 1%k;			for (vlong j=0; j<22; j++) {				if (b&(1<<j)) {					now = (kd[j][i] * now) % k;				}			}			db[i] = now;		}		//nl;		//for (vlong i=0; i<k; i++) {			//debug(i, ck[i], da[i], db[i], ka[i], kb[i]);		//}		vlong toomuch = 0;		for (vlong i=0; i<k; i++) {			ka[ da[i] ] += ck[i];			kb[ db[i] ] += ck[i];			ka[ da[i] ] %= mod;			kb[ db[i] ] %= mod;			if ( ( da[i] + db[i] ) % k == 0 ) {				toomuch += ck[i];				toomuch %= mod;			}		}		vlong tot = 0;		for (vlong i=0; i<k; i++) {			vlong j = ( k-i ) % k;			tot += (ka[i] * kb[j]) % mod;			tot %= mod;		}		vlong ans = tot - toomuch;		while (ans < 0) ans += mod;		printf("%lld\n", ans);
    }


    return 0;
}
