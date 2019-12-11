/*
ID: Labib Rashid
LANG: C++
TASK: poker
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int deck [100005];
long long int findmov (int a, int b)
{
    //cout << a << "  " << b << endl;
    if (a > b) return 0;
    long long int i, lo, k;
    for (i = a, lo = 10000007; i <= b; i++)
        if (lo > deck[i])
            lo = deck[i], k = i;

    for (i = a; i <= b; i++)
        deck[i] -= lo;

    //cout << a << " " << b << endl;
    long long int ans = lo + findmov(a, k-1) + findmov (k+1, b);
    return ans;
}
int main()
{
    int n, i;

    freopen ("poker.in", "r", stdin);
    freopen ("poker.out", "w", stdout);

    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> deck[i];

    long long int ans = findmov(1,n);

    cout << ans << endl;
    return 0;
}
