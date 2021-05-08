#include <bits/stdc++.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define _USE_MATH_DEFINES
#define ll  long long int
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
using namespace __gnu_pbds;
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

class FenwickTree{
	
	public:
	
	vector<ll>bit; // Binary indexed tree
	ll n;
	FenwickTree(vector<ll>v){
		n = v.size();
		
		bit.resize(n, 0);
		
		for(ll i=0;i<n;i++){
			add(i, v[i]);
		}
	}
	
	ll sum(ll r){
		ll res = 0;
		while(r>=0){
			res += bit[r];
			r = (r&(r+1)) - 1; // calualted g(r) = r & (r+1) then decremented
		}
		return res;
	}
	
	ll sum(ll l, ll r){
		return sum(r) - sum(l-1);
	}
	
	void add(ll index, ll delta){
		
		while(index < n){
			bit[index] += delta;
			index = index | (index+1);
		}
	}
	
};
int main()
{
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
   	cout.tie(NULL);
    //freopen("out.txt", "r", stdin);
    //freopen("outf.txt", "w", stdout);
	//cout<<ans<<endl;
	ll n;
	cin>>n;
	vector<ll>v(n);
	for(ll i=0;i<n;i++)
		cin>>v[i];
	FenwickTree ft(v);
	ll q;
	cin>>q;
	while(q--){
		ll x,l,r;
		cin>>x>>l>>r;
		--l,--r;
		if(x){
			cout<<ft.sum(l, r)<<endl;
		}
		else{
			ft.add(l, r+1);
		}
	}
    return 0;
}
























