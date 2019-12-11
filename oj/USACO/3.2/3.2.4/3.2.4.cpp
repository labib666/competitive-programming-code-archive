/*
USACO
3.2.4 - Feed Ratios
brute force, cautios division(division by 0)
21.8.2013
/*
ID: Labib Rashid
LANG: C++
TASK: ratios
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


void get(int x[]) { scanf("%d %d %d", &x[0], &x[1], &x[2]); }

int main()
{
	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);

	int a[3], b[3], c[3], g[3];
	get(g); get(a); get(b); get(c);

	for (int sum = 0; sum <= 300; sum++)
	for (int x = 0; x <= 100; x++)
	for (int y = 0; y <= 100; y++) {
		int z = sum - x - y;
		if (z < 0 || z > 100) continue;

		int r[3];
		for (int i = 0; i < 3; i++)
			r[i] = x*a[i] + y*b[i] + z*c[i];

		int t = -1;
		for (int i = 0; i < 3; i++) {
			if (g[i] == 0) {
				if (r[i] != 0) { t = -2; break; }
			} else if (t < 0) {
				if (r[i] == 0 || (r[i] % g[i]) != 0) { t = -2; break; }
				t = r[i] / g[i];
			} else if (r[i] != t * g[i]) {
				t = -2; break;
			}
		}

		if (t == -2) continue;
		if (t < 0) t = 0;

		printf("%d %d %d %d\n", x, y, z, t);
		return 0;
	}

	printf("NONE\n");
}
