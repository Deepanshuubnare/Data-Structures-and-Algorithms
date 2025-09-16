class Solution {
public:
void f(vector<vector<int>>&ans,vector<int>&a,vector<int>&nums,int i){
    if(i==nums.size()){
        ans.push_back(a);
        return;
    }
    //not take
    f(ans,a,nums,i+1);
    a.push_back(nums[i]);
    f(ans,a,nums,i+1);
    a.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>a;
        f(ans,a,nums,0);
        return ans;
    }
};