/*
ID: Labib Rashid
LANG: C++
TASK: maze1
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


queue < pair < PII, int > > q;


char s[250][100];
bool v[110][40][4], a[110][40];

int X[] = {-1,0,1,0}, Y[] = {0,1,0,-1};

int main()
{
    //freopen ("maze1.txt","r",stdin);
    freopen ("maze1.in","r",stdin);
    freopen ("maze1.out","w",stdout);

    int r, c, i, j, k;

    cin >> c >> r;

    gets (s[0]);

    for (i = 0; i <= 2*r; i++)
        gets (s[i]);

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (s[2*i][2*j+1] == ' ') v[i][j][0] = 1;
            if (s[2*i+1][2*j+2] == ' ') v[i][j][1] = 1;
            if (s[2*i+2][2*j+1] == ' ') v[i][j][2] = 1;
            if (s[2*i+1][2*j] == ' ') v[i][j][3] = 1;
        }
    }

    //for (i = 0; i <= 2*r; i++)
        //for (j = 0; j <= 2*c; j++)

    PII now, e[2];
    pair <PII,int> cur;

    j = 0;

    for (i = 0; i < r; i++)
    {
        if (v[i][0][3]) {
            v[i][0][3] = 0;
            e[j] = make_pair (i,0);
            j++;
        }
    }

    for (i = 0; i < c; i++)
    {
        if (v[0][i][0])
        {
            e[j] = make_pair (0,i);
            v[0][i][0] = 0;
            j++;
        }
    }
    for (i = 0; i < r; i++)
    {
        if (v[i][c-1][1]) {
            e[j] = make_pair (i,c-1);
            v[i][c-1][1] = 0;
            j++;
        }
    }

    for (i = 0; i < c; i++)
    {
        if (v[r-1][i][2])
        {
            e[j] = make_pair (r-1,i);
            v[r-1][i][2] = 0;
            j++;
        }
    }

    //cout << j << endl;

    q.push (make_pair (e[0], 1));
    q.push (make_pair (e[1], 1));

    int ans = 0;

    while (!q.empty()){
        cur = q.front();
        q.pop();

        now = cur.x;
        if (a[now.x][now.y]) continue;
        a[now.x][now.y] = 1;

        //cout << now.x << " " << now.y << endl;

        ans = max (ans, cur.y);

        for (i = 0; i < 4; i++)
        {
            if (now.x + X[i] < 0 || now.x + X[i] >= r) continue;
            if (now.y + Y[i] < 0 || now.y + Y[i] >= c) continue;
            if (!v[now.x][now.y][i]) continue;
            if (a[now.x+X[i]][now.y+Y[i]]) continue;

            q.push (make_pair (make_pair (now.x+X[i],now.y+Y[i]),cur.y+1));
        }
    }

    cout << ans << endl;

    return 0;
}

