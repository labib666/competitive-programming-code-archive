/*
ID: Labib Rashid
LANG: C++
TASK:
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
# include <cstring>
# include <queue>
# define ll long long
# define pb push_back
# define x first
# define y second
# define inf 1000000007
# define pi 2*asin(1)

using namespace std;

string s[505];
int m[505][505], a[505][505];
int X[4] = {1,-1,0,0};
int Y[4] = {0,0,-1,1};
bool v[505][505];
queue < pair < pair<int, int>, int> > q;
priority_queue < pair < int, pair<int, int> > > pq;

int main()
{
    //freopen ("3.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int r, c, i, j, k;
    pair <int, int> st, fn, now, nxtx;
    pair < pair<int, int>, int> cur, nxt;
    pair < int, pair<int, int> > cur2, nxt2;

    cin >> r >> c;
    for (i = 0; i < r; i++){
        cin >> s[i];
        for (j = 0; j < c; j++)
        {
            if (s[i][j] == '+') q.push(make_pair( make_pair(i,j), 0));
            else if (s[i][j] == 'V') st = make_pair(i,j);
            else if (s[i][j] == 'J') fn = make_pair(i,j);
        }
    }

    memset(v, 0, sizeof(v));
    memset(m, -1, sizeof(m));

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        now = cur.x;
        if (v[now.x][now.y]) continue;
        v[now.x][now.y] = 1;
        m[now.x][now.y] = cur.y;

        for (i = 0; i < 4; i++)
        {
            nxtx = make_pair(now.x+X[i], now.y+Y[i]);
            if (nxtx.x < 0 || nxtx.x >= r || nxtx.y < 0 || nxtx.y >= c)
                continue;
            if (v[nxtx.x][nxtx.y])
                continue;
            nxt = make_pair(nxtx, cur.y+1);
            q.push(nxt);
        }
    }

    /*for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            cout << m[i][j] << " ";
        cout <<  endl;
    }*/

    pq.push(make_pair(m[st.x][st.y],st));
    memset(v, 0, sizeof (v));

    while (!pq.empty())
    {
        cur2 = pq.top();
        pq.pop();

        now = cur2.y;
        if (v[now.x][now.y]) continue;
        v[now.x][now.y] = 1;
        if (fn.x == now.x && fn.y == now.y) break;

        for (i = 0; i < 4; i++)
        {
            nxtx = make_pair(now.x+X[i], now.y+Y[i]);
            if (nxtx.x < 0 || nxtx.x >= r || nxtx.y < 0 || nxtx.y >= c)
                continue;
            if (v[nxtx.x][nxtx.y])
                continue;
            k = min(cur2.x, m[nxtx.x][nxtx.y]);
            nxt2 = make_pair( k, nxtx);
            pq.push(nxt2);
        }
    }

    cout << cur2.x << endl;

    return 0;
}

