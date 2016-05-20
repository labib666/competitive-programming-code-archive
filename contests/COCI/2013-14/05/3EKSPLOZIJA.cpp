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

bool yes[1000006];
int st[1000006], first[1000006];

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int len, n, i, j, k, next, cur = 0, now = 0;
    string s, ex;

    cin >> s >> ex;
    n = s.size(); len = ex.size();

    for (i = 0, next = 0; i <= n; i++)
    {
        if (next == len) {
            while (next--){
                yes[st[--now]] = 1;
            }
            next = (cur) ? first[--cur] : 0;
        }

        if (i == n) break;
        if (ex[next] != s[i]) {
            first[cur++] = next;
            next = 0;
            if (ex[next] != s[i]) {
                cur = 0; now = 0;
                continue;
            }
            else {
                st[now++] = i;
                next++;
                continue;
            }
        }
        else {
            st[now++] = i;
            next++;
            continue;
        }
    }

    string ans = "";
    for (i = 0; i < n; i++) {
        if (yes[i]) continue;
        ans += s[i];
    }

    if (ans.size() == 0) ans = "FRULA";
    cout << ans<<endl;
    cout << endl;


    return 0;
}

