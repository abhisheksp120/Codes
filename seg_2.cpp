#include<bits/stdc++.h>
using namespace std;
#define ll long long 

vector<ll> tree;

// All nodes are empty except leaf nodes

// except leaf other nodes store the increment in the range

void update(ll node, ll node_low, ll node_high, ll query_low, ll query_high, ll value){
	
	// if query range lies in the nodes range
	if(query_low <= node_low && node_high <= query_high){
		tree[node] += value;
		return ; 
	}
	// if disjoint ranges
	if(query_high < node_low || node_high < query_low){
		return;
	}
	
	ll last_in_left = (node_low + node_high)/2;
	update(2*node, node_low, last_in_left, query_low, query_high, value);
	update(2*node+1, last_in_left + 1, node_high, query_low, query_high, value);
}

// traversing from leaf to root adding the increament got in the path

ll give(ll pos, ll n){
	ll ans = tree[n+pos];
	for(ll i=(n+pos)/2; i>=1;i/=2){
		ans += tree[i];
	}
	return ans;
}
int main(){
	
	ll n, q;
	cin>>n>>q;
	vector<ll>v(n);
	for(ll i=0;i<n;i++)
		cin>>v[i];
	while(__builtin_popcount(n) != 1){
		v.push_back(0);
		n++;
	}
	
	tree.resize(2 * n);
	// Build tree
	// filling leaf nodes
	for(ll i=0;i<n;i++){
		tree[n+i] = v[i];
	}
	
	//for(ll i=n-1;i>0;i--){
	//	tree[i] = tree[2*i] + tree[2*i+1];
	//}
	
	// query
	
	for(ll i=0;i<q;i++){
		ll type,l, r;
		cin>>type;
		if(type == 1){
			ll a,b,u;
			cin>>a>>b>>u;
			--a,--b;
			update(1, 0, n-1, a, b, u);
		}
		else{
			ll k;
			cin>>k;
			k--;
			cout<< give(k, n) <<endl;
		}
	}
	return 0;
}
