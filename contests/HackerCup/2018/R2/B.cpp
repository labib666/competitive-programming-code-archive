/*
    Hacker Cup 2018
    Round: A
    Task: B
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

vlong n, m, a, b, x, cur;
vlong c[200005];
vector<vlong> v[200005];
vector<pll> duos;

vlong s[200005], e[200005], ara[200005];

void dfs(vlong pos, int lvl) {
    ++cur;
    s[pos] = cur;
    ara[cur] = pos;
    duos.push_back(MP(lvl,pos));
    for (auto u: v[pos]) {
        dfs(u,lvl+1);
    }
    e[pos] = cur;
}

vlong d[4*200005];

void init(vlong nd, vlong st, vlong en) {
    if (st == en) {
        d[nd] = st;
        return;
    }
    vlong md = (st+en)/2;
    init(2*nd, st, md);
    init(2*nd+1, md+1, en);
    d[nd] = (ara[d[2*nd]]>ara[d[2*nd+1]]) ? d[2*nd] : d[2*nd+1];
    return;
}

vlong qry(vlong nd, vlong st, vlong en, vlong p1, vlong p2) {
    if (st > p2 || en < p1) return 0;
    if (st >= p1 && en <= p2) return d[nd];
    vlong md = (st+en)/2;
    vlong pv1 = qry(2*nd,st,md,p1,p2);
    vlong pv2 = qry(2*nd+1,md+1,en,p1,p2);
    return (ara[pv1]>ara[pv2]) ? pv1 : pv2;
}

void upd(vlong nd, vlong st, vlong en, vlong pos) {
    if (st == en) {
        ara[st] = 0 ;
        d[nd] = st;
        return;
    }

    vlong md = (st+en)/2;
    
    if (pos <= md) upd(2*nd,st,md,pos);
    else upd(2*nd+1,md+1,en,pos);

    d[nd] = (ara[d[2*nd]]>ara[d[2*nd+1]]) ? d[2*nd] : d[2*nd+1];
    return;
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
    freopen ( "inputB.txt", "r", stdin );
    freopen ( "outputB.txt", "w", stdout );
    #endif // forthright48

    scanf("%d", &t);
    tc = 0;


    while (tc<t) {
        tc++;
        cerr << "---------- Case: " << tc << " ---------\n";
        printf("Case #%d:", tc);
        //nl;
        sp;

        scanf("%lld", &n);
        scanf("%lld", &m);
        scanf("%lld", &a);
        scanf("%lld", &b);

        duos.clear();
        for (vlong i=0; i<n; i++) {
            v[i].clear();
            c[i] = 0;
        }

        for (vlong i=1; i<n; i++) {
            scanf("%lld", &x);
            v[x].push_back(i);
        }

        cur = 0;
        dfs(0,0);

        init(1,1,n);

        sort(ALL(duos));
        reverse(ALL(duos));

        for (vlong i=0; i<m; i++) {
            x = a * i + b;
            x %= n;
            c[x]++;
        }

        vlong res = 0;

        for (auto u: duos) {
            vlong v = u.ss;
            while (c[v] > 0) {
                c[v]--;
                vlong pos = qry(1,1,n,s[v],e[v]);
                res += ara[pos];
                upd(1,1,n,pos);
            }
        }

        printf("%lld\n" ,res);


    }


    return 0;
}

