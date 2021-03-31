class TreeAncestor {
public:
    int dp[50001][20];
    int depth[50001];
    TreeAncestor(int n, vector<int>& parent) {
        parent[0] = 0;
        memset(depth, 0, sizeof depth);
        for(int i=0;i<n;i++){
            if(i){
                depth[i] = depth[parent[i]] + 1;
                dp[i][0] = parent[i];
            }
            for(int j=1;j<20;j++){
                dp[i][j] = dp[ dp[i][j-1] ][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node] < k)
            return -1;
        for(int i=0;i<20;i++){
            if(k&(1ll<<i)){
                node = dp[node][i];
            }
        }
        return node;
    }
};