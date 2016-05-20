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
    string s;
    int c;
};

vector <string> s[15];
map <string, int> m;

int diff (string s1, string s2, int sz)
{
    int i, j=0;
    for (i = 0; i < sz; i++)
    {
        if (s1[i] != s2[i])
            j++;
    }
    return j;
}

void bfs (string s1, string s2, int sz)
{
    //cout << s1 << " " <<  s2 << endl;
    int v[205], i, j, k;
    queue <two> q;
    two t1, t2;

    t1.s = s1;
    t1.c = 0;
    q.push (t1);

    memset (v, 0, sizeof (v));
    while (!q.empty())
    {
        t1 = q.front();
        q.pop();

        if (v[m[t1.s]]) continue;
        v[m[t1.s]] = 1;
        if (t1.s == s2) break;

        for (i=0; i<(int)s[sz].size(); i++)
        {
            if (v[m[s[sz][i]]]) continue;
            if (diff (s[sz][i],t1.s, sz) == 1)
            {
                t2.s = s[sz][i];
                t2.c = t1.c + 1;
                q.push (t2);
            }
        }
    }
    //cout << s1 << " " << s2 << " " << t1.c << endl;
    printf ("%s %s %d\n", s1.c_str(), s2.c_str(), t1.c);
    return;
}

int main ()
{
    int t, i, j, k, sz;
    string s1, s2, s3, star ="*";
    char str[100];

    cin >> t;
    while (t--)
    {
        while (1)
        {
            cin >> s1;
            if (s1 == star) break;

            sz = (int)s1.size();
            s[sz].push_back (s1);
        }

        for (i = 1; i <= 10; i++){
            sort (s[i].begin(), s[i].end());
            for (j = 0; j < (int) s[i].size(); j++)
                m[s[i][j]] = j;
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

            bfs (s1, s2, sz);
        }

        if (t) cout << endl;
        for (i = 0; i < 15; i++) s[i].clear();
        m.clear();
    }
    return 0;
}
