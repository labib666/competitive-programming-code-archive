/*
USACO
3.4.2 - American Heritage
DS - stack
1 Mar, 2014
/*
ID: Labib Rashid
LANG: C++
TASK: heritage
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

int main()
{
    //freopen ("heritage.txt","r",stdin);
    freopen ("heritage.in","r",stdin);
    freopen ("heritage.out","w",stdout);

    string s1, s2;
    stack <int> q;
    int n, i, j, k, cnt, a[30], marked[30];

    cin >> s1 >> s2;
    n = s1.size();

    for (i=0; i<n; i++) a[s1[i]-'A'] = i;
    memset(marked,0,sizeof(marked));

    for (i=0; i<n; i++) {
        q.push(a[s2[i]-'A']);
        marked[a[s2[i]-'A']] = 1;
        while(!q.empty()) {
            k = q.top();
            for (j=k-1; j>=0; j--) {
                if (marked[j]) break;
            }
            if (j != k-1) break;
            for (j=k+1; j<n; j++) {
                if (marked[j]) break;
            }
            if (j != k+1) break;
            q.pop();
            cout<< s1[k];
        }
    }
    cout << endl;

    return 0;
}
