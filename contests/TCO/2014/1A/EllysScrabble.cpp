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
#define PII pair <int,int>
#define VI vector <int>
#define VII vector < PII >
 
using namespace std;
 
int gcd (int a, int b)
{
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}
 
int bitcount (int a)
{
    return (a == 0) ? 0 : bitcount (a&(a-1)) + 1;
}
 
 
class EllysScrabble {
public:
  string getMin(string S, int M) {
    int sz = S.size(), i, j, k, u;
    char ch;
    int V[55];
    memset(V, 0, sizeof(V));
    string ans = "";
 
    for (i=0; i<sz; i++) {
            j = max (0, i-M);
            k = min (sz-1, i+M);
 
            if (i >= M && !V[i-M]) {
                ans += S[i-M];
                V[i-M] = 1;
                continue;
            }
 
            ch = 'Z'+1;
            int pos = -1;
            for (u=j; u<=k; u++) {
                if (V[u]) continue;
                if (S[u] < ch) {
                    ch = S[u];
                    pos = u;
                }
            }
            V[pos] = 1;
            ans += S[pos];
    }
 
    return ans;
  }
};