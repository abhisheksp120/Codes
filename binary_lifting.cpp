#include <bits/stdc++.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#define _USE_MATH_DEFINES
#define ll  long long int
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
using namespace std;
//mp.reserve(1024);
//mp.max_load_factor(0.25);
const long long inf = 1e18;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
vector<vector<ll>>adj;
vector<ll>depth;
ll up[10001][15];

void dfs(ll src){
	
	for(auto x:adj[src]){
		up[x][0] = src; 
		depth[x] = depth[src] + 1;
		for(ll i=1;i<15;i++){
			up[x][i] = up[ up[x][i-1] ][i-1];
		}
		dfs(x);
	}
}

ll get_lca(ll a, ll b){
	
	if(depth[a] < depth[b])
		swap(a, b);
	// Brute force O(N)
	//while(depth[a] != depth[b]){
	//	a = up[a][0];
	//}
	
	//while(up[a][0] != up[b][0]){
	//	a = up[a][0];
	//	b = up[b][0];
	//}
	
	//return a != b ? up[a][0] : a;
	
	// Using Binary Lifting O(Log(N))
	ll k = depth[a] - depth[b];
	for(ll i=0;i<15;i++){
		if(k&(1<<i))
			a = up[a][i];
	}
	if(a == b)
		return a;
		
	for(ll i=14;i>=0;i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

int main()
{
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
   	cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("outf.txt", "w", stdout);
	ll n;
	cin>>n;
	adj.resize(n, vector<ll>());
	depth.resize(n);
	for(ll i=0;i<n;i++){
		ll x,a;
		cin>>x;
		while(x--){
			cin>>a;
			adj[i].push_back(a);
		}
	}
	dfs(0);
	ll q;
	cin>>q;
	while(q--){
		ll u,v;
		cin>>u>>v;
		cout<<get_lca(u, v)<<endl;
		
	}
    return 0;
}
























