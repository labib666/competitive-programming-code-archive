/*
ID: Labib Rashid
LANG: C++
TASK: irrigation
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
using namespace std;

struct data {
	int u, v, w;
	bool operator < (const data &p) const {
		return w > p.w;
	}
};

data make_data (int u, int v, int w) {
	data a;
	a.u = u, a.v = v, a.w = w;
	return a;
}

int x[2002], y[2002], p[2002];
priority_queue <data> q;

int parent (int pos) {
	if (p[pos] == pos) return pos;
	p[pos] = parent (p[pos]);
	return p[pos];
}

int main() {
	//freopen ("irrigation.txt","r",stdin);
    freopen ("irrigation.in","r",stdin);
    freopen ("irrigation.out","w",stdout);


	int n, c, i, j, k, sum;

	cin >> n >> c;
	for (i=0; i<n; i++) {
		cin >> x[i] >> y[i];
		p[i] = i;
	}

	for (i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			k=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			if (k < c) continue;
			q.push (make_data (i,j,k));
		}
	}

	sum = 0;
	while (!q.empty()) {
		data now = q.top();
		q.pop();
		i = parent (now.u); j = parent (now.v);
		if (i == j) continue;
		p[j] = i;
		sum += now.w;
	}

	bool fail = 0; k = p[0];
	for (i=0;i<n;i++) {
		if (parent(i)!=k) {
			fail = 1;
			break;
		}
	}

	if (fail) cout << "-1\n";
	else cout << sum << endl;

	return 0;
}
