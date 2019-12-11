# include <cstdio>
# include <iostream>
# include <cstring>
# include <map>
# include <vector>
# include <queue>
# define pb push_back

using namespace std;

struct go {
    int p;
    string s;
};

using namespace std;

int main()
{
    int n, m, i, j, t, k, d, cnt;
    map <string,int> tag;
    vector <int> c[50000];
    int v [50000];
    string path [50000];
    string s1, s2;
    queue <go> q;
    go g1, g2;


    cin >> t;
    while (t--)
    {
        tag.clear();
        k = 0;

        cin >> n >> m;
        for (i = 0; i< n; i++)
        {
            cin >> s1 >> s2;

            if (tag.find(s1) == tag.end()){
                //cout << s1 << " " << k << endl;
                path[k] = s1[0];
                tag[s1] = k++;
            }
            if (tag.find(s2) == tag.end()){
                //cout << s2 << " " << k << endl;
                path[k] = s2[0];
                tag[s2] = k++;
            }

            c[tag[s1]].pb (tag[s2]);
            c[tag[s2]].pb (tag[s1]);
        }

        while (m--)
        {
            fill (v, v+k, 0);
            cin >> s1 >> s2;
            d = tag[s2];
            //cout << d << endl;
            //cout << s1 << " "  << tag[s1] << endl;

            g1.p = tag[s1];
            g1.s = path[g1.p];
            q.push (g1);
            string ns;
            while (!q.empty())
            {
                g1 = q.front();
                q.pop();

                int p = g1.p;
                ns = g1.s;

                if (v[p]) continue;
                if (p == d) break;
                //cout << p << " " << ns << endl;

                v[p] = 1;
                for (i = 0; i < (int)c[p].size(); i++)
                {
                    if (v[c[p][i]]) continue;
                    g2.s = ns + path[c[p][i]];
                    g2.p = c[p][i];
                    q.push(g2);
                }
            }
            cout << ns << endl;

            while (!q.empty()) q.pop();
        }

        for (i=0; i<k; i++) c[i].clear();
        if (t != 0) cout << endl;
    }

    return 0;
}
