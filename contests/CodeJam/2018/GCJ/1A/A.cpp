/*
    CodeJam 2018
    Round: 1A
    Task: A
*/

/***********Template Starts Here***********/

#include <bits/stdc++.h>
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

int r, c, h, v, ckc, sum[103][103];
string s[103];
char str[103];
vector<int> hc, vc;

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    // fast_cin;

    scanf("%d", &t);
    tc = 0;

    while (tc<t) {
        tc++;
        cerr << "--------- Case: " << tc << " ---------\n";
        printf("Case #%d:", tc);
        //nl;
        sp;


        scanf("%d %d %d %d", &r, &c, &h, &v);
        //debug(h,v,(h+1)*(v+1));

        s[0] = "";
        for (int i=0; i<=c; i++) {
            s[0] += "#";
        }
        //debug(0,s[0]);

        ckc = 0;
        for (int i=1; i<=r; i++) {
            scanf("%s", str);
            s[i] = str;
            s[i] = "#" + s[i];
            for (int j=1; j<=c; j++) {
                if (s[i][j] == '@') ckc++;
            }
            //debug(i,s[i]);
        }

        //debug("Cookie: ", ckc);
        
        hc.clear();
        vc.clear();
        hc.push_back(0);
        vc.push_back(0);

        if (ckc % ((h+1)*(v+1)) != 0) {
            puts("IMPOSSIBLE");
            continue;
        }

        int tcc, fail = 0;

        tcc = ckc / (h+1);
        for (int i=1, k=0; i<=r; i++) {
            for (int j=1; j<=c; j++) {
                if (s[i][j] == '@') {
                    k++;
                }
            }
            if (k < tcc) {
                continue;
            }
            if (k > tcc) {
                fail = 1;
                break;
            }
            if (k == tcc) {
                k = 0;
                hc.push_back(i);
            }
        }

        if (fail) {
            puts("IMPOSSIBLE");
            continue;
        }
        //phl;

        tcc = ckc / (v+1);
        for (int i=1, k=0; i<=c; i++) {
            for (int j=1; j<=r; j++) {
                if (s[j][i] == '@') {
                    k++;
                }
            }
            //debug(i,k);
            if (k < tcc) {
                continue;
            }
            if (k > tcc) {
                fail = 1;
                break;
            }
            if (k == tcc) {
                k = 0;
                vc.push_back(i);
            }
        }

        if (fail) {
            puts("IMPOSSIBLE");
            continue;
        }
        //phl;

        tcc = ckc / ((h+1)*(v+1));
        for (int i=1; i<hc.size(); i++) {
            for (int j=1; j<vc.size(); j++) {
                //debug(hc[i-1],hc[i],vc[j-1],vc[j]);
                int k = 0;
                for (int xx=hc[i-1]+1; xx<=hc[i]; xx++) {
                    for (int yy=vc[j-1]+1; yy<=vc[j]; yy++) {
                        if (s[xx][yy]=='@') k++;
                    }
                }
                if (k != tcc) {
                    fail = 1;
                    break;
                }
            }
            if (fail) {
                break;
            }
        }

        if (fail) {
            puts("IMPOSSIBLE");
            continue;
        }
        else {
            puts("POSSIBLE");
            continue;
        }

    }


    return 0;
}

