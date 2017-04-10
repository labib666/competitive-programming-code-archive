/*
ID: Labib666
LANG: C++
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector <int>
#define VLL vector <LL>
#define PQI priority_queue <int>
#define PQLL priority_queue <LL>
#define QI queue <int>
#define QLL queue <LL>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define SZ size()
#define INF 1000000007
#define LINF 1000000000000000007ll
#define PI 2*asin(1)
#define EPS 1e-9
 
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)
 
 
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
 
set <int> s;
set <int> ::iterator it;
 
 
class Similars {
public:
  int maxsim(int L, int R) {
    int ans = 0;
    for (int i=L; i<=R; i++) {
      int cur = 0, now = i, xr;
      while (now) {
        int ins = now % 10;
        cur |= (1<<ins);
        now /= 10;
      }
      for (it = s.begin(); it != s.end(); it++) {
        int pp = *it;
        xr = (pp & cur);
        xr = bitcount(xr);
        ans = max (ans, xr);
      }
      s.insert (cur);
    }
    return ans;
  }
};