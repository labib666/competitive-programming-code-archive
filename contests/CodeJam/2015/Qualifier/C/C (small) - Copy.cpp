/*
ID: Labib666
LANG: C++
Contest: Code Jam 2015 Qualifier
Task: C (small)
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

#define MAXN

string s, p;
bool flag[10004];
int l, x, sz;

void clc_flag (int cur, int pos) {
    if (pos < 0) return;
    int now;
    if (s[pos] == 'i') {
        if (abs(cur) == 1) now = 2;
        else if (abs(cur) == 2) now = -1;
        else if (abs(cur) == 3) now = 4;
        else if (abs(cur) == 4) now = -3;
    }else if  (s[pos] == 'j') {
        if (abs(cur) == 1) now = 3;
        else if (abs(cur) == 2) now = -4;
        else if (abs(cur) == 3) now = -1;
        else if (abs(cur) == 4) now = 2;
    }else if  (s[pos] == 'k') {
        if (abs(cur) == 1) now = 4;
        else if (abs(cur) == 2) now = 3;
        else if (abs(cur) == 3) now = -2;
        else if (abs(cur) == 4) now = -1;
    }
    if (cur < 0) now *= (-1);
    if (now == 4) flag[pos] = 1;
    clc_flag(now,pos-1);

    return;
}

int ch2 (int pos, int cur) {
    if (cur == 3 && flag[pos] == 1) return 1;
    if ( pos >= sz-1 ) return 0;
    int now;

    if (s[pos] == 'i') {
        if (abs(cur) == 1) now = 2;
        else if (abs(cur) == 2) now = -1;
        else if (abs(cur) == 3) now = -4;
        else if (abs(cur) == 4) now = 3;
    }else if  (s[pos] == 'j') {
        if (abs(cur) == 1) now = 3;
        else if (abs(cur) == 2) now = 4;
        else if (abs(cur) == 3) now = -1;
        else if (abs(cur) == 4) now = -2;
    }else if  (s[pos] == 'k') {
        if (abs(cur) == 1) now = 4;
        else if (abs(cur) == 2) now = -3;
        else if (abs(cur) == 3) now = 2;
        else if (abs(cur) == 4) now = -1;
    }
    if (cur < 0) now *= (-1);

    return ch2(pos+1, now);
}

bool ch1 (int pos, int cur) {
    if ( pos >= sz-2 ) return 0;
    int now;

    if (s[pos] == 'i') {
        if (abs(cur) == 1) now = 2;
        else if (abs(cur) == 2) now = -1;
        else if (abs(cur) == 3) now = -4;
        else if (abs(cur) == 4) now = 3;
    }else if  (s[pos] == 'j') {
        if (abs(cur) == 1) now = 3;
        else if (abs(cur) == 2) now = 4;
        else if (abs(cur) == 3) now = -1;
        else if (abs(cur) == 4) now = -2;
    }else if  (s[pos] == 'k') {
        if (abs(cur) == 1) now = 4;
        else if (abs(cur) == 2) now = -3;
        else if (abs(cur) == 3) now = 2;
        else if (abs(cur) == 4) now = -1;
    }
    if (cur < 0) now *= (-1);

    if (now == 2) if (ch2(pos+1, 1)) return 1;
    return ch1(pos+1, now);
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);
    freopen ("C-small-attempt1.in","r",stdin);
    freopen ("C-small-attempt1.out","w",stdout);

    int t, tc=0;
    cin >> t;
    while (tc<t) {
        tc++;

        cin >> l >> x;
        cin >> p;

        s = "";
        for (int i=0; i<x; i++) s += p;
        sz = s.size();

        fill (flag, flag+sz, 0);
        clc_flag(1,sz-1);

        bool succ = ch1(0,1);

        if (succ) printf("Case #%d: YES\n", tc);
        else printf("Case #%d: NO\n", tc);
    }


    return 0;
}
