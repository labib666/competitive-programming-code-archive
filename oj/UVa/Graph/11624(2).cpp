#include<stdio.h>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;

int map[1000][1000], dF[1000][1000];
bool visited[1000][1000];

int main() {
//    freopen("input.in", "r", stdin);

    int caseNum;
    scanf("%d", &caseNum);

    while(caseNum--) {
        int r, c;
        scanf("%d%d", &r, &c);

        char line[1200];
        gets(line);

        memset(map, 0, sizeof(map));
        memset(dF, 0xff, sizeof(dF));
        memset(visited, 0, sizeof(visited));

        queue<pair<int, pair<int, int> > > qF;
        queue<pair<int, pair<int, int> > > qJ;

        for(int i = 0;i<r;i++) {
            gets(line);
            for(int j = 0;j<c;j++) {
                if(line[j] == '.')
                    map[i][j] = 1;
                else if(line[j] == 'J') {
                    qJ.push(make_pair(0, make_pair(i, j)));
                    map[i][j] = 1;
                    visited[i][j] = 1;
                }
                else if(line[j] == 'F') {
                    qF.push(make_pair(0, make_pair(i, j)));
                    dF[i][j] = 0;
                    map[i][j] = 1;
                }
            }
        }

        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        while(!qF.empty()) {
            int tt = qF.front().first, nx = qF.front().second.first, ny = qF.front().second.second; qF.pop();

            for(int i = 0;i<4;i++) {
                int nnx = nx+dx[i], nny = ny+dy[i];
                if(nnx < 0 || nnx >= r || nny < 0 || nny >= c)
                    continue;

                if(map[nnx][nny] && (dF[nnx][nny] == -1 || dF[nnx][nny] > tt+1)) {
                    dF[nnx][nny] = tt+1;
                    qF.push(make_pair(tt+1, make_pair(nnx, nny)));
                }
            }
        }

        bool isEscape = false;
        int ans;
        while(!qJ.empty()) {
            int tt = qJ.front().first, nx = qJ.front().second.first, ny = qJ.front().second.second; qJ.pop();

            if(nx == 0 || nx == r-1 || ny == 0 || ny == c-1) {
                isEscape = true;
                ans = tt;
                break;
            }

            for(int i = 0;i<4;i++) {
                int nnx = nx+dx[i], nny = ny+dy[i];
                if(nnx < 0 || nnx >= r || nny < 0 || nny >= c)
                    continue;

                if(map[nnx][nny] && !visited[nnx][nny] && (dF[nnx][nny] > tt+1 || dF[nnx][nny] == -1)) {
                    visited[nnx][nny] = 1;
                    qJ.push(make_pair(tt+1, make_pair(nnx, nny)));
                }
            }
        }

        if(isEscape)
            printf("%d\n", ans+1);
        else
            printf("IMPOSSIBLE\n");
    }
}
