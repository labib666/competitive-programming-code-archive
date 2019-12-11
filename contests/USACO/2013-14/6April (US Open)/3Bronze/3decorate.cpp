/*
ID: Labib Rashid
LANG: C++
TASK: decorate
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

#define pb push_back

using namespace std;

int C[50001], V[50001];
int S[50001], L[50001];
vector <int> E[50001];

int main() {
	freopen ("decorate.in","r",stdin);
    freopen ("decorate.out","w",stdout);
    
    int N, M, i, j, k, p = 0;
    
    cin >> N >> M;
    
    while (M--) {
    	cin >> i >> j;
    	E[i].pb (j);
    	E[j].pb (i);
    }
    
    bool fail = 0;
    int ans = 0;
    
    for (i=1;i<=N;i++) {
    	if (V[i] == 0) {
    		
    		int cnt[2] = {0,1};
    		S[p] = i; L[p] = -1; p++;
    		C[i] = 1, V[i] = 1;
    		
    		while (p != 0) {
    			for (j=L[p-1]+1; j<E[S[p-1]].size(); j++) {
    				
    				k = E[S[p-1]][j];
    				
    				if (V[k] && C[k] == C[S[p-1]]) {
    					fail = 1;
    					break;
    				}
    				else if (V[k]) continue;
    				
    				L[p-1] = j;
    				V[k] = 1, C[k] = C[S[p-1]]^1; cnt[C[k]]++; 
    				S[p] = k; L[p] = -1; p++;
    				j = -1;
    				
    			}
    			
    			if (fail) break;
    			p--;
    			
    		}
    		
    		if (fail) break;
    		ans += max (cnt[0], cnt[1]);
    	}
    	
    	if (fail) break;
    	
    }
    
    if (fail) cout << -1 << endl;
    else cout << ans << endl;
    
    
	return 0;
}