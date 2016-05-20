# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int x[4] = {0, 0, -1, 1};
int y[4] = {1, -1, 0, 0};
int visited [77][77];
int grid[77][77];
int xmx, ymx, xmn, ymn, area, barn = 0, cow = 0;

void dfs (int a, int b, int l, int w)
{
    int i, dx, dy;

    area ++;
    if (xmx < l) xmx = l;
    else if (xmn > l) xmn = l;
    if (ymx < w) ymx = w;
    else if (ymn > w) ymn = w;

    visited [a][b] = 1;
    grid [a][b] = 0;

    for (i=0; i<4; i++)
    {
        dx = a + x[i];
        dy = b + y[i];

        if (visited[dx][dy] == 0 && grid [dx][dy] == 1) dfs (dx,dy, l+x[i], w+y[i]);
    }

    visited[a][b] = 0;
    return;
}

void check (int a, int b)
{
    xmx = ymx = xmn = ymn = 1;
    area = 0;

    dfs (a, b, 1, 1);

    int dl, dw;

    dl = xmx - xmn + 1;
    dw = ymx - ymn + 1;

    //cout << area << " " << dl << " " << dw << endl;

    if (dl*dw == area) barn ++;
    else cow++;

    return;
}

int main ()
{
    int r, c, i, j;
    char line [80];

    memset (grid, 0, sizeof(grid));
    memset (visited, 0, sizeof(visited));

    scanf ("%d %d", &r, &c);

    for (i = 0; i<=r+1; i++)
    {
        visited[i][0] = visited[i][c+1] = -1;
        grid[i][0] = grid[i][c+1] = -1;
    }
    for (i = 0; i<=c+1; i++)
    {
        visited[0][i] = visited[0][i] = -1;
        grid[0][i] = grid[r+1][i] = -1;
    }

    for (i = 1; i<=r; i++)
    {
        scanf ("%s", line);

        for (j=1; j<= c; j++)
        {
            if (line[j-1] == '#') grid[i][j] = 1;
            else grid [i][j] = 0;
        }
    }
    /*for (i = 0; i<=r+1; i++)
    {
        for (j = 0; j<=c+1; j++)
            cout << grid [i][j];
        cout << endl;
    }*/

    for (i = 1; i<=r; i++)
        for (j = 1; j<=c; j++)
            if (grid[i][j] == 1) check (i,j);

    cout << barn << endl << cow << endl;
    return 0;
}
