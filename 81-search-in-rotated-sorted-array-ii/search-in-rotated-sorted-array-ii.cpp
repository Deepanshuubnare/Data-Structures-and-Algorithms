class Solution {
public:
    bool search(vector<int>& nums, int tar) {
        int lo=0;
        int hi=nums.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]==tar) return true;
            if(nums[lo]==nums[mid] && nums[mid]==nums[hi]){
                lo++;
                hi--;
                // continue;
            }
            // identify the sorted half
            // left part sorted
            else if (nums[lo]<=nums[mid]){
                if(nums[lo]<=tar && tar<=nums[mid]){
                    hi=mid-1;
                }
                else lo=mid+1;
            }
            //right part sorted
            else{
                if(nums[mid]<=tar && tar<=nums[hi]){
                    lo=mid+1;
                }
                else hi=mid-1;
            }
        }
        return false;
    }
};