/*
ID: Labib Rashid
LANG: C++
TASK: typo
*/


# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int main()
{
    char line[100000];
    int size, res, i, dif = 0, c1=0, c2=0,gr=0;

    freopen ( "typo.in","r",stdin);
    freopen ( "typo.out","w",stdout);

    scanf("%s", line);
    size = strlen(line);

    if (size % 2 == 1) {
        res =0;
    }

    else {
        for (i=0; i<size; i++)
        {

            if (line[i] == '('){
                dif++;
                if (gr != 1) c1++;
            }
            else {
                dif--;
                if (gr != 1) c2++;
            }

            if (dif <= 1) c1 = 0;

            if (dif < 0) {
                res = c2;
                gr = 1;
            }
        }

        if (dif != 2 && dif != -2) res = 0;
        if (dif == 2) res = c1;
    }

    printf ("%d\n",res);

    return 0;
}
