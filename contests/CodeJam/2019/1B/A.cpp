/*
    CodeJam 2018
    Round: 1A
    Task:
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

#define MAXN 100005

int t, tc;
int p, q, x, y;
vector< pair<int, string> > v[MAXN];
char str[10]; string s;

int d[4*MAXN], h[4*MAXN], l[4*MAXN];

void init(int nd, int st, int ed) {
    if (st == ed) {
        d[nd] = st;
        l[nd] = h[nd] = 0;
        return;
    }
    int md = (st + ed) / 2;
    init(2*nd, st, md);
    init(2*nd+1, md+1, ed);
    d[nd] = st;
    l[nd] = h[nd] = 0;
}

void upd(int nd, int st, int ed, int p1, int p2, int val) {
    if (st > p2 || ed < p1) return;
    if (st >= p1 && ed <= p2) {
        l[nd] += val;
        h[nd] += val;
        return;
    }
    int md = (st + ed) / 2;
    if (l[nd] > 0) { 
        for (int i=2*nd; i<=2*nd+1; i++) {
            l[i] += l[nd];
            h[i] += l[nd];
        }
        l[nd] = 0;
    }
    upd(2*nd, st, md, p1, p2, val);
    upd(2*nd+1, md+1, ed, p1, p2, val);
    if (h[2*nd] >= h[2*nd+1]) {
        h[nd] = h[2*nd];
        d[nd] = d[2*nd];
    }
    else {
        h[nd] = h[2*nd+1];
        d[nd] = d[2*nd+1];
    }
}

int qry (int nd, int st, int ed, int p1, int p2){
    if (st > p2 || ed < p1) return 1;
    if (st >= p1 && ed <= p2) return nd;
    int md  = (st+ed)/2;
    if (l[nd] > 0) { 
        for (int i=2*nd; i<=2*nd+1; i++) {
            l[i] += l[nd];
            h[i] += l[nd];
        }
        l[nd] = 0;
    }
    int v1 = qry(2*nd, st, md, p1, p2);
    int v2 = qry(2*nd+1, md+1, ed, p1, p2);
    if ( h[v1] >= h[v2] ) {
        return v1;
    }
    else {
        return v2;
    }
}


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
        // nl;
        sp;

        scanf("%d %d", &p, &q);

        for (int i=0; i<=q; i++) {
            v[i].clear();
        }

        init(1,0,q);

        int best = 0;
        pii bestLoc{0,0};

        int sum = 0;

        for (int i=0; i<p; i++) {
            scanf("%d %d %s", &x, &y, str);
            s = str;
            v[x].push_back({y,s});
            if (s[0] == 'W') sum++;
            if (s[0] == 'N') upd(1, 0, q, y+1, q, 1);
            if (s[0] == 'S') upd(1, 0, q, 0, y-1, 1);
        }

        for (int i=0; i<=q; i++) {
            for (auto a: v[i]) {
                if (a.ss[0] == 'W') sum--;
            }

            // get max value and update best
            int cb = qry(1, 0, q, 0, q);
            int cp = d[cb];
            int cs = h[cb] + sum;
            if (cs > best) {
                best = cs;
                bestLoc = {i, cp};
            }

            for (auto a: v[i]) {
                if (a.ss[0] == 'E') sum++;
            }
        }
        printf("%d %d\n", bestLoc.ff, bestLoc.ss);
    }


    return 0;
}

