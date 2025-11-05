class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size();
        int p=0;
        int nn=1;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                 nums[p]=arr[i];
                 p+=2;
        }
        else {
            nums[nn]=arr[i];
            nn+=2;
        }
        }
        return nums;
    }
};