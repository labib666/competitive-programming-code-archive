/*
USACO
3.1.4 - shaping regions
DS & implementation
20.8.2013
/*
ID: Labib Rashid
LANG: C++
TASK: rect1
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

struct sec {
    int x, y, c;
};

vector <sec> a[10005];
bool v[10005];
int t[2505];

int main()
{
    //freopen ("rect1.txt","r",stdin);
    freopen ("rect1.in","r",stdin);
    freopen ("rect1.out","w",stdout);

    int r, c, n, i, j, k;
    int lx, ly, rx, ry, nc;

    cin >> c >> r >> n;

    for (i = 0; i < n; i++){
        cin >> lx >> ly >> rx >> ry >> nc;
        rx--, ry--;

        //cout << "at " << i << endl;

        for (j = lx; j <= rx; j++)
        {
            v[j] = 1;

            //cout << "at line >> " << j << endl;

            for (k = a[j].size() - 1; k >= 0 ; k--)
            {
                sec s = a[j][k], s1;

                //cout << "ele >> " << k << " " << s.x << " " << s.y << " " << s.c << endl;

                if (ly > s.y || ry < s.x) continue;
                if (ly <= s.x && ry >= s.y) {
                        a[j].erase (a[j].begin() + k);
                        //cout << "erased\n";
                        continue;
                }
                if (ly <= s.x && ry < s.y) {
                    a[j][k].x = ry+1;
                    //cout << "edited x >> " << ry+1 << endl;
                    continue;
                }
                if (ly > s.x && ry >= s.y) {
                    a[j][k].y = ly-1;
                    //cout << "edited y >> " << ly-1 << endl;
                    continue;
                }
                if (ly > s.x && ry < s.y) {
                    a[j][k].x = ry+1;
                   // cout << "edited x >> " << ry+1 << endl;

                    s1.x = s.x, s1.y = ly - 1;
                    s1.c = s.c;
                    a[j].pb (s1);
                   // cout << "pushed >> " << s1.x << " " << s1.y << " " << s1.c << endl;
                    continue;
                }
            }
            sec s;
            s.x = ly, s.y = ry, s.c = nc;
            a[j].pb (s);
            //cout << "pushed >> " << s.x << " " << s.y << " " << s.c << endl;
        }
    }

    k = 0;
    for (i = 0; i < c; i++)
    {
        if (!v[i]) continue;


        //cout << "counting line >> " << i << endl;

        for (j = 0; j < a[i].size(); j++)
        {
            if (a[i][j].c == 1) continue;
            t[a[i][j].c] += (a[i][j].y - a[i][j].x + 1);
            k += (a[i][j].y - a[i][j].x + 1);

            //cout << "adding to >> " << a[i][j].c << " " << (a[i][j].y - a[i][j].x + 1) << endl;;
        }
    }
    t[1] = c*r - k;

    for (i = 1; i <= 2500; i++)
    {
        if (!t[i]) continue;

        cout << i << " " << t[i] << endl;
    }

    return 0;
}

