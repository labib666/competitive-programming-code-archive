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

    int a, d, i, j, pos, cnt;
    string c, p ="L";
    char c1[3];
    map <int, int> tag;

    scanf ("%d", &a);

    cnt = 0;
    for (i=0, j=0, pos =0; i<a; i++)
    {
        scanf("%d",&d);
        scanf("%s", c1);

        c = c1;
        if(c == p){
            for (j = 1; j <= d; j++){
                tag[pos + j]++;
                if (tag[pos + j] == 2)
                    cnt++;
            }
            pos += d;
        }

        else{
            for (j = 1; j <= d; j++){
                tag[pos - j]++;
                if (tag[pos - j] == 2)
                    cnt++;
            }

            pos -= d;
        }
    }

    printf("%d\n", cnt);

    return 0;
}

