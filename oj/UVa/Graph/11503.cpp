/*
UVa
graph
11503 - virtual friends
12.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# include <map>

using namespace std;

int p[200005], c[200005], rank[2000005], n;
map <string, int> m;

void process (string s) {
    if (m.find(s) == m.end()) {
        m[s] = n;
        p[n] = n;
        c[n] = 1;
        n++;
    }
    return;
}

int fup (int a) {
    if (p[a] == a) return a;
    int ans = fup (p[a]);
    p[a] = ans;
    return ans;
}

int add (int a, int b) {
    int pa = fup(a), pb = fup (b);
    if (pa == pb) return c[pa];
    if (c[pa] >= c[pb]){
        p[pb] = pa;
        c[pa] += c[pb];
        return c[pa];
    }
    else {
        p[pa] = pb;
        c[pb] += c[pa];
        return c[pb];
    }
}

int main()
{
    int t, i, j, k;
    string s1, s2;
    cin >> t;
    while (t--)
    {
        n = 0;
        memset(c, 0, sizeof(c));
        cin >> k;
        while (k--) {
            cin >> s1 >> s2;
            process(s1);
            process(s2);

            j = add(m[s1], m[s2]);
            cout << j << endl;
        }
        m.clear();
    }
    return 0;
}
