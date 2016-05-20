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
    int val, flag, neg, negflag, start, finish, Lchild, Rchild;
    void init(int vst, int vend) {
        val = 0; flag = 0, neg = INF, negflag = 0;
        start = vst, finish = vend;
        Lchild = Rchild = -1;
    }
};

vector <node> tree;
int cur;

void lazy( node &a ) {
    int bb[2]; bb[0] = a.Lchild, bb[1] = a.Rchild;
    for (int j=0; j<=1; j++) {
        int i = bb[j];
        if (a.flag == 0) {
            if (a.negflag == 0) {
                continue;
            }
            else {
                if (tree[i].flag == 0) {
                    tree[i].negflag = 1;
                    tree[i].neg = min(tree[i].neg, a.neg);
                }
                else {
                    tree[i].negflag = 1;
                    tree[i].neg = min(tree[i].neg, a.neg);
                    tree[i].val = min(tree[i].val, tree[i].neg);
                }
                //a.neg = INF; a.negflag = 0;
            }
        }
        else {
            if (a.negflag == 0) {
                //cout << i << " && " << a.start << " " << a.finish << " yes\n";
                if (tree[i].negflag == 0) {
                    tree[i].flag = 1;
                    tree[i].val = max (tree[i].val, a.val);
                }
                else {
                    tree[i].neg = (tree[i].neg <= a.val) ? INF : tree[i].neg;
                    tree[i].flag = 1;
                    tree[i].val = max (tree[i].val, a.val);
                }
            }
            else {
                if (tree[i].negflag == 0) {
                    tree[i].negflag = 1; tree[i].neg = a.neg;
                    tree[i].val = (a.val<a.neg) ? min(max(a.val,tree[i].val),a.neg) : a.val;;
                    tree[i].flag = 1;
                }
                else {
                    tree[i].flag = 1; tree[i].val = (a.val<a.neg) ? min(max(a.val,tree[i].val),a.neg) : a.val;
                    tree[i].neg = (a.val>tree[i].neg) ? a.neg : min(tree[i].neg, a.neg);
                }
                //a.neg = INF; a.negflag = 0;
            }
            //a.val = a.flag = 0;
        }
    }
    a.val = a.flag = a.negflag = 0; a.neg = INF;
    return;
}

void build_tree(int n, int s, int e) {
    //cout << n << " -> " << s << " -> " << e << endl;

    if (s == e) return;

    int m = (s+e)/2; node nchild;

    // create Lchild
    tree.push_back (nchild);
    tree[n].Lchild = ++cur;
    tree[cur].init(s, m);
    build_tree(cur, s, m);

    // create Rchild
    tree.push_back (nchild);
    tree[n].Rchild = ++cur;
    tree[cur].init(m+1, e);
    build_tree(cur, m+1, e);

    return;
}

void update (int n, int p1, int p2, int typ, int score) {
    //cout << n << " " << tree[n].start << " " << tree[n].finish << endl;
    if (p1 > tree[n].finish || p2 < tree[n].start) return;
    if (p1 <= tree[n].start && p2 >= tree[n].finish) {
        if (typ == 2) {
            if (tree[n].flag == 0) {
                tree[n].neg = min (tree[n].neg, score);
                tree[n].negflag = 1;
            }
            else {
                //cout << "yes\n";
                tree[n].negflag = 1;
                tree[n].neg = min (tree[n].neg, score);
                tree[n].val = min (tree[n].neg, tree[n].val);
            }
        }
        else {
            if (tree[n].negflag == 0) {
                tree[n].val = max(tree[n].val, score); tree[n].flag = 1;
            }
            else {
                tree[n].flag = 1;
                tree[n].neg = (tree[n].neg<=score) ? INF : tree[n].neg;
                tree[n].val = max(tree[n].val, score);
            }
        }
        //cout << n << " -> " << tree[n].start << " & " << tree[n].finish << endl;
        //cout << tree[n].val << " - id " << tree[n].flag << " " << tree[n].negflag << " id - " << tree[n].neg << endl;
        return;
    }

    lazy(tree[n]);
    update(tree[n].Lchild,p1,p2,typ,score);
    update(tree[n].Rchild,p1,p2,typ,score);

    return;
}

int query (int n, int pos) {
    if (tree[n].start == tree[n].finish) { return tree[n].val; }

    int m = (tree[n].start+tree[n].finish)/2;
    lazy(tree[n]);

    if (pos <= m) return query(tree[n].Lchild, pos);
    else return query(tree[n].Rchild, pos);
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("zz test.txt", "r", stdin);

    int N, K, typ, u, v, val;
    cin >> N >> K;

    node root; root.init(0,N-1);
    tree.push_back(root);

    cur = 0;
    build_tree(0,0,N-1);

    while (K--) {
        cin >> typ >> u >> v >> val;
        //cout << "new update\n";
        update(0,u,v,typ,val);
    }

    for (int i=0; i<N; i++) cout << query(0,i) << endl;

    return 0;
}
