/*
ID: Labib Rashid
LANG: C++
TASK: ttwo
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
# define PII pair<int,int>
# define VI vector <int>
# define loop(a,s,e) for(a=s;a<e;a++)
# define rloop(a,s,e) for(a=s-1;a>=e;a--)

using namespace std;

int gcd (int a, int b)
{
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

int bitcount (ll a)
{
    int i;
    for (i = 0; a > 0; i++) a &= (a-1);
    return i;
}


string g[10];
int X[4] = {-1,0,1,0}, Y[4] = {0,1,0,-1};


struct pos {
    int x,y,z;
};


pos select (pos a)
{
    int i, j, k;

    i = a.x, j = a.y, k = a.z;

    if (i + X[k] < 0 || i + X[k] >= 10) {
        a.z++;
        a.z %= 4;
        return a;
    }
    else if (j + Y[k] < 0 || j + Y[k] >= 10) {
        a.z++;
        a.z %= 4;
        return a;
    }
    else if (g[i+X[k]][j+Y[k]] == '*') {
        a.z++;
        a.z %= 4;
        return a;
    }

    a.x += X[k], a.y += Y[k];
    return a;
}

queue < pair < pair <pos, pos> , int > > q;

int bfs (pos a, pos b, int t)
{
    q.push (make_pair (make_pair (a,b), t));
    pair < pair <pos, pos> , int > cur;
    pair <pos, pos> now;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        now = cur.x;
        a = now.x;
        b = now.y;

        if (a.x == b.x && a.y == b.y) break;
        if (cur.y > 160000) {
            cur.y = 0;
            break;
        }

        cur.y++;
        cur.x.x = select(a);
        cur.x.y = select(b);

        q.push (cur);
    }

    return cur.y;
}


int main()
{
    //freopen (".txt","r",stdin);
    freopen ("ttwo.in","r",stdin);
    freopen ("ttwo.out","w",stdout);

    int i, j, k;
    pos f, c;

    for (i = 0; i < 10; i++)
    {
        cin >> g[i];

        for (j = 0;j < 10; j++)
        {
            if (g[i][j] == 'F') f.x = i, f.y = j, f.z = 0;
            else if (g[i][j] == 'C' ) c.x = i, c.y = j, c.z = 0;
        }
    }

    cout << bfs (c,f,0) << endl;

    return 0;
}

