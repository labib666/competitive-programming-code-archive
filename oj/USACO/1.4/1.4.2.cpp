/*
USACO
search
1.4.2 - clocks
25.12.12
*/

/*
ID: Labib Rashid
LANG: C++
TASK: clocks
*/

# include <cstdio>
# include <cstring>
# include <vector>
# include <iostream>

using namespace std;

int c[9];
vector <int> m[10];
int e[10];
int res[30];
int l, found = 0, run = 0, f = 0;

void revm(int k)
{
    for (int i = 0; i<m[k].size(); i++) c[m[k][i]]--;
}

void move (int k)
{
    int i;
    run++;
    e[k]++;

    for (i = 0; i<m[k].size(); i++) c[m[k][i]]++;


    if (l == run)
    {
        found = 1;
        for (i=0;i<9;i++) {
            if (c[i]%4 != 0)
             {
                 found = 0;
                 break;
             }
             if (found == 1)f=run;
        }
    }
    else for (i=k;i<=9;i++) {
        if (e[i] < 3) move (i);
        if (found == 1) break;
    }

    if (found == 1) {
        res[run] = k;
        run--;
        return;
    }

    else {
        run--;
        e[k]--;

        revm (k);
        return;
    }
}

int main()
{
    int i,k;

    freopen ("clocks.in","r",stdin);
    freopen ("clocks.out","w",stdout);

    for (i = 0; i<9; i++)
    {
        scanf("%d", &k);

        c[i] = (k/3)%4;
    }

    memset (res, 0, sizeof(res));
    memset (e, 0, sizeof(e));

    { //move details
        m[1].push_back(0);
        m[1].push_back(1);
        m[1].push_back(3);
        m[1].push_back(4);

        m[2].push_back(0);
        m[2].push_back(1);
        m[2].push_back(2);

        m[3].push_back(1);
        m[3].push_back(2);
        m[3].push_back(5);
        m[3].push_back(4);

        m[4].push_back(0);
        m[4].push_back(3);
        m[4].push_back(6);

        m[5].push_back(1);
        m[5].push_back(3);
        m[5].push_back(4);
        m[5].push_back(5);
        m[5].push_back(7);

        m[6].push_back(2);
        m[6].push_back(5);
        m[6].push_back(8);

        m[7].push_back(3);
        m[7].push_back(4);
        m[7].push_back(6);
        m[7].push_back(7);

        m[8].push_back(6);
        m[8].push_back(7);
        m[8].push_back(8);

        m[9].push_back(4);
        m[9].push_back(5);
        m[9].push_back(7);
        m[9].push_back(8);
    }

    for (l=1; l<=27; l++)
    {
        for (i=1;i<=9;i++) {
            if (e[i] < 3) move (i);
            if (found == 1) break;
        }
        if (found == 1) break;
    }

    for (i=0; i<=f; i++) {
        if (res[i] != 0) {
            if (i == f) cout << res[i] << "\n";
            else cout << res[i] << " ";
        }
    }

    return 0;
}
