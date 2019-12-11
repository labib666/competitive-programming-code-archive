/*
UVa
graph - floyd warshall
429 - word transformation
14.3.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <vector>
# include <string>
# include <map>
# include <sstream>
# include <queue>
# include <algorithm>

using namespace std;

struct two {
    int u, v, w;
};

int diff (string s1, string s2)
{
    int i, j=0;
    int sz1 = s1.size(), sz2 = s2.size();
    if (sz1 != sz2) return 1000;
    for (i = 0; i < sz1; i++)
    {
        if (s1[i] != s2[i])
            j++;
    }
    return j;
}

int d[205][205];
two e[40005];
int main ()
{
    int t, i, j, k, sz, m, n;

    string s1, s2, s3, star ="*";
    char str[100];
    vector <string> word;
    map <string, int> mp;

    cin >> t;
    while (t--)
    {
        n = 0;
        while (1)
        {
            cin >> s1;
            if (s1 == star) break;

            word.push_back(s1);
            mp[s1] = n++;
        }

        sz = (int)word.size();
        memset (d, -1, sizeof (d));
        m = 0;

        for (i = 0; i < sz; i++)
            for (j=0; j < sz; j++)
                d[i][j] = 0x33333333;
        for (i = 0; i < sz; i++)
            d[i][i] = 0;

        for (i = 0; i < sz; i++)
            for (j = i+1; j < sz; j++)
                if (diff (word[i], word[j]) == 1)
                    e[m].u = i, e[m].v = j, e[m].w = 1, m++;

        for (i = 0; i < sz; i++) //floyd warshall
            for (j = 0; j < sz; j++)
                for (k=0; k<m;k++){
                    if (d[i][e[k].v] > d[i][e[k].u] + e[k].w)
                        d[i][e[k].v] = d[i][e[k].u] + e[k].w;
                    if (d[i][e[k].u] > d[i][e[k].v] + e[k].w)
                        d[i][e[k].u] = d[i][e[k].v] + e[k].w;
                }

        gets (str); // dummy
        while (gets (str) != NULL)
        {
            if ((int)strlen(str) == 0) break;
            s3 = str;
            stringstream ss;
            ss << s3;
            ss >> s1;
            ss >> s2;
            sz = (int) s1.size();

            int p1 = mp[s1], p2 = mp[s2];
            cout << s1 << " " << s2 << " " << d[p1][p2] << endl;
        }

        if (t) cout << endl;
        mp.clear();
        word.clear();
    }
    return 0;
}

