class Solution {
public:
void f(int j,vector<int>&a,vector<vector<int>>&ans,int n,int k){
    if(a.size()==k){
        ans.push_back(a);
        return;
    }
    for(int i=j;i<=n;i++){
        a.push_back(i);
        f(i+1,a,ans,n,k);
        a.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<int>a;
        vector<vector<int>>ans;
        f(1,a,ans,n,k);
        return ans;
    }
};