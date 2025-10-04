class Solution {
public:
int f(vector<int>&nums,int m){
   int cnt=0;
    int c=0;
    for(int i=0;i<nums.size();i++){
        if(c+nums[i]<=m) c+=nums[i];
        else {
            cnt++;
            c=nums[i];
        }
    }
    cnt++;
    return cnt;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int lo=-1e9;
        int hi=0;
        for(int i=0;i<n;i++){
            lo=max(lo,nums[i]);
            hi+=nums[i];
        }
       
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(f(nums,mid)>k) lo=mid+1;
            else hi=mid-1;
        }
        return lo;
    }
};