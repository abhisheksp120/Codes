#include <bits/stdc++.h>
#define ll long long 

// Trie
string ans;
void dfs(int node, string& so_far, const vector<vector<int>>& nxt, const vector<bool>& terminal){
    if(so_far.size() > ans.size() )
        ans = so_far;
    for(int i=0;i<26;i++){
        int tmp = nxt[node][i];
        if(tmp != 0 && terminal[tmp]){
            so_far += char('a'+i);
            dfs(tmp, so_far, nxt, terminal);
            so_far.pop_back();
        }
    }
}
string longestWord(vector<string>& words) {
    int n = 0;
    vector<vector<int>>nxt(1, vector<int>(26));
    vector<bool>terminal(1);
    for(auto x:words){
        int node = 0;
        for(auto c:x){
            if(nxt[node][c-'a'] == 0){
                nxt.push_back(vector<int>(26));
                terminal.push_back(false);
                nxt[node][c-'a'] = ++n;
            }
            node = nxt[node][c-'a'];
        }
        terminal[node] = true;
    }
    string so_far = "";
    dfs(0, so_far, nxt, terminal);
    return ans;
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
















