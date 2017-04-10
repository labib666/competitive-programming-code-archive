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

#define pb push_back

#define ss second

#define MP make_pair

#define CLR(x,y) memset(x,y,sizeof(x))

#define MIN(a,b) ((a)<(b)?(a):(b))

#define ABS(x) ((x)<0?-(x):(x))

using namespace std;

typedef long long vlong;

typedef pair < int, int > pii;

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
    #define debug(args...)  
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
    if ( x < 0 ) x += m; 
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

#define NODE 250
#define EDGE 100005

struct node {
    int x, y, next, cap, cost;
};

struct FLOW {
    int source, sink;

    int head[NODE];
    void clear() {
        e = 0;
        CLR(head,-1);
    }

    node edge[EDGE]; int e;
    void addEdge ( int u, int v, int cap, int cap2, int cost ) {
        edge[e].x = u; edge[e].y = v; edge[e].cap = cap; edge[e].cost = cost;
        edge[e].next = head[u]; head[u] = e; e++;
        edge[e].x = v; edge[e].y = u; edge[e].cap = cap2; edge[e].cost = -cost;
        edge[e].next = head[v]; head[v] = e; e++;
    }

    int vis[NODE], q[NODE], now[NODE];
    bool bfs ( ) {
        memset ( vis, -1, sizeof vis );
        vis[source] = 0;
        int ini = 0, qend = 0;
        q[qend++] = source;

        while ( ini < qend && vis[sink] == -1 ) {
            int s = q[ini++];
            int i;
            for (i=head[s];i!=-1;i= edge[i].next){
                int t = edge[i].y;
                if ( vis[t] == -1 && edge[i].cap){
                    vis[t] = vis[s] + 1;
                    q[qend++] = t;
                }
            }
        }
        if ( vis[sink] != -1 ) return true;
        else return false;
    }
    int dfs ( int s, int f ) {
        if ( f == 0 ) return 0;
        if ( s == sink ) return f;
        for ( int &i=now[s];i!=-1;i=edge[i].next){
            int t = edge[i].y;
            if ( vis[s] + 1 != vis[t] ) continue;
            int pushed=dfs(t,MIN(f,edge[i].cap));
            if ( pushed ) {
                edge[i].cap -= pushed;
                edge[i^1].cap += pushed;
                return pushed;
            }
        }
        return 0;
    }

    int maxFlow ( int limit, int flow ) {
        int res = 0;
        while ( 1 ) {
            if ( flow == 0 ) break;
            if ( bfs () == false ) break;
            int i;
            for ( i=0;i<=limit;i++)now[i]= head[i];
            while (int pushed=dfs(source,flow ) ) {
                res += pushed; 
                flow -= pushed;
            }
        }
        return res;
    }

    int inq[NODE], par[NODE], record[NODE];
    pii minCostFlow ( int limit ) {
        int res = 0, i, fl = 0;
        while ( 1 ) {

            for ( i = 0; i <= limit; i++ ) vis[i] = inf; 
            vis[source] = 0;
            deque < int > dq;
            dq.pb ( source );
            while ( !dq.empty() ) {
                int s = dq.front(); dq.pop_front();

                inq[s] = 0;
                for ( i = head[s]; i != -1; i = edge[i].next ) {
                    int t = edge[i].y;
                    if ( edge[i].cap ) {
                        if ( vis[s] + edge[i].cost < vis[t] ) { 
                            vis[t] = vis[s] + edge[i].cost;
                            par[t] = s;
                            record[t] = i;
                            if ( inq[t] == 0 ) {
                                inq[t] = 1;
                                if ( dq.empty() == false && vis[dq.front()] > vis[t] ) dq.push_front( t ); 
                                else dq.pb ( t );
                            }
                        }
                    }
                }
            }

            if ( vis[sink] == inf ) break; 
            fl++; 
            res += vis[sink]; 
            for ( i = sink; i != source; i = par[i] ) { 
                int t = record[i]; 
                edge[t].cap--;
                edge[t^1].cap++;
            }
        }

        return MP(res,fl); 
    }

} g;

class BearGridRect {
public:
	vector <int> findPermutation(int N, vector <int> r1, vector <int> r2, vector <int> c1, vector <int> c2, vector <int> cnt) {
		int M = r1.size();

		g.clear();

		for (int i=2*N+1; i<=2*N+M; i++) {
			for (int j=r1[i-2*N-1]; j<=r2[i-2*N-1]; j++) {
				g.addEdge(j+1,i,1,0,0);

			}
		}

		for (int i=2*N+M+1; i<=2*N+M+M; i++) {
			for (int j=c1[i-2*N-1-M]; j<=c2[i-2*N-1-M]; j++) {
				g.addEdge(i,j+1+N,1,0,0);

			}
		}

		int ee[100];
		for (int i=2*N+M+1; i<=2*N+M+M; i++) {
			ee[i-2*N-M-1] = g.e;
			g.addEdge(i-M,i,cnt[i-2*N-M-1],0,0);

		}

		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				bool fail = 0;
				for (int k=0; k<M; k++) {
					if (r1[k] <= i && r2[k] >= i && c1[k] <= j && c2[k] >= j) {
						fail = 1;
						break;
					}
				}
				if (fail) continue;
				g.addEdge(i+1,N+j+1,1,0,1e7);

			}
		}

		g.source = 2*N+2*M+1;
		g.sink = 2*N+2*M+2;
		for (int i=0; i<N; i++) {
			g.addEdge(g.source,i+1,1,0,0);
			g.addEdge(N+i+1,g.sink,1,0,0);

		}

		pii res = g.minCostFlow(2*N+2*M+2);

		vi fin;

		if (res.ss < N) {
			fin.pb(-1);
			return fin;
		}
		else {
			for (int i=0; i<M; i++) {

				if (g.edge[ee[i]].cap > 0) {
					fin.pb(-1);
					return fin;
				}
			}

			for (int i=0; i<N; i++) {
				fin.pb(0);
			}
			int vv[250] = {0};

			for (int i=1; i<=N; i++) {
				int cut = i;
				while (cut <= N || cut > 2*N) {
					for (int es = g.head[cut]; es != -1; es = g.edge[es].next) {

						if (vv[g.edge[es].y] == 1) continue;
						if (g.edge[es].cap == 0) {
							cut = g.edge[es].y;
							break;
						}
					}
					if(cut > N && cut <=2*N) vv[cut] = 1;
				}
				fin[i-1] = cut-1-N;
			}
			return fin;
		}
	}
};



<%:testing-code%>//Powered by KawigiEdit-pf 2.3.0
//With unused code cleaner (beta) by ahmed_aly