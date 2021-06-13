#include <bits/stdc++.h>
#define ll long long 

// Heap
vector<ll> ht;

void heapify(ll index){

	ll mx = index, n = ht.size();
	ll left_child = 2*index+1;
	ll right_child = 2*index+2;
	debug(index, left_child, right_child);
	if(left_child < n && ht[left_child] > ht[mx])
		mx = left_child;
	if(right_child < n && ht[right_child] > ht[mx])
		mx = right_child;
	if(mx != index){
		swap(ht[index], ht[mx]);
		heapify(mx);
	}
}
void insert1(ll value){
	ll n = ht.size();
	if(n == 0)
		ht.push_back(value);
	else{
		ht.push_back(value);
		n = ht.size();
		for(ll i=n/2-1;i>=0;i--){
			heapify(i);
		}
	}
}

void del(){
	swap(ht[0], ht[ht.size()-1]);
	ht.pop_back();
	ll n = ht.size();
	for(ll i=n/2-1;i>=0;i--){
		heapify(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
   	cout.tie(NULL);
    //freopen("input.in", "r", stdin);
    //freopen("outf.txt", "w", stdout);
    
    return 0;
}
















