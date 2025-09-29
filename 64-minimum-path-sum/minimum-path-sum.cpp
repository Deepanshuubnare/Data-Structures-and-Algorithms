class Solution {
public:
int f(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j,int n,int m){
    if(i==0 && j==0) return grid[0][0];
    if(i<0 ||  j<0) return 1e8;
    if(dp[i][j]!=-1) return dp[i][j];
    int top=grid[i][j]+f(grid,dp,i-1,j,n,m);
    int left=grid[i][j]+f(grid,dp,i,j-1,n,m);
    return dp[i][j]=min(top,left);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(grid,dp,n-1,m-1,n,m);
    }
};