/*
ID: Labib666
LANG: C++
Contest: Facebook Hacker Cup 2015
Task: 3 ( 55 pts )
*/

#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector <int>
#define VLL vector <LL>
#define PQI priority_queue <int>
#define PQLL priority_queue <LL>
#define QI queue <int>
#define QLL queue <LL>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define SZ size()
#define INF 1000000007
#define LINF 1000000000000000007ll
#define PI 2*asin(1)
#define EPS 1e-9

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)

#define MAXN

int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

struct data {
    int x, y, t, p;
};

data MD (int x, int y, int t, int p) {
    data a;
    a.x = x, a.y = y, a.t = t, a.p = p;
    return a;
}

queue <data> q;
char s[105][105]; bool g[105][105][4], vis[105][105][4];
PII p[4] = { MP(1,0), MP(0,-1), MP(-1,0), MP(0,1) };

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen (".txt","r",stdin);
    //freopen ("output.txt","w",stdout);

    int t, tc = 0, r, c;
    data S, G;

    scanf("%d", &t);
    while (tc < t) {
        tc++;

        scanf("%d%d", &r, &c);
        for (int i=0; i<r; i++) scanf("%s", s[i]);

        memset(g, 0, sizeof (g));
        memset(vis, 0, sizeof (vis));

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (s[i][j] == 'S') S = MD(i,j,0,0);
                else if (s[i][j] == 'G') G = MD(i,j,0,0);
                else if (s[i][j] == '.' || s[i][j] == '#') continue;
                else {
                    int u, v, w;
                    u = ( s[i][j]=='v' ) ? 0 : ( ( s[i][j]=='<' ) ? 1 : ( ( s[i][j]=='^' ) ? 2 : 3 ) ) ;
                    for (v=0; v<4; v++) {
                        w = u+v; w %= 4;
                        int xx = i, yy = j;
                        for ( ; ; xx += p[w].X, yy += p[w].Y) {
                            if (xx < 0 || xx >= r || yy < 0 || yy >= c) break;
                            if (s[xx][yy] != '.' && s[xx][yy] != 'S' && s[xx][yy] != 'G') break;
                            g[xx][yy][v] = 1;
                        }
                    }
                }
            }
        }

        while(!q.empty()) q.pop();
        q.push (S);

        bool fail = 1; data now; int ans;

        while (!q.empty()) {
            now = q.front();
            q.pop();

            cout << now.x << " " << now.y << endl;

            if (s[now.x][now.y] == 'G') { fail = 0; ans = now.t; break;  }
            if (vis[now.x][now.y][now.p] == 1) continue;
            vis[now.x][now.y][now.p] = 1;

            for (int i=0; i<4; i++) {
                int u = now.x + p[i].X, v = now.y + p[i].Y, w = (w+1)%4;
                if (u < 0 || u >= r || v < 0 || v >= c) continue;
                if (g[u][v][w]) continue;
                if (s[u][v] != '.' && s[u][v]!= 'S' && s[u][v] != 'G') continue;
                if (vis[u][v][w] == 1) continue;
            }
        }

        if (fail) printf ("Case %d: impossible\n", tc);
        else printf ("Case %d: %d\n", tc, ans);
    }


    return 0;
}
