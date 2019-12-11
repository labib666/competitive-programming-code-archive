#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define LL long long
#define xx first
#define yy second

vector < int > vc[100001], vr[100001];
stack < int > st;
int vis[100001], sz[200001], com[100001];
void dfs(int c) {
    vis[c] = 1;
    for(int i = 0; i < vc[c].size(); i++) {
        if(!vis[ vc[c][i] ]) dfs(vc[c][i]);
    }
    st.push(c);
}
void SCC(int c, int p) {
    com[c] = p;
    vis[c] = 1;
    for(int i = 0; i < vr[c].size(); i++) {
        if(!vis[ vr[c][i] ]) SCC(vr[c][i], p);
    }
}
pair < int, int > pp[100001];
main() {
//    freopen("large.in", "r", stdin);
//    freopen("large1.out", "w", stdout);
    int cases;
    cin >> cases;
    for(int ts = 1; ts <= cases; ts++) {
        for(int i = 0; i <= 100000; i++) {
            vc[i].clear();
            vr[i].clear();
        }
        memset(sz, 0, sizeof sz);
        memset(vis, 0, sizeof vis);
        memset(com, 0, sizeof com);
        while(!st.empty()) st.pop();
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &pp[i].xx, &pp[i].yy);
        }
        sort(pp + 1, pp + n + 1);
        // process from left to right
        st.push(1);
        for(int i = 2; i <= n; i++) {
            while(st.size() > 0) {
                int pre = st.top();
                if((pp[i].xx - pp[pre].xx) > pp[i].yy) break;
                st.pop();
                vc[i].pb(pre);
                vr[pre].pb(i);
            }
            st.push(i);
        }
        while(!st.empty()) {
            st.pop();
        }

        // process from right to left
        st.push(n);
        for(int i = n - 1; i >= 1; i--) {
            while(st.size() > 0) {
                int pre = st.top();
                if((pp[pre].xx - pp[i].xx) > pp[i].yy) break;
                st.pop();
                vc[i].pb(pre);
                vr[pre].pb(i);
            }
            st.push(i);
        }
        while(!st.empty()) {
            st.pop();
        }

        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);

        memset(vis, 0, sizeof vis);
        int cnt = 1;
        while(!st.empty()) {
            int p = st.top();
            st.pop();
            if(!vis[p]) {
                SCC(p, cnt);
                cnt++;
            }
        }
        for(int i = 1; i <= n; i++) {
            sz[com[i]]++;
            for(int j = 0; j < vc[i].size(); j++) {
                if(com[i] != com[ vc[i][j] ]) sz[com[i]] = 1000000;
            }
        }
        int mv = n;
        for(int i = 0; i <= 200000; i++) if(sz[i]) mv = min(mv, (int)sz[i]);

        cout << mv << endl;
    }

}


