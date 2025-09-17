class Solution {
public:
    string removeDuplicates(string s, int k) {
         stack<pair<char,int>>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.size()==0) st.push({s[i],1});
            else if(st.top().first!=s[i]) st.push({s[i],1});
            else if(st.top().first==s[i]){
                st.push({s[i],st.top().second+1});
                if(st.top().second==k){
                    int t=k;
                    while(t!=0){
                        st.pop();
                        t--;
                    }
                }
            }
        }
        string ss;
        while(st.size()>0){
            ss+=st.top().first;
            st.pop();
        }
        reverse(ss.begin(),ss.end());
        return ss;
    }
};