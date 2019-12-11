/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

struct nodeY{
    LL s, e, v;
    nodeY *l, *r;
    nodeY(int st, int ed){
        s = st; e = ed;
        v = 0;
        l = r = NULL;
    }
};
struct nodeX{
    int s, e;
    nodeY *n;
    nodeX *l, *r;
    nodeX(int st, int ed){
        s = st; e = ed;
        l = r = NULL;
        n = NULL;
    }
};
int R, C;

LL queryY(nodeY *ob, int s, int e){
//    cout << ob->s << " " << ob->e << " " << s << " " << e << endl;
    if(ob->s == s && ob->e == e) return ob->v;
    int mid = (ob->s + ob->e) / 2;
    if(e <= mid) {
        if(ob->l == NULL) return 0;
        return queryY(ob->l, s, e);
    } else if(s > mid) {
        if(ob->r == NULL) return 0;
        return queryY(ob->r, s, e);
    } else {
        LL ret = 0;
        if(ob->l != NULL) ret = gcd(ret, queryY(ob->l, s, mid));
        if(ob->r != NULL) ret = gcd(ret, queryY(ob->r, mid + 1, e));
        return ret;
    }
}
LL queryX(nodeX *ob, int sx, int ex, int sy, int ey){
    if(ob->s == sx && ob->e == ex) {
        if(ob->n == NULL) return 0;
        return queryY(ob->n, sy, ey);
    }
    int mid = (ob->s + ob->e) / 2;
    if(ex <= mid) {
        if(ob->l == NULL) return 0;
        return queryX(ob->l, sx, ex, sy, ey);
    } else if(sx > mid) {
        if(ob->r == NULL) return 0;
        return queryX(ob->r, sx, ex, sy, ey);
    } else {
        LL ret = 0;
        if(ob->l != NULL) ret = gcd(ret, queryX(ob->l, sx, mid, sy, ey));
        if(ob->r != NULL) ret = gcd(ret, queryX(ob->r, mid + 1, ex, sy, ey));
        return ret;
    }
}
void insertY(nodeY *ob, int py, LL v){
    if(ob->s == ob->e){
        ob->v = v;
        return;
    }
    int mid = (ob->s + ob->e) / 2;
    if(py <= mid){
        if(ob->l == NULL) ob->l = new nodeY(ob->s, mid);
        insertY(ob->l, py, v);
    } else {
        if(ob->r == NULL) ob->r = new nodeY(mid + 1, ob->e);
        insertY(ob->r, py, v);
    }
    ob->v = 0;
    if(ob->l != NULL) ob->v = gcd(ob->v, ob->l->v);
    if(ob->r != NULL) ob->v = gcd(ob->v, ob->r->v);
}
void insertX(nodeX *ob, int px, int py, LL v){
    if(ob->s == ob->e){
        if(ob->n == NULL) ob->n = new nodeY(0, C - 1);
        insertY(ob->n, py, v);
        return;
    }
    int mid = (ob->s + ob->e) / 2;
    if(px <= mid){
        if(ob->l == NULL) ob->l = new nodeX(ob->s, mid);
        insertX(ob->l, px, py, v);
    } else {
        if(ob->r == NULL) ob->r = new nodeX(mid + 1, ob->e);
        insertX(ob->r, px, py, v);
    }
    LL t = 0;
    if(ob->l != NULL && ob->l->n != NULL) t = gcd(t, queryY(ob->l->n, py, py));
    if(ob->r != NULL && ob->r->n != NULL) t = gcd(t, queryY(ob->r->n, py, py));
    if(ob->n == NULL) ob->n = new nodeY(0, C - 1);
    insertY(ob->n, py, t);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> R >> C >> a;
    nodeX *root = new nodeX(0, R - 1);
    REP(i, a){
        cin >> b >> c >> d >> e;
        if(b == 1){
            insertX(root, c, d, e);
        } else {
            cin >> f;
            cout << queryX(root, c, e, d, f) << endl;
        }
    }
}
/*
2 3 9
1 0 0 20
1 0 2 15
1 1 1 12
2 0 0 0 2
2 0 0 1 1
1 0 1 6
1 1 1 14
2 0 0 0 2
2 0 0 1 1
*/
