/*
    CodeJam APAC Test 2016
    Round: E
    Task:
*/

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

int ext_gcd ( int A, int B, int *X, int *Y ){
    int x, y, u, v, m, n, a, b, q, r;
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

inline vlong modInv ( int a, int m ) {
    int x, y;
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
LL n, q, u, v, ans;
LL a[200005];
LL s[1000006];
LL c[1000006];

LL elem(LL val) {
    LL i=0, j=0;
    LL ans = 0;
    while (i<n) {
        while (j<=n) {
            if (s[j]-s[i]>val) break;
            j++;
        }
        ans += j-i-1;
        i++;
    }
    return ans;
}

LL findval(LL pos) {
    LL hi=20000000, lo=0, mid;
    while (hi>=lo) {
        mid = (hi+lo)/2;
        LL el = elem(mid);
        if (el >= pos) hi = mid-1;
        else lo = mid+1;
    }
    return lo;
}

int main () {
    #ifdef forthright48
    //freopen ( "zz_test.txt", "r", stdin );
    freopen ( "Dl.in", "r", stdin );
    freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    tc = 0;
    scanf("%d", &t);
    while (tc < t) {
        tc++;
        printf("Case #%d:", tc);        // use space/newline accordingly
        //sp;
        nl;

        scanf("%lld%lld", &n, &q);
        for (LL i=0; i<n; i++) {
            scanf("%lld", &a[i]);
            s[i+1] = s[i]+a[i];
            c[i+1] = s[i+1]+c[i];
        }

        while (q--) {
            scanf("%lld%lld", &u, &v);

            LL vu = findval(u);
            LL vv = findval(v);


            if (vu == vv) {
                ans = (v-u+1) * vv;
            }
            else {
                ans = 0;
                ans += (elem(vu)-u+1) * vu;
                ans += (v-elem(vv-1)) * vv;
                if (vv > vu+1) {
                    LL i=0, j=0, k=0;
                    while (i<n) {
                        while (j<=n) {
                            if (s[j]-s[i]>vu) {  break; }
                            j++;
                        }
                        while (k<=n) {
                            if (s[k]-s[i]>=vv) {  break; }
                            k++;
                        }
                        j--; k--;

                        LL tmp = c[k]-c[j];
                        tmp -= (s[i])*(k-j);
                        ans += tmp;
                        i++;
                    }
                }
            }

            printf("%lld\n", ans);
        }

    }


    return 0;
}
