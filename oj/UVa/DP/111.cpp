/*
UVa
DP
111 - history Grading
15.1.13
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <map>

using namespace std;

int main()
{
    int n, i, j, t;
    map <int, int> tag;
    int order [21], check[21];

    scanf ("%d", &n);

    for (i=1; i<=n; i++)
    {
        scanf ("%d", &j);
        tag[i] = j;
    }

    while (1)
    {
        for(j=1;j<=n; j++) check[j] = 1;

        if (scanf ("%d", &j) == EOF) break;

        order[j] = tag[1];

        for (i=2; i<=n; i++){
            scanf ("%d", &j);
            order [j] = tag[i];
        }

        //for (i=1; i<=n; i++) cout << order[i] << " " ;
        //cout << endl;

        for (i=n-1; i>0; i--)
        {
            for(j=i+1;j<=n; j++)
            {
                if (order[i] < order[j])
                    if (check[i] < check[j] + 1)
                        check[i] = check[j] + 1;
            }
        }

        t = 0;
        for(j=1;j<=n; j++)
            if (t < check[j])
                t = check[j];

        //for(j=1;j<=n; j++) cout << check[j] << " " << j << endl;

        cout << t << endl;
    }

    return 0;
}
