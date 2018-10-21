/*
    CodeJam Kickstart 2018
    Round: G
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

vlong n, q;
vlong totStudent, L[400005], R[400005], K[400005];
vlong d[50000006], lazy[50000006], l[50000006], r[50000006];
vlong cc, maxval = mod-7;

vlong init() {
    ++cc;
    d[cc] = lazy[cc] = 0;
    l[cc] = r[cc] = -1;
    return cc;
}

void upd(vlong nd, vlong st, vlong en, vlong p1, vlong p2) {
    //debug("U", nd, st, en, p1, p2);
    if (p1 > en || p2 < st) {
        //debug(nd,st,en,"->",d[nd]);
        return;
    }
    if (st >= p1 && en <= p2) {
        d[nd] += (en - st + 1);
        lazy[nd]++;
        //debug(nd,st,en,"->",d[nd]);
        return;
    }
    vlong md = (st+en)/2;
    if (l[nd] == -1) {
        l[nd] = init();
    }
    if (r[nd] == -1) {
        r[nd] = init();
    }
    vlong lc = l[nd], rc = r[nd];
    if (lazy[nd] > 0) {
        d[lc] += (md - st + 1) * lazy[nd];
        lazy[lc] += lazy[nd];
        //debug("-->",lc,d[lc]);
        d[rc] += (en - (md+1) + 1) * lazy[nd];
        lazy[rc]  += lazy[nd];
        //debug("-->",rc,d[rc]);
        lazy[nd] = 0;
        d[nd] = d[lc] + d[rc];
    }
    upd(lc,st,md,p1,p2);
    upd(rc,md+1,en,p1,p2);
    d[nd] = d[lc] + d[rc];
    //debug(nd,st,en,"->",d[nd]);
    return;
}

vlong qry(vlong nd, vlong st, vlong en, vlong p1, vlong p2) {
    //debug("Q",nd, st, en, p1, p2);    
    if (p1 > en || p2 < st) {
        return 0;
    }
    if (st >= p1 && en <= p2) {
        return d[nd];
    }
    vlong md = (st+en)/2;
    if (l[nd] == -1) {
        l[nd] = init();
    }
    if (r[nd] == -1) {
        r[nd] = init();
    }
    vlong lc = l[nd], rc = r[nd];
    if (lazy[nd] > 0) {
        d[lc] += (md - st + 1) * lazy[nd];
        lazy[lc]  += lazy[nd];
        d[rc] += (en - (md+1) + 1) * lazy[nd];
        lazy[rc]  += lazy[nd];
        lazy[nd] = 0;
        d[nd] = d[lc] + d[rc];
    }
    vlong vl = qry(lc,st,md,p1,p2);
    vlong vr = qry(rc,md+1,en,p1,p2);
    return vl+vr;
}

bool check(vlong val, vlong goal) {
    vlong cnt = qry(1,1,maxval,1,val);
    return cnt >= goal;
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
    freopen ( "B01.in", "r", stdin );
    freopen ( "Boutput2.txt", "w", stdout );
    #endif // forthright48

    scanf("%d", &t);
    tc = 0;


    while (tc<t) {
        tc++;
        cerr << "---------- Case: " << tc << " ---------\n";
        printf("Case #%d:", tc);
        //nl;
        sp;

        totStudent = 0;

        cin >> n >> q;

        vlong X[3], Y[3], Z[3], A[3], B[3], C[3], M[3];

        for (vlong i=0; i<3; i++) {
            if (i==0) {
                cin >> X[0] >> X[1];
            }
            else if (i==1) {
                cin >> Y[0] >> Y[1];
            }
            else {
                cin >> Z[0] >> Z[1];
            }
            cin >> A[i] >> B[i] >> C[i] >> M[i];
        }

        cc = 0;
        init();
        
        for (vlong i=0; i<MAX(n,q); i++) {
            if (i<2) {
                L[i] = MIN(X[i], Y[i]) + 1;
                R[i] = MAX(X[i], Y[i]) + 1;
                K[i] = Z[i] + 1;
            }
            else {
                X[2] = (A[0] * X[1] + B[0] * X[0] + C[0]) % M[0];
                Y[2] = (A[1] * Y[1] + B[1] * Y[0] + C[1]) % M[1];
                Z[2] = (A[2] * Z[1] + B[2] * Z[0] + C[2]) % M[2];
                L[i] = MIN(X[2], Y[2]) + 1;
                R[i] = MAX(X[2], Y[2]) + 1;
                K[i] = Z[2] + 1;
                for (vlong j=0; j<=1; j++) {
                    X[j] = X[j+1];
                    Y[j] = Y[j+1];
                    Z[j] = Z[j+1];
                }
            }
            if (i<n) {
                //phl;
                //debug("ASK");
                //debug(qry(1,1,maxval,7,8));
                //debug("Update");
                upd(1,1,maxval,L[i],R[i]);
                //debug("ASK");
                //debug(qry(1,1,maxval,7,8));
                totStudent += (R[i]-L[i]) + 1;
            }
            //debug("-----", i, L[i], R[i], K[i]);
        }

        vlong res = 0;
        //debug("QRY");

        for (vlong i=0; i<q; i++) {
            //debug(K[i], totStudent);
            if (K[i] > totStudent) {
                continue;
            }
            vlong pos = totStudent - K[i] + 1;
            vlong hi = maxval, lo = 1, md;
            while (hi>=lo) {
                md = (hi+lo)/2;
                if (check(md,pos)) {
                    hi = md - 1;
                }
                else {
                    lo = md + 1;
                }
            }
            res += (i+1) * lo;
        }
        printf("%lld\n", res);
    }


    return 0;
}



