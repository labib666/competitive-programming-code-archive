/*
UVa
120 - stack of flapjacks
DS
23.2.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <sstream>
# include <queue>
# include <stack>
# include <algorithm>

using namespace std;

int cur [35], n;
void flipit (int a, int b)
{
    reverse (cur, cur+a+1);
    reverse (cur, cur+b+1);

    if (a != 0) cout << n-a << " ";
    cout << n-b << " ";

    return;
}

int main()
{
    int i, j, k, m;
    string s;
    char s1[100];

    while (gets(s1) != NULL)
    {
        s = s1;
        stringstream ss;

        ss << s;
        n = 0;

        while (ss >> cur[n]) n++;

        cout << s << endl;

        for (i = n-1; i > 0; i--)
        {
            int st = 0, m = -1;
            for (j = 0; j <= i; j++)
                if (m < cur[j])
                    m = cur [j], st = j;

            if (st == i) continue;
            flipit (st, i);
        }
        cout << "0" << endl;
    }
    return 0;
}
