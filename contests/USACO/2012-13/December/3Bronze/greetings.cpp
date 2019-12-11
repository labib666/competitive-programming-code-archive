/*
ID: Labib Rashid
LANG: C++
TASK: greetigs
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>


using namespace std;

int main()
{
    freopen ("greetings.in","r",stdin);
    freopen ("greetings.out","w",stdout);

    int a,b,d, i,j, it, base, t1=0, t2=0, st, cnt, ma,k;
    string c, p ="L";
    char c1[3];
    int bes[1000000];
    int els[1000000];


    memset(bes,0,sizeof(bes));
    memset(els,0,sizeof(els));



    scanf ("%d %d", &a, &b);


    for (i=0,j=0,base=0, st=0; i<a; i++)
    {
        scanf("%d",&d);
        scanf("%s", c1);

        c=c1;
        if(c == p){
            for (;j<st+d;j++)
            {
                bes[j] = base - j + st - 1;
            }
        }
        else {
            for (;j<st+d;j++)
            {
                bes[j] = base + j - st + 1;
            }
        }
        base = bes[j-1];
        st = j;
        t1 += d;
    }
    for (i=0,j=0,base=0, st=0; i<b; i++)
    {
        scanf("%d",&d);
        scanf("%s", c1);

        c=c1;
        if(c == p){
            for (;j<st+d;j++)
            {
                els[j] = base - j + st - 1;
            }
        }
        else {
            for (;j<st+d;j++)
            {
                els[j] = base + j - st + 1;
            }
        }
        base = els[j-1];
        st = j;
        t2 += d;
    }
    if (t1 > t2) {
        for (i=t2; i<t1; i++) {
            els [i] = els [t2-1];
        }
    }

    else if (t2 > t1){
        for (i=t1; i<t2; i++) {
            bes [i] = bes [t1-1];
        }
    }

    ma = max(t1,t2);

    cnt = 0;
    it = 1;
    for (i=0; i<ma; i++)
    {
        if (bes[i]==els[i] && it==0)
        {
            it = 1;
            cnt ++;
        }
        else if (bes[i] != els[i] && it != 0) it = 0;
    }

    printf("%d\n", cnt);

    return 0;
}
