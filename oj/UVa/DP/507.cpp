# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int stop [20005];

int main()
{
    int t, i, sum, n, mx, c, start, end, j;

    cin >> t;
    for (i=0;i<t; i++)
    {
        scanf ("%d", &n);

        stop[0] = 0;
        for (j=1;j<n; j++) scanf ("%d", &stop[j]);

        c = 0;
        mx = 0;
        start = 0;
        end = 0;
        sum = 0;
        int tend, tstart;
        tend = tstart = 0;

        for (j=1;j<n;j++)
        {
            sum += stop[j];

            if (sum < 0) c = 0;

            if (sum >= 0)
            {
                if (c == 0)
                {
                    c = 1;
                    tstart = j - 1;
                    tend = j;
                    if (sum > mx) {
                        mx = sum;
                        end = tend;
                        start = tstart;
                    }
                    else if (sum == mx){
                        if (tend - tstart > end - start)
                        {
                            //cout << "YES sum = " << sum << endl;
                            end = tend;
                            start = tstart;
                        }
                    }
                }
                else
                {
                    tend = j;
                    if (sum > mx) {
                        mx = sum;
                        end = tend;
                        start = tstart;
                    }
                    else if (sum == mx){
                        if (tend - tstart > end - start)
                        {
                            //cout << endl << "YES sum = " << sum  << " mx = " << mx << endl;
                            end = tend;
                            start = tstart;
                        }
                    }
                }
            }
            sum = max (sum,0);
            //cout << "at stop " << j << " sum = " << sum << " start = " << start << " end = " << end << endl;
        }

        if (mx == 0) printf ("Route %d has no nice parts\n", i+1);
        else printf ("The nicest part of route %d is between stops %d and %d\n", i+1, start+1, end+1);
    }
    return 0;
}
