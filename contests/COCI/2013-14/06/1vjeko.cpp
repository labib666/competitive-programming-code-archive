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


int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int n, sz, i, j;
    string s, str;

    cin >> n >> s;
    sz = s.size();

    while (n--) {
        cin >> str;
        if (str.size() < sz-1) {cout << "NE" << endl; continue;}
        bool fail = 0;
        for (i=0;i<n;i++) {
            if (s[i]=='*') {break;}
            if (s[i]!=str[i]) {fail=1;break;}
        }
        if (fail) {cout << "NE" << endl; continue;}
        for(i=sz-1,j=str.size()-1;i>=0;i--,j--) {
            if (s[i]=='*') {break;}
            if (s[i]!=str[j]) {fail=1;break;}
        }
        if (fail) {cout << "NE" << endl; continue;}
        cout << "DA" << endl;
    }



    return 0;
}
