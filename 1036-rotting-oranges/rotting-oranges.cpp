class Solution {
public:
// queue<pair<pair<int,int>,int>>q;
int orangesRotting(vector<vector<int>>& grid) {
    vector<vector<int>>mat=grid;
    int n=mat.size();
    int m=mat[0].size();
    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>>vit(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==2){
                q.push({{i,j},0});
                vit[i][j]=1;
            }
        }
    }
    int maxt=0;
    while(q.size()>0){
    int i=q.front().first.first;
    int j=q.front().first.second;
    int t=q.front().second;
    q.pop();
    maxt=max(maxt,t);
    int a[4]={-1,0,1,0};
    int b[4]={0,1,0,-1};
    for(int ii=0;ii<4;ii++){
        int nr=i+a[ii];
        int nc=j+b[ii];
    if(nr<n && nc<m && nr>=0 && nc>=0 && mat[nr][nc]==1 && vit[nr][nc]!=1){
        q.push({{nr,nc},t+1});
        vit[nr][nc]=1;
    }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1 && vit[i][j]!=1) return -1;
        }
    }
    return maxt;
}
};