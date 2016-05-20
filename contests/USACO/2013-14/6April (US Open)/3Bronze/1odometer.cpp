/*
ID: Labib Rashid
LANG: C++
TASK: odometer
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

#define LL long long
#define pb push_back
#define x first
#define y second
#define inf 1000000007
#define pi 2*asin(1)
#define PII pair<int,int>
#define VI vector <int>
#define eps 1e-9

using namespace std;

set <LL> S;
set <LL>::iterator it;
vector <LL> V;

int main() {
	freopen ("odometer.in","r",stdin);
    freopen ("odometer.out","w",stdout);
    
    LL V1, V2, i, j, k, p;
    char c1, c2;
    string s;
    
    for (i=3; i<=16; i++) {
    	for (c1='0'; c1<='9';c1++) {
    		s = "";
    		for (j=0;j<i;j++) s += c1;
    		for (c2='0';c2<='9';c2++) {
    			if (c1 == c2) continue;
    			for (k=0;k<i;k++) {
    				if (c2 == '0' && k == 0) continue;
    				if (c1 == '0' && k > 0) continue;
    				s[k] = c2;
    				stringstream ss;
    				ss << s;
    				ss >> p;
    				S.insert(p);
    				s[k] = c1;
    			}
    		}
    	}
    }
    
    cin >> V1 >> V2;
    
    for (it=S.begin();it!=S.end();it++) {
    	V.pb (*it);
    }
    V.pb (10000000000000000ll);
    
    k = upper_bound (V.begin(), V.end(), V2) - lower_bound(V.begin(), V.end(), V1);
    
    cout << k << endl;
    
    
	return 0;
}