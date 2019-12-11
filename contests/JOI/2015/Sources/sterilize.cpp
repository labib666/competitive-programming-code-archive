/*
ID: Labib666
LANG: C++
Contest:
Task:
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

int gcd (int a, int b){return (b > a) ? gcd (b,a) : (b == 0) ? a : gcd (b, a%b);}
int bitcount (int a) {return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;}
LL bigmod (LL num, LL pow, LL prime) {
    if (pow == 0ll) return 1ll;
    LL ans = bigmod(num, pow/2ll, prime); ans = (ans*ans)%prime;
    if (pow%2ll) ans = (ans*num)%prime; return ans;
}

struct node {
    LL sum[40], lazy;
    node *lc; node *rc;
    node() {
        lc = NULL, rc = NULL;
        for (LL i=0; i<32; i++) sum[i] = 0;
        lazy = 0;
    }
} *root;

LL a[100005];
LL n, q, k, x, y, t;

void build (node *nd, LL st, LL en) {
    //cout << st << " " << en << endl;
    if (st == en) {
        nd->sum[0] = a[st];
        for (LL i=1; i<32; i++) {
            nd->sum[i] = nd->sum[i-1]/k;
        }
        return;
    }

    LL md = (st+en)/2;
    //cout << "here2\n";
    nd->lc = new node();
    nd->rc = new node();
    //cout << "here3\n";

    build(nd->lc, st, md);
    build(nd->rc, md+1, en);

    for (LL i=0; i<32; i++) {
        nd->sum[i] = nd->lc->sum[i] + nd->rc->sum[i];
    }
    return;
}

void updatelazy(node *nd, LL vl) {
    nd->lazy += vl;
    for (LL i=0; i<32-vl; i++) {
        nd->sum[i] = nd->sum[i+vl];
    }
    for (LL i=max(0ll,32-vl); i<32; i++) {
        nd->sum[i] = 0;
    }
    return;
}

void upd2 (node *nd, LL st, LL en, LL p1, LL p2, LL vl) {
    //cout << st << " u2 " << en << endl;
    if (st > p2 || en < p1) return;
    if (st >= p1 && en <= p2) {
        updatelazy(nd,vl);
        return;
    }

    LL md = (st+en)/2;

    updatelazy(nd->lc,nd->lazy);
    updatelazy(nd->rc,nd->lazy);
    nd->lazy = 0;

    upd2(nd->lc, st, md, p1, p2, vl);
    upd2(nd->rc, md+1, en, p1, p2, vl);

    for (LL i=0; i<32; i++) {
        nd->sum[i] = nd->lc->sum[i] + nd->rc->sum[i];
    }

    return;
}

void upd1 (node *nd, LL st, LL en, LL pos, LL vl) {
    //cout << st << " u1 " << en << endl;
    if (st == en) {
        nd->sum[0] = vl;
        for (LL i=1; i<32; i++) {
            nd->sum[i] = nd->sum[i-1]/k;
        }
        return;
    }

    LL md = (st+en)/2;

    updatelazy(nd->lc,nd->lazy);
    updatelazy(nd->rc,nd->lazy);
    nd->lazy = 0;

    if (pos<=md) upd1(nd->lc, st, md, pos, vl);
    else upd1(nd->rc, md+1, en, pos, vl);

    for (LL i=0; i<32; i++) {
        nd->sum[i] = nd->lc->sum[i] + nd->rc->sum[i];
    }
    return;
}

LL qry (node *nd, LL st, LL en, LL p1, LL p2) {
    //cout << st << " q " << en << endl;
    if (st > p2 || en < p1) return 0;
    if (st >= p1 && en <= p2) return nd->sum[0];

    LL md = (st+en)/2;

    updatelazy(nd->lc,nd->lazy);
    updatelazy(nd->rc,nd->lazy);
    nd->lazy = 0;

    LL v1 = qry(nd->lc, st, md, p1, p2);
    LL v2 = qry(nd->rc, md+1, en, p1, p2);

    return v1 + v2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen ("zz test.txt","r",stdin);

    cin >> n >> q >> k;

    for (LL i=1; i<=n; i++) cin >> a[i];

    root = new node();
    build(root, 1, n);

    while (q--) {
        cin >> t >> x >> y;
        //cout << t << " " << x << " " << y << endl;

        if (t == 1) {
            upd1(root, 1, n, x, y);
        }

        else if (t == 2) {
            if (k == 1) continue;
            upd2(root, 1, n, x, y, 1);
        }

        else {
            cout << qry(root, 1, n, x, y) << endl;
        }
    }


    return 0;
}
