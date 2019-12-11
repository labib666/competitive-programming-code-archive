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
# include <cstring>
# include <queue>

using namespace std;

int main()
{
    int n, ans = 0, i, j, k;
    cin >> n;

    for (i = 0; i <= n; i++) {
        j = i+1;
        k = n-i + 1;
        ans = max(ans, j*k);
    }

    cout << ans << endl;

    return 0;
}

