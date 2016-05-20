# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int main()
{
    int n, i, j, max, start, ans = 1;
    int num[5005];
    int opt[5005];

    memset (num, 0, sizeof(num));

    scanf ("%d", &n);

    for (i=0; i<n; i++)
        scanf ("%d", &num[i]);

    for (i = n-1; i>0; i--)
    {
        max = 1;
        start = 1;
        for (j=i+1; j<n; j++)
        {
            if (num[j] < num[i]){
                if (opt[j]+start > max) {
                    max = start + opt[j];
                }
            }
        }
        opt[i] = max;
        if (max > ans) ans = max;
    }
    cout << ans << endl;

    return 0;
}
