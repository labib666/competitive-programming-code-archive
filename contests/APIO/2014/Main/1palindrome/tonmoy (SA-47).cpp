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

#define MAX 300005
struct data {
  Pii tup;
  int p;

  bool operator < (const data &b) const
  {
    return tup < b.tup;
  }
} L[MAX];
int srt_indx[21][MAX], n, lcp[MAX];
char str[MAX];

bool find_pal(int indx, int sz)
{
  int rght = indx + sz - 1;
  while(indx < rght) {
    if(str[indx] != str[rght])
      return false;
    indx++;
    rght--;
  }

  return true;
}

Long func(int sz)
{
  Long ret = 0;
  int i = 0;

  while(i < n) {
    if(n - L[i].p < sz) {
      i++;
      continue;
    }
    if(!find_pal(L[i].p, sz)) {
      i++;
      continue;
    }

    int j = i;
    while(i < n) {
      i++;
      if(lcp[i] < sz)
        break;
    }
    //printf("sz: %d i: %d j: %d\n", sz, i, j);
    ret = max(ret, (i-j) * (Long)sz);
  }

  return ret;
}

int main()
{
  READ("palindrome.in");
  WRITE("palindrome.out");
  scanf("%s", str);
  n = strlen(str);

  REP(i, n)
    srt_indx[0][i] = str[i] - 'a';

  int done, step;
  for(done = 1, step = 1; (done / 2) < n; done *= 2, step++) {
    REP(i, n) {
      L[i].tup.Fr = srt_indx[step-1][i];
      L[i].tup.Sc = (i + done < n) ? srt_indx[step-1][i + done] : -1;
      L[i].p = i;
    }
    sort(L, L+n);

    REP(i, n) {
      srt_indx[step][L[i].p] = (i>0 && L[i].tup.Fr == L[i-1].tup.Fr && L[i].tup.Sc == L[i-1].tup.Sc) ? srt_indx[step][L[i-1].p] : i;
    }
  }

  for(int i = 1; i < n; i++) {
    int x = L[i-1].p, y = L[i].p;
    for(int j = step-1; j >= 0 && x < n && y < n; j--) {
      if(srt_indx[j][x] == srt_indx[j][y]) {
        x += (1 << j);
        y += (1 << j);
        lcp[i] += (1 << j);
      }
    }
  }

  // debug
/*
  REP(i, n) {
    printf("L[%d].p: %d\n", i, L[i].p);
    printf("lcp[%d]: %d\n", i, lcp[i]);
  }
  puts("");
*/
  Long ret = 0;
  ITR(i, 1, n+1) {
    ret = max(ret, func(i));
  }
  cout << ret << endl;

  return 0;
}
