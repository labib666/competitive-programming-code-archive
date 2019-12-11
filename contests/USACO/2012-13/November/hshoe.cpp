/*
ID: Labib Rashid
LANG: C++
TASK: hshoe
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int grid[7][7];
int visited [7][7];
int res = 0;
int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};

void find (int a, int b, int open, int close, int sign)
{
    int dx,dy,i;

    if (sign == 1) if (2*open <= res) return;

    if (open == close)
    {
        res = 2*open;
        return;
    }

    visited [a][b] = 1;

    for (i = 0; i<4; i++)
    {
        dx = a+x[i];
        dy = b+y[i];

        if (visited[dx][dy] == 0)
        {
            if (sign == 1) {
                if (grid[dx][dy] != 1) continue;
                else find (dx,dy,open,close+1,1);
            }
            else {
                if (grid[dx][dy] == 1) find (dx,dy,open,close+1,1);
                else if (grid[dx][dy] == 0) find (dx,dy,open+1,close,0);
            }
        }


    }
    visited [a][b] = 0;
    return;
}

int main()
{
    int n,i,j;
    char line[10];

    freopen ( "hshoe.in","r",stdin);
    freopen ( "hshoe.out","w",stdout);

    scanf ("%d", &n);

    for (i=0; i<=n+1; i++)
    {
        grid[0][i] = grid[i][0] = grid[n+1][i] = grid[i][n+1] = -1;
        visited[0][i] = visited[i][0] = visited[n+1][i] = visited[i][n+1] = 1;
    }

    for (i=1; i<=n; i++)
    {
        scanf("%s", line);
        for (j=1; j<=n; j++){
            if (line[j-1] == ')') grid[i][j] = 1;
            else grid[i][j] = 0;
            visited[i][j] = 0;
        }
    }

   // for (i=0; i<=n+1; i++){
    //    for (j=0; j<=n+1; j++)
     //       cout << grid[i][j];
    //    cout << endl;
   // }

    if (grid[1][1] == 0)
        find(1,1,1,0,0);

    printf ("%d", res);

    return 0;
}

