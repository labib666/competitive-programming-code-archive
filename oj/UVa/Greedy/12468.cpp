/*
UVa
12468 - zapping
greedy
3.4.2013
*/

# include <cstdio>
# include <cmath>
# include <iostream>

using namespace std;

int main()
{
    int n, m, a1, a2;

    while (1)
    {
        cin >> n >> m;
        if (n == -1 && m == -1)
            break;

        a1 = abs (n - m);

        if (n <= m) n += 100;
        else m += 100;

        a2 = abs (n - m);

        cout << min (a1, a2) << endl;
    }
    return 0;
}
