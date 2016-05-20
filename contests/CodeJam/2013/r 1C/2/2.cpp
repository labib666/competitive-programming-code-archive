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

int main()
{
    //freopen (".txt","r",stdin);
    freopen ("B-small-practice.in","r",stdin);
    freopen ("B-small-practice.txt","w",stdout);

    ll t, tc = 0, i, j, k, dx, dy;
    string s;

    cin >> t;
    while (tc < t)
    {
        ++tc;
        s.clear();

        cin >> dx >> dy;

        if (dx != 0){
            if (dx > 0){
                for (i = 0; i < abs(dx); i++)
                    s += "WE";
            }
            else if (dx < 0){
                for (i = 0; i < abs(dx); i++)
                    s += "EW";
            }
        }

        if (dy != 0){
            if (dy > 0){
                for (i = 0; i < abs(dy); i++)
                    s += "SN";
            }
            else if (dy < 0){
                for (i = 0; i < abs(dy); i++)
                    s += "NS";
            }
        }


        printf ("Case #%d: ", tc);
        cout << s << endl;
    }

    return 0;
}

