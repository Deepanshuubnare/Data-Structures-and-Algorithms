class Solution {
public:
void f1(vector<int>&arr,vector<int>&nse,int n){
    stack<int>st;
 nse[n-1]=n;
   st.push(n-1);
   for(int i=n-2;i>=0;i--){
    while(st.size()>0 && arr[st.top()]>=arr[i]){
        st.pop();
    } 
    if(st.size()==0) nse[i]=n;
    else nse[i]=st.top();
    st.push(i);
   }
}
   void f2(vector<int>&arr,vector<int>&pse,int n){
 pse[0]=-1;
 stack<int>st;
   st.push(0);
   for(int i=1;i<n;i++){
    while(st.size()>0 && arr[st.top()]>arr[i]){
        st.pop();
    } 
    if(st.size()==0) pse[i]=-1;
    else pse[i]=st.top();
    st.push(i);
   }
   }
   void f3(vector<int>&arr,vector<int>&nse,int n){
    stack<int>st;
 nse[n-1]=n;
   st.push(n-1);
   for(int i=n-2;i>=0;i--){
    while(st.size()>0 && arr[st.top()]<=arr[i]){
        st.pop();
    } 
    if(st.size()==0) nse[i]=n;
    else nse[i]=st.top();
    st.push(i);
   }
}
void f4(vector<int>&arr,vector<int>&pse,int n){
 pse[0]=-1;
 stack<int>st;
   st.push(0);
   for(int i=1;i<n;i++){
    while(st.size()>0 && arr[st.top()]<arr[i]){
        st.pop();
    } 
    if(st.size()==0) pse[i]=-1;
    else pse[i]=st.top();
    st.push(i);
   }
   }
    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse(n);
        vector<int>pse(n);
         f1(arr,nse,n);
         f2(arr,pse,n);
         long long sum=0;
         int mod=1e9+7;
        for(int i=0;i<n;i++){
            int l=nse[i]-i;
            int r=i-pse[i];
      sum = (sum + (1LL * l * r * arr[i])) ;
        }
        return sum;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse(n);
        vector<int>pse(n);
         f3(arr,nse,n);
         f4(arr,pse,n);
         long long sum=0;
         int mod=1e9+7;
        for(int i=0;i<n;i++){
            int l=nse[i]-i;
            int r=i-pse[i];
      sum = (sum + (1LL * l * r * arr[i]) );
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};