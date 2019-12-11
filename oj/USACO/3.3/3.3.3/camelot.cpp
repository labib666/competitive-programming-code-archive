/*
USACO
3.3.3 - Camelot
graph
6.2.2014
/*
ID: Labib Rashid
LANG: C++
TASK: camelot
*/

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define x first
#define y second
#define inf 1000000007
#define pi 2*asin(1)
#define PII pair<int,int>
#define VI vector <int>
#define eps 1e-9

using namespace std;

struct data {
    ll x, y, v;
};
data make_data (ll x, ll y, ll v) {
    data d;
    d.x = x, d.y = y, d.v = v;
    return d;
}

queue < data > que;            // bfs material
bool vis[35][30];
ll dist[35][30][35][30];        // records distance
ll sum[35][30], tot = 0, row, col, ans = inf;
data king, knight[35*30];
ll X[] = {1,1,-1,-1,2,2,-2,-2}, Y[] = {2,-2,2,-2,1,-1,1,-1};

void take_input () {
    ll i, j, k, u, v;
    string s;

    cin >> row >> col;

    cin >> s >> king.x;
    king.y = s[0]-'A'+1, king.v = 0;

    while (cin >> s >> knight[tot].x) {
        knight[tot].y = s[0]-'A'+1, knight[tot].v=0;
        tot++;
    }
    return;
}

void bfs (data dd)
{
    data d, now;
    ll i, j, k, u, v, px, py;
    memset(vis, 0, sizeof(vis));
    que.push (dd);

    while (!que.empty()) {
        d = que.front();
        que.pop();
        if (vis[d.x][d.y]) continue;
        vis [d.x][d.y] = 1;
        dist[dd.x][dd.y][d.x][d.y] = d.v;
        for (i=0;i<8;i++){
            px = d.x+X[i], py = d.y+Y[i];
            if (px <= 0 || px > row) continue;
            if (py <= 0 || py > col) continue;
            if (vis[px][py]) continue;
            now = make_data(px,py,d.v+1);
            que.push(now);
        }
    }

    // find the sum of distance of all knights from this cell
    for (i=0;i<tot;i++)
        sum[dd.x][dd.y] += dist[dd.x][dd.y][knight[i].x][knight[i].y];

    return;
}

void solve (ll px, ll py) {
    ll i, j, k, u, v;
    for (i=1;i<=row;i++)
    {
        for (j=1;j<=col;j++)
        {
            if (abs(i-king.x)+abs(j-king.y) > 4) continue;                    // moving the king any further in needless **
            if (dist[px][py][i][j] == inf) continue;                          // are the two cells connected?

            for (k=0;k<tot;k++)
            {
                if (dist[px][py][knight[k].x][knight[k].y] == inf) continue;  // are both the cells reachable from the knight?
                if (dist[i][j][knight[k].x][knight[k].y] == inf) continue;

                v = sum[px][py]+max(abs(i-king.x),abs(j-king.y))+dist[px][py][i][j];
                v += dist[i][j][knight[k].x][knight[k].y] - dist[px][py][knight[k].x][knight[k].y];
                ans = min(ans, v);
            }
        }
    }
}


int main()
{
    //freopen ("camelot.txt","r",stdin);
    freopen ("camelot.in","r",stdin);
    freopen ("camelot.out","w",stdout);

    ll i, j, k, u, v;

    take_input();
    if (tot==0) {cout << "0\n"; return 0;}

    // initialise
    memset(sum, 0, sizeof (sum));
    for (i=1;i<=row;i++) {
        for(j=1;j<=col;j++) {
            for (u=1;u<=row;u++) {
                for (v=1;v<=col;v++) {
                    dist[i][j][u][v] = inf;
                }
            }
        }
    }

    // find the "knight" distance of the reachable cells
    for (i=1;i<=row;i++)
        for (j=1;j<=col;j++)
            bfs(make_data(i,j,0));

    // look for the target cell
    for (i=1;i<=row;i++)
        for (j=1;j<=col;j++)
            solve (i, j);

    //since, there's a guranteed solution
    //if the king staying in its region does not work, then all the knights are in the same cell
    //king needs to move to that cell
    if (ans >= inf) ans = max(abs(knight[0].x-king.x) , abs(knight[0].y-king.y));

    cout << ans << endl;


    return 0;
}
