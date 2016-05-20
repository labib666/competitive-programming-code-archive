#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <math.h>
using namespace std;
#define rep(i,n) for(int (i)=(0);(i)<(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
#define fi first
#define se second
typedef long long ll;

char s[300010];
char tmp[600020];
int rad[600020];
int N;

void manacher()
{
	rep(i,N*2+1)tmp[i]='#';
	rep(i,N)tmp[i*2+1]=s[i];
	int i=0,j=0;
	int n=N*2+1;
	for(int i=0;i<n;)
	{
			while(i-j>=0&&i+j<n&&tmp[i-j]==tmp[i+j])j++;
			rad[i]=j;
			int k=1;
			while(rad[i-k]<rad[i]-k)rad[i+k]=rad[i-k],k++;
			i+=k;
			j=max(0,j-k);
	}
}
int sa[300001],ra[300001],sak;
int ti[300001];
int lcp[300001];
bool cmp_sa(int a,int b)
{
	if(ra[a]!=ra[b])return ra[a]<ra[b];
	int cha=(a+sak<=N)?ra[a+sak]:-1;
	int chb=(b+sak<=N)?ra[b+sak]:-1;
	return cha<chb;
}
void construct_sa(int n)
{
	rep(i,n+1)
	{
		sa[i]=i;
		ra[i]=(i<n)?s[i]:-1;
	}
	for(sak=1;sak<n;sak*=2)
	{
		sort(sa,sa+n+1,cmp_sa);
		ti[sa[0]]=0;
		for(int i=1;i<=n;i++)ti[sa[i]]=ti[sa[i-1]]+cmp_sa(sa[i-1],sa[i]);
		rep(i,n+1)ra[i]=ti[i];
	}
}
void construct_lcp(int n)
{
	rep(i,n+1)ti[sa[i]]=i;
	int h=0;
	rep(i,n)
	{
		int j=sa[ti[i]-1];
		if(h>0)h--;
		while(i+h<n&&j+h<n&&s[i+h]==s[j+h])h++;
		lcp[ti[i]]=h;
	}
}
struct UnionFind
{
	int par[300001],ra[300001],sz[300001];
	void init(){rep(i,300001)par[i]=i,ra[i]=0,sz[i]=0;}
	int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
	bool same(int a,int b){return find(a)==find(b);}
	void unite(int a,int b){if((a=find(a))!=(b=find(b))){if(ra[a]<ra[b])swap(ra[a],ra[b]);sz[a]+=sz[b];par[b]=a,ra[a]+=ra[a]==ra[b];}}
} uf;

int main()
{
	FILE *in,*out;
	
	in=stdin;out=stdout;
	// in APIO 2014
	//in=fopen("palindrome.in","r");
	//out=fopen("palindrome.out","w");
	
	fscanf(in,"%s",&s);
	ll ans=0;
	N=strlen(s);
	manacher();
	construct_sa(N);
	construct_lcp(N);
	vector<pip> lun;
	repn(i,1,N+1)lun.pb(mp(lcp[i],mp(sa[i-1],sa[i])));
	sort(lun.begin(),lun.end(),greater<pip>());
	//odd
	uf.init();
	vector<pii> aq;
	rep(i,N)aq.pb(mp(rad[i*2+1]/2,i));
	sort(aq.begin(),aq.end(),greater<pii>());
	int ptr=0;
	rep(i,N)
	{
		while(ptr<N&&lun[ptr].fi>=aq[i].fi)
		{
			uf.unite(lun[ptr].second.first,lun[ptr].second.second);
			ptr++;
		}
		int ppuf=uf.find(aq[i].se);
		uf.sz[ppuf]++;
		ans=max(ans,ll(uf.sz[ppuf])*(aq[i].first*2-1));
	}
	
	//even
	uf.init();
	aq.clear();
	rep(i,N)aq.pb(mp(rad[i*2]/2,i));
	sort(aq.begin(),aq.end(),greater<pii>());
	ptr=0;
	rep(i,N)
	{
		while(ptr<N&&lun[ptr].fi>=aq[i].fi)
		{
			uf.unite(lun[ptr].second.first,lun[ptr].second.second);
			ptr++;
		}
		int ppuf=uf.find(aq[i].se);
		uf.sz[ppuf]++;
		ans=max(ans,ll(uf.sz[ppuf])*(aq[i].first*2));
	}

	fprintf(out,"%lld\n",ans);
	fclose(in);fclose(out);
}