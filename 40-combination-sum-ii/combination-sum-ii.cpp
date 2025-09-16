class Solution {
public:
void f(int idx,int t, vector<int>&candi,vector<vector<int>>&ans,vector<int>&d){
  if(t==0) {
    ans.push_back(d);
    return;
    }
  for(int i=idx;i<candi.size();i++){
    if(i>idx && candi[i]==candi[i-1]) continue;
    if(candi[i]>t) break;
    d.push_back(candi[i]);   // take
    f(i+1,t-candi[i],candi,ans,d);
    d.pop_back();
  }
  } 
  

    vector<vector<int>> combinationSum2(vector<int>& candi, int t) {
       vector<vector<int>>ans;
        vector<int>d;
        sort(candi.begin(),candi.end());
        f(0,t,candi,ans,d);
        return ans;
    }
};