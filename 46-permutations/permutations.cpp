class Solution {
public:
void f(vector<vector<int>>&ans,vector<int>&nums,int i){
    if(i==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int idx=i;idx<nums.size();idx++){
        swap(nums[idx],nums[i]);
        f(ans,nums,i+1);
        swap(nums[idx],nums[i]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        f(ans,nums,0);
        return ans;
    }
};