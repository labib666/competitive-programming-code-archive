/*
USACO
3.1.5 - Contact
string processing
21.8.2013
/*
ID: Labib Rashid
LANG: C++
TASK: contact
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
    int cnt, sz;
    string s;
    bool operator < (const node &p) const {
        if (cnt < p.cnt) return true;
        if (cnt == p.cnt) {
            if (sz < p.sz) return false;
            if (sz == p.sz)
            {
                if (s < p.s) return false;
                return true;
            }
            return true;
        }
        return false;
    }
};

int c[200005];
priority_queue <node> q;
vector <string> v;
map <string, int> m;

void push_node (int cnt, int sz, string s)
{
    node a;
    a.cnt = cnt, a.sz = sz;
    a.s = s;
    q.push(a);
}

int main()
{
    //freopen ("contact.txt","r",stdin);
    freopen ("contact.in","r",stdin);
    freopen ("contact.out","w",stdout);

    int i, j, k, l, r, n, sz;
    node now;
    string str, s1, s2;

    cin >> l >> r >> n;

    while (cin >> s1)
        str += s1;

    sz = str.size();

    for (i = l;i <= r; i++)
    {
        string s;
        if (sz < i) break;

        for (j = 0; j < i; j++)
            s += str[j];
        v.pb (s);
        m[s] = 1;

        for(j = i; j < sz; j++)
        {
            s.erase(s.begin());
            s += str[j];

            if (!m[s]) {
                    v.pb (s);
            }
            m[s]++;
        }
    }

    for (i = 0; i < v.size(); i++){
        push_node(m[v[i]],v[i].size(),v[i]);
    }

    i = 0;
    while (!q.empty())
    {
        now = q.top();
        q.pop();

        if (!c[now.cnt]) {
                i++;
                if (i > n) break;
                printf ((i > 1) ? "\n%d" : "%d", now.cnt);
        }

        printf ((c[now.cnt] % 6) ? " %s" : "\n%s", now.s.c_str());

        c[now.cnt]++;
    }

    cout << endl;

    return 0;
}

