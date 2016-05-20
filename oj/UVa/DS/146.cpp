/*
UVa
146 - id codes
DS
23.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>

using namespace std;

int c[64];
char s[64];
string s1, h = "#";

int main ()
{
    int i, j, a1, sz, a2;
    while (1)
    {
        cin >> s;
        s1 = s;
        if (s1 == h) break;

        sz = strlen(s);
        reverse (s, s+sz);

        for (i = 0; i < sz; i++)
            c[i] = 0x33333333;

        for (i = 0; i < sz; i++)
        {
            for (j = i+1; j < sz; j++)
                if (s[i] > s[j]) {
                    c[i] = j;
                    break;
                }
        }

        a1 = a2 = 0x33333333 - 10;
        for (i = 0; i < sz; i++)
        {
            if (a2 > c[i]){
                a2 = c[i];
                a1 = i;
            }
            else if (a2 == c[i]){
                a1 = (s[a1] <= s[i]) ? a1 : i;
            }
        }

        if (a2 >= 0x33333333 - 10){
            cout << "No Successor\n";
            continue;
        }

        swap (s[a1], s[a2]);
        sort (s, s+a2);
        reverse(s, s+a2);
        reverse (s, s+sz);

        cout << s << endl;
    }
    return 0;
}

