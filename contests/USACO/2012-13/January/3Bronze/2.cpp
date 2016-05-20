/*
ID: Labib Rashid
LANG: C++
TASK: paint
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# include <map>


using namespace std;

int main()
{
    freopen ("paint.in","r",stdin);
    freopen ("paint.out","w",stdout);

    int a, d, i, j, it, base, st, cnt;
    string c, p ="L";
    char c1[3];
    int bes[1000000];
    map <int, int> tag;


    memset(bes,0,sizeof(bes));

    scanf ("%d", &a);

    it = 0;
    for (i=0, j=0, base=0, st=0; i<a; i++)
    {
        scanf("%d",&d);
        scanf("%s", c1);

        c = c1;
        if(c == p)
            for (;j<st+d;j++)
                bes[j] = base - j + st - 1;
        else
            for (;j<st+d;j++)
                bes[j] = base + j - st + 1;

        base = bes[j-1];
        st = j;

        it += d;
    }

    cnt = 0;
    for (i=0; i<it;i++)
    {
        if (tag[bes[i]] == 0) tag[bes[i]] ++;
        else if (tag[bes[i]] == 1) {
            tag[bes[i]] ++;
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}

