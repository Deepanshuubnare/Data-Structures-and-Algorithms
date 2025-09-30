class Solution {
public:
int f(int i,int j,string s, string t,vector<vector<int>>&dp){
  if(i<0) return j+1;
  if(j<0) return i+1;
  if(dp[i][j]!=-1) return dp[i][j];
  if(s[i]==t[j]) return dp[i][j]= 0+f(i-1,j-1,s,t,dp);
  else{
    int ist=1+f(i,j-1,s,t,dp);
    int del=1+f(i-1,j,s,t,dp);
    int rep=1+f(i-1,j-1,s,t,dp);
    return dp[i][j]=min({ist,del,rep});
  }
  
}
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,s,t,dp);
        // Tabulation 
         vector<vector<double >>dpp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++) dpp[i][0]=i;
        for(int j=0;j<=m;j++) dpp[0][j]=j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                     dpp[i][j]=dpp[i-1][j-1];
                }
                else {
                    dpp[i][j]=1+min({dpp[i][j-1],dpp[i-1][j],dpp[i-1][j-1]});
                }
            }
        }
        // return (int)dpp[n][m];
    }
};