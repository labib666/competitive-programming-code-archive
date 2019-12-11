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

__int128 ext_gcd ( __int128 A, __int128 B, __int128 *X, __int128 *Y ){
    __int128 x2, y2, x1, y1, x, y, r2, r1, q, r;
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

inline __int128 modInv ( __int128 a, __int128 m ) {
    __int128 x, y;
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
const vlong nmod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-11;


/***********Template Ends Here***********/

/*
1. Set MAXROW and MAXCOL of mat
2. Set row, col and mod of mat
3. Call clear(), then setup the matrix in a
4. Call gaussian() to perform gaussian-elimination and find rank (returns rank)
5. Call isValid() to find if solution exists.
6. Call gauss_jordan() to get values for variables
Careful about int a[x][x]. If mod^2 crosses int, take vlong.
If mod is 2, it is better to use XOR since it a lot faster.
*/

#define MAXROW 7
#define MAXCOL 7

struct GAUSS {
    __int128 mod;
    __int128 row, col, rank, freeVar;
    __int128 a[MAXROW][MAXCOL];    // the matrix
    bool valid;

    GAUSS() {
        mod = nmod;       // set mod here
    }
    void clear () {
        memset ( a, 0, sizeof a );
    }

    bool isValid () {
        __int128 i, st = rank;
        valid = true;
        for ( i = st; i < row; i++ ) {
            if ( a[i][col-1] ) {
                valid = false;
                return valid;
            }
        }
        return valid;
    }

    __int128 gaussian() {
        __int128 cRow = 0, cCol = 0, k, r, u;
        while (cRow < row && cCol < col - 1){
            r = cRow;
            for (k = r; k < row; k++) {
                if ( a[k][cCol] ) {
                    r = k;          ///Find non-zero coefficient
                    break;
                }
            }
            if ( a[r][cCol] ) {
                if (r != cRow) {    ///Swap row if required
                    swap( a[r], a[cRow] );
                }
                /// Neutralize if required. Not required if mod = 2
                __int128 w = a[cRow][cCol];
                w = modInv ( w, mod );
                for ( u = cCol; u < col; u++ ) {
                    a[cRow][u] = ( a[cRow][u] * w ) % mod;
                }

                for(u = cRow + 1; u < row; u++) {
                    if( a[u][cCol] ) {   /// Eliminate
                        __int128 v = a[u][cCol];
                        for(k = cCol; k < col; k++) {
                            // a[u][k] = ( ( a[cRow][k] & v ) ^ a[u][k] );    /// When mod = 2
                            a[u][k] = ( ( a[cRow][k] * v ) - a[u][k] ) % mod; /// Change here if no mod
                            if ( a[u][k] < 0 ) a[u][k] += mod;
                        }
                    }
                }
                cRow++;  /// increase rank
            }
            cCol++;
        }
        rank = cRow;
        freeVar = col - 1 - rank;
        return rank;
    }

    void gauss_jordan() {
        for(__int128 i = rank - 1; i>=0; i--)
        {
            __int128  j;
            for (j = 0; j < col-1; j++) {
                if ( a[i][j] ) {
                    break;
                }
            }
            for(__int128 k = i - 1; k >= 0; k--)
            {
                a[k][col-1] = ( a[k][col-1] - (a[k][j] * a[i][col-1]) ) % mod;
                if ( a[k][col-1] < 0 ) a[k][col-1] += mod;  /// change if no mod
                a[k][j] = 0;
            }
        }
    }

    void print() {  /// for debugging purpose
        nl;
        FOR(i,0,row-1){
            FOR(j,0, col-1){
                printf ( "%d ", a[i][j] );
            }
            nl;
        }
        nl;
    }

} mat;


int w, t, tc;
vlong d[10], res;

void printInt(int &x) {
    printf("%d\n", x);
    fflush(stdout);
}

int main () {
    #ifdef forthright48
    // freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    // fast_cin;
    // cerr << (vlong)(mat.mod-1) << endl;

    scanf("%d %d", &t, &w);
    if (t == -1 || w == -1) return 0;
    tc = 0;

    while (tc<t) {
        tc++;
        mat.clear();
        mat.row = 6;
        mat.col = 7;

        for (int i=0; i<6; i++) {
            for (int j=0; j<6; j++) {
                mat.a[i][j] = 1;
            }
        }
        mat.a[0][0] = 2;
        for (int i=2; i<=6; i++) {
            for (int j=1; j<=6; j++) {
                if (i % j == 0) {
                    mat.a[i-1][j-1] = mat.a[i-2][j-1] + mat.a[i-2][j-1];
                }
                else {
                    mat.a[i-1][j-1] = mat.a[i-2][j-1];
                }
            }
        }
        
        for (int i=1; i<=6; i++) {
            printInt(i);
            scanf("%lld", &d[i]);
            if (d[i] == -1) return 0;
            mat.a[i-1][6] = d[i];
        }

        // mat.print();

        mat.gaussian();
        mat.gauss_jordan();

        for (int i=1; i<=6; i++) {
            if (i != 1) sp;
            printf("%lld", mat.a[i-1][6]);
        } nl;
        fflush(stdout);

        scanf("%lld", &res);
        if (res == -1) return 0;
    }


    return 0;
}

