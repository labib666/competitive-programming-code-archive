#include"station.h"
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair <int,int>
#define PLL pair <LL,LL>
#define X first
#define Y second
#define VI vector <int>
#define VLL vector <LL>
#define PB push_back
#define SZ size()

#define INF 1000000007ll
#define LINF INF*INF
#define PI 2.0*acos(0.0)
#define EPS 1e-9

set <int> s;
set <int> ::iterator it;

int findMinDays(int n, int k, int a[])
{
    for (int i=0; i<n; i++) { if (a[i]) s.insert(i); }
    int day = 0, cur = 0;
    while (cur != n-1) {
        it = s.upper_bound(cur+k);
        it--;
        if (*it == cur) { day = -1; break; }
        cur = *it;
        day++;
    }
    //cout << day << endl;
	return day;
}
