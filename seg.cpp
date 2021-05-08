#include<bits/stdc++.h>
using namespace std;
#define ll long long 

vector<ll> tree;

ll query(ll node, ll node_low, ll node_high, ll query_low, ll query_high){
	
	// if query range lies in the nodes range
	if(query_low <= node_low && node_high <= query_high){
		return tree[node];
	}
	// if disjoint ranges
	if(query_high < node_low || node_high < query_low){
		return 0;
	}
	
	ll last_in_left = (node_low + node_high)/2;
	return query(2*node, node_low, last_in_left, query_low, query_high) +
		   query(2*node+1, last_in_left + 1, node_high, query_low, query_high);
}

void update(ll pos, ll new_value, ll n){
	tree[n+pos] = new_value;
	for(ll i=(n+pos)/2; i>=1;i/=2){
		tree[i] = tree[2*i] + tree[2*i+1];
	}
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
	// going bottom up
	for(ll i=n-1;i>0;i--){
		tree[i] = tree[2*i] + tree[2*i+1];
	}
	
	// query
	
	for(ll i=0;i<q;i++){
		ll type,l, r;
		cin>>type>>l>>r;
		if(type == 1){
			--l;
			update(l, r, n);
			continue;
		}
		--l,--r;
		cout<< query(1, 0, n-1, l, r) <<endl;
	}
	return 0;
}
