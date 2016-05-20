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
    int n, ans, i;
    ans = 0;
    cin >> n;

    for (i = 1; i <= n; i++)
        ans += ((i+1)*i + ((i+1)*i)/2);

    cout << ans << endl;

    return 0;
}

