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

VI v, c;
queue <int> q;
int m[1001], sz, b;
int r[1001];

int cycle (int pos)
{
    fill (m+1, m+sz+1, 0);
    v.clear();
    c.clear();

    int i, val;
    //cout << pos << " starts >> \n";

    while (1)
    {
        //cout << pos << endl;
        if (m[pos]) {
            val = pos; break;
        }
        q.push(pos);
        m[pos] = 1;

        if (pos > (sz+1)/2) pos = (sz - pos + 1)*2;
        else pos = 2*(pos-1)+1;
    }

    while (!q.empty())
    {
        if (q.front() == val) break;
        v.pb (q.front());
        q.pop();
    }

    q.pop();
    while(!q.empty()) {c.pb (q.front()); q.pop();}
    c.pb (val);

    i = b;
    if (v.size() < i) i -= v.size();
    else return v[i-1];

    i--;
    i %= (c.size());
    return c[i];
}

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int i, j, k;
    string s;

    cin >> b >> s;
    sz = s.size();
    s = "." + s;

    for (i = 1; i <= sz; i++)
    {
        r[i] = cycle (i);
        //cout << i << " -> r[i] = " << r[i] << endl;
    }

    for (i = 1; i <= sz; i++)
        cout << s[r[i]];
    cout << endl;


    return 0;
}
