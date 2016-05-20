/*
ID: Labib Rashid
LANG: C++
TASK: COCI contest 8, T3
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

set <int> BU, BL, RU, RL;
set <int> ::iterator I1, I2;
int N, M;
string Q = "Q", A = "A", B = "B";

bool Connected (int U, int V);

int main()
{
    freopen ("3Mostovi.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int i, j;
    string s;

    cin >> N >> M;
    while (M--) {
        cin >> s;

        if (s == B) {
            cin >> i >> j;
            if (i <= N) {
                if (i > j) swap (i, j);
                RU.insert(i);
            }
            else {
                if (i < j) swap (i, j);
                RL.insert(i);
            }
        }

        else if (s == A) {
            cin >> i >> j;
            if (i > j) swap (i, j);
            BU.insert(i);
            BL.insert(j);
        }

        else {
            cin >> i >> j;
            if (Connected(i, j)) cout << "DA\n";
            else cout << "NE\n";
        }
    }


    return 0;
}

bool Blocade (int U, int V) {
    if (U <= N) {
        I1 = RU.lower_bound(U);
        if (I1 == RU.end() || *I1 >= V) return 1;
        return 0;
    }
    else {
        I1 = RL.lower_bound(V+1);
        if (I1 == RL.end() || *I1 > U) return 1;
        return 0;
    }
}

bool

bool Connected(int U, int V) {
    int i, j;

    //** Case 1 - both on upper side, U < V

    if (U <= N && V <= N && U <= V)
        return Blocade(U,V);

    //** Case 2 - both on lower side, U > V

    else if (U > N && V > N && U >= V)
        return Blocade(U,V);

    //** Case 3 - U,V on different sides

}
