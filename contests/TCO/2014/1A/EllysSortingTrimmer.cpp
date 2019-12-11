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
 
 
class EllysSortingTrimmer {
public:
  string getMin(string S, int L) {
    int sz = S.size(), i, j, C[26];
    priority_queue <int> Q;
    memset( C, 0, sizeof (C) );
 
    for (i = 0; i < sz; i++ )
            C[S[i]-'A']++;
 
        for (i = sz-1,j=0; j<L; j++, i--) {
            Q.push(S[i]-'A');
        }
 
        for (; i>=0; i--) {
            j = Q.top();
            Q.pop();
            C[j]--;
 
            Q.push(S[i]-'A');
        }
 
        string ans = "";
 
        for (i=0;i<26;i++) {
            for (j=0; j<C[i]; j++) {
                char ch = 'A'+i;
                ans += ch;
            }
        }
 
        return ans;
  }
};
