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

string s[705];
priority_queue < pair < int, pair < int, int > > > q;
bool v[705][705];
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

int main()
{
    //freopen ("2.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int t, tc = 0, r, c, i, j, k;
    pair < int, int > now, nxt, st;
    pair < int, pair <int, int> > cur;


    cin >> t;
    while (tc < t)
    {
        ++tc;

        cin >> r >> c;
        bool f = 0;
        while (!q.empty()) q.pop();

        for (i = 0; i < r; i++)
        {
            cin >> s[i];
            if (f) continue;
            for (j = 0; j < c; j++)
            {
                if (s[i][j] == 'A')
                {
                    st.x = i, st.y = j;
                    f = 1;
                    break;
                }
            }
        }

        memset(v, 0, sizeof (v));
        q.push(make_pair(0,st));

        while (!q.empty())
        {
            cur = q.top();
            q.pop();

            now = cur.y;
            if (v[now.x][now.y]) continue;

            v[now.x][now.y] = 1;
            if (s[now.x][now.y] == 'B') break;

            for (i = 0; i < 4; i++)
            {
                nxt = make_pair(now.x+X[i], now.y+Y[i]);
                if (nxt.x < 0 || nxt.x >= r || nxt.y < 0 || nxt.y >= c)
                    continue;
                if (v[nxt.x][nxt.y]) continue;
                if (s[nxt.x][nxt.y] == '#') continue;
                if ((s[nxt.x][nxt.y] >= 'A' && s[nxt.x][nxt.y] <= 'Z') || s[nxt.x][nxt.y] == '*')q.push(make_pair(cur.x, nxt));
                else q.push(make_pair(cur.x - 1, nxt));
            }
        }

        cout << (-1)*cur.x << endl;
    }

    return 0;
}

