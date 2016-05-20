# include <cstdio>
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main()
{
    int a, r;
    vector <int> bin;

    freopen ("binnum.in", "r", stdin);
    freopen ("binnum.out", "w" stdout);

    scanf ("%d", &a);
    if (a != 0)
    {
        while (a != 0)
        {
            r = a%2;
            a /= 2;

            bin.push_back (r);
        }

        reverse (bin.begin(),bin.end());
        for (int i = 0; i < bin.size(); i++)
            cout << bin[i];
        cout << endl;
    }

    else cout << 0 << endl;

    return 0;
}
