/*
ID: Labib Rashid
LANG: C++
TASK: 3
CONTEST: CodeJam 2014 R2
*/

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
#define LINF 1000000000000000007
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

struct node {
    node *a[26];
    node() {
        MEM(a,NULL);
    }
} *root[102];

string S[1002];
int N, M, C[102], ans, f, P[1002];

void goin (int pos, int tree) {
    node *cur = root[tree];
    int len = S[pos].SZ;

    FOR(i,0,len) {
        int pp = S[pos][i]-'A';
        if (cur->a[pp] == NULL) {
            cur->a[pp] = new node();
            C[tree]++;
        }
        cur = cur -> a[pp];
    }
    return;
}

void del (node *cur) {
    FOR(i,0,26) {
        if (cur->a[i] != NULL)
            del(cur->a[i]);
    }
    delete cur;
}

void dfs (int pos) {
    if (pos == M) {
        fill (C,C+N,1);
        FOR(i,0,N) root[i] = new node();
        FOR(i,0,M) goin(i, P[i]);
        int sum = 0;
        FOR(i,0,N) sum += C[i]==1 ? 0 : C[i];
        if (sum > ans) {
            ans = sum; f = 1;
        }
        else if (sum == ans) f++;
        FOR(i,0,N) del (root[i]);
        return;
    }
    FOR(i,0,N) {P[pos] = i; dfs(pos+1);}
    return;
}

int main()
{
    //freopen ("input.txt","r",stdin);
    freopen ("D-small-attempt1.in","r",stdin);
    freopen ("D-small-attempt1.txt","w",stdout);

    int T, tc = 0, i, j, k;

    cin >> T;
    while (tc < T) {
        tc++;
        ans = 0, f = 0;

        cin >> M >> N;
        FOR(ii,0,M) cin >> S[ii];

        dfs(0);
        printf ("Case #%d: %d %d\n", tc, ans, f);
    }
    return 0;
}
