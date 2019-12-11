/*
USACO
3.2.5 - magic squares
string processing, bfs
22.8.2013
/*
ID: Labib Rashid
LANG: C++
TASK: msquare
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

int bitcount (int a)
{
    int i;
    for (i = 0; a > 0; i++) a &= (a-1);
    return i;
}

struct node {
    string s, d;
    int sz;
};

queue < node > q;
map <string, int> m;

node make_node (string s, string d, int sz)
{
    node p;
    p.s = s, p.d = d, p.sz = sz;
    return p;
}

void push_node (node p)
{
    string s1, s2;
    int sz, i;

    s1 = p.s;
    for (i = 0; i < 4; i++)
        swap(s1[i], s1[7-i]);
    s2 = p.d;
    s2 += "A";
    if (!m[s1]) q.push(make_node(s1,s2,p.sz+1));

    s1 = p.s;
    char t = s1[3];
    for (i = 3; i > 0; i--)
        s1[i] = s1[i-1];
    s1[0] = t;
    t = s1[4];
    for (i = 4; i < 7 ; i++)
        s1[i] = s1[i+1];
    s1[7] = t;
    s2 = p.d;
    s2 += "B";
    if (!m[s1]) q.push(make_node(s1,s2,p.sz+1));

    s1 = p.s;
    for (i = 1; i < 3; i++)
        swap(s1[i], s1[7-i]);
    swap(s1[2],s1[6]);
    s2 = p.d;
    s2 += "C";
    if (!m[s1]) q.push(make_node(s1,s2,p.sz+1));

    return;
}

int main()
{
    //freopen ("msquare.txt","r",stdin);
    freopen ("msquare.in","r",stdin);
    freopen ("msquare.out","w",stdout);

    int i, j, k;
    char st[20];
    string s;
    node now;

    gets(st);
    s = st;

    for (i = s.size() - 1;i >= 0; i--)
        if (s[i] == ' ') s.erase(s.begin()+i);

    q.push(make_node("12345678","",0));
    while (!q.empty())
    {
        now = q.front();
        q.pop();

        if (m[now.s]) continue;
        m[now.s] = 1;

        //if (now.sz == 1) cout << now.s << " " << now.d << " " << now.sz << endl;

        if (now.s == s) break;

        push_node(now);
    }
    //cout << s << " " << now.s << endl;

    cout << now.sz << endl << now.d << endl;

    return 0;
}

