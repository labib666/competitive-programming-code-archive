#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

#define LL long long

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

class TheArray {
public:
	int find(int n, int d, int first, int last) {
	    n--;
		int ans = max (first,last);
		FOR (i,0,n+1) {
            if (first+d*i > last+d*(n-i)) {
                ans = max (ans, last+d*(n-i));
                break;
            }
            ans = max (ans, first+d*i);
		}
		return ans;
	}
};

