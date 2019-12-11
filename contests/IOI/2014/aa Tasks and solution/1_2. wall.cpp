/*
ID: Labib666
LANG: C++
Contest: IOI 2014
Task: wall
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

//-------------------------------------------------------------------------------------------------

#define MAXN

struct node {
    int valHi, valLo, idHi, idLo, start, finish, Lchild, Rchild;
    init(int vst, int vend) {
        valHi = 0; valLo = INF;
        idHi = idLo = 0;
        start = vst, finish = vend;
        Lchild = Rchild = -1;
    }
    lazy() {
        for (int i=tree[n].Lchild; i<=tree[n].Rchild; i++) {
            if (tree[n].valHi > tree[i].valLo) { tree[i].valLo = tree[n].valHi; }
            if (tree[n].valLo < tree[i].valHi) { tree[i].valLo = tree[n].valLo; }
            if (tree[n].valHi > tree[i].valHi) { tree[i].idHi = tree[n].idHi; tree[i].valHi = tree[n].idHi; }
            if (tree[n].valLo < tree[i].valLo) { tree[i].idLo = tree[n].idLo; tree[i].valLo = tree[n].idLo; }
        }
    }
};

vector <node> tree;
int cur;

void build_tree(int n, int s, int e) {

    if (s == e) return;

    int m = (s+e)/2; node nchild;

    // create Lchild
    tree.push_back (nchild);
    tree[n].Lchild = ++cur;
    tree[cur].init(s, m);

    // create Rchild
    tree.push_back (nchild);
    tree[n].Rchild = ++cur;
    tree[cur].init(m+1, e);

    return;
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, K, typ, u, v, val;
    cin >> N >> K;

    node root; root.init(1,N);
    tree.push_back(root);
    build_tree(0,1,N);

    while (K--) {
        cin >> typ >> u >> v >> val;

    }

    return 0;
}
