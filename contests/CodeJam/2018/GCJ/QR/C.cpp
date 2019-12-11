/*
    CodeJam Kickstart 2018
    Round: A
    Task:
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
int dir8[9][2] = {{0,0},{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};
const vlong inf = 2147383647;
const vlong mod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-11;


/***********Template Ends Here***********/

int t, tc;
int n, a[2050][2050];

pii goCheck(int x, int y) {
    for (int i=0; i<9; i++) {
        int nx = x+dir8[i][0];
        int ny = y+dir8[i][1];
        if (a[nx][ny] == 0) return MP(nx,ny);
    } return MP(-1,-1);
}

int makeClear(int x, int y) {
    int px, py;
    while (1) {
        pii now = goCheck(x,y);
        if (now == MP(-1,-1)) break;
        printf("%d %d\n", x, y);
        fflush(stdout);
        scanf("%d %d", &px, &py);
        if (px == -1 && py == -1) return 0;
        if (px == 0 && py == 0) return 2;
        a[px][py] = 1;
    }
    return 1;
}

int main () {
    #ifdef forthright48
    //freopen ( "input.txt", "r", stdin );
    #endif // forthright48

    scanf("%d", &t);
    tc = 0;

    bool fail = 0, pass, now;

    while (tc<t) {
        tc++;
        //cerr << "---------------- Case: " << tc << " ----------------------\n";

        scanf("%d", &n);
        CLR(a,0);
        int cc = 0, x0, x1, y0, y1;
        pass = 0;

        if (n == 20) {
            x0 = 2, x1 = 4;
            y0 = 2, y1 = 3;   
        }
        else {
            x0 = 2, x1 = 34;
            y0 = 2, y1 = 5;
        }

        for (int k=x0; k<=x1; k+=2) {
            for (int i=y0, j=y1; i<=j; i+=2,j-=2) {
                now = makeClear(k,i);
                if (now == 2) {
                    pass = 1;
                    break;
                }
                if (now == 0) {
                    fail = 1;
                    break;
                }
                now = makeClear(k,j);
                if (now == 2) {
                    pass = 1;
                    break;
                }
                if (now == 0) {
                    fail = 1;
                    break;
                }
            }
            if (fail || pass) break;
        }
        if (fail) break;
    }


    return 0;
}

