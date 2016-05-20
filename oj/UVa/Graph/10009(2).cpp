/*
UVa
10009 - all roads lead where
graph
7.3.2013
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <map>
# include <vector>
# include <queue>

using namespace std;

struct two {
    int p, c, f;
};

map <string,int> m;
char path [50000];
vector <int> e[50000];
int parent [50000];
queue <two> q;
string s1, s2;

inline void pseq (int a,int k)
{
    if (k == 0)
    {
        cout << path[a];
        return;
    }

    pseq (parent[a], k-1);
    cout << path[a];
    return;
}

int main()
{
    int t, n, z, i, j, k, d, a;
    two s;

    cin >> t;
    while (t--){
        k = 0;

        cin >> n >> z;
        while (n--) //input
        {
            cin >> s1 >> s2;

            if (m.find (s1) == m.end()){
                path[k] = s1[0];
                m[s1] = k++;
            }
            if (m.find (s2) == m.end()){
                path[k] = s2[0];
                m[s2] = k++;
            }

            e[m[s1]].push_back (m[s2]);
            e[m[s2]].push_back (m[s1]);
        }

        while (z--)
        {
            memset (parent, -1, sizeof (parent));

            cin >> s1 >> s2;
            s.p = m[s1], d = m[s2];
            s.c = 0, s.f = s.p;

            q.push (s);

            while (!q.empty())
            {
                s = q.front();
                q.pop();

                i = s.p, j = s.c, k = s.f;
                if (parent[i] != -1) {
                    continue;
                }
                parent[i] = s.f;

                if (s.p == d) {
                    break;
                }

                for (a = 0; a < (int) e[i].size(); a++)
                {
                    if (parent[e[i][a]] != -1) continue;
                    s.p = e[i][a], s.c = j+1, s.f = i;
                    q.push (s);
                }
            }
            pseq (i, j);
            cout << endl;

            while (!q.empty()) q.pop();
        }
        if (t != 0) cout << endl;

        for (i = 0; i < 50000; i++) e[i].clear();
        m.clear();
    }

    return 0;
}
