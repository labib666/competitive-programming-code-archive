#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 234567
#define UNUSE 0
#define USE 1
#define MID 2
#define NOMID 0
#define mp make_pair
#define pb push_back
#define INF 1000000000000LL

int n, a, b; ll w, pw[N], dp[N][4];
vector<pair<int,ll> > al[N];
void slv(int at, int par) {
	if (al[at].size()==1 && par != -1) return;
	ll sc = 0, bst_mid = -INF, bst_unuse_mid = -INF, bst_unuse_mid2 = -INF, bst_unuse_nomid = -INF, bst_unuse_nomid2 = -INF;
	int bst_unuse_mid_child, bst_unuse_mid_child2, bst_unuse_nomid_child, bst_unuse_nomid_child2;
	for (int i = 0; i < al[at].size(); i++) if (al[at][i].first != par) {
		int go = al[at][i].first; ll ew = al[at][i].second;
		pw[go] = ew; slv(go, at);
		ll normsc = max(dp[go][UNUSE|NOMID], dp[go][USE|NOMID]);
		sc += normsc;
		ll midsc = max(dp[go][UNUSE|MID], dp[go][USE|MID]) - normsc;
		if (midsc > bst_mid) bst_mid = midsc; 
		ll unuse_midsc = dp[go][UNUSE|MID] + ew - normsc;
		if (unuse_midsc > bst_unuse_mid) {
			bst_unuse_mid2 = bst_unuse_mid; bst_unuse_mid_child2 = bst_unuse_mid_child;
			bst_unuse_mid = unuse_midsc;
			bst_unuse_mid_child = go;
		}
		else if (unuse_midsc > bst_unuse_mid2) {
			bst_unuse_mid2 = unuse_midsc;
			bst_unuse_mid_child2 = go;
		}
		ll unuse_nomidsc = dp[go][UNUSE|NOMID] + ew - normsc;
		if (unuse_nomidsc > bst_unuse_nomid) {
			bst_unuse_nomid2 = bst_unuse_nomid; bst_unuse_nomid_child2 = bst_unuse_nomid_child;
			bst_unuse_nomid = unuse_nomidsc;
			bst_unuse_nomid_child = go;
		}
		else if (unuse_nomidsc > bst_unuse_nomid2) {
			bst_unuse_nomid2 = unuse_nomidsc;
			bst_unuse_nomid_child2 = go;
		}
	}
	dp[at][UNUSE|NOMID] = sc;
	dp[at][UNUSE|MID] = sc + max(0LL, bst_mid);
	dp[at][UNUSE|MID] = max(dp[at][UNUSE|MID], sc + bst_unuse_nomid + bst_unuse_nomid2);
	if (bst_unuse_mid_child != bst_unuse_nomid_child) dp[at][UNUSE|MID] = max(dp[at][UNUSE|MID], sc + bst_unuse_nomid + bst_unuse_mid);
	else {
		dp[at][UNUSE|MID] = max(dp[at][UNUSE|MID], sc + bst_unuse_nomid2 + bst_unuse_mid);
		dp[at][UNUSE|MID] = max(dp[at][UNUSE|MID], sc + bst_unuse_nomid + bst_unuse_mid2);
	}

	dp[at][USE|NOMID] = sc + pw[at] + bst_unuse_nomid;
	dp[at][USE|MID] = sc + pw[at] + bst_unuse_mid;
}
int main() {
	freopen("beads.in", "r", stdin); freopen("beads.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d %lld", &a, &b, &w);
		al[a].pb(mp(b, w)); al[b].pb(mp(a, w));
	}
	slv(1, -1);
	printf("%lld\n", max(dp[1][UNUSE|MID], dp[1][UNUSE|NOMID]));

	return 0;
}