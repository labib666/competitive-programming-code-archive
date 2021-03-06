/*
    CodeJam Kickstart 2018
    Round: A
    Task: C
*/

/***********Template Starts Here***********/

#include <bits/stdc++.h>
#include <sys/resource.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define nl puts("")
#define sp printf(" ")
#define phl debug("Hello")
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((vlong)(x).size())
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define SQ(x) ((x)*(x))
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define NORM(x) if(x>=mod) x-=mod;if(x<0) x+=mod;
#define ODD(x) (((x)&1)==0?(0):(1))
#define Set(N,cur) N=(N|(1LL<<cur))
#define Reset(N,cur) N=(N&(~(1LL<<cur)))
#define Check(N,cur) (!((N&(1LL<<cur))==0))
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<int> vi;
typedef vector<vlong> vl;
typedef vector<pll> vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, 
                    tree_order_statistics_node_update> pb_ds;

#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
     #define bug printf("%d\n",__LINE__);
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

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}


//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//int dir8[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};
const vlong inf = 2147383647;
const vlong mod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-11;


/***********Template Ends Here***********/

int t, tc;

vlong n, m, a, b, c, d, x[1000006];
string text;
string s[20003];
char str[1000006], d0[10], d1[10];
vlong h0[1000006], h1[1000006];

vlong hashWP(string &s, vlong p) {
    vlong res = 0, val;
    for (vlong i=0,j=1; i<s.size(); i++) {
        val = (s[i]-'a');
        for (vlong j=0; j<p; j++) {
            val = (val * val) % mod;
        }
        res = (res + val) % mod;
    } return res;
}

pll getHash(string &s) {
    pll res;
    res.ff = hashWP(s,2);
    res.ss = hashWP(s,3);
    return res;
}

pll getHashInRange(vlong l, vlong r) {
    pll res;
    vlong v0 = h0[r+1]-h0[l]; if (v0<0) v0 += mod;
    vlong v1 = h1[r+1]-h1[l]; if (v1<0) v1 += mod;
    res = MP(v0,v1);
    return res;
}

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
    freopen ( "C00.in", "r", stdin );
    freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    scanf("%d", &t);
    tc = 0;


    while (tc<t) {
        tc++;
        cerr << "---------------- Case: " << tc << " ----------------------\n";
        printf("Case #%d:", tc);
        //nl;
        sp;

        scanf("%lld", &m);

        for (vlong i=0; i<m; i++) {
            scanf("%s", str);
            s[i] = str;
        }

        scanf("%s %s %lld", d0, d1, &n);
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

        text = d0; text += d1;

        //debug(text);

        x[0] = text[0] - 'a' + 97;
        x[1] = text[1] - 'a' + 97;

        for (vlong i=2; i<n; i++) {
            vlong v0 = x[i-2];
            vlong v1 = x[i-1];
            x[i] = a * v1 + b * v0 + c;
            x[i] %= d;
            char cc = 'a' + x[i]%26;
            text += cc;
        }

        //debug(text);

        h0[0] = h1[0] = 0;
        for (vlong i=0; i<n; i++) {
            vlong val = (text[i]-'a');
            for (vlong kk =0; kk<2; kk++) {
                val = (val * val) % mod;
            }
            h0[i+1] = (h0[i] + val) % mod;
            val = (val * val) % mod;
            h1[i+1] = (h1[i] + val) % mod;
        }
        
        int res = 0;
        for (int i=0; i<m; i++) {
            if (s[i].size() > n) {
                continue;
            }
            pll now = getHash(s[i]);
            //debug(i, now.ff, now.ss);
            for (int j=0; j+s[i].size()<=n; j++) {
                if (text[j] != s[i][0]) continue;
                if (text[j+s[i].size()-1] != s[i][s[i].size()-1]) continue;
                if (now != getHashInRange(j,j+s[i].size()-1)) continue;
                res++;
                break;
            }
        }

        printf("%d\n", res);

    }


    return 0;
}

