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
		for(ll i=1;i<15;i++){
			up[x][i] = up[ up[x][i-1] ][i-1];
		}
		dfs(x);
	}
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
		ll u,k;
		cin>>u>>k;
		for(ll i=0;i<15;i++){
			if(k&(1<<i)){
				u = up[u][i];
			}
		}
		cout<<u<<endl;
	}
    return 0;
}
























