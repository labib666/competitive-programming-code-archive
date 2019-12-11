/*
ID: Labib Rashid
LANG: C++
TASK: fairphoto
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>

#define LL long long
#define PB push_back
#define X first
#define Y second
#define INF 1000000007
#define PI 2*asin(1)
#define PII pair<int,int>
#define VI vector <int>
#define EPS 1e-9

using namespace std;


#define MAX 100005
int N, K, Ans = -1;

struct Data {
    int d[8];
    Data() {
        fill (d, d+8, 0);
    }
    bool operator < (const Data &p) const {
        for (int i = 0; i < 8; i++) {
            if (d[i] < p.d[i]) return true;
            else if (d[i] > p.d[i]) return false;
        }
        return false;
    }
};

int V[8], S[8][MAX];
PII P[MAX];
map <Data, int> M;

void Init () {
    M.clear();
    Data d = new Data();
    M[d] = 1;
    return;
}

void Solve (int pos, int rem) {
    if (pos < rem) return;
    if (rem == 0) {
        int i, j, k, base;
        Init();

        for (i=0;i<8;i++) {
            if (V[i]) {
                base = i;
                break;
            }
        }

        for (i = 0, cur = -1; i < N; i++) {

            Data D = new Data();
            bool fail = 0;
            for (j = 0; j < K; j++) {
                k = C[i];
                if (S[i][k] == 0) {fail = 1; break;}
                D.d[j] = S[i][k] - S[i][base];
            }
            if (fail) continue;
            if (M.find(D) == M.end()) M[D] =  P[i].X;
            else {
                cur = P[i].X - M[D] - 1;
            }
        }

        return;
    }
    Solve(pos-1,K);
    V[i] = 1;
    Solve(pos-1,K-1);
    V[i] = 0;
    return;
}

int main()
{
    //freopen ("1fairphoto.txt","r",stdin);
    //freopen ("fairphoto.in","r",stdin);
    //freopen ("fairphoto.out","w",stdout);

    int i;

    cin >> N >> K;

    for (i=0; i<N; i++) {
        cin >> P[i].X >> P[i].Y;
        P[i].Y--;
        P[i].X += 2;
    }

    sort (P, P+N);
    for (i=0; i<N; i++) {
        S[i][P[i].Y]++;
    }

    Solve(8,K);

    return 0;
}
