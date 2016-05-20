#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <set>
#include <utility>
#include <queue>
#include <cassert>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ size()
#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define ITR(i, j, n) for(int i = j; i < (int)n; i++)
#define mem(array, val) memset(array, val, sizeof(array))
#define READ(filename) freopen(filename, "r", stdin)
#define WRITE(filename) freopen(filename, "w", stdout)
#define Pii pair <int, int>
#define Fr first
#define Sc second
#define Long long long
#define get(a) scanf("%d", &a)

#define MAX 1000002
int n;
char list[MAX+5];

// problem code
struct node {
  node *l, *r;
  int st, en, val;

  node(int s, int e, int v)
  {
    st = s;
    en = e;
    val = v;
    l = r = NULL;
  }
  node(int s, int e, node *ll, node *rr)
  {
    st = s;
    en = e;
    l = ll;
    r = rr;
    val = 0;
    if(l) val += l->val;
    if(r) val += r->val;
  }
};
node *roots[MAX+5];
int nxt_pos, curr_node;

node *create(int l, int r)
{
  if(l == r)
    return new node(l, r, 0);
  int mid = (l+r) / 2;
  return new node(l, r, create(l, mid), create(mid+1, r));
}

node *update(node *ob, int pos)
{
  if(ob->st == pos && ob->en == pos)
    return new node(pos, pos, 1);

  int mid = (ob->st + ob->en) / 2;
  if(pos <= mid)
    return new node(ob->st, ob->en, update(ob->l, pos), ob->r);
  else
    return new node(ob->st, ob->en, ob->l, update(ob->r, pos));
}

int find(node *ob, int a)
{
  if(ob->st == ob->en)
    return ob->st;

  int al = 0;
  if(ob->l)  al = ob->l->val;

  if(al < a)
    return find(ob->r, a - al);
  else
    return find(ob->l, a);
}

void init()
{
  roots[0] = create(0, MAX);
}

void TypeLetter(char ch)
{
  list[nxt_pos] = ch;
  roots[curr_node+1] = update(roots[curr_node], nxt_pos++);
  curr_node++;
}

void UndoCommands(int num)
{
  roots[curr_node+1] = roots[curr_node-num];
  curr_node++;
}

char getletter(int num)
{
  int pos = find(roots[curr_node], num+1);
  return list[pos];
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin >> n;

  init();
  REP(i, n) {
    char type, ch;
    int num;
    cin >> type;

    if(type == 'T') {
      cin >> ch;
      TypeLetter(ch);
    }
    else if(type == 'U') {
      cin >> num;
      UndoCommands(num);
    }
    else {
      cin >> num;
      cout << getletter(num) << endl;
    }
  }

  return 0;
}
