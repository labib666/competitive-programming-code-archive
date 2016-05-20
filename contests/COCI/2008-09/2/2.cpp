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

int c[10], n;
string s;

void count ()
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        if (s[i] == 'I') c[1]++;
        else if (s[i] == 'V') c[2]++;
        else if (s[i] == 'X') c[3]++;
        else if (s[i] == 'L') c[4]++;
        else if (s[i] == 'C') c[5]++;
    }
}

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int i, j, k;

    memset(c, 0, sizeof (c));
    cin >> s;
    n = s.size();

    count();

    if (c[5] == 1 || c[4] == 1)
    {
        if (c[3] == 2 && c[2] == 0 && c[1] == 1){
            if (c[5] == 1) cout << "XCIX\n";
            else cout << "XLIX\n";
            return 0;
        }
        else if (c[3] == 1)
        {
            c[3]--;
            if (c[5] == 1) {
                cout << "XC";
                c[5]--;
            }
            else {
                cout << "XL";
                c[4]--;
            }
        }
        else {
            if (c[5] == 1) {
                cout << "C";
                c[5]--;
            }
            else {
                cout << "L";
                c[4]--;
            }
        }
    }

    if (!c[2])
    {
        if (c[1] == 1 && c[3])
        {
            for (i = 0; i < c[3]-1; i++)
                cout << "X";
            cout << "IX\n";
        }
        else {
            for (i = 0; i < c[3]; i++)
                cout << "X";
            for (i = 0; i < c[1]; i++)
                cout << "I";
            cout << endl;
        }
        return 0;
    }

    for (i = 0; i < c[3]; i++)
        cout << "X";

    if (!c[1] && c[2])
        cout << "V";
    else if (c[1] == 1 && c[2])
        cout << "IV";
    else if (c[1] > 1 && c[2])
    {
        cout << "V";
        for (i = 0; i < c[1]; i++)
            cout << "I";
    }
    else {
        for (i = 0; i < c[1]; i++)
            cout << "I";
    }

    return 0;
}

