/*
ID: Labib Rashid
LANG: C++
TASK: slowdown
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
#define eps 1e-11

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

double fabs (double a,double b) {double ans = abs(a-b); return ans;}

vector <ll> t, d;

int main()
{
    //freopen ("1slowdown.txt","r",stdin);
    freopen ("slowdown.in","r",stdin);
    freopen ("slowdown.out","w",stdout);

    ll n, i, j, k;
    double ct = 0.0, cd = 0.0, cs = 1.0, cnt = 1.0;
    string s;

    cin >> n;
    while (n--)
    {
        cin >> s >> k;
        if (s == "T") t.pb (k);
        else d.pb (k);
    }

    sort(t.begin(),t.end());
    sort(d.begin(),d.end());

    ll tsz = t.size(), dsz = d.size();
    double v1, v2;

    for (j = 0, k = 0; j < tsz || k < dsz; )
    {
        if (j < tsz) v1 = double(t[j]) - ct;
        else v1 = 1e9;
        if (k < dsz) {v2 = double(d[k]) - cd; v2/=cs;}
        else v2 = 1e9;
        if (fabs(v1,v2) > eps && v1 < v2) {cd += v1*cs; cnt += 1.0; cs = 1.0/cnt; ct += v1; j++;}
        else if (fabs(v1,v2) > eps && v1 > v2) {cd += v2*cs; cnt += 1.0; cs = 1.0/cnt; ct += v2; k++;}
        else {cd += v1*cs; cnt += 2.0; cs = 1.0/cnt; ct += v1; k++; j++;}
        //printf("ct = %.9lf\n", ct);
    }

    ct += (1000.0 - cd)/cs;

    /*stringstream ss;
    ss << ct;
    ss >> k >> s;
    if (s[1]-'4' > 0) k++; // needs checking*/
    cout <<  int ( floor( ct + 0.5 + 1e-9) + 1e-9 ) << "\n";

    return 0;
}
