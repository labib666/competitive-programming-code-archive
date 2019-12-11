/*
ID: Labib Rashid
PROG: auto
LANG: C++
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
using namespace std;

vector < pair<string,int> > m;

int lower (string s) {
	int hi = m.size()-1, lo = 0, mid;
	while (hi >= lo) {
		mid = (hi+lo)/2;
		if (m[mid].first >= s) hi = mid-1;
		else lo = mid+1;
	}
	return lo;
}
int upper (string s) {
	int hi = m.size()-1, lo = 0, mid;
	while (hi >= lo) {
		mid = (hi+lo)/2;
		bool fail = 0; string ss = m[mid].first;

			int sz = min (s.size(), ss.size());
			for (int i=0;i<sz; i++) {
				if (s[i] > ss[i]) break;
				else if (s[i] < ss[i]) {fail = 1; break;}
			}

		if (fail) hi = mid-1;
		else lo = mid+1;
	}
	return lo;
}


int main ()
{
    freopen("auto.in", "r", stdin);
    freopen("auto.out", "w", stdout);
    int W,N,l,i,sz,k,st,en;

    string s,sub;
    cin>>W>>N;
    for (l=1;l<=W;l++){
    	cin>>s;
    	m.push_back (make_pair(s,l));
    }
    sort (m.begin(),m.end());

   	while (N--){
   	   	cin>>k>>s;
   	   	st = lower(s);
   	   	en = upper(s);
   	   	sz = en-st;
   	   	if (sz < k) cout << -1 << endl;
   	   	else {
   	   		cout << m[st+k-1].second << endl;
   	   	}
   	}
	return 0;
}
