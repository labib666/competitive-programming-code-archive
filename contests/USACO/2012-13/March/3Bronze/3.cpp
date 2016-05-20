/*
ID: Labib Rashid
LANG: C++
TASK: assign
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

using namespace std;

struct two {
    int c1, c2;
    string r;
};

int flag [20], n, m;
int res;
two rel[55];
string s1 = "S", s2 = "D";

void check ();

void form(int k)
{
    int i;
    if (k == 0){
        for (i = 0; i <3; i++){
            flag[k] = i;
            check ();
        }
        return;
    }
    for (i = 0; i <3; i++){
        flag[k] = i;
        form(k-1);
    }

    return;
}


void check ()
{
    int i, a = 1,  j, k;
    for (i=0; i < m; i++)
    {
        if (rel [i]. r == s1)
        {
            if (flag[rel[i].c1] != flag[rel[i].c2]){
                a = 0;
                break;
            }
        }
        else if (rel [i]. r == s2)
        {
            if (flag[rel[i].c1] == flag[rel[i].c2]){
                a = 0;
                break;
            }
        }
    }
    res += a;
    return;
}

int main()
{
    int i, x, y;
    two t1;
    string s;

    //freopen ("assign.in","r",stdin);
    //freopen ("assign.out","w",stdout);

    cin >> n >> m;
    memset(flag, 0, sizeof (flag));
    for (i=0; i<m; i++)
    {
        cin >> t1.r >> t1.c2 >> t1.c1;
        rel[i] = t1;
    }

    res = 0;
    memset(flag, 0, sizeof (flag));
    form(n-1);

    cout << res << endl;

    return 0;
}
