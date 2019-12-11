/*
ID: Labib Rashid
LANG: C++
TASK: cowfind
*/


# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int main()
{
    char grass[51000];
    int cur = 0, sum = 0, i, size, was_left = 0, was_ryt = 0;

    freopen ( "cowfind.in","r",stdin);
    freopen ( "cowfind.out","w",stdout);

    scanf ("%s", grass);

    size = strlen(grass);

    if ( grass [0] == '(' ) was_left = 1;
    else was_ryt = 1;

    for (i=1; i<size; i++)
    {
        if ( grass [i] == '(' )
        {
            if (was_left == 1) {
                cur++;
                //cout << cur << " = cur, i+1 = " << i+1 << endl;
            }
            else {
                was_left++;
                was_ryt--;
            }
        }
        if ( grass [i] == ')' )
        {
            if (was_ryt == 1) {
                sum+=cur;
                //cout << sum << " = sum, i+1 = " << i+1 << endl;
            }
            else {
                was_left--;
                was_ryt++;
            }
        }
    }
    printf ("%d\n", sum);

    return 0;
}
