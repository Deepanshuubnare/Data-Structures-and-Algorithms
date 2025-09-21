class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // pair<int,int>
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
          vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            // if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                pq.push({abs(target-sum),sum});
               if(sum<target) j++;
              else if(target<sum)  k--;
              else {
                j++;
                k--;
              }
            //   while(j<k && nums[j]==nums[j-1]) j++;
            //     while(j<k && nums[k]==nums[k+1]) k--;
                }
               
            }
        return pq.top().second;
    }
};