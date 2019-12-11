/*
ID: Labib Rashid
LANG: C++
TASK: fairphoto
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <utility>

#define pb push_back
#define x first
#define y second 
#define PII pair <int,int>

using namespace std;

PII sum, pos[100002];
map <int,int> M;

int main() {
	freopen ("fairphoto.in","r",stdin);
    freopen ("fairphoto.out","w",stdout);
    
    int N, i, j, k;
    string s, H = "H", G = "G";
    
    cin >> N;
    for (i=0;i<N;i++) {
    	cin >> pos[i].x >> s;
    	pos[i].y = (s == G) ? 0 : 1;
    }
    
    sort (pos, pos+N);
    int ans = 0;
    M[0] = -1;
    sum = make_pair (0,0);
    
    for (i=0, j=-1, k=0;i<N;i++) {
    	if (k!=pos[i].y && i != 0) 
    		ans = max (pos[i-1].x - pos[i-1-j].x, ans), j = -1;
    	k = pos[i].y, j++;
    	
    	pos[i].y == 0 ? sum.x++ : sum.y++;
    	if (M.find(sum.y-sum.x) != M.end()) 
    		ans = max (ans, pos[i].x - pos[M[sum.y-sum.x]+1].x);
    	else M[sum.y-sum.x] = i;
    }
    ans = max (ans, pos[i-1].x - pos[i-1-j].x);
    
    cout << ans << endl;
    
    
	return 0;
}