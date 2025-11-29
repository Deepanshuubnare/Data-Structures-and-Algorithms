class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        vector<int>hash(256,-1);
        int maxl=0;
        while(r<s.size()){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            maxl=max(maxl,r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxl;
    }
};