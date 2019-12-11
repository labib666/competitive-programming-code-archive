#include <bits/stdc++.h>using namespace std;#define pb push_back#define ff first#define ss second#define MP make_pair#define MIN(a,b) ((a)<(b)?(a):(b))#define MAX(a,b) ((a)>(b)?(a):(b))#define POPCOUNT __builtin_popcountll#define RIGHTMOST __builtin_ctzll#define LEFTMOST(x) (63-__builtin_clzll((x)))#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)#define CLR(x,y) memset(x,y,sizeof(x))#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)#define SQ(x) ((x)*(x))#define ABS(x) ((x)<0?-(x):(x))#define FABS(x) ((x)+eps<0?-(x):(x))#define ALL(x) (x).begin(),(x).end()#define LCM(x,y) (((x)/gcd((x),(y)))*(y))#define SZ(x) ((vlong)(x).size())#define Set(N,cur) N=(N|(1LL<<cur))#define Reset(N,cur) N=(N&(~(1LL<<cur)))#define Check(N,cur) (!((N&(1LL<<cur))==0))#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)#define nl printf("\n")#define phl cerr<<"hello\n"#define arrayIndexPrint(A,i) cerr<<"@ At pos: "<<i<<" = "<<A[i]#define dump(x) cerr<<"@ "<<#x<<" = "<<x<<endl#define arrayPrint(A,st,ed) cerr<<"@ Array:";FOR(i,st,ed) cerr<<" "<<A[i];cerr<<endl#define LINE cerr<<"\n"; FOR(i,0,50) cerr<<"=";cerr<<"\n\n"#ifdef forthright48     #include <ctime>     clock_t tStart = clock();     #define debug(args...) {dbg,args; cerr<<endl;}     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)     #define bug printf("%d\n",__LINE__);#else     #define debug(args...)  // Just strip off all debug tokens     #define timeStamp#endifstruct debugger{    template<typename T> debugger& operator , (const T& v){        cerr<<v<<" ";        return *this;    }}dbg;#define LL long long#define LLU long long unsigned inttypedef long long vlong;typedef unsigned long long uvlong;typedef pair < int, int > pii;typedef pair < vlong, vlong > pll;inline vlong gcd ( vlong a, vlong b ) {    a = ABS ( a ); b = ABS ( b );    while ( b ) { a = a % b; swap ( a, b ); } return a;}vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;    x2 = 1; y2 = 0; x1 = 0; y1 = 1;    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {        q = r2 / r1; r = r2 % r1;        x = x2 - (q * x1); y = y2 - (q * y1);    }    *X = x2; *Y = y2;    return r2;}inline vlong modInv ( vlong a, vlong m ) {    vlong x, y;    ext_gcd( a, m, &x, &y );    x %= m;    if ( x < 0 ) x += m;    return x;}inline vlong power ( vlong a, vlong p ) {    vlong res = 1, x = a;    while ( p ) {        if ( p & 1 ) res = ( res * x );        x = ( x * x ); p >>= 1;    }    return res;}inline vlong bigmod ( vlong a, vlong p, vlong m ) {    vlong res = 1 % m, x = a % m;    while ( p ) {        if ( p & 1 ) res = ( res * x ) % m;        x = ( x * x ) % m; p >>= 1;    }    return res;}inline int STRLEN(char *s){    int p = 0; while(s[p]) p++; return p;}//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};//int dir8[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};const double pi = 2 * acos ( 0.0 );const double eps = 1e-9;const LL inf = 2147383647LL;const LL mod = 1e9 + 7; /// CHANGE HEREconst int Size = 20004; /// CHANGE HERE///=========================  TEMPLATE ENDS HERE  ========================///vlong t, tc = 0;vlong n, k, c[100], dp[Size], tmp[Size];vlong val[Size], sum[Size], csum[Size], cadd[Size];string alph, s;// convex hull, minimumclass HullLinear {    int pointer; //Keeps track of the best line from previous query    vector<long long> M; //Holds the slopes of the lines in the envelope    vector<long long> B; //Holds the y-intercepts of the lines in the envelope    //Returns true if line l3 is always better than line l2    bool bad(int l1,int l2,int l3){        /*        intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)        intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)        set the former greater than the latter, and cross-multiply to        eliminate division. use deterministic comuputation with long        long if sufficient.        */        return (B[l3]-B[l1])*(M[l1]-M[l2])<(B[l2]-B[l1])*(M[l1]-M[l3]);    }    public:    void clear() {        pointer = 0;        M.clear();        B.clear();    }    //Adds a new line (with lowest slope) to the structure    void insert_line(long long m,long long b){        if ( M.size() > 0 && M.back() == m ) return; ///Same Gradient. Don't add.        //First, let's add it to the end        M.push_back(m);        B.push_back(b);        //If the penultimate is now made irrelevant between the antepenultimate        //and the ultimate, remove it. Repeat as many times as necessary        while (M.size()>=3&&bad(M.size()-3,M.size()-2,M.size()-1)){            M.erase(M.end()-2);            B.erase(B.end()-2);        }    }    //Returns the minimum y-coordinate of any intersection between a given vertical    //line and the lower envelope    long long eval(long long x){        //Any better line must be to the right, since query values are        //non-decreasing        while (pointer<M.size()-1 &&            M[pointer+1]*x+B[pointer+1]<M[pointer]*x+B[pointer]) {                pointer++;        }        return M[pointer]*x+B[pointer];    }} hull;inline vlong getConst(vlong u) {    return dp[u] - csum[u] + u * sum[u];}// m = u// c = getconst(u)// maximize u*sum[v] - c// minimize -u*sum[v] + cint main () {    #ifdef forthright48    freopen ( "input.txt", "r", stdin );    /// freopen ( "C.txt", "w", stdout );    #endif // forthright48    cin >> t;    while (tc<t) {        tc++;        cin >> alph;        cin >> k;        cin >> s;        //debug(alph, k, s);        for (vlong i=0; i<26; i++) {            c[alph[i]-'a'] = i;        }        n = s.size();        s = " " + s;        CLR(dp,0);        for (vlong i=1; i<=n; i++) {        	val[i] = c[s[i]-'a'];        	sum[i] = sum[i-1] + val[i];        	csum[i] = csum[i-1] + (i-1) * val[i];        	cadd[i] = cadd[i-1] + SQ(val[i]);            dp[i] = csum[i];            //debug(i, dp[i]);        }        for (vlong i=2; i<=k; i++) {            hull.clear();            hull.insert_line(-i+1, getConst(i-1));                        for (vlong j=i; j<=n; j++) {                tmp[j] = csum[j] + hull.eval(sum[j]);                hull.insert_line(-j, getConst(j));            }            for (vlong j=i; j<=n; j++) {            	//debug(j,tmp[j]);                dp[j] = tmp[j];            }        }        printf("Case %lld: %lld\n", tc, dp[n]-cadd[n]);    }    return 0;}