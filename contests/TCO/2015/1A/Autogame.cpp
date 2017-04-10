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
#define INF 1000000007ll
#define LINF 1000000000000000007ll
#define PI 2*asin(1)
#define EPS 1e-9
 
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define MEM(A,V)   memset (A, (V), sizeof A)
 
 
int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}
 
int K, N, vis[64], c[64], path[64];
vector <int> v;
 
void find_end(int pos, int now) {
  if (now == K) {
    c[pos]++;
    return;
  }
  if (vis[pos]) {
    int cyc = now - vis[pos];
    int dif = K-vis[pos];
    dif %= cyc;
    dif = vis[pos] + dif;
    dif = path[dif];
    c[dif]++;
    return;
  }
  vis[pos] = now;
  path[now] = pos;
  find_end(v[pos]-1, now+1);
  return;
}
 
class Autogame {
public:
  int wayscnt(vector <int> a, int k) {
    v.clear(); memset (c, 0, sizeof(c));
    
    for (int i=0; i<(int)a.size(); i++) v.push_back (a[i]);
    K = k;
    N = a.size();
    
    for (int i=0; i<N; i++) {
      memset(vis, 0, sizeof(vis));
      find_end(i, 0);
    }
    for (int i=0; i<N; i++) c[i]++;
    
    LL ans = 1ll;
    for (int i=0; i<N; i++) {
      cout << i << " " << c[i] << endl;
      ans = (ans * (LL)c[i]) % INF;
    }
    
    return ans;
  }
};
 