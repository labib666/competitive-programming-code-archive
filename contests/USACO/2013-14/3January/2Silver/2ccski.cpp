/*
ID: Labib Rashid
LANG: C++
TASK: ccski
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
#include <cstring>
#include <queue>

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

int gcd (int a, int b)
{
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

int bitcount (int a)
{
    return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;
}

bool v[500][500], w[500][500];
int a[500][500], n, m, X[] = {0, 0, -1, 1}, Y[] = {1,-1,0,0}, tot;
queue < PII > q;
PII st;

bool is_possible (int mid)
{
    int i, j, k, cnt = 0;
    PII cur;

    q.push(st);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (v[cur.x][cur.y]) continue;
        v[cur.x][cur.y] = 1;
        for (i = 0; i < 4; i++)
        {
            if (cur.x + X[i] < 0 || cur.x + X[i] >= n) continue;
            if (cur.y + Y[i] < 0 || cur.y + Y[i] >= m) continue;
            if (v[cur.x+X[i]][cur.y+Y[i]]) continue;
            if (abs(a[cur.x+X[i]][cur.y+Y[i]]-a[cur.x][cur.y]) > mid) continue;
            q.push(make_pair(cur.x+X[i],cur.y+Y[i]));
        }
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (w[i][j] && v[i][j]) cnt++;
            v[i][j] = 0;
        }
    }

    //cout << mid << " & " << cnt << endl;
    if (cnt == tot) return 1;
    else return 0;
}

int main()
{
    //freopen ("2ccski.txt","r",stdin);
    freopen ("ccski.in","r",stdin);
    freopen ("ccski.out","w",stdout);

    int i, j, k, mx = 0, mn = inf;

    cin >> n >> m;
    tot = 0;

    for ( i = 0; i < n; i++ ) {
        for (j = 0; j < m; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
            mn = min(mn, a[i][j]);
        }
    }

    for ( i = 0; i < n; i++ ){
        for (j = 0; j < m; j++) {
            cin >> k;
            if (k) {w[i][j] = 1; st = make_pair(i,j); tot++;}
        }
    }

    int hi, lo, mid;
    hi = mx-mn, lo = 0;

    //cout << tot << endl;

    while (hi >= lo)
    {
        //cout << hi << " " << lo << endl;
        mid = (hi + lo)/2;
        if (is_possible(mid)) hi = mid - 1;
        else lo = mid + 1;
    }

    cout << lo << "\n";

    return 0;
}
